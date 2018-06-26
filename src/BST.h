//
// Created by Ultron on 12-Mar-18.
//

#ifndef BINARY_SEARCH_TREE_BST_H
#define BINARY_SEARCH_TREE_BST_H

/// BST is Binary Search Trees
/// class
class BST {
private:
    struct node{
        int key;
        node* left;
        node* right;
    };
    node* root;
    void AddLeafPrivate(int key, node* Prt);
    void PrintInOrderPrivate(node* Prt);
    node* ReturnNodePrivate(int key, node* Prt);
    int FindSmallestPrivate(node* Ptr);
    void RemoveNodePrivate(int key, node* parent);
    void RemoveRootMatch();
    void RemoveMatch(node* parent, node* match, bool left);
    void RemoveSubTree(node* Ptr);

public:
    BST();
    ~BST();
    node* CreateLeaf(int key);
    node* ReturnNode(int key);
    void AddLeaf(int key);
    void PrintInOrder();
    int RetrunRootKey();
    void PrintChildren(int key);
    int FindSmallest();
    void RemoveNode(int key);

};

#endif //BINARY_SEARCH_TREE_BST_H
