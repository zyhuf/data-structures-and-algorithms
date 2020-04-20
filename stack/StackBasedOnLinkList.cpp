#include <iostream>
#include <string>
#include "StackBasedOnLinkList.h"
using namespace std;

template <class T>
inline LinkedListStack<T>::LinkedListStack()
{
    this->count = 0;
    this->head = new LinkedNode;
    this->head->next = NULL;
}

template <class T>
inline LinkedListStack<T>::~LinkedListStack()
{
    LinkedNode *p, *q;
    p = this->head;
    while (p->next != NULL)
    {
        q = p->next;
        p->next = q->next;
        delete q;
    }

    delete this->head;
    this->head = NULL;
    this->count = 0;
}

//入栈
template <class T>
inline void LinkedListStack<T>::push(const T &data)
{
    LinkedNode *insertNode = new LinkedNode;
    insertNode->data = data;
    insertNode->next = this->head->next;
    this->head->next = insertNode;
    this->count++;
    cout << "push data: " << this->head->next->data << endl;
}

template <class T>
inline T LinkedListStack<T>::peek()
{
    if (this->count == 0 || this->head == NULL)
    {
        return NULL;
    }
    else
    {
        return this->head->next->data;
    }
}

template <class T>
inline T LinkedListStack<T>::pop()
{
    if (this->count == 0 || this->head == NULL)
    {
        return NULL;
    }
    else
    {
        LinkedNode *tmp = this->head->next;
        this->head->next = tmp->next;
        T data = tmp->data;
        delete tmp;
        this->count--;
        return data;
    }
}

template <class T>
inline int LinkedListStack<T>::size() const
{
    return this->count;
}

int main(int argc, char const *argv[])
{
    cout << "=== StackBasedOnLinkList test begin ===" << endl;
    LinkedListStack<string> stack;
    stack.push("abc");
    stack.push("def");
    stack.push("ghi");

    cout << "stack pop" << stack.pop() << endl;
    cout << "stack pop" << stack.pop() << endl;
    cout << "stack pop" << stack.pop() << endl;
}