#include <iostream>
using std::cout, std::endl;

template <typename T>
class Node {
public:
    T info;
    Node<T>* next;

    Node(T info_, Node<T>* next_ = nullptr ) : next(next_), info(info_) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    LinkedList() {
        head = tail = nullptr;
    }

    ~LinkedList() {
        Node<T>* p;
        while(!is_empty()) {
            p = head->next;
            delete head;
            head = p;
        }
    }

    bool is_empty() {
        return (head == nullptr);
    }

    void add_head(T info) {
        if (is_empty()) {
            head = tail = new Node<T>(info);
            return;
        }
        head = new Node<T>(info, head);
    }

    void remove_head() {
        if (is_empty()) {
            return;
        }
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }

        Node<T>* p = head->next;
        delete head;
        head = p;
    }

    void add_tail(T info) {
        if (is_empty()) {
            head = tail = new Node<T>(info);
            return;
        }

        tail->next = new Node<T>(info);
        tail = tail->next;
    }

    void remove_tail() {
        if (is_empty()) {
            return;
        }
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }
        Node<T>* p;
        for (p = head; p->next->next != nullptr; p = p->next);
        delete tail;
        p->next = nullptr;
        tail = p;
    }

    void remove(int index) {
        if (index < 0) {
            return;
        }
        if (is_empty()) {
            return;
        }
        if (head == tail) {
            if (index == 0) {
                delete head;
                head = tail = nullptr;
            }
            return;
        }
        Node<T>* current = head;
        Node<T>* previous = nullptr;
        int i = 0;

        while (current != nullptr && i != index) {
            previous = current;
            current = current->next;
            i++;
        }

        if (current == nullptr) {
            return;
        }
        previous->next = current->next;
        if (current == tail) {
            tail = previous;
        }
        delete current;
    }

    void add(int index) {
        
    }

    void print() {
        for (Node<T>* p = head; p != nullptr; p = p->next) {
            cout << p->info << " ";
        }
        cout << endl;
    }
};

int main() {
    LinkedList<int> l1;
    l1.add_head(2); // 0 current = head;
    l1.add_head(3); // 
    l1.print();
    l1.remove(1);
    l1.print();
    l1.remove(0);
    l1.print();
    return 0;
}