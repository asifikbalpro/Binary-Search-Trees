#include <iostream>
#include "src/BST.h"  /// including a .cpp file ????

using namespace std;


int main() {
    int TreeKeys[] = {50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80, 1};
    BST myTree;
    int input = 0;

    cout << "Printing the tree in order" << endl;
    cout << "Before Adding Number " << endl;

    myTree.PrintInOrder();

    for (int i = 0; i < 17; ++i) {
       myTree.AddLeaf(TreeKeys[i]);
    }
    cout << "Printing the tree in order" << endl;
    cout << "After Adding Number " << endl;

    myTree.PrintInOrder();

    myTree.PrintChildren(myTree.RetrunRootKey());

    cout << "the smallest value is in the tree " << myTree.FindSmallest() << endl;
    cout << "Enter a key value to delete. Enter -1 to stop to process" << endl;

    while(input != -1){
        cout << "delete Node: ";
        cin >> input;
        {
            if(input != -1){
                cout << endl;
                myTree.RemoveNode(input);
                myTree.PrintInOrder();
                cout << endl;
            }
        }
    }
    return 0;
}