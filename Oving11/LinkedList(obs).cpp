/*#include "LinkedList.h"

std::ostream& operator<<(std::ostream& os, const LinkedList::Node& node){
    os << node.getValue();
    return os;
}

LinkedList::Node* LinkedList::LinkedList::insert(::LinkedList::Node *pos, const std::string& value){
    std::unique_ptr<::LinkedList::Node> ptr = std::make_unique<::LinkedList::Node>(value, std::move(pos->prev->next), pos->getPrev());
    pos->prev->next = move(ptr);
    pos->prev = ptr.get();
    return ptr.get();
}

LinkedList::Node* LinkedList::LinkedList::remove(::LinkedList::Node* pos){
    pos->prev->next = move(pos->next);
    pos->next->prev = pos->prev;
    return pos->next.get();
}

LinkedList::Node* LinkedList::LinkedList::find(const std::string& value){
    ::LinkedList::Node* search = head.get();
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

void LinkedList::LinkedList::remove(const std::string& value){
    remove(find(value));
    return;
}

std::ostream & operator<<(std::ostream & os, const ::LinkedList::LinkedList& list){
    auto element = list.begin();
    while (true){
        os << element->getValue() << " ";
        element = element->getNext();
        if (element == list.end()) break;
    }
    return os;
}

void testLinkedList(){
    
}*/