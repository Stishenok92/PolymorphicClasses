#include "array.h"
#include "stack.h"
#include "queue.h"


int main()
{
    std::cout << "Choose a class to test:\n"
    << "1. Class Stack\n"
    << "2. Class Queue\n"
    << "0. Exit\n"
    << "\nEnter number: ";
    int choise;
    std::cin >> choise;
    
    
    
    
    
    
    size_t size;
    std::cout << "\nEnter size of array: ";
    std::cin >> size;
    Array* array = new Stack(size);
    array->push(10);
    array->push(20);
    array->push(30);
    array->print();
    array->menu();
    return 0;
}
