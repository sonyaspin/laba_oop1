#include "Mystring.hpp"


////////////////////////////////////////////////////////////////////////////////////

MyString::MyString()
{
    str_ = nullptr;
    capacity_ = 0;
}
MyString::MyString(char* str) :MyString(str, strlen(str))
{

}
MyString::MyString(string str) :MyString((char*)str.c_str())
{

}
MyString::MyString(const initializer_list<char> char_list) :MyString(string(char_list))
{

}
MyString::MyString(char* str, const int count)
{
    this->str_ = new char[count + 1];

    capacity_ = count + 1;

    for (int i = 0; i < count; i++)
    {
        this->str_[i] = str[i];
    }

    this->str_[count] = '\0';
}
MyString::MyString(const int count, const char str) :MyString(string(count, str))
{

}
MyString::~MyString()
{
    delete[] this->str_;
}
MyString::MyString(const MyString& other)
{
    int length = strlen(other.str_);
    this->str_ = new char[length + 1];

    for (int i = 0; i < length; i++)
    {
        this->str_[i] = other.str_[i];
    }

    this->str_[length] = '\0';
    this->capacity_ = length + 1;
}


/////////////////////////////////////////////////////////////////////////////////////

