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

    void remove_node(T info) {
        if (is_empty()) {
            return;
        }

        if (head == tail && head->info == info) {
            delete head;
            head = tail = nullptr;
            return;
        } 
        if (head->info == info) {
            Node<T>* p = head->next;
            delete head;
            head = p;
            return;
        }

        Node<T>* current = head;
        Node<T>* previous = nullptr;
        while (current != nullptr && current->info != info) {
            previous = current;
            current = current->next;
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

    bool search(T info) {
        for (Node<T>* p = head; p != nullptr; p = p->next) {
            if (p->info == info) {
                return true;
            }
        }
        return false;
    }

    int length() {
        int length = 0;
        for (Node<T>* p = head; p != nullptr; p = p->next) {
            length++;
        }
        return length;
    }

    void reverse() {
        if (is_empty()) {
            return;
        }

        Node<T> *current = nullptr, *next = head, *previous;

        while (next != nullptr) {
            previous = current;
            current = next;
            next = next->next;
            current->next = previous;
        }

        head = current;

        Node<T>* p;
        for (p = head; p->next != nullptr; p = p->next);
        tail = p;
    }

    void concat(LinkedList<T>& l1, LinkedList& l2) {
        Node<T>* p1 = l1.head;
        while (p1 != nullptr) {
            add_tail(p1->info);
            p1 = p1->next;
        }   

        Node<T>* p2 = l2.head;
        while (p2 != nullptr) {
            add_tail(p2->info);
            p2 = p2->next;
        }
    }

    LinkedList<T>& operator=(const LinkedList<T> &list) {
        Node<T>* p;

        while (!is_empty()) {
            p = head->next;
            delete head;
            head = p;
        }

        p = list.head;
        head = tail = nullptr;

        while(p != nullptr) {
            add_tail(p->info);
            p = p->next;
        }

        return *this;
    }

    LinkedList<T> operator+(const LinkedList<T> &list) {
        LinkedList<T> result;
        Node<T>* p = head;

        while (p != nullptr) {
            result.add_tail(p->info);
            p = p->next;
        }
        
        p = list.head;
        while (p != nullptr) {
            result.add_tail(p->info);
            p = p->next;
        }

        return result;
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
    l1.add_head(2);
    l1.add_head(3); 
    l1.add_head(1);
    l1.add_head(2);
    l1.add_head(3);
    l1.print();
    // cout << "LENGTH: " << l1.length() << endl;
    // cout << "SEARCH 1: " << l1.search(1) << endl;
    // l1.reverse();
    // l1.print();

    LinkedList<int> l2;

    l2.add_head(7);
    l2.add_head(8);
    l2.add_head(9);

    l2.print();

    LinkedList<int> l3;
    l3.add_head(10);
    l3.add_head(20);
    l3.add_head(30);

    l3.print();

    l1 = l2 + l3;

    l1.print();
    return 0;
}