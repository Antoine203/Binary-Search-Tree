//
//  binaryTree.hpp
//  binarySearchTree
//
//  Created by Antoine Jermaine Smith Jr. on 10/21/20.
//

#ifndef binaryTree_hpp
#define binaryTree_hpp

#include <stdio.h>
#include <iostream>
using namespace std;


template <class ItemType>
struct TreeNode
{
    ItemType info; // Information
    TreeNode * left; // Points to left node
    TreeNode * right; // Points to right node
};

template <class ItemType>
class TreeType
{
private:
    TreeNode<ItemType> * root; // Root of the tree
    void destroy(TreeNode<ItemType> *& tree); // *& means you are pointing to that address and manipulating the original data
    void copyTree(TreeNode<ItemType> *& copy, const TreeNode<ItemType> * origTree);
    void deleteNode(TreeNode<ItemType> *& tree); // deleting a node in the tree
    void printNode(TreeNode<ItemType> *& tree); //
    void Delete(TreeNode<ItemType> *& tree, ItemType item);
    int countNodes(TreeNode<ItemType> *& tree);
    void getPredeccessor(TreeNode<ItemType> *& tree, ItemType& item);
    void retrieve(TreeNode<ItemType> *& tree, ItemType& item, bool& found);
    void insert(TreeNode<ItemType>*& tree, ItemType & item );
    
public:
    TreeType(); //Constructor
    ~TreeType(); //Deconstructor
    TreeType(const TreeType& origTree); //Copy constructor
    void operator = (const TreeType & originalTree); // Assignment operator
    
    void makeEmpty(); //Makes the tree empty
    bool isEmpty() const; //Check to see if the tree is empty or not
    bool isFull() const; // Check to see if the tree is full
    
    int getLength() const; // Total number of nodes in the tree
    
    ItemType getItem(ItemType item, bool & found); //Grabbing an item and returning true or false if it is found
    
    void addItem(ItemType item); // Adding an item to the tree
    void deleteItem(ItemType item); // Deleting an item from the tree
    void printTree(); //Print items from the tree
};
#endif /* binaryTree_hpp */
