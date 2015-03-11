#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <vector>


template < typename stack_t >
class Stack
{
    public:
        Stack();
        Stack(int size);
        ~Stack();

        void dump() const;
        bool isEmpty() const;
        bool push(stack_t val);
        stack_t pop();
        stack_t peek() const;


    //private:
        bool Ok() const;
        void Assert() const;
        bool Check() const;

        //stack_t* data;
        std::vector<stack_t> data;
        int count;
        //int max;

};

template < typename stack_t >
Stack <stack_t>::Stack():
    count(0),
    data(10)
    {
        Check();
    }

template < typename stack_t >
Stack<stack_t>::Stack(int size):

    data(size),
    count(0)
    {
        data.reserve(size);
        Check();
    }

template < typename stack_t >
Stack<stack_t>::~Stack()
{
    if(Ok())
    {
        count = -1;
        data.clear();
    }
    else
        std::cout << "Invalid stack. Did not delete" << std::endl;
}


template < typename stack_t >
bool Stack<stack_t>::isEmpty() const
{
    if(!count)
        return true;
    return false;
}

template < typename stack_t >
bool Stack<stack_t>::Ok() const
{
    if(count >= 0 && data.max_size() >= count)
        return true;
    else
        return false;
}



template < typename stack_t >
void Stack<stack_t>::dump() const
{
    std::cout << "\n\n";
    std::cout << "\tStack dump" << std::endl;
    std::cout << "\tCount: ";
    if(Ok())
         std::cout << count <<std:: endl;
    else
        std::cout << "?" <<std:: endl;
    std::cout << "\n";

    if(Ok())
        for(int i = 0; i < /*count*/ data.size(); i++)
        {
            std::cout <<"\t[" << i << "]" << " = " << data[i] << "\n";
        }
    std::cout << "\n\n";
}




template < typename stack_t >
void Stack<stack_t>::Assert() const
{
    dump();
    assert(Ok());
}

template < typename stack_t >
bool Stack<stack_t>::Check() const
{
    if(Ok())
        return true;
    else
        Assert();
    return false;
}


template < typename stack_t >
bool Stack<stack_t>::push(stack_t val)
{
    Check();

    if(data.size() > count)
    {
        data[count] = val;
        count++;
    }
    else
    {
        data.insert(data.begin() + count, val);
        count++;
    }
    Check();
    return true;
}


template < typename stack_t >
stack_t Stack<stack_t>::pop()
{
    stack_t val = 0;
    Check();
    if(count == 0)
    {
        std::cout << "\nStack is empty!\n Returned NULL\n";
        return NULL;
    }
    data.erase(data.begin() + count - 1);
    val = data[--count];
    return val;
}

template < typename stack_t >
stack_t Stack<stack_t>::peek() const
{
    Check();
    if(count == 0)
    {
        std::cout << "\nStack is empty!\n Returned NULL\n";
        return (stack_t)NULL;
    }
    return data[count - 1];
}



int main()
{
    Stack<int> s1(10);
    Stack<int> s2;
    s1.push(5);
    s1.push(1);
    s1.dump();
    s1.push(2);
    s1.push(2);
    s1.push(2);
    s1.push(2);
    s1.push(0);
    s1.dump();
    std::cout << s1.peek() << "\n";
    std::cout << s1.peek() << "\n";
    std::cout << s1.peek() << "\n";
    s1.dump();
    std::cout << s1.pop() << "\n";
    std::cout << s1.pop() << "\n";
    std::cout << s1.pop() << "\n";
    std::cout << s1.pop() << "\n";
    s1.dump();
    std::cout << s1.peek() << "\n";
    std::cout << s1.peek() << "\n";
    s1.push(1);
    s1.push(9);
    s1.push(9);
    s1.push(6);
    s1.dump();

    return 0;
}
