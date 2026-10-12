#pragma once
#include <iostream>
#include "List.h"

// Solution file. Lab 3's ArrayList plus addBack, getFront, isEmpty, size.

template <typename T>
class ArrayList : public List<T> {
public:
    ArrayList() : size_(0) {}

    void addFront(T* value) override {
        if (size_ >= CAPACITY) {
            std::cout << "ArrayList is full." << std::endl;
            return;
        }
        for (int i = size_; i > 0; --i) {
            data_[i] = data_[i - 1];
        }
        data_[0] = value;
        ++size_;
    }

    void addAnywhere(int position, T* value) override {
        if (size_ >= CAPACITY) {
            std::cout << "ArrayList is full. " << std::endl;
            return;
        }
        if (position < 0 || position > size_ ) {
            std::cout << "The position is out of range." << std::endl;
            return;
        }
        for (int i = size_ ; i > position; i--) { // shifts every value starting at position one slot to the right
            data_[i] = data_[i-1];
        }
        data_[position] = value; // assigns the now empty position with the value given in the parameter
        size_++; // increases the array size
    }


    void deleteFront() override {
        if (size_ == 0) {
            std::cout << "ArrayList is empty." << std::endl;
            return;
        }
        delete data_[0];
        for (int i = 0; i < size_ - 1; ++i) {
            data_[i] = data_[i + 1];
        }
        --size_;
    }

    void deleteAnywhere(int position) override {
        if (size_ == 0 ) {
            std::cout << "ArrayList is empty." << std::endl;
            return;
        }
        if (position < 0 || position >= size_) {
            std::cout << "The position is out of range." << std::endl;
            return;
        }
        delete data_[position]; // freeing the T itself at position
        for (int i = position ; i < size_-1; ++i) { // shifting the array left while copying the values from the right
            data_[i] = data_[i + 1];
        }
        --size_;
    }

    void reverse() override {
        int left = 0;
        int right = size_ - 1;
        while ( left < right ) {
            T* temp = data_[left];
            data_[left] = data_[right];
            data_[right] = temp;
            ++left;
            --right;
        }
    }

    void concat(List<T>* other) override {
        ArrayList<T>* src = dynamic_cast<ArrayList<T>*>(other);
        if (src == nullptr) {
            std::cout << "Type Mismatch in concat." << std::endl; // checks if the type is a match or not. If src is null pointer it means it is not a Arraylist but a LinkedList
            return;
        }
        if (src->size_ + size_ > CAPACITY) { //
            std::cout << "ArrayList has not enough capacity " << std::endl;
            return;
        }
        for (int i = 0 ; i < src->size_ ; ++i) {
            data_[size_ + i] = src->data_[i]; // concat the other arraylist on this arraylist
        }
        size_ = src->size_ + size_; // increasing the size of the arraylist
        src->size_ = 0; // making the size of other 0
    }


    bool search(T* value) const override {
        for (int i = 0; i < size_; ++i) {
            if (*data_[i] == *value) {
                return true;
            }
        }
        return false;
    }

    void print() const override {
        for (int i = 0; i < size_; ++i) {
            std::cout << *data_[i] << ",";
        }
        std::cout << std::endl;
    }

    ~ArrayList() override {
        for (int i = 0; i < size_; ++i) {
            delete data_[i];
        }
    }

private:
    static const int CAPACITY = 20;
    T* data_[CAPACITY];
    int size_;
};
