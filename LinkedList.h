//
// Created by Alex Hayden van Zuiden-Rylander on 11/26/18.
//

#ifndef ASSIGNMENT4_LINKEDLIST_H
#define ASSIGNMENT4_LINKEDLIST_H

#include <iostream>

using namespace std;


class MyException : public exception {
    int code;
    const char *message;
public:
    MyException(const char *_message, int _code) : message(_message), code(_code) {}

    int getCode() { return code; }

    const char *what() const throw() { return message; }
};

template<class T>
struct Node { // struct is just like a class but everything is set to public initially
    T data;
    Node<T> *next;

    Node(T data) : data(data), next(NULL) {}     //constructor
    //Node(T data, Node *next) : data(data), next(next) {}  //constructor
};

template<class T>
class LinkedList {
    //friend class OrderedLinkedList;
private:
    // LinkedList(const LinkedList &) = delete; //copy constructor

protected:
    int count;
    Node<T> *head, *last;
public:
    //constructors
    //parameterless constructor
    LinkedList();

    //conversion constructor
    LinkedList(const T &item);    //creates linked list with first node

    //observer methods
    bool isEmpty();

    int length();

    T front();

    T back();

    bool search(LinkedList<T> &, T &);

    // mutator methods
    void insertFirst(T &);

    void insertLast(T &);

    virtual void deleteNode(T &);

    virtual void destroylist();

    //overload operators
    LinkedList<T> &operator=(LinkedList<T> &);

    template<class U>
    friend ostream &operator<<(ostream &os, LinkedList<U> &list);

    virtual ~LinkedList();    // allows use of base class and polymorphism to derived class
};

template<class T>
LinkedList<T>::LinkedList() {

    // cout << "i1" <<endl;
    head = last = NULL;
    count = 0;
}

template<class T>
LinkedList<T>::LinkedList(const T &item) : head(new Node<T>(item)), last(head), count(1) {
//cout << "i2" <<endl;
}

template<class T>
bool LinkedList<T>::isEmpty() { return head == NULL; }

template<class T>
int LinkedList<T>::length() { return count; }

template<class T>
T LinkedList<T>::front() {
    if (head == nullptr) {
        cout << "No front node." << endl;
    }
    return head->data;
}

template<class T>
T LinkedList<T>::back() {
    return last->
            data;
}

template<class T>
void LinkedList<T>::insertFirst(T &item) {
    cout << item;
    Node<T> *temp = new Node<T>(item);
    // temp->data = item;
    temp->next = head;
    head = temp;
    count++;
    if (last == NULL) last = temp;
}

template<class T>
void LinkedList<T>::insertLast(T &item) {
    Node<T> *newnode = new Node<T>(item);
    if (head == NULL) { head = last = newnode; }
    else {
        last->next = newnode;
        last = newnode;
        last->next = NULL;

    }
    count++;
}

template<class T>
void LinkedList<T>::deleteNode(T &item) {
    if (head == NULL)cerr << "empty list";
    else {
        if (head->data == item) {
            Node<T> *p = head;
            head = head->next;
            delete p;
            count--;
            if (head == NULL) last = NULL;
        } else {
            Node<T> *p = head;
            Node<T> *q = p->next;
            while (!(q == NULL) && !(q->data == item)) {
                p = q;
                q = q->next;
            }
            if (q != NULL) {
                p->next = q->next;
                count--;
                if (last == q) last = p;
                delete q;
            }
        }
    }
}

template<class T>
bool LinkedList<T>::search(LinkedList<T> &list, T &item) {
    Node<T> *r = list.head;
    while (r != NULL) {
        if (item == r->data) {
            return true;
        }
        r = r->next;
    }
    return false;
}


template<class T>
void LinkedList<T>::destroylist() {
    Node<T> *p;
    while (head != NULL) {
        p = head;
        head = head->next;
        delete p;
    }
    last = NULL;
    count = 0;
}


template<class T>
ostream &operator<<(ostream &os, LinkedList<T> &list) {
    Node<T> *p = list.head;
    while (p != NULL) {
        os << p->data << " " << endl;
        p = p->next;
    }
    return os;
}


//class destructor
template<class T>
LinkedList<T>::~LinkedList() { destroylist(); }


#endif //ASSIGNMENT4_LINKEDLIST_H
