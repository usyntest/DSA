#include <iostream>

template <typename T>
class Node {
public:
    T info;
    Node<T>* next;

    Node(T data, Node<T>* next_ = nullptr) {
        info = data;
        next = next_;
    }

};

class ArrayADT {
private:
    int size = 0;
    int length = 0;
    int *list;

public:
    ArrayADT(int length_) : size(length_) {
        list = new int[size];
        for (int i = 0; i < size; i++) {
            list[i] = 0;
        }
    }

    ~ArrayADT() {
        delete []list;
    }

    void display();
    void append(int el);
    void insert(int el, int index);
    int remove(int index);
    bool search(int el);
    int get(int index);
    void set(int index, int x);
    int max();
    int min();
    void reverse();
    int left_shift();
    int right_shift();
    void left_rotate();
    void right_rotate();
};


void ArrayADT::reverse() {
    int top = 0, last = length - 1;
    while (last > top) {
        int temp = list[top];
        list[top] = list[last];
        list[last] = temp;
        top++;
        last--;
    }
}

int ArrayADT::min() {
    int min = list[0];
    for (int i = 1; i < length; i++) {
        if (list[i] < min) {
            min = list[i];
        }
    }
    return min;
}

int ArrayADT::max() {
    int max = list[0];
    for (int i = 1; i < length; i++) {
        if (list[i] > max) {
            max = list[i];
        }
    }
    return max;
}

void ArrayADT::set(int index, int x) {
    if (index < 0 && index >= length) {
        return;
    }
    list[index] = x;
}

int ArrayADT::get(int index) {
    if (index < 0 && index >= length) {
        return -1;
    }
    return list[index];
}

bool ArrayADT::search(int el) {
    for (int i = 0; i < length; i++) {
        if (el == list[i]) {
            list[i] = list[0];
            list[0] = el;
            return true;
        }
    }
    return false;
}

void ArrayADT::display() {
    std::cout << "Length: " << length << '\n';
    std::cout << "Size: " << size << '\n';
    for (int i = 0; i < length; i++) {
        std::cout << list[i] << " ";
    }
    std::cout << "\n";
}

void ArrayADT::append(int el) {
    if (length < size) {
        list[length] = el;
        length++;
    }
    else {
        size = size * 2;
        int *p = new int[size];
        for (int i = 0; i < length; i++) {
            p[i] = list[i];
        }
        p[length] = el;
        list = p;
        length++;
    }
}

void ArrayADT::insert(int el, int index) {
    if (length == size) {
        size = size * 2;
        int *p = new int[size];
        for (int i = 0; i < length; i++) {
            p[i] = list[i];
        }
        list = p;
    }
    if (index < 0 && index > length) {
        return;
    }
    else if (index == length) {
        append(el);
    } else {
        for (int i = length; i > index; i--) {
            list[i] = list[i - 1];
        }
        list[index] = el;
        length++;
    }
}

int ArrayADT::remove(int index) {
    if (index < 0 && index >= length) {
        return -1;
    }
    for (int i = index; i < length - 1; i++) {
        list[i] = list[i+1];
    }
    length--;
}

int ArrayADT::left_shift() {
    int temp = list[0];
    for (int i = 0; i < length - 1; i++) {
        list[i] = list[i + 1];
    }
    list[length - 1] = 0;
    return temp;
}

int ArrayADT::right_shift() {
    int temp = list[length - 1];
    for (int i = length; i > 0; i--) {
        list[i] = list[i - 1];
    }
    list[0] = 0;
    return temp;
}

void ArrayADT::left_rotate() {
    int el = left_shift();
    list[length - 1] = el;
}

void ArrayADT::right_rotate() {
    int el = right_shift();
    list[0] = el;
}