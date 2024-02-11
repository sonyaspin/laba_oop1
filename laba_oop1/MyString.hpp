#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include <iostream>
#include <cstring>

using namespace std;

//#define MAX_STR_SIZE 1000

class MyString
{
private:
    char* str_;
    unsigned int capacity_;

public:
    MyString();
    MyString(char* str);
    MyString(const initializer_list<char> char_list);
    MyString(string str);
    MyString(char* str, const int count);
    MyString(const int count, const char str);
    MyString(const MyString& other);
    ~MyString();
    MyString operator+(const MyString& other);
    MyString operator+(const char* other);
    MyString operator+(string str);
    MyString& operator+=(const MyString& other);
    MyString& operator+=(const char* other);
    MyString& operator+=(string str);
    MyString& operator=(const char* other);
    MyString& operator=(string str);
    MyString& operator=(const char str);
    MyString& operator=(const MyString& other);
    char& operator[](int index);
    bool operator>(const MyString& other);
    bool operator<(const MyString& other);
    bool operator>=(const MyString& other);
    bool operator<=(const MyString& other);
    bool operator!=(const MyString& other);
    bool operator==(const MyString& other);
    char* c_str();
    char* data();
    const int length();
    const int size();
    const int empty();
    const int capacity();
    void shrink_to_fit();
    void clear();
    friend ostream& operator<<(ostream& stream, const MyString& other);
    friend istream& operator>>(istream& stream, MyString& other);
    MyString& insert(int index, int count, const char str);
    MyString& insert(int index, char* str);
    MyString& insert(int index, char* str, int count);
    MyString& insert(int index, string str);
    MyString& insert(int index, string str, int count);
    void erase(int index, const int count);
    MyString& append(int count, const char str);
    MyString& append(char* str);
    MyString& append(char* str, int index, int count);
    MyString& append(string str);
    MyString& append(string str, int index, int count);
    MyString& replace(int index, int count, char* str);
    MyString& replace(int index, int count, string str);
    MyString substr(int index);
    MyString substr(int index, int count);
    const int find(char* str);
    const int find(char* str, int index);
    const int find(string str);
    const int find(string str, int index);
};

#endif
