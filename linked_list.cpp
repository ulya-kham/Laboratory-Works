#include "linked_list.h"
#include <iostream>
LinkedList::LinkedList() : head(nullptr) {}//конструк
LinkedList::~LinkedList() { clear(); }//деструк
ListNode* LinkedList::get_second() const {//второй элемент
	if (!head || !head->next) return nullptr;//больше 1
	return head->next;
}
void LinkedList::add(int value) {//добавка в конец
	if (!head) {
		head = new ListNode(value);
		return;
	}
	ListNode* current = head;
	while (current->next) {
		current = current->next;
	}
	current->next = new ListNode(value);
}
bool LinkedList::is_empty() const { return head == nullptr; }
void LinkedList::print() const {
	if (!head) {
		std::cout << "пустой";
		return;
	}
	ListNode* current = head;
	std::cout << current->data;
	current = current->next;
	while (current) {
		std::cout << " -> " << current->data;
		current = current->next;
	}
}
void LinkedList::clear() {
	while (head) {
		ListNode* temp = head;
		head = head->next;
		delete temp;
	}
}
void LinkedList::add_after(ListNode* node, int value) {
	if (!node) return;
	ListNode* new_node = new ListNode(value, node->next);
	node->next = new_node;
}
ListNode* LinkedList::every_second(int M) {
	if (!head || !head->next) {
		ListNode* tail = head;
		while (tail && tail->next) tail = tail->next;
		return tail;
	}
	ListNode* current = head;
	int i = 1;//номер текущ исходного
	while (current) {
		if (i % 2 == 0) {//четные
			ListNode* new_node = new ListNode(M, current->next);
			current->next = new_node;
			current = new_node->next;
			i++;
		}
		else {
			current = current->next;
			i++;
		}
	}
	ListNode* tail = head;
	while (tail && tail->next) {
		tail = tail->next;
	}
	return tail;
}
ListNode* LinkedList::every_k(int K, int M) {
	if (!head || K <= 0) {
		ListNode* tail = head;
		while (tail && tail->next) tail = tail->next;
		return tail;
	}
	ListNode* current = head;
	int count = 1;//номер текущего исходног
	while (current) {
		if (count % K == 0) {
			ListNode* new_node = new ListNode(M, current->next);
			current->next = new_node;
			current = new_node->next;
			if (current) count++;
		}
		else {
			current = current->next;
			if (current) count++;
		}
	}
	ListNode* tail = head;
	while (tail && tail->next) {
		tail = tail->next;
	}
	return tail;
}