#include <iostream>
#include <cassert>
#include <cstdlib>
#include <vector>
#include "Stack_lib_header.h"

int main()
{


        Stack<double> s1(10);
    	Stack<int> s2;
    	s2.push(5);
    	s2.push(1);
        s2.dump();
    	s2.push(2);
    	s2.push(2);
    	s2.push(2);
    	s2.push(2);
        s2.push(0);
    	s2.dump();
    	std::cout << s2.peek() << "\n";
    	std::cout << s2.peek() << "\n";
    	std::cout << s2.peek() << "\n";
    	s2.dump();
    	std::cout << s2.pop() << "\n";
    	std::cout << s2.pop() << "\n";
    	std::cout << s2.pop() << "\n";
    	std::cout << s2.pop() << "\n";
    	s2.dump();
    	std::cout << s2.peek() << "\n";
    	std::cout << s2.peek() << "\n";
    	s2.push(1);
    	s2.push(9);
    	s2.push(9);
    	s2.push(6);
    	s2.dump();


	return 0;
}
