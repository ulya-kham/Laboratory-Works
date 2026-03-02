#include "queue.h"
#include <iostream>

Queue::Queue() : head(nullptr), tail(nullptr) {}//конструктор-пустая
Queue::~Queue() {//деструктор
	while (head) {
		TNode* temp = head;
		head = head->next;
		delete temp;
	}
	tail = nullptr;
}
void Queue::add(int value) {//добавка в конец 
	TNode* new_node = new TNode(value, nullptr);
	if (!tail) {
		head = tail = new_node;
	}
	else {
		tail->next = new_node;
		tail = new_node;
	}
}
bool Queue::is_empty() const { return head == nullptr; }//пустота
void Queue::print() const {//вывод
	if (!head) {
		std::cout << "пустая";
		return;
	}
	TNode* cur = head;
	std::cout << cur->data;
	cur = cur->next;
	while (cur) {
		std::cout << " -> " << cur->data;
		cur = cur->next;
	}
}