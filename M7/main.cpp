#include "data.h"
#include <iostream>

using namespace std;

int main() {
    BST bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    cout << "Inorder traversal: ";
    bst.inorder();

    cout << "Preorder traversal: ";
    bst.preorder();

    cout << "Postorder traversal: ";
    bst.postorder();

    cout << "Displaying BST:\n";
    bst.display();

    Node* searchedNode = bst.search(60);
    if (searchedNode == NULL) {
        cout << "Node not found in the BST\n";
    } else {
        cout << "Node found in the BST: " << searchedNode->key << endl;
    }
    
    bst.remove(30);

    cout << "Inorder traversal after deleting a node: ";
    bst.inorder();

    return 0;
}

