#pragma once

#include <memory>
#include <ostream>
#include <string>

// test code 
void testLinkedList();


namespace LinkedList {

template<typename T>
class Node {
private:
    const T value;    // The data held by the LinkedList
    std::unique_ptr<Node> next; // unique_ptr to the next node
    Node* prev;                 // raw (non-owning) ptr to the previous node
public:
    Node() : value(), next(nullptr), prev(nullptr) {}
    // construct a node with string value, a unique_ptr to the next node, and a pointer to the previous node
    Node(const T& value, std::unique_ptr<Node> next, Node* prev)
        : value(value)
        , next(std::move(next))
        , prev(prev)
    {}
    // We can use the default destructor, since unique_ptr takes care of deleting memory
    ~Node() = default;
    // return the value of the node
    T getValue() const { return value; }

    // return a raw (non-owning) pointer to the next node
    Node* getNext() const { return next.get(); }
    // return a raw (non-owning) pointer to the previous node
    Node* getPrev() const { return prev; }

    // write the value of the node to the ostream
    friend std::ostream & operator<<(std::ostream & os, const Node & node){
        os << node.getValue();
        return os;
    }

    friend class LinkedList;
};


template<typename Value>
class LinkedList {
private:
    // ptr to the first node
    std::unique_ptr<Node<Value>> head;
    // a raw pointer to the last node, the last node is always a dummy node
    // this is declared as a const ptr to a Node, so that tail never can
    // point anywhere else
    Node<Value>* const tail;
public:
    //create the dummy node, and make tail point to it
    LinkedList()
        : head(std::make_unique<Node<Value>>())
        , tail(head.get())
    {}
    ~LinkedList() = default;

    //if next is a nullptr (i.e. head is the dummy node), the list is emtpy
    bool isEmpty() const { return !head->next; }


    //return a pointer to first element
    Node<Value>* begin() const { return head.get(); }
    //return a pointer to beyond-end element
    Node<Value>* end() const { return tail; }

    // The insert function takes a pointer to node (pos) and a string (value). It creates a new
    // node which contains value. The new node is inserted into the LinkedList BEFORE the
    // node pointed to by pos. Returns a pointer to the new Node
    Node<Value>* insert(Node<Value> *pos, const Value& value){
        std::unique_ptr<::LinkedList::Node<Value>> ptr = std::make_unique<::LinkedList::Node<Value>>(value, std::move(pos->prev->next), pos->getPrev());
        pos->prev->next = move(ptr);
        pos->prev = ptr.get();
        return ptr.get();
    }

    // The find function traverses the linked list and returns a pointer to the first node
    // that contains the value given.
    // If the value isn't in the list, find returns a pointer to the dummy node at the end
    // of the list.
    Node<Value>* find(const Value& value){
        ::LinkedList::Node<Value>* search = head.get();
        while(true){
            if (search->getValue() == value){
                break;
            }
            else if (search == tail){
                break;
            }
            else{
                search = search->getNext();
            }
        }
        return search;
        }

    // The remove function takes a pointer to a node, and removes the node from the list. The
    // function returns a pointer to the element after the removed node.
    Node<Value>* remove(Node<Value>* pos){
        pos->prev->next = move(pos->next);
        pos->next->prev = pos->prev;
        return pos->next.get();
    }

    // The remove function takes a string and removes the first node which contains the value.
    void remove(const Value& value){
        remove(find(value));
        return;
    }

    // write a string representation of the list to the ostream
    friend std::ostream & operator<<(std::ostream & os, const LinkedList& list){
        auto element = list.begin();
        while (true){
            os << element->getValue() << " ";
            element = element->getNext();
            if (element == list.end()) break;
        }
        return os;
    }
};
}// namespace LinkedList



