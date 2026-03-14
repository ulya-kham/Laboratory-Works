#include "circular_doubly_list.h"
#include <vector>
CircularDoublyList::CircularDoublyList() : head(nullptr) {}
CircularDoublyList::~CircularDoublyList() {
    clear();
}
CircularDoublyList::CircularDoublyList(const CircularDoublyList& other) : head(nullptr) {
    copy_from(other);
}
CircularDoublyList& CircularDoublyList::operator=(const CircularDoublyList& other) {
    if (this != &other) {
        clear();
        copy_from(other);
    }
    return *this;
}
void CircularDoublyList::clear() {
    if (!head) return;
    Node* current = head;
    do {
        Node* temp = current;
        current = current->next;
        delete temp;
    } while (current != head);
    head = nullptr;
}
void CircularDoublyList::copy_from(const CircularDoublyList& other) {
    if (!other.head) {
        head = nullptr;
        return;
    }
    head = new Node(other.head->data);
    Node* current = head;
    Node* other_current = other.head->next;
    while (other_current != other.head) {
        current->next = new Node(other_current->data, nullptr, current);
        current = current->next;
        other_current = other_current->next;
    }
    current->next = head;//замыкаем кольцо
    head->prev = current;
}
void CircularDoublyList::push_back(int value) {
    Node* new_node = new Node(value);
    if (!head) {
        head = new_node;
        head->next = head;
        head->prev = head;
    }
    else {
        Node* tail = head->prev;
        tail->next = new_node;
        new_node->prev = tail;
        new_node->next = head;
        head->prev = new_node;
    }
}
bool CircularDoublyList::is_empty() const {
    return head == nullptr;
}
void CircularDoublyList::print() const {
    if (!head) {
        std::cout << "пустой";
        return;
    }
    Node* current = head;
    do {
        std::cout << current->data;
        current = current->next;
        if (current != head) std::cout << " <-> ";
    } while (current != head);
}
Node* CircularDoublyList::find(int value) const {
    if (!head) return nullptr;
    Node* current = head;
    do {
        if (current->data == value) return current;
        current = current->next;
    } while (current != head);
    return nullptr;
}
bool CircularDoublyList::remove(Node* target) {
    if (!target || !head) return false;
    if (head->next == head) {
        delete head;
        head = nullptr;
        return true;
    }
    target->prev->next = target->next;
    target->next->prev = target->prev;
    if (target == head) {
        head = target->next;
    }
    delete target;
    return true;
}
Node* CircularDoublyList::listwork42() {
    if (!head) return nullptr;
    std::vector<Node*> to_remove;
    Node* current = head;
    do {
        if (current->prev->data == current->next->data) {//проверка
            to_remove.push_back(current);
        }
        current = current->next;
    } while (current != head);
    for (Node* node : to_remove) {//по одному из списка удаляем
        remove(node);
    }
    return get_tail();//послед эл
}