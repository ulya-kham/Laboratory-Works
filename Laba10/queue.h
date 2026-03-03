#pragma once
#include <iostream>
struct TNode {//узел очереди
	int data;
	TNode* next;
	TNode(int val = 0, TNode* nxt = nullptr) : data(val), next(nxt) {}
};
class Queue {
private:
	TNode* head; // начало очереди
	TNode* tail; // конец очереди
public:
	Queue();//пустой
	~Queue();//деструктор
	Queue(const Queue&) = delete;
	Queue& operator=(const Queue&) = delete;
	void add(int value);//добавить в конец
	bool dequeue(int& value);//удалить из начала
	TNode* find(int value) const;//найти элемент по зн
	bool is_empty() const;//проверить пустоту
	void print() const;//вывод
	TNode* get_head() const { return head; }//начало
	TNode* get_tail() const { return tail; }//конец
	void detach() { head = nullptr; tail = nullptr; }//отсоединяем
};