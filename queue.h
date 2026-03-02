#pragma once
#include <iostream>
struct TNode {
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
	void add(int value);
	bool is_empty() const;
	void print() const;
	TNode* get_head() const { return head; }
	TNode* get_tail() const { return tail; }
	void detach() { head = nullptr; tail = nullptr; }//отсоединяем
};