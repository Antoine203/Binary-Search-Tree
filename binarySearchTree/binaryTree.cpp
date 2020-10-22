//
//  binaryTree.cpp
//  binarySearchTree
//
//  Created by Antoine Jermaine Smith Jr. on 10/21/20.
//

#include "binaryTree.hpp"
#include <iostream>
using namespace std;


template <class ItemType>
TreeType<ItemType>:: TreeType()
{
    root = NULL;
}

template <class ItemType>
TreeType<ItemType>:: ~TreeType()
{
    destroy(root);
}

template <class ItemType>
void TreeType<ItemType>::destroy(TreeNode<ItemType> *&tree)
{
    if(tree != NULL)
    {
        destroy(tree->left);
        destroy(tree->right);
        delete tree;
    }
}

template <class ItemType>
TreeType<ItemType>::TreeType(const TreeType& origTree)
{
    copyTree(root, origTree);
}

template <class ItemType>
void TreeType<ItemType>:: copyTree(TreeNode<ItemType> *&copy, const TreeNode<ItemType> *origTree)
{
    if (origTree == NULL)
    {
        copy == NULL;
    }
    else
    {
        copy = new TreeNode<ItemType>; // Creating new node
        copy->info = origTree->info;
        
        copyTree(copy->left, origTree->left); // Copying the left side of the original tree
        copyTree(copy->right, origTree->right); // Copying the right side of the original tree
    }
}

template <class ItemType>
void TreeType<ItemType>:: operator=(const TreeType<ItemType> &origTree)
{
    if (&origTree == this)
    {
        return;
    }
    destroy(root);
    copyTree(root, origTree.root);
}

template <class ItemType>
inline bool TreeType<ItemType>::isFull() const // Inline means during the compile time
{
    TreeNode<ItemType>* location;
    try
    {
        location = new TreeNode<ItemType>;
        delete location;
        return false;
    }
    catch (bad_alloc)
    {
        return true;
    }
}

template <class ItemType>
inline bool TreeType<ItemType>::isEmpty() const
{
    return (root == NULL);
}

template <class ItemType>
void TreeType<ItemType>:: makeEmpty()
{
    destroy(root);
    root = NULL;
}

template <class ItemType>
inline int TreeType<ItemType>:: getLength() const
{
    return countNodes(root);
}

template <class ItemType>
int TreeType<ItemType>:: countNodes(TreeNode<ItemType> *&tree)
{
    if (tree == NULL)
        return 0;
    else
        return (countNodes(tree->left) + countNodes(tree->right) + 1); //Using recursion to count both sides of the tree and  +1 for counting the root node
}

template <class ItemType>
ItemType TreeType<ItemType>:: getItem(ItemType item, bool &found)
{
    retrieve(root, item, found);
    return item;
}

template <class ItemType>
void TreeType<ItemType>::retrieve(TreeNode<ItemType> *&tree, ItemType &item, bool &found)
{
    if (tree == NULL)
    {
        found = false;
    }
    else if (item < tree->info)
    {
        retrieve(tree->left, item, found);
    }
    else if(item > tree->info)
    {
        retrieve(tree->right, item, found);
    }
    else
    {
        item = tree->info;
        found = true;
    }
}

template <class ItemType>
void TreeType<ItemType>::addItem(ItemType item)
{
    insert(root, item);
}

template <class ItemType>
void TreeType<ItemType>:: insert(TreeNode<ItemType>*& tree, ItemType & item)
{
    if (tree == NULL)
    {
        tree = new TreeNode<ItemType>;
        tree->right = NULL;
        tree->left = NULL;
        tree->info = item;
    }
    else if (item < tree->info)
    {
        insert(tree->left, item);
    }
    else if(item > tree->info)
    {
        insert(tree->right, item);
    }
}

template <class ItemType>
void TreeType<ItemType>::deleteItem(ItemType item)
{
    Delete(root, item);
}

template <class ItemType>
void TreeType<ItemType>::Delete(TreeNode<ItemType> *&tree, ItemType item)
{
    if(item < tree->info)
    {
        Delete(tree->left, item);
    }
    else if(item > tree->info)
    {
        Delete(tree->right, item);
    }
    else
        deleteNode(tree);
}

template <class ItemType>
void TreeType<ItemType>:: deleteNode(TreeNode<ItemType> *&tree)
{
    ItemType data;
    TreeNode<ItemType> * tempPtr;
    tempPtr = tree;
    if (tree->left == NULL)
    {
        tree = tree->right;
        delete tempPtr;
    }
    else if(tree->right == NULL)
    {
        tree = tree->left;
        delete tempPtr;
    }
    else
    {
        getPredeccessor(tree->left, data);
        tree->info = data;
        Delete(tree->left, data); // Delete predecessor
    }
}

template <class ItemType>
void TreeType<ItemType>:: getPredeccessor(TreeNode<ItemType> *&tree, ItemType& item)
{
    while (tree->right != NULL)
    {
        tree = tree->right;
    }
    item = tree->info;
}

template <class ItemType>
void TreeType<ItemType>:: printTree()
{
    printNode(root);
    cout<<endl;
}

template <class ItemType>
void TreeType<ItemType>:: printNode(TreeNode<ItemType> *&tree)
{
    if (tree == root)
    {
        cout<<"Root: "<< tree->info<<endl;
    }
    if (tree != NULL)
    {
        printNode(tree->left);
        cout<<tree->info<<" ";
        printNode(tree->right);
    }
}
