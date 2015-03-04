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
        bool push(stack_t val);
        stack_t pop();
        bool dump() const;


    private:
        stack_t* data;
        int count;
        int max;

};


Stack::Stack():
    data((stack_t*)calloc(10, sizeof(stack_t))),
    count(0),
    max(10)
    {
        std::cout << "Created stack " << max << " elements" << std::endl;
    }





Stack::Stack(int size):
    data((stack_t*)calloc(size, sizeof(stack_t))),
    count(0),
    max(size)
    {
        std::cout << "Created stack " << max << " elements" << std::endl;
    }


Stack::~Stack()
{
    std::cout << "Deleted stack " << max << " elements" << std::endl;
    free(data);
    data = NULL;
    count = -1;
    max = -1;
}


bool Stack::push(stack_t val)
{
    //!!!
    if(count == (max - 1))
    {
        data = (stack_t*)realloc(data, sizeof(stack_t) * (max + 5));
    }


    data[count++] = val;
    return 1;
}


stack_t Stack::pop()
{

    return data[--count];
}


int main()
{
    Stack s1(5);
    Stack s2;
    s1.push(5);
    s1.push(5);
    s1.push(5);
    s1.push(5);
    s1.push(5);
    s1.push(1);
    s1.push(2);


    return 0;
}
