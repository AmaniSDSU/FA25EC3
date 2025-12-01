//
// Created by Manju Muralidharan on 11/22/25.
//

#ifndef FA25EC3_TREE_H
#define FA25EC3_TREE_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
   TEMPLATE TREE CLASS
   Multiple parents may point to the same child.
   Students must manage storage, pointers, and dynamic allocation.

   Requirements:
   1. Templated Tree class.
   2. Nodes stored dynamically.
   3. Each node has:
      - id
      - data
      - vector of children pointers
   4. Students must prevent memory leaks.
   5. Students must create createRoot, addNode, findNode, print functions, etc.

   DO NOT IMPLEMENT ANYTHING HERE.
   Only placeholders and TODO comments.
*/


template <typename U>
class Node {
public:
    string id;
    U data;
    vector<Node<U>*> children;

    // TODO: Write constructor
    Node(const string &nodeID, const U &value) {
        id = nodeID;
        data = value;
    };
};

template <typename T>
class Tree {
private:
    Node<T>* root;

public:
    Tree() {
        root = nullptr;
    };
    // TODO: Initialize root pointer to nullptr

    void createRoot(const string &id, const T &value) {
        Node<T> *node = new Node<T>(id, value);
        root = node;
    }
    // TODO: Allocate memory, assign id, assign data, set as root

    void addNode(const string &parentID, const string &childID, const T &value) {
        Node<T> *parent = findNode(parentID);
        if (findNode(childID)) {
            parent->children.push_back(findNode(childID));
            return;
        }
        Node<T> *child = new Node<T>(childID, value);
        parent->children.push_back(child);
    }
    // TODO: Find parent, create child, link parent to child
    // TODO: Support repeated children under multiple parents

    Node<T>* findNode(const string &id) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->id == id) {
            return root;
        }

        for (Node<T> *child : root->children) {
            Node<T> *node = findNode(child->id);
            if (node != nullptr) {
                return node;
            }
        }
        return nullptr;
    };
    // TODO: Use DFS or BFS to search tree

    void printAll() {
        while (root != nullptr) {
            cout << "Node " + root->id + ": " + root->data << "\n" << endl;
            root = root->children[0];
        }

    };
    // TODO: Print entire structure in readable form

    ~Tree() {
        if (root != nullptr) {
            for (int i = 0; i < root->children.size(); i++) {
                delete root->children[i];
            }
        }
        delete root;
        root = nullptr;
    }
    // TODO: Free all allocated memory
};

#endif //FA25EC3_TREE_H
