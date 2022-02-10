#pragma once
#include <memory>
#include <iostream>

//using namespace std;
using std::ostream;
using std::shared_ptr;
using std::make_shared;
using std::runtime_error;


template<class Type>
class LinkedList;

template<class Type>
ostream& operator<< (ostream& out, const LinkedList<Type>& list);

template<class Type>
struct Node{
    Type data;
    //Node<Type> *next;
    shared_ptr<Node<Type>> next;
    
};

template<class Type>
class LinkedList{
public:
    LinkedList(): front(nullptr), back(nullptr), count(0) {}// Default constructor for the LinkedList.  Creates an empty list by setting front and back of the list to nulllptr
    //~LinkedList();           //Destructor for the LinkedList.  Creates an empty list by setting front and back of the list to nulllptr
    void insert(Type data);  //Adds to the back of the list
    Type peek(int ndx)const ;//Looks at an element at the given ndx value
    void remove(int ndx);    //Removes an element at the given ndx position
    void pointerPractice(Type, Type);
    friend ostream& operator<< <>(ostream& out, const LinkedList<Type>& list);// Returns an output stream for displaying the LinkedList
protected:
    int count;
    shared_ptr<Node<Type>> front;
    shared_ptr<Node<Type>> back;

};

template<class Type>
void LinkedList<Type>::insert(Type data){
    auto temp = make_shared<Node<Type>>();
    temp->data = data;
    temp->next = nullptr;
    if(!front){
        front = temp;
        back = temp;
    }else{
        back->next = temp;
        back = temp;
    }
    count++;
}

template<class Type>
Type LinkedList<Type>::peek(int ndx)const{
    if(ndx >= count|| ndx < 0){
        throw runtime_error("Out of range");
    }
    int currNodeNum = 0;
    auto currentNode = front;
    while(currNodeNum < ndx){
        currNodeNum++;
        currentNode = currentNode->next;
    }
    return currentNode->data;
}
template<class Type>
void LinkedList<Type>::remove(int ndx){
    if(ndx >= count|| ndx < 0){
        throw runtime_error("Out of range");
    }else if(ndx == 0){
        auto toDelete = front;
        front = toDelete->next;
        return;
    }else{
        int currNodeNum = 0;
        auto currentNode = front;
        while(currNodeNum < ndx-1){
            currNodeNum++;
            currentNode = currentNode->next;
        }
        auto toDelete = currentNode->next;
        if(toDelete->next){
            currentNode->next = toDelete->next;
        }else{
            currentNode->next = nullptr;
            back = currentNode;
        }
        count--;
    }
}

template<class Type>
ostream& operator<< (ostream& out, const LinkedList<Type>& list){
    auto curr = list.front;
    while (curr) {
        out << curr->data;
        if(curr->next){
            out << " ";
        }
        curr = curr->next;
    }
    return out;
}



template<class Type>
void LinkedList<Type>::pointerPractice(Type toInsert, Type toRemove)
{
    int i = 0;
    auto curr = front;
    auto newNode = make_shared< Node<Type>>();
    newNode->data = toInsert;
    while(i < 2){
        curr = curr->next;
        //std::cout << curr->data;
        i++;
    }
    newNode->next = curr->next;
    curr->next= newNode;
    i = 0;
    curr = front;
    auto extra = make_shared<Node<Type>>();
    //std::cout << "hi";
    //curr->next = newNode;
    
    while(curr->data <= 4){
        curr = curr->next;
        //std::cout << curr->data;
        //i++;
    }
    extra = curr->next;
    curr -> next = extra->next;

}
