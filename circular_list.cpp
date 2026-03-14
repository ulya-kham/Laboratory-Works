#include "circular_list.h"
#include <fstream>
#include <iostream>
#include <locale>  
#include <windows.h>  
CircularList::CircularList() : head(nullptr) {}
CircularList::~CircularList() { clear(); }
CircularList::CircularList(const CircularList& other) : head(nullptr) {
	copy_from(other);
}
CircularList& CircularList::operator=(const CircularList& other) {
	if (this != &other) {
		clear();
		copy_from(other);
	}
	return *this;
}
void CircularList::clear() {
	if (!head) return;
	CNode* current = head;
	do {
		CNode* temp = current;
		current = current->next;
		delete temp;
	} while (current != head);
	head = nullptr;
}
void CircularList::copy_from(const CircularList& other) {
	if (!other.head) {
		head = nullptr;
		return;
	}
	head = new CNode(other.head->data);
	CNode* current = head;
	CNode* other_current = other.head->next;
	while (other_current != other.head) {
		current->next = new CNode(other_current->data);
		current = current->next;
		other_current = other_current->next;
	}
	current->next = head;//замыкаем в кольцо
}
void CircularList::push_back(int value) {
	CNode* new_node = new CNode(value);
	if (!head) {
		head = new_node;
		head->next = head;
	}
	else {
		CNode* tail = head;
		while (tail->next != head) tail = tail->next;
		tail->next = new_node;
		new_node->next = head;
	}
}
bool CircularList::is_empty() const { return head == nullptr; }
void CircularList::print() const {
	if (!head) {
		std::cout << "пустой";
		return;
	}
	CNode* current = head;
	do {
		std::cout << current->data;
		current = current->next;
		if (current != head) std::cout << " -> ";
	} while (current != head);
}
CNode* CircularList::find(int value) const {
	if (!head) return nullptr;
	CNode* current = head;
	do {
		if (current->data == value) return current;
		current = current->next;
	} while (current != head);
	return nullptr;
}
int CircularList::size() const {
	if (!head) return 0;

	int count = 0;
	CNode* current = head;
	do {
		count++;
		current = current->next;
	} while (current != head);

	return count;
}
bool CircularList::remove(int value) {
	if (!head) return false;
	if (head->next == head) {
		if (head->data == value) {
			delete head;
			head = nullptr;
			return true;
		}
		return false;
	}
	CNode* current = head;
	CNode* prev = nullptr;
	do {
		if (current->data == value) {
			if (current == head) {
				CNode* tail = head;
				while (tail->next != head) tail = tail->next;
				tail->next = head->next;
				head = head->next;
			}
			else {
				prev->next = current->next;
			}
			delete current;
			return true;
		}
		prev = current;
		current = current->next;
	} while (current != head);
	return false;
}
void CircularList::listwork66(const std::string& filename) {
	if (!head) return;
	std::ofstream file(filename);
	if (!file.is_open()) {
		std::cout << "\n\tОшибка! Не удалось открыть файл \"" << filename << "\"\n";
		return;
	}
	std::cout << "\n\n\tПроцесс удаления:\n";
	CNode* current = head; //начало
	int step = 1;
	while (head != nullptr) { 
		for (int i = 0; i < 2; ++i) {
			current = current->next;
		}
		int value = current->data;
		file << value << "\n";
		std::cout << "\tШаг " << step << ": удаляем " << value;
		if (current == head && current->next == head) {
			delete current;
			head = nullptr;
			current = nullptr;
		}
		else {
			CNode* prev = head;
			while (prev->next != current) {
				prev = prev->next;
			}
			if (current == head) {
				head = current->next;
			}
			prev->next = current->next;
			CNode* next_node = current->next;
			delete current;
			current = next_node; //продолжаем отсюда
		}

		std::cout << " /*/ осталось: ";
		if (head) print(); else std::cout << "пусто";
		std::cout << "\n";
		step++;
	}
	file.close();
	std::cout << "\n\tРезультат записан в файлик \"" << filename << "\"\n";
}