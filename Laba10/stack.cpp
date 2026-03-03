#include "stack.h"
#include <iostream>

Stack::Stack() { top = nullptr; }//конструктор по умолч. пустой стек
Stack::Stack(const Stack& other) { top = nullptr; copy_from(other); }//копирования
Stack::~Stack() { clear(); }//деструк
Stack& Stack::operator=(const Stack& other) {// присваивания
	if (this != &other) {
		clear();
		copy_from(other);
	}
	return *this;
}
void Stack::add(int value) {//добавить
	Node* new_node = new Node;
	new_node->data = value;
	new_node->next = top;
	top = new_node;
}
bool Stack::pop(int& value) {//удалить
	if (top == nullptr) return false;//если тек пуст
	value = top->data;
	Node* temp = top;
	top = top->next;
	delete temp;
	return true;
}
bool Stack::peek(int& value) const {//посмотреть вершину
	if (top == nullptr) return false;
	value = top->data;
	return true;
}
Node* Stack::find(int value) const {//найти элемент по знач
	Node* current = top;
	while (current) {
		if (current->data == value) return current;
		current = current->next;
	}
	return nullptr;
}
bool Stack::is_empty() const { return top == nullptr; }//пустота
Node* Stack::get_top() const { return top; }//указатель на вершину
void Stack::print() const {//вывод
	if (top == nullptr) {
		std::cout << "\tСтек пустой";
		return;
	}
	std::cout << "\t";
	Node* current = top;
	while (current != nullptr) {
		std::cout << current->data;
		if (current->next != nullptr) std::cout << " -> ";
		current = current->next;
	}
}
void Stack::clear() {//очистка
	while (top != nullptr) {
		Node* temp = top;
		top = top->next;
		delete temp;
	}
}
void Stack::copy_from(const Stack& other) {//копирования
	if (other.top == nullptr) {
		top = nullptr;
		return;
	}
	Node* temp = nullptr;
	Node* current = other.top;
	while (current != nullptr) {//копируем в обратном порядке
		Node* new_node = new Node;
		new_node->data = current->data;
		new_node->next = temp;
		temp = new_node;
		current = current->next;
	}
	top = nullptr;
	while (temp != nullptr) {//переворачиваем обратно
		Node* new_node = new Node;
		new_node->data = temp->data;
		new_node->next = top;
		top = new_node;
		temp = temp->next;
	}
}