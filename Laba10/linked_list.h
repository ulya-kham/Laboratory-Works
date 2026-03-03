#pragma once
#include <string>
struct ListNode {//узел списка
	int data;
	ListNode* next;
	ListNode(int val = 0, ListNode* nxt = nullptr) : data(val), next(nxt) {}
};
class LinkedList {
private:
	ListNode* head;//указатель на головушку
public:
	LinkedList();//конструк
	~LinkedList();//деструк
	LinkedList(const LinkedList&) = delete;//запрет копирования
	LinkedList& operator=(const LinkedList&) = delete;
	void add(int value);//добавка в конец
	bool remove(int value);//удалить первый найденный 
	ListNode* find(int value) const;//найти элемент по знач.
	bool is_empty() const;//пустота
	void print() const;//вывод
	void clear();//очистить список
	ListNode* get_head() const { return head; }
	ListNode* get_second() const;//указатель на второй
	static void add_after(ListNode* node, int value);//вставка после заданного
	ListNode* every_second(int M);//вставка м после каждого второго
	ListNode* every_k(int K, int M);//вставка м после каждого к
};