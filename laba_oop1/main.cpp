#include "Mystring.hpp"
#include <string>

int main()
{
    MyString a1("short");
    int cap1 = a1.capacity();
    std::cout << cap1 << std::endl;
    a1 = "loooooooooooooong";
    a1.insert(0, "__");
    std::cout << a1 << " " << a1.size() << " " << a1.capacity();
    return 0;
}