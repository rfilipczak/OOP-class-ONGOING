#ifndef LIST_H
#define LIST_H

#include <initializer_list>
#include <iostream>
#include <fstream>
#include <cassert>
#include <sstream>
#include <vector>


template <typename T>
class List
{
private:
    struct Node
    {
        T id{};
        Node *prev{ nullptr };
        Node *next{ nullptr };

        Node(const T& _id)
         : id{_id}, prev{nullptr}, next{nullptr}
        {
        }

        friend std::ostream& operator<<(std::ostream& out, const Node* node)
        {
            out << "Node{" << node->id << '}';
            return out;
        }
    };

    Node *m_head{ nullptr };
    Node *m_tail{ nullptr };
    int m_length{ 0 };

    bool is_empty() const
    {
        return (m_length == 0);
    }

    void push_back(Node *node)
    {
        assert(node != nullptr);
        
        if (is_empty())
        {
            m_head = node;
            m_tail = node;
        }
        else
        {
            m_tail->next = node;
            node->prev = m_tail;
            m_tail = node;
        }
        ++m_length;
    }
    
    void push_between(Node *prev, Node *node, Node *next)
    {
        assert(prev != nullptr);
        assert(node != nullptr);
        assert(next != nullptr);

        node->prev = prev;
        node->next = next;
        prev->next = node;
        next->prev = node;
        ++m_length;
    }

    Node *find(const T& id) const
    {
        if (is_empty())
            return nullptr;
        
        Node *result = nullptr;

        if (m_head == m_tail)
        {
            if (m_head->id == id)
            {
                result = m_head;
            }
        }
        else
        {
            bool found{ false };
            Node *node = m_head;
            do {
                if (node->id == id)
                {
                    result = node;
                    found = true;
                }
                else
                {
                    node = node->next;
                }
            } while (!found && node != nullptr);
        }

        return result; // found node in the list or nullptr
    }

    Node *get_node_at(int index)
    {
        assert(index >= 0);

        if (is_empty())
            return nullptr;
        
        Node *node = m_head;
        int current_index = 0;
        do {
            if (current_index == index)
                return node;
            ++current_index;
            node = node->next;
        } while (node != nullptr);

        return nullptr;
    }

    void swap_id(Node *a, Node *b)
    {
        assert(a != nullptr);
        assert(b != nullptr);
        
        auto tmp = a->id;
        a->id = b->id;
        b->id = tmp;
    }

public:

    using NodeIDType = T;

    List(std::initializer_list<T> li)
        : m_head{nullptr}, m_tail{nullptr}
    {
        for (const auto& id : li)
        {
            Node *node = new Node(id);
            push_back(node);
        }
    }

    List(std::ifstream& ifile)
    {
        std::vector<T> values{};
        std::string line;
        while (std::getline(ifile, line))
        {
            std::istringstream iss{ line };
            while (!iss.eof())
            {
                std::string tmp;
                iss >> tmp;
                T id;
                if (std::istringstream{tmp} >> id)
                {
                    values.emplace_back(id);
                }
            }
        }
        for (const auto& id : values)
        {
            Node *node = new Node(id);
            push_back(node);
        }
    }
    
    ~List()
    {
        if (!is_empty())
        {
            Node *node = m_head;
            Node *next = nullptr;
            do {
                next = node->next;
                delete node;
                node = next;
            } while (node != nullptr);
        }
    }

    enum class RemoveResultType
    {
        Success,
        NotFound
    };

    RemoveResultType remove(const T& id)
    {
        // TODO: simplify
        // TODO: too many returns?

        if (is_empty())
        {
            return RemoveResultType::NotFound;
        }
        else if (m_head == m_tail)
        {
            // 1 node in the list
            if (m_head->id == id)
            {
                delete m_head;
                m_head = m_tail = nullptr;
                --m_length;
                return RemoveResultType::Success;
            }
            else
            {
                return RemoveResultType::NotFound;
            }
        }
        else
        {
            // more nodes in the list

            if (Node *node = find(id); node != nullptr)
            {
                if (node == m_head)
                {
                    node->next->prev = nullptr;
                    m_head = node->next;
                }
                else if (node == m_tail)
                {
                    node->prev->next = nullptr;
                    m_tail = node->prev;
                }
                else
                {
                    node->prev->next = node->next;
                    node->next->prev = node->prev;
                }
                delete node;
                --m_length;
                return RemoveResultType::Success;
            }
            else
            {
                // node with id not found
            }
        }
        
        // node with id not found
        return RemoveResultType::NotFound;
    }

    const Node* push_back(const T& id)
    {
        Node *node = new Node(id);
        push_back(node);
        return node;
    }

    const Node* insert_after(const T& id, const T& new_id)
    {
        // TODO: simplify

        Node *node = new Node(new_id);

        if (is_empty())
        {
            push_back(node);
        }
        else if (m_head == m_tail)
        {
            // 1 node in the list  
            push_back(node);
        }
        else
        {
            // more nodes in the list

            if (Node *found = find(id); found != nullptr)
            {
                if (found == m_tail)
                {
                    push_back(node);
                }
                else
                {
                    push_between(found, node, found->next);
                }
            }
            else
            {
                // node with given id not found
                push_back(node);
            }
        }

        return node;
    }

    const List& sort()
    {

        // TODO: ridiculously bad time complexity
        //
        // hacked "standard" bubble sort for arrays into linked list with get_node_at() 
        // which iterates over the list every inner loop

        if (is_empty())
            return *this;
        
        int len = m_length;
        
        for (int i = 0; i < len - 1; ++i)
        {
            for (int j = 0; j < len - i - 1; ++j)
            {
                Node *a = get_node_at(j);
                Node *b = a->next;

                assert(a != nullptr);
                assert(b != nullptr);

                if (a->id > b->id)
                    swap_id(a, b);
            }
        }

        return *this;
    }

    const List& clear()
    {
        if (!is_empty())
        {
            Node *node = m_head;
            Node *next = nullptr;
            do {
                next = node->next;
                delete node;
                node = next;
            } while (node != nullptr);
        }
        m_head = nullptr;
        m_tail = nullptr;
        m_length = 0;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, const List& list)
    {
        out << "List{";
        if (!list.is_empty())
        {
            Node *node = list.m_head;
            do {
                out << node;
                node = node->next;
                if (node != nullptr) // TODO: same check as the loop itself, maybe refactor the loop
                    out << "<->";
            } while (node != nullptr);
        }
        out << '}';
        return out;
    }

    void saveToFile(std::ofstream& out)
    {
        if (!is_empty())
        {
            Node *node = m_head;
            do {
                out << node->id << ' ';
                node = node->next;
            } while (node != nullptr);
        }
        out << '\n';
    }
};

#endif
