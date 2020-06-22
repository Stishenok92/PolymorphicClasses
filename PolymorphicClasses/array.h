#pragma once
#include <iostream>

class Array //абстрактный класс
{
protected:
    size_t size;
    int* array;
public:
    Array();
    Array(size_t);
    Array(const Array&);
    virtual ~Array();
    Array& operator=(const Array&);
    
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual void push(const int) = 0;
    virtual int pop() = 0;
    virtual void print() const = 0;
    virtual void menu() = 0;
};

Array:: Array(): size(10), array(new int[size] {0}) //конструктор без параметров
{
    
}

Array:: Array(size_t _size): size(_size), array(new int[size] {0}) //конструктор с параметром size_t
{
    
}

Array:: Array(const Array& temp) //конструктор с параметром Array
{
    size = temp.size;
    array = new int[size];
    memcpy(array, temp.array, (sizeof(array) * size));
}

Array:: ~Array() //деструктор
{
    delete [] array;
}

Array& Array:: operator=(const Array& temp) //метод копирования
{
    size = temp.size;
    delete [] array;
    array = new int[size];
    memcpy(array, temp.array, (sizeof(array) * size));
    return *this;
}
