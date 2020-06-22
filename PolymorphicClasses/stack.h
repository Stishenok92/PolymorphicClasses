#pragma once

class Stack: public Array
{
protected:
    size_t top;
public:
    Stack();
    Stack(size_t);
    Stack(const Stack&);
    ~Stack();
    Stack& operator=(const Stack&);
    
    bool isEmpty() const override;
    bool isFull() const override;
    void push(const int) override;
    int pop() override;
    void print() const override;
    void menu() override;
};

Stack:: Stack(): Array(), top(0)
{
    
}

Stack:: Stack(size_t _size): Array(_size), top(0)
{
    
}

Stack:: Stack(const Stack& temp)
{
    size = temp.size;
    array = new int[size];
    memcpy(array, temp.array, (sizeof(array) * size));
    top = temp.top;
}

Stack:: ~Stack()
{
    
}

Stack& Stack:: operator=(const Stack& temp)
{
    size = temp.size;
    delete [] array;
    array = new int[size];
    memcpy(array, temp.array, (sizeof(array) * size));
    top = temp.top;
    return *this;
}

bool Stack:: isEmpty() const
{
    if (top == 0)
    {
        std::cout << "Error! Stack is empty!\n";
        return true;
    }
    
    return false;
}

bool Stack:: isFull() const
{
    if (top == size)
    {
        std::cout << "Error! Stack is full!\n";
        return true;
    }
    
    return false;
}

void Stack:: push(const int key)
{
    if (!isFull())
    {
        array[top++] = key;
    }
}

int Stack:: pop()
{
    if (!isEmpty())
    {
        return array[--top];
    }
    
    return 0;
}

void Stack:: print() const
{
    if (!isEmpty())
    {
        std::cout << "Stack has view:\n";
        
        for (size_t i = 0; i < top; i++)
        {
            std::cout << array[i] << " ";
        }
        
        std::cout << "\n";
    }
}

void Stack:: menu()
{
    while (true)
    {
        std::cout << "\nОperations:\n"
        << "1. Print\n"
        << "2. Push\n"
        << "3. Pop\n"
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
                print();
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
