#ifndef LIST_H
#define LIST_H

#include <initializer_list>
#include <iostream>


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

    void push_back(Node *node)
    {
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


    bool is_empty() const
    {
        return (m_head == nullptr && m_tail == nullptr);
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

    friend std::ostream& operator<<(std::ostream& out, const List& list)
    {
        Node *node;
        if (!list.is_empty())
        {
            node = list.m_head;
            do {
                out << node;
                node = node->next;
                if (node != nullptr) // same check as the loop itself, maybe refactor the loop
                    out << "<->";
            } while (node != nullptr);
        }
        return out;
    }
};

#endif