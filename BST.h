#ifndef _BST_H_
#define _BST_H_

#include <iostream>

// Binary Search Tree (BST) implementation
class BST {
private:
    // Node structure representing a single element in the BST
    struct node {
        int value;              // Value of the node
        node *Lchild;           // Pointer to the left child
        node *Rchild;           // Pointer to the right child

        node(int n) : value(n), Lchild(nullptr), Rchild(nullptr) {}
    };

    node *root;                 // Root of the BST
    static int sumOfTree;       // Static variable to store the sum of leaf nodes

    // Private helper methods
    node *insert(node *parent, int n);         // Insert a node into the tree
    void preOrder(node *nd);                   // Pre-order traversal
    void inOrder(node *nd);                    // In-order traversal
    void postOrder(node *nd);                  // Post-order traversal
    void sumTree(node *nd);                    // Sum the values of all leaf nodes
    int treeHeight(node *nd, int h);           // Calculate the height of the tree
    bool searchIf(node *nd, int n);            // Search for a value in the tree
    void closestCommonAncestor(node *nd, int n, int m); // Find the closest common ancestor of two values
    node *deleteNode(node *nd, int n);         // Delete a node from the tree
    void burnTree(node *nd);                   // Delete all nodes in the tree
    int min(node *nd);                         // Find the minimum value in the tree
    int max(node *nd);                         // Find the maximum value in the tree

public:
    // Constructors
    BST();                                      // Default constructor
    BST(int n);                                 // Constructor with root value

    // Public interface methods
    void insert(int n);                         // Insert a value into the tree
    void printTree();                           // Print tree elements in various orders
    int sumTree();                              // Calculate and return the sum of leaf nodes
    int treeHeight();                           // Calculate and return the height of the tree
    void printRoot();                           // Print the value of the root node
    int min();                                  // Return the minimum value in the tree
    int max();                                  // Return the maximum value in the tree
    void closestCommonAncestor(int n, int m);  // Find and print the closest common ancestor of two values
    bool deleteNode(int n);                     // Delete a value from the tree

    // Destructor
    ~BST();                                    // Free all resources used by the tree
};

#endif