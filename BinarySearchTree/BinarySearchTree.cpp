// BinarySearchTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Timer.h"

// BINARY TREE IMPLEMENTATION////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

template <typename T>
struct Node {
    T data;
    Node<T> *left, *right;
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

// MAIN ////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

// Pre-declaring some functions that main needs, which are defined below main
bool runFunctionalTests();
void runPerformanceTest(int numElements);

int main() {
    // First, run the functional tests to make sure that 
    // the binary tree implementation works.
    bool functionalTestsPass = runFunctionalTests();

    std::cout << "" << std::endl; // blank line

    if (functionalTestsPass) {
        runPerformanceTest(100);
        runPerformanceTest(1000);
        runPerformanceTest(10000);
        runPerformanceTest(100000);
    }
    else {
        std::cout << "Skipping performance tests because there were errors in the functional tests.";
    }

    std::cout << "" << std::endl; // blank line

    return functionalTestsPass ? 0 : 1;
}

// TESTS ////////////////////////////////////////////////////////////////
// Everything below this comment is a Test function that is used to    //
// test your implementation of the binary tree.                        //
/////////////////////////////////////////////////////////////////////////

template <typename T>
void shuffleArray(T* array, int count) {
    // Count down to 1 starting from count
    for (int i = count; i > 0; i--) {
        // pick a random index to shuffle with;
        int shuffleIndex = rand() % i;
        // swap with that index
        T temp = array[shuffleIndex];
        array[shuffleIndex] = array[i - 1];
        array[i - 1] = temp;
    }
}

bool assertLeaf(const char* tag, Node<char>* node, char expectedData) {
    if (node == nullptr) {
        std::cout << tag << " FAILED: Expected leaf node is nullptr" << std::endl;
        return false;
    }

    if (node->data != expectedData) {
        std::cout << tag << " FAILED: Expected leaf node data is '" << expectedData << "' but was '" << node->data << "'" << std::endl;
        return false;
    }

    if (node->left != nullptr) {
        std::cout << tag << " FAILED: Expected leaf node has left node" << std::endl;
        return false;
    }

    if (node->right != nullptr) {
        std::cout << tag << " FAILED: Expected leaf node has right node" << std::endl;
        return false;
    }

    return true;
}

bool assertNodeWithLeftChildOnly(const char* tag, Node<char>* node, char expectedData) {
    if (node == nullptr) {
        std::cout << tag << " FAILED: node is nullptr" << std::endl;
        return false;
    }

    if (node->data != expectedData) {
        std::cout << tag << " FAILED: Expected node data is '" << expectedData << "' but was '" << node->data << "'" << std::endl;
        return false;
    }

    if (node->left == nullptr) {
        std::cout << tag << " FAILED: Expected node '" << expectedData << "' to have a left node, but left node is nullptr" << std::endl;
        return false;
    }

    if (node->right != nullptr) {
        std::cout << tag << " FAILED: Expected node '" << expectedData << "' to have no right node, but right node is '" << 
            node->right->data << "'" << std::endl;
        return false;
    }

    return true;
}

bool assertNodeWithRightChildOnly(const char* tag, Node<char>* node, char expectedData) {
    if (node == nullptr) {
        std::cout << tag << " FAILED: node is nullptr" << std::endl;
        return false;
    }

    if (node->data != expectedData) {
        std::cout << tag << " FAILED: Expected node data is '" << expectedData << "' but was '" << node->data << "'" << std::endl;
        return false;
    }

    if (node->right == nullptr) {
        std::cout << tag << " FAILED: Expected node '" << expectedData << "' to have a right node, but right node is nullptr" << std::endl;
        return false;
    }

    if (node->left != nullptr) {
        std::cout << tag << " FAILED: Expected node '" << expectedData << "' to have no left node, but left node is '" << 
            node->left->data << "'" << std::endl;
        return false;
    }

    return true;
}

bool assertNodeWithTwoChildren(const char* tag, Node<char>* node, char expectedData) {
    if (node == nullptr) {
        std::cout << tag << " FAILED: node is nullptr" << std::endl;
        return false;
    }

    if (node->data != expectedData) {
        std::cout << tag << " FAILED: Expected node data is '" << expectedData << "' but was '" << node->data << "'" << std::endl;
        return false;
    }

    if (node->left == nullptr) {
        std::cout << tag << " FAILED: Expected node '" << expectedData << "' to have a left node, but left node is nullptr" << std::endl;
        return false;
    }

    if (node->right == nullptr) {
        std::cout << tag << " FAILED: Expected node '" << expectedData << "' to have a right node, but right node is nullptr" << std::endl;
        return false;
    }
}

bool testAddNode() {
    // Given an existing binary tree
    // 
    //        t
    //       / \
    //      /   \
    //     m     z
    //    /     / 
    //   h     w
    //  / \     \
    // d   j     x

    Node<char>* root = new Node<char>('t');

    Node<char>* m = new Node<char>('m');
    Node<char>* z = new Node<char>('z');

    Node<char>* h = new Node<char>('h');
    Node<char>* w = new Node<char>('w');

    Node<char>* d = new Node<char>('d');
    Node<char>* j = new Node<char>('j');
    Node<char>* x = new Node<char>('x');

    root->left = m;
    root->right = z;

    m->left = h;
    h->left = d;
    h->right = j;

    z->left = w;
    w->right = x;

    // When we add 'u' to it
    addNode(root, 'u');

    // Then expect the tree to contain 'u' to the left of 'w'
    bool success = w->left != nullptr && w->left->data == 'u';

    if (success) {
        std::cout << "testAddNode PASSED" << std::endl;
    }
    else {
        std::cout << "testAddNode FAILED: Node 'u' not added at the expected place." << std::endl;
    }

    deleteTree(root);

    return success;
}

bool testRemoveLeaf() {
    // Given an existing binary tree
    // 
    //        t
    //       / \
    //      /   \
    //     m     z
    //    /     / 
    //   h     w
    //  / \     \
    // d   j     x

    Node<char>* root = new Node<char>('t');

    Node<char>* m = new Node<char>('m');
    Node<char>* z = new Node<char>('z');

    Node<char>* h = new Node<char>('h');
    Node<char>* w = new Node<char>('w');

    Node<char>* d = new Node<char>('d');
    Node<char>* j = new Node<char>('j');
    Node<char>* x = new Node<char>('x');

    root->left = m;
    root->right = z;

    m->left = h;
    h->left = d;
    h->right = j;

    z->left = w;
    w->right = x;

    // When we remove 'j' from it
    Node<char>* result = removeNode(root, 'j');

    // We should find all nodes in the tree except 'j'
    // 
    //        t
    //       / \
    //      /   \
    //     m     z
    //    /     / 
    //   h     w
    //  /       \
    // d         x

    bool success = true;
    success = success && assertNodeWithTwoChildren("testRemoveLeaf", result, 't');
    success = success && assertNodeWithLeftChildOnly("testRemoveLeaf", result->left, 'm');
    success = success && assertNodeWithLeftChildOnly("testRemoveLeaf", result->left->left, 'h');
    success = success && assertLeaf("testRemoveLeaf", result->left->left->left, 'd');
    success = success && assertNodeWithLeftChildOnly("testRemoveLeaf", result->right, 'z');
    success = success && assertNodeWithRightChildOnly("testRemoveLeaf", result->right->left, 'w');
    success = success && assertLeaf("testRemoveLeaf", result->right->left->right, 'x');

    deleteTree(root);

    if (success) {
        std::cout << "testRemoveLeaf PASSED" << std::endl;
    }

    return true;
}

bool testRemoveNodeWithOneChild() {
    // Given an existing binary tree
    // 
    //        t
    //       / \
    //      /   \
    //     m     z
    //    /     / 
    //   h     w
    //  / \     \
    // d   j     x

    Node<char>* root = new Node<char>('t');

    Node<char>* m = new Node<char>('m');
    Node<char>* z = new Node<char>('z');

    Node<char>* h = new Node<char>('h');
    Node<char>* w = new Node<char>('w');

    Node<char>* d = new Node<char>('d');
    Node<char>* j = new Node<char>('j');
    Node<char>* x = new Node<char>('x');

    root->left = m;
    root->right = z;

    m->left = h;
    h->left = d;
    h->right = j;

    z->left = w;
    w->right = x;

    // When we remove 'w'
    Node<char>* result = removeNode(root, 'w');

    // Then the tree is intact, but now 'w' is gone 
    //        t
    //       / \
    //      /   \
    //     m     z
    //    /     / 
    //   h     x
    //  / \     
    // d   j

    bool success = true;
    success = success && assertNodeWithTwoChildren("testRemoveNodeWithOneChild", result, 't');
    success = success && assertNodeWithLeftChildOnly("testRemoveNodeWithOneChild", result->left, 'm');
    success = success && assertNodeWithTwoChildren("testRemoveNodeWithOneChild", result->left->left, 'h');
    success = success && assertLeaf("testRemoveNodeWithOneChild", result->left->left->left, 'd');
    success = success && assertLeaf("testRemoveNodeWithOneChild", result->left->left->right, 'j');
    success = success && assertNodeWithLeftChildOnly("testRemoveNodeWithOneChild", result->right, 'z');
    success = success && assertLeaf("testRemoveNodeWithOneChild", result->right->left, 'x');

    deleteTree(result);

    if (success) {
        std::cout << "testRemoveNodeWithOneChild PASSED" << std::endl;
    }

    return true;
}

bool testRemoveNodeWithTwoChildren() {
    // Given an existing binary tree
    // 
    //        t
    //       / \
    //      /   \
    //     m     z
    //    /     / 
    //   h     w
    //  / \     \
    // d   j     x

    Node<char>* root = new Node<char>('t');

    Node<char>* m = new Node<char>('m');
    Node<char>* z = new Node<char>('z');

    Node<char>* h = new Node<char>('h');
    Node<char>* w = new Node<char>('w');

    Node<char>* d = new Node<char>('d');
    Node<char>* j = new Node<char>('j');
    Node<char>* x = new Node<char>('x');

    root->left = m;
    root->right = z;

    m->left = h;
    h->left = d;
    h->right = j;

    z->left = w;
    w->right = x;

    // When we remove 'h'
    Node<char>* result = removeNode(root, 'h');

    // Then we will respect 'h' to be gone and 'j' replaces 'h'
    // 
    //        t
    //       / \
    //      /   \
    //     m     z
    //    /     / 
    //   j     w
    //  /       \
    // d         x


    bool success = assertNodeWithTwoChildren("testRemoveNodeWithTwoChildren", result, 't');
    success = success && assertNodeWithLeftChildOnly("testRemoveNodeWithTwoChildren", result->left, 'm');
    success = success && assertNodeWithLeftChildOnly("testRemoveNodeWithTwoChildren", result->left->left, 'j');
    success = success && assertLeaf("testRemoveNodeWithTwoChildren", result->left->left->left, 'd');
    success = success && assertNodeWithLeftChildOnly("testRemoveNodeWithTwoChildren", result->right, 'z');
    success = success && assertNodeWithRightChildOnly("testRemoveNodeWithTwoChildren", result->right->left, 'w');
    success = success && assertLeaf("testRemoveNodeWithTwoChildren", result->right->left->right, 'x');

    deleteTree(result);

    if (success) {
        std::cout << "testRemoveNodeWithTwoChildren PASSED" << std::endl;
    }

    return success;
}

bool testRemoveRootNode() {
    // Given an existing binary tree
    // 
    //        t
    //       / \
    //      /   \
    //     m     z
    //    /     / 
    //   h     w
    //  / \     \
    // d   j     x

    Node<char>* root = new Node<char>('t');

    Node<char>* m = new Node<char>('m');
    Node<char>* z = new Node<char>('z');

    Node<char>* h = new Node<char>('h');
    Node<char>* w = new Node<char>('w');

    Node<char>* d = new Node<char>('d');
    Node<char>* j = new Node<char>('j');
    Node<char>* x = new Node<char>('x');

    root->left = m;
    root->right = z;

    m->left = h;
    h->left = d;
    h->right = j;

    z->left = w;
    w->right = x;

    // When we remove 't'
    Node<char>* result = removeNode(root, 't');

    // Then we will respect 't' to be gone
    // 'w' will be lifted to the root, and
    // 'x' will take the place of 'w'
    // 
    //        w
    //       / \
    //      /   \
    //     m     z
    //    /     / 
    //   h     x
    //  / \      
    // d   j     

    bool success = assertNodeWithTwoChildren("testRemoveRootNode", result, 'w');
    success = success && assertNodeWithLeftChildOnly("testRemoveRootNode", result->left, 'm');
    success = success && assertNodeWithTwoChildren("testRemoveRootNode", result->left->left, 'h');
    success = success && assertLeaf("testRemoveRootNode", result->left->left->left, 'd');
    success = success && assertLeaf("testRemoveRootNode", result->left->left->right, 'j');
    success = success && assertNodeWithLeftChildOnly("testRemoveRootNode", result->right, 'z');
    success = success && assertLeaf("testRemoveRootNode", result->right->left, 'x');

    deleteTree(result);

    if (success) {
        std::cout << "testRemoveRootNode PASSED" << std::endl;
    }

    return success;
}

bool testFindNode() {
    // Given an existing binary tree
    // 
    //        t
    //       / \
    //      /   \
    //     m     z
    //    /     / 
    //   h     w
    //  / \     \
    // d   j     x

    Node<char>* root = new Node<char>('t');

    Node<char>* m = new Node<char>('m');
    Node<char>* z = new Node<char>('z');

    Node<char>* h = new Node<char>('h');
    Node<char>* w = new Node<char>('w');

    Node<char>* d = new Node<char>('d');
    Node<char>* j = new Node<char>('j');
    Node<char>* x = new Node<char>('x');

    root->left = m;
    root->right = z;

    m->left = h;
    h->left = d;
    h->right = j;

    z->left = w;
    w->right = x;

    // Make sure we can find every node.
    const char* allNodesArray = "dhjmtwxz";
    const unsigned int length = strlen(allNodesArray);
    bool allNodesFound(true); // assume true until proven otherwise
    for (int i = 0; i < length; i++) {
        char nodeToFind = allNodesArray[i];
        Node<char>* node = findNode(root, nodeToFind);
        if (node == nullptr) {
            // uh oh
            std::cout << "testFindNode error: Cannot find node: " << nodeToFind << std::endl;
            allNodesFound = false;
        }
    }

    // Test some nodes that are NOT in the list 
    // and make sure we cannot find them.
    const char* badNodes = "abcefgiklnopqrsuvy";
    const unsigned int badLength = strlen(allNodesArray);
    bool badNodeFound(false); // assume false until proven otherwise
    for (int i = 0; i < badLength; i++) {
        char nodeToFind = badNodes[i];
        Node<char>* node = findNode(root, nodeToFind);
        if (node != nullptr) {
            // uh oh
            std::cout << "testFindNode error: Found bad node: " << nodeToFind << std::endl;
            badNodeFound = true;
        }
    }

    bool success = allNodesFound && !badNodeFound;

    if (success) {
        std::cout << "testFindNode PASSED" << std::endl;
    }

    if (!allNodesFound) {
        std::cout << "testFindNode FAILED: Not all nodes were found." << std::endl;
    }

    if (badNodeFound) {
        std::cout << "testFindNode FAILED: One or more bad nodes were found." << std::endl;
    }

    deleteTree(root);

    return success;
}

bool testGetNodeLevel() {
    // Given an existing binary tree
    // 
    //        t
    //       / \
    //      /   \
    //     m     z
    //    /     / 
    //   h     w
    //  / \     \
    // d   j     x

    Node<char>* root = new Node<char>('t');

    Node<char>* m = new Node<char>('m');
    Node<char>* z = new Node<char>('z');

    Node<char>* h = new Node<char>('h');
    Node<char>* w = new Node<char>('w');

    Node<char>* d = new Node<char>('d');
    Node<char>* j = new Node<char>('j');
    Node<char>* x = new Node<char>('x');

    root->left = m;
    root->right = z;

    m->left = h;
    h->left = d;
    h->right = j;

    z->left = w;
    w->right = x;

    // Check to make sure that getNodeLevel returns the 
    // correct level for each node in the tree, and returns -1 
    // for some nodes that aren't in the tree
    struct Pair {
        char value;
        int expectedLevel;
    };

    const int NUM_TEST_NODES = 10;
    const Pair expectedLevels[NUM_TEST_NODES] = {
        {'t', 0},
        {'m', 1},
        {'z', 1},
        {'h', 2},
        {'w', 2},
        {'d', 3},
        {'j', 3},
        {'x', 3},
        {'a', -1},
        {'b', -1},
    };

    bool success = true; // assume success until proven otherwise
    for (int i = 0; i < NUM_TEST_NODES; i++) {
        auto& pair = expectedLevels[i];
        int level = getNodeLevel(root, pair.value);
        if (level != pair.expectedLevel) {
            success = false;
            std::cout << "testGetNodeLevel error: getNodeLevel returned the wrong level. Expected: " << pair.expectedLevel << ", Actual: " << level << std::endl;
        }
    }

    if (success) {
        std::cout << "testGetNodeLevel PASSED" << std::endl;
    }
    else {
        std::cout << "testGetNodeLevel FAILED: One or more nodes returned the wrong level." << std::endl;
    }

    deleteTree(root);

    return success;    
}

bool runFunctionalTests() {
 
    bool success = testAddNode();
    success = testFindNode() && success;
    success = testGetNodeLevel() && success;
    success = testRemoveLeaf() && success;
    success = testRemoveNodeWithOneChild() && success;
    success = testRemoveNodeWithTwoChildren() && success;
    success = testRemoveRootNode() && success;

    return success;
}

void runPerformanceTest(int numElements) {
    // First we're going to create an integer array that has 
    // a size of numElements, and the values of that array will 
    // go in order from 0 to numElements-1.
    int* bigArray = new int[numElements];
    for (int i = 0; i < numElements; i++) {
        bigArray[i] = i;
    }

    // Now we're going to shuffle the array so that the 
    // numbers are out of order.
    shuffleArray(bigArray, numElements);

    // Now we're going to make a binary tree using the same 
    // exact values that are in the shuffled array.
    Node<int> *bigBinaryTree = new Node<int>(bigArray[0]);
    for (int i = 0; i < numElements; i++) {
        addNode(bigBinaryTree, bigArray[i]);
    }

    // So now we have:
    // 1. An array with all values 0 through (numElements-1), shuffled
    // 2. A binary tree with those same values in it.
    // And we can compare how long it takes to search for values in each
    // of these data structures. For the array, we do a basic linear search 
    // which should be O(N). For the binary tree, we are doing a binary 
    // search, which is much quicker O(log N).

    // Find every value in the array using a linear search
    Timer timer;
    timer.start();
    for (int i = 0; i < numElements; i++) {
        int valueToFind = i;
        int foundIndex = -1;
        for (int j = 0; j < numElements; j++) {
            int arrayValue = bigArray[j];
            if (arrayValue == valueToFind) {
                foundIndex = j;
                break; // we can stop searching the array for valueToFind
            }
        }
        if (foundIndex == -1) {
            // We didn't find the value (should never happen, but always 
            // good to add error-checking code to check your assumptions).
            std::cout << "Error! Value not found in array: " << valueToFind << std::endl;
        }
    }
    unsigned long linearSearchTime = timer.getTimeMicroseconds();
    std::cout << "Linear search time for " << numElements << " elements: " << linearSearchTime << " microseconds" << std::endl;

    // Find every value in the binary tree
    timer.start();
    for (int i = 0; i < numElements; i++) {
        int valueToFind = i;
        Node<int>* foundNode = findNode(bigBinaryTree, valueToFind);
        if (foundNode == nullptr) {
            std::cout << "Error! Value not found in binary tree: " << valueToFind << std::endl;
        }
    }
    unsigned long binarySearchTime = timer.getTimeMicroseconds();
    std::cout << "Binary search time for " << numElements << " elements: " << binarySearchTime << " microseconds" << std::endl;

    double multiplier = (double)linearSearchTime / (double)binarySearchTime;
    std::cout << "The linear search took " << multiplier << " times longer than the binary search\n" << std::endl;

    // clean up
    delete[] bigArray;
    deleteTree(bigBinaryTree);
}