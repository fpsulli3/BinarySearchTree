#pragma once

template <typename T>
struct Node {
    T data;
    Node<T>* left, * right;
    Node(T data) : data(data), left(nullptr), right(nullptr) {}
};

// Finds a Node in the Binary Tree that matches the 
// value of nodeData, and returns a pointer to it.
template <typename T>
Node<T>* findNode(Node<T>* tree, T nodeData) {
    return nullptr;
}

// Removes a Node from the Binary Tree.
// Returns the same tree back, modified.
template <typename T>
Node<T>* removeNode(Node<T>* tree, T nodeValue) {
    return nullptr;
}

// Adds a Node to the Binary Tree.
template <typename T>
void addNode(Node<T>* tree, T nodeData) {

}

// Returns true if the Binary Tree contains a node with 
// a value matching nodeData; otherwise, returns false.
template <typename T>
bool hasNode(Node<T>* tree, T nodeData) {
    return false;
}

// Gets the Level of the Node in the Binary Tree which has
// a value matching nodeData. If no such Node exists, returns -1
template <typename T>
int getNodeLevel(Node<T>* tree, T nodeData, int level = 0) {
    return level;
}

// Frees up the memory for an entire Binary Tree
template <typename T>
void deleteTree(Node<T>* tree) {
    if (tree == nullptr) {
        return;
    }

    deleteTree(tree->left);
    tree->left = nullptr;
    deleteTree(tree->right);
    tree->right = nullptr;

    delete tree;
}