//
// Created by Alex on 11/15/2018.
//

#ifndef ASSIGNMENT4_BINARYSEARCHTREE_H
#define ASSIGNMENT4_BINARYSEARCHTREE_H

#include <iostream>

using namespace std;

template<class T>
struct node {
    T data;
    node<T> *left;
    node<T> *right;
};

template<class T>
class BinarySearchTree {
    node<T> *root;

public:

    BinarySearchTree() { root = NULL; }

    void insert(T &);

    void deleteNode(T &);

    int height();

    T findMax(T &);

    T findMin(T &);

    bool isEmpty();

    bool search(T &);

    void printPreOrder();

    void printPostOrder();

    void printInOrder();

private:
    int height(node<T> *);

    void insert(node<T> *&, T &);

    void deleteNode(node<T> *&, T &);

    bool search(node<T> *, T &);

    void printPreOrder(node<T> *);

    void printPostOrder(node<T> *);

    void printInOrder(node<T> *);

    T findMax(node<T> *, T &);

    T findMin(node<T> *, T &);

    int max(int, int);
};

template<class T>
void BinarySearchTree<T>::insert(T &item) {
    insert(root, item);
}

template<class T>
void BinarySearchTree<T>::deleteNode(T &item) {
    deleteNode(root, item);
}

template<class T>
int BinarySearchTree<T>::height() {
    return height(root);
}

template<class T>
T BinarySearchTree<T>::findMax(T &item) {
    return findMax(root, item);
}

template<class T>
T BinarySearchTree<T>::findMin(T &item) {
    return findMin(root, item);
}

template<class T>
bool BinarySearchTree<T>::isEmpty() {
    return root == NULL;
}

template<class T>
bool BinarySearchTree<T>::search(T &item) {
    return search(root, item);
}

template<class T>
void BinarySearchTree<T>::printPreOrder() {
    printPreOrder(root);
}

template<class T>
void BinarySearchTree<T>::printPostOrder() {
    printPostOrder(root);
}

template<class T>
void BinarySearchTree<T>::printInOrder() {
    printInOrder(root);
}

template<class T>
int BinarySearchTree<T>::height(node<T> *n) {
    if (n != NULL) {
        return 1 + max(height(n->left), height(n->right));
    }
}

template<class T>
void BinarySearchTree<T>::insert(node<T> *&r, T &item) {
    if (r == NULL) {
        r = new node<T>;
        r->data = item;
        r->left = r->right = NULL;
    } else if (item < r->data) {
        insert(r->left, item);
    } else if (item > r->data) {
        insert(r->right, item);
    }

}

template<class T>
void BinarySearchTree<T>::deleteNode(node<T> *&r, T &item) {
    if (r == NULL) {
        return;
    }
    if (item < r->data) {
        deleteNode(r->left, item);
    } else if (item > r->data) {
        deleteNode(r->right, item);
    } else {
        //case 1: we delete a node with two children, either find max of left subtree, or min of right subtree and replace the node with one of those values
        //two steps, first find max of left subtree, copy the value to the node you want to delete, and then recursively call delete on that value.
        if (r->right != NULL && r->left != NULL) {
            //find the max on the left
            T maxNode = findMax(r->left, item);
            //set the nodes data to
            r->data = maxNode;
            //recursively update the tree
            deleteNode(r->left, maxNode);
        }
            //case 2: we delete a node with one child, find parents parent and have it's pointer point to the child
        else {
            node<T> *q = r;
            if (r->left != NULL) { //a node with only one left child
                r = r->left;
            } else if (r->right != NULL) { //a node with only one right child
                r = r->right;
            } else {
                //case 3:  we delete a leaf node
                r = NULL; //
            }
            delete q; // deletes the old node that was removed and prevents memory leak
        }
    }
}

template<class T>
bool BinarySearchTree<T>::search(node<T> *r, T &item) {
    if (r == NULL) {
        return false;
    } else if (item < r->data) {
        search(r->left, item);
    } else if (item > r->data) {
        search(r->right, item);
    } else {
        //cout << r->data;
        return true;
    }
    return true;
}

template<class T>
void BinarySearchTree<T>::printPreOrder(node<T> *r) {
    if (r != NULL) {
        cout << r->data << endl;
        printPreOrder(r->left);
        printPreOrder(r->right);
    }
}

template<class T>
void BinarySearchTree<T>::printPostOrder(node<T> *r) {
    if (r != NULL) {
        printPostOrder(r->left);
        printPostOrder(r->right);
        cout << r->data << endl;
    }
}

template<class T>
void BinarySearchTree<T>::printInOrder(node<T> *r) {
    if (r != NULL) {
        printInOrder(r->left);
        cout << r->data << endl;
        printInOrder(r ->right);
    }
}

template<class T>
T BinarySearchTree<T>::findMax(node<T> *r, T &item) {
    if (r == NULL) {
        return item;
    } else if (r->right == NULL) {
        return r->data;
    } else {
        findMax(r->right, item);
    }
}

template<class T>
T BinarySearchTree<T>::findMin(node<T> *r, T &item) {
    if (r == NULL) {
        return item;
    } else if (r->left == NULL) {
        return r->data;
    } else {
        findMin(r->left, item);
    }
}

template<class T>
int BinarySearchTree<T>::max(int x, int y) {
    if (x > y)
        return x;
    return y;
}

#endif //ASSIGNMENT4_BINARYSEARCHTREE_H
