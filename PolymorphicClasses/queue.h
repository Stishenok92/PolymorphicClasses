#pragma once

class Queue: public Array
{
protected:
    size_t head;
    size_t tail;
public:
    Queue();
    Queue(size_t);
    Queue(const Queue&);
    ~Queue();
    Queue& operator=(const Queue&);
    bool isEmpty() const override;
    bool isFull() const override;
    void push(const int) override;
    int pop() override;
    std::ostream& print(std::ostream&) const override;
    std::istream& read(std::istream&) override;
};

Queue:: Queue(): Array(), head(0), tail(0) {}

Queue:: Queue(size_t _size): Array(_size), head(0), tail(0) {}

Queue:: Queue(const Queue& temp)
{
    size = temp.size;
    array = new int[size];
    memcpy(array, temp.array, (sizeof(array) * size));
    head = temp.head;
    tail = temp.tail;
}

Queue:: ~Queue() {}

Queue& Queue:: operator=(const Queue& temp)
{
    size = temp.size;
    delete [] array;
    array = new int[size];
    memcpy(array, temp.array, (sizeof(array) * size));
    head = temp.head;
    tail = temp.tail;
    return *this;
}

bool Queue:: isEmpty() const
{
    if (head == tail)
    {
        std::cout << "Error! Queue is empty!\n";
        return true;
    }
    
    return false;
}

bool Queue:: isFull() const
{
    if (tail == size) //ddfververvrvretbtergergg
    {
        std::cout << "Error! Queue is full!\n";
        return true;
    }
    
    return false;
}

void Queue:: push(const int key)
{
    if (!isFull())
    {
        array[tail++] = key;
    }
}

int Queue:: pop()
{
    if (!isEmpty())
    {
        int temp = array[head]; //запоминаем первый элемент очереди
        
        for (size_t i = 1; i < tail; i++) //копируем очередь без первого элемента в начало массива
        {
            array[i-1] = array[i];
        }
        
        --tail;
        return temp;
    }
    
    return 0;
}

std::ostream& Queue:: print(std::ostream& out) const
{
    if (!isEmpty())
    {
        out << "Queue has view:\n";
        
        for (size_t i = head; i < tail; i++)
        {
            out << array[i] << "\n";
        }
    }
    
    return out;
}

std::istream& Queue:: read(std::istream& in)
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
