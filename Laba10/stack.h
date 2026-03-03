#pragma once
#include <string>

struct Node {//поле данных
	int data;//указатель на следующий
	Node* next;
};

class Stack {
private:
	Node* top;
	void copy_from(const Stack& other);// функция для копирования стека

public:
	Stack();//конструктор по умол. создает пустой
	Stack(const Stack& other);//конструктор копирования
	~Stack();//деструкт.освобождает всю память
	Stack& operator=(const Stack& other);//присваивания
	void add(int value);//добавить
	bool pop(int& value);//удалить
	bool peek(int& value) const;//посмотреть вершину
	Node* find(int value) const;//найти элемент по значению
	bool is_empty() const;//проверить пустоту
	Node* get_top() const;//указатель на вершину стека
	void print() const;//вывод
	void clear();//очистить
};