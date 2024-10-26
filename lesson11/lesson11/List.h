#pragma once
#include <string>

class Node
{
public:
    Node() {

    }

    ~Node() {

    }
    std::string value;
    Node* previous = nullptr;
    Node* next = nullptr;

};


class List
{
public:
    List() {

    }

    ~List() {
        clear();
    }

    void push_back(const std::string& val) {
        sz++;
        Node* node = new Node();
        //node->previous = nullptr;
        //node->next = nullptr;

        node->value = val;
        if (head == nullptr) {
            head = node;
            tail = node;
        }
        else {
            node->previous = tail;
            tail->next = node;
            tail = node;

        }


    }

    void clear() {

        Node* it = head;

        while (it != nullptr)
        {
            Node* it2 = it;
            it = it->next;
            delete it2;

        }

        head = nullptr;
        tail = nullptr;
        sz = 0;
    }

    int size() { //O(1)
        return sz;
    }

    bool exist(const std::string& word) {
        Node* it = head;

        while (it != nullptr)
        {
            if (it->value == word)
            {
                return true;
            }
            it = it->next;

        }
        return false;
    }

private:
    Node* head = nullptr;
    Node* tail = nullptr;
    int sz = 0;
};


