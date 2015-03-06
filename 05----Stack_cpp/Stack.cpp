#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cstring>

typedef double stack_t;

class Stack
{
    public:
        Stack();
        Stack(int size);
        ~Stack();

        void dump() const;

        bool push(stack_t val);
        stack_t pop();
        stack_t peek() const;


    private:
        bool StOk() const;
        void StAssert() const;
        bool StCheck() const;

        stack_t* data;
        int count;
        int max;

};


Stack::Stack():
    data((stack_t*)calloc(10, sizeof(stack_t))),
    count(0),
    max(10)
    {
        //std::cout << "Created stack " << max << " elements" << std::endl;
        StCheck();
    }

Stack::Stack(int size):
    data((stack_t*)calloc(size, sizeof(stack_t))),
    count(0),
    max(size)
    {
        //std::cout << "Created stack " << max << " elements" << std::endl;
    }

Stack::~Stack()
{
    if(StOk())
    {
        //std::cout << "Deleted stack " << max << " elements" << std::endl;
        free(data);
        data = NULL;
        count = -1;
        max = -1;
    }
    else
        std::cout << "Invalid stack. Did not delete" << std::endl;
}












void Stack::dump() const
{
    std::cout << "\n\n";
    std::cout << "\tStack dump" << std::endl;
    std::cout << "\tData: " << data <<std:: endl;

    std::cout << "\tCount: ";
    if(StOk())
         std::cout << count <<std:: endl;
    else
        std::cout << "?" <<std:: endl;

    std::cout << "\tMax: ";
    if(StOk())
         std::cout << max <<std:: endl;
    else
        std::cout << "?" <<std:: endl;
    std::cout << "\n\n";

    if(StOk())
        for(int i = 0; i < max; i++)
        {
            std::cout <<"\t[" << i << "]" << " = " << data[i] << " ";
            if(i < count)
                std::cout << "*\n";
            else
                std::cout << "\n";
        }
    std::cout << "\n\n";
}




bool Stack::StOk() const
{
    if(this && this -> data && max > 0)
        return 1;
    else
        return 0;
}

void Stack::StAssert() const
{
    dump();
    assert(StOk());
}

bool Stack::StCheck() const
{
    if(StOk())
        return 1;
    else
        StAssert();
    return 0;
}







bool Stack::push(stack_t val)
{
    StCheck();
    if(count == max)
    {
        data = (stack_t*)realloc(data, sizeof(stack_t) * (max + 4));
        max += 4;
    }


    data[count++] = val;

    StCheck();
    return 1;
}

stack_t Stack::pop()
{
    StCheck();
    if(count == 0)
    {
        std::cout << "\nStack is empty!\n Returned NULL\n";
        return NULL;
    }
    return data[--count];
}

stack_t Stack::peek() const
{
    StCheck();
    if(count == 0)
    {
        std::cout << "\nStack is empty!\n Returned NULL\n";
        return NULL;
    }
    return data[count - 1];
}



int main()
{
    Stack s1(2);
    Stack s2;
    s1.push(5);
    s1.push(1);
    //s1.push(2);
    //s1.push(2);
    //s1.push(2);
    //s1.push(2);
    //s1.push(0);
    std::cout << s1.peek() << "\n";
    std::cout << s1.peek() << "\n";
    std::cout << s1.peek() << "\n";
    std::cout << s1.pop() << "\n";
    std::cout << s1.pop() << "\n";
    std::cout << s1.pop() << "\n";
    std::cout << s1.pop() << "\n";
    std::cout << s1.peek() << "\n";
    std::cout << s1.peek() << "\n";
    //s1.data = 0;
    s1.dump();
    //s1.StAssert();

    return 0;
}
