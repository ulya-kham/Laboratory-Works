#include "doubly_list.h"
DoublyList::DoublyList() : head(nullptr), tail(nullptr) {}
DoublyList::~DoublyList() { clear(); }
DoublyList::DoublyList(const DoublyList& other) : head(nullptr), tail(nullptr) {
    copy_from(other);
}
DoublyList& DoublyList::operator=(const DoublyList& other) {
    if (this != &other) {
        clear();
        copy_from(other);
    }
    return *this;
}
void DoublyList::clear() {
    while (head) {
        DNode* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}
void DoublyList::copy_from(const DoublyList& other) {
    DNode* current = other.head;
    while (current) {
        push_back(current->data);
        current = current->next;
    }
}
void DoublyList::push_back(int value) {
    DNode* new_node = new DNode(value);
    if (!head) {
        head = tail = new_node;
    }
    else {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
}
void DoublyList::print() const {
    if (!head) {
        std::cout << "пустой";
        return;
    }
    DNode* current = head;
    while (current) {
        std::cout << current->data;
        current = current->next;
        if (current) std::cout << " <-> ";
    }
}
bool DoublyList::is_empty() const {
    return head == nullptr;
}
void DoublyList::disconnect() { //отсоединить узлы
    head = nullptr;
    tail = nullptr;
}
void DoublyList::push_front(int value) {
    DNode* new_node = new DNode(value);
    if (!head) {
        head = tail = new_node;
    }
    else {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
}
bool DoublyList::remove(int value) {
    DNode* current = head;
    while (current) {
        if (current->data == value) {
            if (current == head && current == tail) {
                head = tail = nullptr;
            }
            else if (current == head) {
                head = head->next;
                head->prev = nullptr;
            }
            else if (current == tail) {
                tail = tail->prev;
                tail->next = nullptr;
            }
            else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            delete current;
            return true;
        }
        current = current->next;
    }
    return false;
}

DNode* DoublyList::find(int value) const { 
    DNode* current = head;
    while (current) {
        if (current->data == value) return current;
        current = current->next;
    }
    return nullptr;
}
DNode* DoublyList::listwork43() {
    if (!head || !head->next) return head; 
    DNode* even_head = nullptr;
    DNode* even_tail = nullptr;
    DNode* odd_head = nullptr;
    DNode* odd_tail = nullptr;
    DNode* current = head;
    int pos = 1;
    while (current) {//разделяем на чет/нечет
        DNode* next = current->next;
        current->next = nullptr;
        current->prev = nullptr;
        if (pos % 2 == 0) {//чет
            if (!even_head) {
                even_head = even_tail = current;
            }
            else {
                even_tail->next = current;
                current->prev = even_tail;
                even_tail = current;
            }
        }
        else {//нечет
            if (!odd_head) {
                odd_head = odd_tail = current;
            }
            else {
                odd_tail->next = current;
                current->prev = odd_tail;
                odd_tail = current;
            }
        }
        current = next;
        pos++;
    }
    if (even_head) {//склеиваем
        head = even_head;
        if (odd_head) {
            even_tail->next = odd_head;
            odd_head->prev = even_tail;
            tail = odd_tail;
        }
        else {
            tail = even_tail;
        }
    }
    else {
        head = odd_head;
        tail = odd_tail;
    }
    return head;
}
DNode* create_barrier_and_link(DNode* head, DNode* tail) {
    DNode* barrier = new DNode(0);
    if (head == nullptr) {//пусто
        barrier->next = barrier;
        barrier->prev = barrier;
    }
    else {
        barrier->next = head;
        barrier->prev = tail;
        head->prev = barrier;
        tail->next = barrier;
    }

    return barrier;
}


