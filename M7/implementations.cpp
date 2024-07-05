#include "data.h"
#include <iostream>

using namespace std;

    Node::Node(int key) {
        this->key = key;
        this->left = NULL;
        this->right = NULL;
    }

    void BST::insertNode(Node*& node, int key) {
        if (node == NULL) {
            node = new Node(key);
            return;
        }

        if (key < node->key) {
            insertNode(node->left, key);
        } else if (key > node->key) {
            insertNode(node->right, key);
        }
    }

    Node* BST::searchNode(Node* node, int key) {
        if (node == NULL || node->key == key) {
            return node;
        }

        if (key < node->key) {
            return searchNode(node->left, key);
        } else {
            return searchNode(node->right, key);
        }
    }

    Node* BST::findMin(Node* node) {
        while (node->left != NULL) {
            node = node->left;
        }

        return node;
    }

    Node* BST::deleteNode(Node*& node, int key) {
        if (node == NULL) {
            return node;
        }

        if (key < node->key) {
            node->left = deleteNode(node->left, key);
        } else if (key > node->key) {
            node->right = deleteNode(node->right, key);
        } else {
            if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = findMin(node->right);
            node->key = temp->key;
            node->right = deleteNode(node->right, temp->key);
        }

        return node;
    }

    void BST::inorderTraversal(Node* node) {
        if (node == NULL) {
            return;
        }

        inorderTraversal(node->left);
        cout << node->key << " ";
        inorderTraversal(node->right);
    }

    void BST::preorderTraversal(Node* node) {
        if (node == NULL) {
            return;
        }

        cout << node->key << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

    void BST::postorderTraversal(Node* node) {
        if (node == NULL) {
            return;
        }

        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->key << " ";
    }

    void BST::displayBST(Node* node, int space) {
        if (node == NULL) {
            return;
        }

        space += 5;
        displayBST(node->right, space);

        cout << endl;
        for (int i = 5; i < space; i++) {
            cout << " ";
        }
        cout << node->key << "\n";

        displayBST(node->left, space);
    }

    BST::BST() {
        this->root = NULL;
    }

    void BST::insert(int key) {
        insertNode(this->root, key);
    }

    Node* BST::search(int key) {
        return searchNode(this->root, key);
    }

    void BST::remove(int key) {
        deleteNode(this->root, key);
    }

    void BST::inorder() {
        inorderTraversal(this->root);
        cout << endl;
    }

    void BST::preorder() {
        preorderTraversal(this->root);
        cout << endl;
    }

    void BST::postorder() {
        postorderTraversal(this->root);
        cout << endl;
    }

    void BST::display() {
        displayBST(this->root, 0);
    }

