#ifndef LIST_H
#define LIST_H

#include <initializer_list>
#include <iostream>
#include <cassert>


template <typename T>
class List
{
private:
    struct Node
    {
        T id;
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

    bool is_empty() const
    {
        return (m_head == nullptr && m_tail == nullptr);
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

        return result;
    }

    int length()
    {
        if (is_empty())
            return 0;
        int count = 0;
        Node *node = m_head;
        do {
            ++count;
            node = node->next;
        } while (node);

        return count;
    }

    Node *get_node_at(int index)
    {
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

    void swap(Node *a, Node *b)
    {
        auto tmp = a->id;
        a->id = b->id;
        b->id = tmp;
    }

public:
    List()
        : m_head{nullptr}, m_tail{nullptr}
    {
    }

    List(std::initializer_list<T> li)
        : m_head{nullptr}, m_tail{nullptr}
    {
        for (const auto& id : li)
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

    void remove(const T& id)
    {
        // TODO: return type
        // TODO: simplify

        if (is_empty())
        {
            // possible early return
        }
        else if (m_head == m_tail)
        {
            // 1 node in the list
            if (m_head->id == id)
            {
                delete m_head;
                m_head = m_tail = nullptr;
            }
            else
            {
                // node with id not found
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
                    delete node;
                }
                else if (node == m_tail)
                {
                    node->prev->next = nullptr;
                    m_tail = node->prev;
                    delete node;
                }
                else
                {
                    node->prev->next = node->next;
                    node->next->prev = node->prev;
                    delete node;
                }
            }
            else
            {
                // node with id not found
            }
        }
        
        // node with id not found
        return;
    }

    Node* push_back(const T& id)
    {
        Node *node = new Node(id);
        push_back(node);
        return node;
    }

    void insert_after(const T& id, const T& new_id)
    {
        Node *node = new Node(new_id);

        if (is_empty())
        {
            m_head = node;
            m_tail = node;
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
                    node->prev = found;
                    node->next = found->next;
                    found->next = node;
                    node->next->prev = node;
                }
            }
            else
            {
                // node with given id not found
                push_back(node);
            }
        }
    }

    const List& sort()
    {

        // TODO: ridiculously bad time complexity

        if (is_empty())
            return *this;
        
        int len = length();
        
        for (int i = 0; i < len - 1; ++i)
        {
            for (int j = 0; j < len - i - 1; ++j)
            {
                Node *a = get_node_at(j);
                Node *b = get_node_at(j+1);

                assert(a != nullptr);
                assert(b != nullptr);

                if (a->id > b->id)
                    swap(a, b);
            }
        }

        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, const List& list)
    {
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
        return out;
    }
};

#endif
