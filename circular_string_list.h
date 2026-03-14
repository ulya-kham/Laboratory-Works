#pragma once
#include <iostream>
#include <string>
class CStringNode {
public:
    std::string name;
    CStringNode* next;
    CStringNode(const std::string& n = "", CStringNode* nxt = nullptr)
        : name(n), next(nxt) {
    }
};
class CircularStringList {
private:
    CStringNode* head;

    void clear();

public:
    CircularStringList();
    ~CircularStringList();
    CircularStringList(const CircularStringList&) = delete;
    CircularStringList& operator=(const CircularStringList&) = delete;
    void push_back(const std::string& name);
    bool is_empty() const { return head == nullptr; }
    void josephus(int k, const std::string& output_filename);
};