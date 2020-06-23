#include "array.h"
#include "stack.h"
#include "queue.h"


int main()
{

    std::ifstream fin("Text.txt"); //проверка открытия файла
    
    if (!fin)
    {
        std::cout << "Error open file!\n";
        return 0;
    }
    
    fin.close();
    
    while (true) //меню
    {
        std::cout << "Choose a class to test:\n"
        << "1. Class Stack\n"
        << "2. Class Queue\n"
        << "0. Exit\n"
        << "\nEnter number: ";
        int choise;
        std::cin >> choise;
    
        switch (choise)
        {
            case 1: //тест класса Stack
            {
                size_t size;
                std::cout << "\nEnter size stack: ";
                std::cin >> size;
                Array* array = new Stack(size);
                array->menu();
                break;
            }
            case 2: //тест класса Queue
            {
                size_t size;
                std::cout << "\nEnter size queue: ";
                std::cin >> size;
//                Array* array = new Queue(size);
//                array->menu();
                break;
            }
            default: //отсутсвующий выбор
            {
                std::cout << "Enter right number!\n";
            }
        }
    }
    
    system("pause");
    return 0;
}
