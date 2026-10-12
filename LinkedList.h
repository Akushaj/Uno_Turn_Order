#pragma once
#include <iostream>
#include "Node.h"
#include "List.h"


template<typename T>
class LinkedList : public List<T> {
public:
    LinkedList() : head_(nullptr), size_(0) {}

    void addFront(T* value) override {
        Node<T>* fresh = new Node<T>(value);
        fresh->next = head_;
        head_ = fresh;
        ++size_;
    }

    void deleteFront() override {
        if (head_ == nullptr) {
            std::cout << "LinkedList is empty" << std::endl;
            return;
        }
        Node<T>* doomed = head_;
        head_ = head_->next;
        delete doomed->data;
        delete doomed;
        --size_;                                  // new
    }

    void addAnywhere(int position, T* value) override {
        if (position < 0 || position > size_) {
            std::cout << "The position is out of range." << std::endl;
            return;
        }
        if (position == 0) {
            addFront(value);
            return;
        }

        Node<T>* prev = head_;
        for (int i = 0; i < position - 1; ++i) { // going to the node just before the insertion point
            prev = prev->next;
        }
        Node<T>* fresh = new Node<T>(value);
        fresh->next = prev->next; // linking the new node to the rest of the list first
        prev->next = fresh; // linking the previous node to the new node / splicing it
        ++size_; // increasing the size of the linked list
    }

    void deleteAnywhere(int position) override {
        if (position < 0 || position >= size_) {
            std::cout << "Position out of bounds." << std::endl;
            return;
        }
        if (position == 0) {
            deleteFront();
            return;
        }
        Node<T>* prev = head_;
        for (int i = 0; i < position - 1; ++i) {
            prev = prev->next;
        }
        Node<T>* doomed = prev->next;
        prev->next = doomed->next; // skipping the doomed node
        delete doomed->data;  // free the T
        delete doomed; // free the node
        --size_;
    }

    void reverse() override {
        Node<T>* prev = nullptr;
        Node<T>* current = head_;
        while (current != nullptr) {
            Node<T>* next = current->next;        // save the rest
            current->next = prev;                 // flip backward
            prev = current;
            current = next;
        }
        head_ = prev;                             // old last node is the new head
    }

    void concat(List<T>* other) override {
        LinkedList<T>* src = dynamic_cast<LinkedList<T>*>(other);
        if (src == nullptr) {
            std::cout << "Type mismatch in concat." << std::endl;
            return;
        }
        if (src->head_ == nullptr) {
            return;                               // nothing to attach
        }
        if (head_ == nullptr) {
            head_ = src->head_;                   // this is empty, take over
        } else {
            Node<T>* last = head_;                // no tail, so walk to the end: O(n)
            while (last->next != nullptr) {
                last = last->next;
            }
            last->next = src->head_;
        }
        size_ += src->size_;
        src->head_ = nullptr;                     // ownership moved
        src->size_ = 0;
    }

    bool search(T* value) const override {
        Node<T>* current = head_;
        while (current != nullptr) {
            if (*current->data == *value) return true;
            current = current->next;
        }
        return false;
    }

    void print() const override {
        Node<T>* current = head_;
        while (current != nullptr) {
            std::cout << *current->data << ",";
            current = current->next;
        }
        std::cout << std::endl;
    }

    ~LinkedList() override {
        while (head_ != nullptr) {
            Node<T>* doomed = head_;
            head_ = head_->next;
            delete doomed->data;
            delete doomed;
        }
    }

private:
    Node<T>* head_;
    int size_;
};