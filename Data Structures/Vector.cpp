#include <cassert>
#include <iostream>
using namespace std;

template <typename T>
class Vector {
private:
    int size;
    int cap;
    T* ptr;

public:
    Vector() : size(0), cap(0), ptr(nullptr) {}

    Vector(int n) : size(n), cap(n) {
        ptr = new T[n];
    }

    Vector(int n, const T& value) : size(n), cap(n) {
        ptr = new T[n];
        for (int i = 0; i < n; ++i) {
            ptr[i] = value;
        }
    }

    // Copy constructor
    Vector(const Vector& other) : size(other.size), cap(other.cap) {
        ptr = new T[cap];
        for (int i = 0; i < size; ++i) {
            ptr[i] = other.ptr[i];
        }
    }

    // Copy assignment
    Vector& operator=(const Vector& other) {
        if (this == &other) return *this;

        T* new_ptr = new T[other.cap];
        for (int i = 0; i < other.size; ++i) {
            new_ptr[i] = other.ptr[i];
        }

        delete[] ptr;
        ptr = new_ptr;
        size = other.size;
        cap = other.cap;

        return *this;
    }

    ~Vector() {
        delete[] ptr;
    }

    int get_size() const {
        return size;
    }

    void push_back(const T& value) {
        if (size == cap) {
            int new_cap = (cap == 0) ? 1 : cap * 2;
            T* new_ptr = new T[new_cap];

            for (int i = 0; i < size; ++i) {
                new_ptr[i] = ptr[i];
            }

            delete[] ptr;
            ptr = new_ptr;
            cap = new_cap;
        }

        ptr[size++] = value;
    }

    void pop_back() {
        assert(size > 0);
        --size;
    }

    T& operator[](int index) {
        assert(index >= 0 && index < size);
        return ptr[index];
    }

};

int main() {
    Vector<int> v(5, 2);
    Vector<int> copy = v;

    v.push_back(10);
    v[0] = 99;

cout << copy[0] << "\n"; // 2
cout << v[0] << "\n";    // 99
}