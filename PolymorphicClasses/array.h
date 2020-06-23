#pragma once
#include <iostream>
#include <fstream>
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
    friend std::ostream& operator<<(std::ostream&, const Array*);
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual void push(const int) = 0;
    virtual int pop() = 0;
    virtual std::istream& read(std::istream&) = 0;
    virtual std::ostream& print(std::ostream&) const = 0;
    void menu();
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

std::ostream& operator<<(std::ostream& out, const Array* array)
{
    array->print(out);
    return out;
}

std::istream& operator>>(std::istream& in, Array* array)
{
    array->read(in);
    return in;
}

void Array:: menu()
{
    while (true)
    {
        std::cout << "\nОperations:\n"
        << "1. Print\n"
        << "2. Push\n"
        << "3. Push from file\n"
        << "4. Pop\n"
        << "0. Exit\n"
        << "\nEnter operation: ";
        size_t choise;
        std::cin >> choise;
        std::cout << "\n";

        switch (choise)
        {
            case 0:
            {
                return;
            }
            case 1:
            {
                std::cout << this;
                break;
            }
            case 2:
            {
                int num;
                std::cout << "Enter number: ";
                std::cin >> num;
                push(num);
                break;
            }
            case 3:
            {
                std::ifstream fin("Text.txt");
                fin >> this;
                fin.close();
                break;
            }
            case 4:
            {
                pop();
                break;
            }
            default:
            {
                std::cout << "No such operation\n";
            }
        }
    }
}
