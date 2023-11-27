#include <iostream>
using std::cout, std::endl;

template <typename T>
class Node {
public:
    T info;
    Node<T>* next;
    Node<T>* prev;

    Node(T info_, Node<T>* prev_ = nullptr, Node<T>* next_ = nullptr) : info(info_), prev(prev_), next(next_) {}
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
        while(is_empty()) {
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
        head->prev = new Node<T>(info, nullptr, head);
        head = head->prev;
    }

    void add_tail(T info) {
        if (is_empty()) {
            head = tail = new Node<T>(info);
            return;
        }
        tail->next = new Node<T>(info, tail, nullptr);
        tail = tail->next;
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
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
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
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
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
            head = head->next;
            delete head->prev;
            head->prev = nullptr;
            return;
        }

        Node<T>* p = head;
        while (p != nullptr) {
            if (p->info == info) {  
                break;
            }
            p = p->next;
        }
        p->prev->next = p->next;
        if (p != tail) {
            p->next->prev = p->prev;
        }
        delete p;
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
        Node<T>* current = head, *temp = nullptr;
        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next =  temp;
            current = current->prev;
        }

        head = temp->prev;
        
        Node<T>* p = head;
        while (p->next == nullptr) {
            p = p->next;
        }
        tail = p;
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
    l1.print();
    l1.add_tail(1);
    l1.print();
    // l1.remove_head();
    // l1.remove_tail();
    // l1.remove_node(2);
    // cout << l1.search(3) << endl;
    l1.reverse();
    l1.print();
    return 0;
}