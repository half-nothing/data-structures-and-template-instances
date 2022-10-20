#ifndef VECTOR_HPP_
#define VECTOR_HPP_
#include <iostream>
#endif

template<typename T>
class Vector
{
private:
    int maxsize = 10;
    void updateSize(int newLength)
    {
        if (newLength <= this->length)
        {
            return;
        }
        this->maxsize = newLength;
        T * oldData = this->data;
        this->data = new T[this->maxsize];
        for (int i = 0; i < this->length; ++i) {
            this->data[i] = oldData[i];
        }
        delete oldData;
    }
public:
    T * data;
    int length = 0;
    Vector()
    {
        this->data = new T[this->maxsize];
    }
    Vector(T * data, int length)
    {
        this->length = length;
        this->maxsize = 2 * length;
        this->data = new T[this->maxsize];
        for (int i = 0; i < this->length; ++i)
        {
            this->data[i] = data[i];
        }
    }
    ~Vector()
    {
        delete [] this->data;
    }
    void push_back(T & input)
    {
        if (this->length == this->maxsize)
        {
            this->updateSize(2 * this->length);
        }
        this->data[length] = input;
        length++;
    }
    void pop_back()
    {
        length--;
        if (this->length < this->maxsize / 4)
        {
            this->updateSize(this->maxsize / 2);
        }
    }
    bool search(T & target)
    {
        for (int i = 0; i < this->length; ++i)
        {
            if (target == this->data[i])
            {
                return true;
            }
        }
        return false;
    }
    bool search(int target, T & result)
    {
        if (target < 1 || target > length + 1)
        {
            return true;
        }
    }
    void print()
    {
        using namespace std;
        for (int i = 0; i < this->length; ++i)
        {
            cout << this->data[i] << " ";
        }
        cout << endl;
    }
};