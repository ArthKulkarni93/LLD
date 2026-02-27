#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

class String
{
private:
    char *ptr;
    int cap;

public:
    int size;

    // Default constructor
    String() : ptr(new char[1]), cap(0), size(0)
    {
        ptr[0] = '\0';
    }

    String(const char arr[])
    {
        size = 0;

        // count characters until null terminator
        while (arr[size] != '\0')
        {
            size++;
        }

        cap = size;
        ptr = new char[cap + 1];

        // copy characters
        for (int i = 0; i < size; i++)
        {
            ptr[i] = arr[i];
        }

        ptr[size] = '\0';
    }

    // Copy constructor
    String(const String &other)
    {
        size = other.size;
        cap = other.cap;
        ptr = new char[cap + 1];

        for (int i = 0; i < size; i++)
            ptr[i] = other.ptr[i];

        ptr[size] = '\0';
    }

    // Copy assignment operator
    String &operator=(const String &other)
    {
        if (this == &other)
            return *this;

        delete[] ptr;

        size = other.size;
        cap = other.cap;
        ptr = new char[cap + 1];

        for (int i = 0; i < size; i++)
            ptr[i] = other.ptr[i];

        ptr[size] = '\0';

        return *this;
    }

    // Destructor
    ~String()
    {
        delete[] ptr;
    }

    int get_size() const;
    void push_back(const char &c);
    void pop_back();
    char &operator[](int i);
    const char &operator[](int i) const;
};

int String:: get_size() const
{
    return size;
}

void String:: push_back(const char &c)
{
    if (size == cap)
    {
        int new_cap = (cap == 0) ? 1 : cap * 2;
        char *new_ptr = new char[new_cap + 1];

        for (int i = 0; i < size; i++)
            new_ptr[i] = ptr[i];

        delete[] ptr;
        ptr = new_ptr;
        cap = new_cap;
    }

    ptr[size] = c;
    size++;
    ptr[size] = '\0';
}

void String:: pop_back()
{
    assert(size > 0);
    size--;
    ptr[size] = '\0';
}

char& String:: operator[](int i)
{
    assert(i >= 0 && i < size);
    return ptr[i];
}

const char& String::operator[](int i) const
{
    assert(i >= 0 && i < size);
    return ptr[i];
}

int main()
{
    String a;
    a.push_back('a');
    cout << a[0] << endl;

    String b("hello");
    cout << b[1] << endl;

    String c = b;
    cout << c[2] << endl;
}