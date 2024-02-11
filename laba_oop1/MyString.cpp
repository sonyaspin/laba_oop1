#include "Mystring.hpp"

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
}
MyString& MyString::operator=(const char* other)
{
    if (this->str_ != nullptr)
    {
        this->str_ = nullptr;
    }

    int length = strlen(other);
    if (capacity_ < length + 1)
        capacity_ = length + 1;
    this->str_ = new char[capacity_];

    for (int i = 0; i < length; i++)
    {
        this->str_[i] = other[i];
    }

    this->str_[length] = '\0';

    return *this;
}
MyString& MyString::operator=(const MyString& other)
{
    return operator=(other.str_);
}
MyString& MyString::operator=(string str)
{
    return operator=((char*)str.c_str());
}
MyString& MyString::operator=(const char str)
{
    return operator=(string(1, str));
}
MyString MyString::operator+(const MyString& other)
{
    return operator+(other.str_);
}
MyString MyString::operator+(const char* other)
{
    MyString newStr;

    int thisLength = strlen(this->str_);
    int otherLength = strlen(other);
    newStr.str_ = new char[thisLength + otherLength + 1];

    int i = 0;
    for (; i < thisLength; i++) {
        newStr.str_[i] = this->str_[i];
    }
    for (int j = 0; j < otherLength; j++, i++) {
        newStr.str_[i] = other[j];
    }

    newStr.str_[thisLength + otherLength] = '\0';

    return newStr;
}
MyString MyString::operator+(string str)
{
    return operator+((char*)str.c_str());
}
MyString& MyString::operator+=(const MyString& other)
{
    return this->append(other.str_);
}
MyString& MyString::operator+=(const char* other)
{
    return this->append(other);
}
MyString& MyString::operator+=(string str)
{
    return this->append(str);
}
bool MyString::operator>(const MyString& other)
{
    return !operator<=(other);
}
bool MyString::operator<(const MyString& other)
{
    return !operator>=(other);
}
bool MyString::operator>=(const MyString& other)
{
    for (int i = 0; i < strlen(other.str_); ++i)
        if (this->str_[i] < other.str_[i])
            return false;
    return true;
}
bool MyString::operator<=(const MyString& other)
{
    for (int i = 0; i < strlen(other.str_); ++i)
        if (this->str_[i] > other.str_[i])
            return false;
    return true;
}
bool MyString::operator!=(const MyString& other)
{
    for (int i = 0; i < strlen(other.str_); ++i)
        if (this->str_[i] != other.str_[i])
            return true;
    return false;
}
bool MyString::operator==(const MyString& other)
{
    for (int i = 0; i < strlen(other.str_); ++i)
        if (this->str_[i] != other.str_[i])
            return false;
    return true;
}
const int MyString::size()
{
    if (this->str_ == nullptr)
        return 0;
    return strlen(this->str_);
}
const int MyString::length()
{
    return size();
}
const int MyString::capacity()
{
    if (this->str_ == nullptr)
        return 0;
    return capacity_;
}
const int MyString::empty()
{
    if (strlen(this->str_) == 0)
        return 1;
    else
        return 0;
}
char& MyString::operator[](int index)
{
    return this->str_[index];
}
char* MyString::c_str()
{
    return this->str_;
}
char* MyString::data()
{
    return this->str_;
}
void MyString::clear()
{
    this->str_ = nullptr;
}
void MyString::erase(int index, const int count)
{
    int max = strlen(this->str_) + 1;

    for (int i = index + count; i < max - 1; ++i)
    {
        if (i + 1 != max)
            this->str_[i - count] = this->str_[i];
    }
    this->str_[strlen(this->str_) - count] = NULL;
}
void MyString::shrink_to_fit()
{
    if (capacity_ > strlen(this->str_) + 1)
    {
        char* newStr = new char[strlen(this->str_) + 1];

        for (int i = 0; i < strlen(this->str_); ++i)
            newStr[i] = this->str_[i];

        this->str_ = nullptr;
        this->str_ = newStr;
        capacity_ = strlen(this->str_) + 1;
    }
}
MyString& MyString::insert(int index, int count, const char str)
{
    return this->insert(index, string(count, str));
}
MyString& MyString::insert(int index, char* str)
{
    return this->insert(index, str, strlen(str));
}
MyString& MyString::insert(int index, char* str, int count)
{
    char* newStr = new char[size() + count + 1];
    for (int i = 0; i < index; ++i)
        newStr[i] = this->str_[i];
    int i = 0;
    for (int j = index; j < index + count; ++j)
    {
        newStr[j] = str[i];
        ++i;
    }
    for (int z = index + count; z < size() + count; ++z)
        newStr[z] = this->str_[z - count];

    delete[] this->str_;
    if (this->capacity_ < strlen(newStr) + 1)
    {
        this->str_ = new char[strlen(newStr) + 1];
        this->capacity_ = strlen(newStr) + 1;
    }
    this->str_ = newStr;
    this->str_[strlen(newStr)] = '\0';

    return *this;
}
MyString& MyString::insert(int index, string str)
{
    return this->insert(index, (char*)str.c_str());
}
MyString& MyString::insert(int index, string str, int count)
{
    return this->insert(index, (char*)str.c_str(), count);
}
MyString& MyString::append(int count, const char str)
{
    return this->insert(size(), count, str);
}
MyString& MyString::append(char* str)
{
    return this->insert(size(), str);
}
MyString& MyString::append(char* str, int index, int count)
{
    char* newStr = new char[size() + count + 1];

    for (int i = 0; i < index; ++i)
        newStr[i] = this->str_[i];
    int i = index;
    for (int j = index; j < index + count; ++j)
    {
        newStr[j] = str[i];
        ++i;
    }

    delete[] this->str_;
    if (this->capacity_ < strlen(newStr) + 1)
    {
        this->str_ = new char[strlen(newStr) + 1];
        this->capacity_ = strlen(newStr) + 1;
    }
    this->str_ = newStr;
    this->str_[strlen(newStr)] = '\0';

    return *this;
}
MyString& MyString::append(string str)
{
    return this->append((char*)str.c_str());
}
MyString& MyString::append(string str, int index, int count)
{
    return this->append((char*)str.c_str(), index, count);
}
MyString& MyString::replace(int index, int count, char* str)
{
    erase(index, count);
    insert(index, str);
    return *this;
}
MyString& MyString::replace(int index, int count, string str)
{
    replace(index, count, (char*)str.c_str());
    return *this;
}
MyString MyString::substr(int index)
{
    MyString newStr(str_);
    newStr.erase(0, index);
    return newStr;
}
MyString MyString::substr(int index, int count)
{
    MyString newStr(str_);
    newStr.erase(0, index);
    newStr.erase(count, newStr.size() - count);
    return newStr;
}
const int MyString::find(char* str)
{
    int length = strlen(str);

    for (int i = 0; i < strlen(this->str_) - length + 1; ++i)
    {
        MyString newStr(this->substr(i, length));
        if (newStr == str)
            return i;
    }
    return -1;
}
const int MyString::find(char* str, int index)
{
    int length = strlen(str);

    for (int i = index; i < strlen(this->str_) - length + 1; ++i)
    {
        MyString newStr(this->substr(i, length));
        if (newStr == str)
            return i;
    }
    return -1;
}
const int MyString::find(string str)
{
    return find((char*)str.c_str());
}
const int MyString::find(string str, int index)
{
    return find((char*)str.c_str(), index);
}
ostream& operator<<(ostream& stream, const MyString& other)
{
    if (other.str_ == nullptr)
        stream << "";
    else
        stream << other.str_;
    return stream;
}
istream& operator>>(istream& stream, MyString& other)
{
    string in_str;
    stream >> in_str;

    int length = strlen((char*)in_str.c_str());

    if (other.capacity_ < length + 1)
        other.capacity_ = length + 1;
    other.str_ = new char[other.capacity_];
    for (int i = 0; i < length; ++i)
    {
        other.str_[i] = in_str[i];
    }
    other.str_[length] = '\0';
    return stream;
}