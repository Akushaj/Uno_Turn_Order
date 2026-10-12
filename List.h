#pragma once
#include <memory>

// The List ADT. Same file as Lab 3, plus four new methods at the bottom
// of the class. ArrayList and LinkedList both implement all of them.

template <typename T>
class List {
public:
    virtual ~List() = default;

    // From Lab 3.
    virtual void addFront(T* value) = 0;
    virtual void deleteFront() = 0;
    virtual bool search(T* value) const = 0;
    virtual void print() const = 0;
    virtual void addAnywhere(int position, T* value) = 0;
    virtual void deleteAnywhere(int position) = 0;
    virtual void reverse() = 0;
    virtual void concat(List<T>* other) = 0;

};

#include "ArrayList.h"
#include "LinkedList.h"

template <typename T>
std::unique_ptr<List<T>> makeList() {
       return std::make_unique<LinkedList<T>>();
      // return std::make_unique<ArrayList<T>>();
}
