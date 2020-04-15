#include <iostream>
#include "StackBasedOnArray.h"
using namespace std;

template <class T>
inline ArrayStack<T>::ArrayStack()
{
    this->count = 10;
    this->flag = 0;
    this->array = new T[this->count];
}

template <class T>
inline ArrayStack<T>::ArrayStack(int count)
{
    this->count = count;
    this->flag = 0;
    this->array = new T[this->count];
}

template <class T>
inline ArrayStack<T>::~ArrayStack()
{
    this->count = 0;
    this->flag = 0;

    if (this->array != NULL)
    {
        delete[] this->array;
        this->array = NULL;
    }
}

//入栈
template <class T>
inline void ArrayStack<T>::push(T data)
{
    if (this->flag == this->count)
    {
        cout << "The stack is full, so need to enlarge 1.5x!" << endl;
        this->count = int(1.5 * this->count);
        T *temp = new T[this->count];
        for (int i = 0; i < this->flag; i++)
        {
            temp[i] = this->array[i];
        }

        delete[] this->array;
        temp[this->flag] = data;
        this->flag++;
        this->array = temp;
    }
    else
    {
        this->array[this->flag] = data;
        this->flag++;
    }
}

//出栈
template <class T>
inline T ArrayStack<T>::pop()
{
    if (this->flag <= 0)
    {
        ;
    }
    this->flag--;
    T temp = this->array[this->flag];

    return temp;
}

template <class T>
inline T ArrayStack<T>::peek()
{
    if (this->flag <= 0)
    {
        ;
    }
    T temp = this->array[this->flag - 1];
    return temp;
}

template <class T>
inline int ArrayStack<T>::stackSize()
{
    return this->flag;
}

template <class T>
inline int ArrayStack<T>::stackMaxSize()
{
    return this->count;
}

int main(int argc, char *argv[])
{
    cout << "=== Test Begin ===" << endl;
    ArrayStack<int> stack(12);
    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "pop, delete:" << stack.pop() << endl;
    cout << "pop, delete:" << stack.pop() << endl;
    cout << "pop, delete:" << stack.pop() << endl;

    stack.push(11);
    stack.push(21);
    stack.push(31);
    cout << "pop, delete:" << stack.pop() << endl;
    cout << "pop, delete:" << stack.pop() << endl;
    cout << "pop, delete:" << stack.pop() << endl;
}
