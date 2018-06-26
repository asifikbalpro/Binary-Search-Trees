//
// Created by Ultron on 12-Mar-18.
//

#include <iostream>
#include "BST.h"

using namespace std;

BST::BST(){
    root = NULL; // use nullptr
//    root = nullptr; // use nullptr
}

BST::node* BST::CreateLeaf(int key){
    node* n = new node;
    n->key = key;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void BST::AddLeaf(int key){
    return AddLeafPrivate(key, root);
}
void BST::AddLeafPrivate(int key, node* Prt){
//    cout << "Entry AddLeafPrivate(int, node*) : line " << __LINE__ << endl; //
    if(root == NULL){
        root = CreateLeaf(key);
    } else if(key < Prt->key){
        if (Prt->left != NULL){
            AddLeafPrivate(key, Prt->left);
//            cout << "key" << Prt->key << endl;
        } else{
            Prt->left =CreateLeaf(key);
//            cout << "key" << Prt->key << endl;
        }
    }else if(key > Prt->key){
        if (Prt->right != NULL){
            AddLeafPrivate(key, Prt->right);
//            cout << "key" << Prt->key << endl;
        } else{
            Prt->right =CreateLeaf(key);
//            cout << "key" << Prt->key << endl;
        }
    } else{
        cout << "the Key " << key << "has Already been added to the tree" << endl;
    }

}

void BST::PrintInOrder() {
    PrintInOrderPrivate(root);
}

void BST::PrintInOrderPrivate(node *Prt) {
    if(root != NULL){
        if (Prt->key == NULL){
            PrintInOrderPrivate(Prt->left);
            cout << Prt->key << " ";
        }

        if(Prt->right != NULL){
            PrintInOrderPrivate(Prt->right);
            cout << Prt->key << " ";
        }
    } else{
        cout << "The Tree is empty" << endl;
    }
}

BST::node* BST::ReturnNode(int key){
    return ReturnNodePrivate(key, root);
}

BST::node* BST::ReturnNodePrivate(int key, node* Ptr){
    if (Ptr != NULL){
        if (Ptr->key == key){
            return Ptr;
        } else{
            if (key < Ptr->key){
                return ReturnNodePrivate(key, Ptr->left);
            } else{
                return ReturnNodePrivate(key, Ptr->right);
            }
        }
    } else{
        return NULL;
    }
}

int BST::RetrunRootKey(){
    if (root != NULL){
        return root->key;
    } else{
        return -1000;
    }
}

void BST::PrintChildren(int key){
    cout << "Entry PrintChildren" << endl;
    node* Ptr = ReturnNode(key);

    if(Ptr != NULL){
        cout << "Parent node = " << Ptr->key << endl;
        Ptr->left == NULL ?
        cout << "left child = Null" << endl:
        cout << "left child = " << Ptr->left->key << endl;

        Ptr->right == NULL ?
        cout << "left child = Null" << endl:
        cout << "left child = " << Ptr->right->key << endl;
    } else{
        cout << "Key" << key << "Is not in the tree" << endl;
    }
}

int BST::FindSmallest() {
    FindSmallestPrivate(root);
}
/// Find Smallest
int BST::FindSmallestPrivate(node* Ptr){
    if(root == NULL){
        cout << "the tree is empty" << endl;
        return -1000;
    } else{
        if (Ptr->left != NULL){
            return FindSmallestPrivate(Ptr->left);
        } else{
            return Ptr->key;
        }
    }
}

///

void BST::RemoveNode(int key){
    RemoveNodePrivate(key, root);
}

void BST::RemoveNodePrivate(int key, node* parent){
    if(root != NULL){
        if(root->key == key){
            RemoveRootMatch();
        } else{
            if(key< parent->key && parent->left != NULL){
                parent->left->key == key ?
                RemoveMatch(parent, parent->left, true):
                RemoveNodePrivate(key, parent->left);
            } else if(key > parent->key && parent->right != NULL){
                parent->right->key == key ?
                RemoveMatch(parent, parent->right, false):
                RemoveNodePrivate(key, parent->right);
            } else{
                cout << "The key" << key << "was not found on the tree" << endl;
            }
        }
    } else{
        cout << "The tree is empty" << endl;
    }
}

void BST::RemoveRootMatch(){
    if(root != NULL){
        node* delPtr = root;
        int rootkey = root->key;
        int smallestInRightSubtree;

        //case 0 - 0 children
        if(root->left == NULL && root->right == NULL){
            root = NULL;
            delete delPtr;
        }

        // case 1 - 1 child
        else if (root->left == NULL && root->right != NULL){
            root = root->right;
            delPtr->right = NULL;
            delete delPtr;
            cout << "the root node with key " << rootkey << " Was deleted";
            cout << "The new Root containes key"  << root->key << endl;

        }else if (root->left != NULL && root->right == NULL){
            root = root->left;
            delPtr->left = NULL;
            delete delPtr;
            cout << "the root node with key " << rootkey << "Was deleted";
            cout << "The new Root containes key"  << root->key << endl;

            // case 2 - 2 children
        } else{
            smallestInRightSubtree = FindSmallestPrivate(root->right);
            RemoveNodePrivate(smallestInRightSubtree, root);
            root->key = smallestInRightSubtree;
            cout << "the root key contianing key " << rootkey;
            cout << "was overwritten with key" << root->key <<endl;

        }
    } else{
        cout << "can not remove root. the tree is empty" << endl;
    }
}

void BST::RemoveMatch(node* parent, node* match, bool left){
    if(root != NULL){
        node* delPtr;
        int matchKey = match->key;
        int smallestInRightSubtree;

        // case 0 - 0 children
        if (match->left == NULL && match->right == NULL) {
            delPtr = match;
            left == true ? parent->left = NULL : parent->right = NULL;
            delete delPtr;
            cout << "the node contianing Key " << matchKey << " was removed" << endl;

            /// case 1 - 1 child
        }else if(match->left == NULL && match->right != NULL){
            left == true ? parent->left = match->right : parent->right = match->right;
            match->left = NULL;
            delPtr = match;
            delete delPtr;
            cout << "the node contianing Key " << matchKey << " was removed" << endl;

        }else if(match->left != NULL && match->right == NULL) {
            left == true ? parent->left = match->left : parent->right = match->left;
            match->left = NULL;
            delPtr = match;
            delete delPtr;
            cout << "the node contianing Key " << matchKey << " was removed" << endl;
            // case 2 - 2 children
        } else{
            smallestInRightSubtree = FindSmallestPrivate(match->right);
            RemoveNodePrivate(smallestInRightSubtree, match);
            match->key = smallestInRightSubtree;
        }
    } else{
        cout << "can not remove. the tree is empty" << endl;
    }
}

BST::~BST() {
    RemoveSubTree(root);
}

void BST::RemoveSubTree(node *Ptr) {
    if(Ptr != NULL){
        if(Ptr->left != NULL){
            RemoveSubTree(Ptr->left);
        }
        if(Ptr->right != NULL){
            RemoveSubTree(Ptr->right);
        }
        cout << "Deleteing the node contianing Key" << Ptr->key << endl;
        delete Ptr;
    }
}






