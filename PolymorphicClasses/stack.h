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
    std::ostream& print(std::ostream&) const override;
    std::istream& read(std::istream&) override;
};

Stack:: Stack(): Array(), top(0) {}

Stack:: Stack(size_t _size): Array(_size), top(0) {}

Stack:: Stack(const Stack& temp)
{
    size = temp.size;
    array = new int[size];
    memcpy(array, temp.array, (sizeof(array) * size));
    top = temp.top;
}

Stack:: ~Stack() {}

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

std::ostream& Stack:: print(std::ostream& out) const
{
    if (!isEmpty())
    {
        out << "Stack has view:\n";

        for (int i = static_cast<int>(top) - 1; i >= 0; i--)
        {
            out << array[i] << "\n";
        }
    }
    
    return out;
}

std::istream& Stack:: read(std::istream& in)
{
    int temp;
    
    while (!in.eof())
    {
        if (!isFull())
        {
            in >> temp;
            push(temp);
        }
        else
        {
            return in;
        }
    }
    
    return in;
}
