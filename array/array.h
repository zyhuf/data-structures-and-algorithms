// array.h
#pragma once
#include <iostream>
#include <cassert>

using namespace std;

//数组类模板定义
template <class T>
class Array
{
private:
    T *m_pArray; //存放动态分配的数组内存首地址
    int m_iSize; //数组大小

public:
    Array(int iSize = 50);      //构造函数
    Array(const Array<T> &arr); //拷贝构造
    ~Array();                   //析构函数

    //重载=
    Array<T> &operator=(const Array<T> &arr);

    //重载==
    bool operator==(const Array<T> &arr);

    //重载!=
    bool operator!=(const Array<T> &arr);

    //重载[]
    T &operator[](int iIndex);

    //获取数组大小
    int getArrSize();

    //修改数组大小
    void resetArrSize(int iSize);

    //打印数据
    void print();
};

template <class T>
inline Array<T>::Array(int iSize)
{
    assert(iSize >= 0);
    m_iSize = iSize;
    m_pArray = new T[iSize];
}

template <class T>
inline Array<T>::Array(const Array<T> &arr)
{
    m_iSize = arr.m_iSize;
    m_pArray = new T[m_iSize];
    if (NULL == m_pArray)
    {
        cout << "new memery fail" << endl;
        this->exit(-1);
    }

    for (int i = 0; i < m_iSize; i++)
    {
        m_pArray[i] = arr.m_pArray[i];
    }
}

template <class T>
inline Array<T>::~Array()
{
    delete[] m_pArray;
    m_pArray = NULL;
}

template <class T>
inline Array<T> &Array<T>::operator=(const Array<T> &arr)
{
    if (this != &arr)
    {
        if (this->m_iSize != arr.m_iSize)
        {
            delete[] this->m_pArray;
            this->m_pArray = NULL;
            this->m_iSize = arr.m_iSize;
            this->m_pArray = new T[this->m_iSize];
        }

        for (int i = 0; i < this->m_iSize; i++)
        {
            this->m_pArray[i] = arr.m_pArray[i];
        }
    }

    return *this;
}

template <class T>
inline bool Array<T>::operator==(const Array<T> &arr)
{
    if (this->m_iSize != arr.m_iSize)
    {
        return false;
    }

    //判断内容是否相同
    for (int i = 0; i < this->m_iSize; i++)
    {
        if (this->m_pArray[i] != arr.m_pArray[i])
        {
            return false;
        }
    }

    return true;
}

template <class T>
inline bool Array<T>::operator!=(const Array<T> &arr)
{
    return !(*this == arr);
}

template <class T>
inline T &Array<T>::operator[](int iIndex)
{
    assert(iIndex >= 0 && iIndex < m_iSize);
    return m_pArray[iIndex];
}

template <class T>
inline int Array<T>::getArrSize()
{
    return m_iSize;
}

template <class T>
inline void Array<T>::resetArrSize(int iSize)
{
    if (m_iSize == iSize)
    {
        return;
    }

    T *pArray = new T[iSize];
    if (NULL == pArray)
    {
        cout << "aollc memory fail" << endl;
        this->exit(1);
    }

    int n = iSize > m_iSize ? m_iSize : iSize;
    for (int i = 0; i < n; i++)
    {
        pArray[i] = m_pArray[i];
    }
    delete[] m_pArray;
    m_pArray = pArray;
    m_iSize = iSize;

    return;
}

template <class T>
inline void Array<T>::print()
{
    cout << "size:" << m_iSize << endl;
    for (int i = 0; i < m_iSize; i++)
    {
        cout << "data:" << m_pArray[i] << endl;
    }
}