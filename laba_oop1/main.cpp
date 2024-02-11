#include "MyString.hpp"
#include <string>

int main()
{
    MyString a1;

    std::cout << a1 << " " << a1.size() << " " <<a1.capacity();
    
    MyString a2("Hello world!");
    std::cout << a2 << " " << a2.size() << " " << a2.capacity() << std::endl;
    MyString a3({ 'h','e','l','l','o' });
    std::cout << a3 << " " << a3.size() << " " << a3.capacity() << std::endl;
    std::string s = "hello";
    MyString a4(s);
    std::cout << a4 << " " << a4.size() << " " << a4.capacity() << std::endl;
    //MyString a5("hello", 4);
   // std::cout << a5 << " " << a5.size() << " " << a5.capacity() << std::endl;
    MyString a6(5, '!');
    std::cout << a6 << " " << a6.size() << " " << a6.capacity() << std::endl;
    MyString a7("hello");
    MyString a8(a7);
    std::cout << a8 << " " << a8.size() << " " << a8.capacity() << std::endl;

}