#ifndef LIST_HPP_
#define LIST_HPP_
#include <iostream>
#endif

template<typename T>
struct node
{
    T data;
    node * prev;
    node * next;
    node(): prev(nullptr), next(nullptr){}
    explicit node(T & n): prev(nullptr), next(nullptr), data(n){}
    explicit node(node<T> * prev, T & n, node<T> * next): prev(prev), data(n), next(next){}
};

template<typename T>
class List
{
private:
    node<T> * head;
    node<T> * tail;
public:
    List()
    {
        this->head = new node<T>();
        auto * temp = new node<T>();
        temp->prev = this->head;
        this->head->next = temp;
        this->tail = temp;
    }
    explicit List(T & data)
    {
        this->head = new node<T>();
        auto * temp = new node<T>(this->head, data, nullptr);
        this->head->next = temp;
        this->tail = temp;
    }
    List(T * data, int length)
    {
        this->head = new node<T>;
        node<T> * last = this->head;
        node<T> * temp;
        for (int i = 0; i < length; ++i)
        {
            temp = new node<T>(last, data[i], nullptr);
            last->next = temp;
            last = temp;
        }
        this->tail = last;
    }
    List(List<T> & copy)
    {
        this->head = new node<T>();
        node<T> * temp = copy.head->next;
        node<T> * data = nullptr;
        node<T> * last = this->head;
        while (temp != nullptr)
        {
            data = new node<T>(last, temp->data, nullptr);
            last->next = data;
            last = data;
            temp = temp->next;
        }
        this->tail = last;
    }
    ~List()
    {
        node<T> * temp;
        while (this->tail != nullptr)
        {
            temp = this->tail->prev;
            delete this->tail;
            this->tail = temp;
        }
    }
    void print(bool trans = false)
    {
        using namespace std;
        node<T> * temp;
        if (trans)
        {
            temp = this->tail;
            while (temp != this->head)
            {
                cout << temp->data << " ";
                temp = temp->prev;
            }
            cout << endl;
        }
        else
        {
            temp = this->head->next;
            while (temp != nullptr)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
    List<T> & operator=(const List<T> & parm)
    {
        if (this == &parm)
        {
            return *this;
        }
        node<T> * left = this->head->next;
        node<T> * right = parm.head->next;
        while (left != nullptr && right != nullptr)
        {
            left->data = right->data;
            left = left->next;
            right = right->next;
        }
        node<T> * temp = nullptr;
        if (left == nullptr && right != nullptr)
        {
            node<T> * last = this->tail;
            while (right != nullptr)
            {
                temp = new node<T>(last, right->data, nullptr);
                last->next = temp;
                last = temp;
                right = right->next;
            }
            this->tail = last;
            this->tail->next = nullptr;
            return *this;
        }
        else if (left != nullptr)
        {
            left = left->prev;
            while (this->tail != left)
            {
                temp = this->tail->prev;
                delete this->tail;
                this->tail = temp;
            }
            this->tail->next = nullptr;
            return *this;
        }
        else
        {
            return *this;
        }
    }
    List<T> & operator+(List<T> & parm)
    {
        node<T> * temp;
        node<T> * data = parm.head->next;
        while (data != nullptr)
        {
            temp = new node<T>(this->tail, data->data, nullptr);
            this->tail->next = temp;
            this->tail = temp;
            data = data->next;
        }
        return *this;
    }
    List<T> & operator+=(List<T> & parm)
    {
        node<T> * temp;
        node<T> * data = parm.head->next;
        while (data != nullptr)
        {
            temp = new node<T>(this->tail, data->data, nullptr);
            this->tail->next = temp;
            this->tail = temp;
            data = data->next;
        }
        return *this;
    }
    T & front()
    {
        return this->head->next->data;
    }
    T & back()
    {
        return this->tail->data;
    }
    void push_back(T & input)
    {
        auto * temp = new node<T>(this->tail, input, nullptr);
        this->tail->next = temp;
        this->tail = temp;
    }
    void push_front(T & input)
    {
        node<T> * next = this->head->next;
        auto * temp = new node<T>(this->head, input, next);
        this->head->next = temp;
        next->prev = temp;
    }
    void pop_back()
    {
        node<T> * temp = this->tail->prev;
        delete this->tail;
        this->tail = temp;
        this->tail->next = nullptr;
    }
    void pop_front()
    {
        node<T> * next = this->head->next->next;
        delete this->head->next;
        this->head->next = next;
        next->prev = this->head;
    }
    bool find(T & input)
    {
        node<T> * temp = this->head->next;
        while (temp != nullptr)
        {
            if (temp->data == input)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
};
