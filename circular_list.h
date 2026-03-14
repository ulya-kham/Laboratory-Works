#pragma once
#include <iostream>
#include <string>

class CNode {
public:
	int data;
	CNode* next;
	CNode(int val = 0, CNode* nxt = nullptr) : data(val), next(nxt) {}
};
class CircularList {
private:
	CNode* head;//указатель на головку кольца
	void clear();
	void copy_from(const CircularList& other);
public:
	CircularList();//констр
	CircularList(const CircularList& other);
	~CircularList();//деструкт
	CircularList& operator=(const CircularList& other);//присваивания
	int size() const;
	void push_back(int value);//в конец
	bool remove(int value);//удалить
	CNode* find(int value) const;//поиск
	bool is_empty() const;//пустота
	void print() const;//вывод списка
	CNode* get_head() const { return head; }//указатель на головку
	void listwork66(const std::string& filename);
};