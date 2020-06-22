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
    friend std::ostream& operator<<(std::ostream&, const Stack&);
    friend std::istream& operator>>(std::istream&, Stack&);
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

std::ostream& operator<<(std::ostream& out, const Stack& stack)
{
    if (!stack.isEmpty())
    {
        out << "Stack has view:\n";
        
        for (int i = static_cast<int>(stack.top) - 1; i >= 0; i--)
        {
            out << stack.array[i] << "\n";
        }
    }
    
    return out;
}

std::istream& operator>>(std::istream& in, Stack& stack)
{
    int temp;
    
    while (!in.eof())
    {
        if (!stack.isFull())
        {
            in >> temp;
            stack.push(temp);
        }
        else
        {
            return in;
        }
    }
    
    return in;
}

void Stack:: print() const
{
    std::cout << *this;
}

void Stack:: menu()
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
                std::ifstream fin("Text.txt");
                fin >> *this;
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
