#include <iostream>
#include <queue>
#include <cassert>
using namespace std;

template <typename T>
class Stack {
private:
    queue<T> data;

public:
    Stack() = default;

    // Copy constructor
    Stack(const Stack<T>& other) : data(other.data) {}

    // Copy assignment (rule of 3)
    Stack& operator=(const Stack<T>& other) {
        if (this == &other) return *this;
        data = other.data;
        return *this;
    }

    void push(const T& value) {
        data.push(value);   // back = new top
    }

    void pop() {
        assert(!data.empty());

        queue<T> temp;
        // move everything except the last element
        while (data.size() > 1) {
            temp.push(data.front());
            data.pop();
        }

        // remove the last element (stack top)
        data.pop();

        data = std::move(temp);
    }

    T top() const {
        assert(!data.empty());
        return data.back();
    }

    bool empty() const {
        return data.empty();
    }

    size_t size() const {
        return data.size();
    }
};

int main() {
    Stack<int> st;
    st.push(3);
    st.push(4);
    cout << st.top() << "\n";   // 4
    st.push(5);
    cout << st.top() << "\n";   // 5
    cout << "size -> " << st.size() << "\n"; // 3

    Stack<int> st2 = st;
    st2.pop();
    cout << st2.top() << " " << st2.size() << "\n"; // 4 2

    Stack<int> st3;
    st3 = st2;
    cout << st3.empty() << "\n"; // 0
    st3.pop();
    st3.pop();
    cout << st3.empty() << "\n"; // 1
}