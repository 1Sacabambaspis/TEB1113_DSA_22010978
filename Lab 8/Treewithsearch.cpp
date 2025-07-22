#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int v) {
        value = v;
        left = nullptr;
        right = nullptr;
    }
};

class Tree {
public:
    Node* root;

    Tree() {
        root = nullptr;
    }

    void insert(int value) {
        root = insert_rec(root, value);
    }

    Node* insert_rec(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->value) {
            node->left = insert_rec(node->left, value);
        } else if (value > node->value) {
            node->right = insert_rec(node->right, value);
        }
        // Ignore duplicates
        return node;
    }

    Node* find_node_by_value(Node* node, int target_value) {
        if (node == nullptr || node->value == target_value) {
            return node;
        }

        if (target_value < node->value) {
            return find_node_by_value(node->left, target_value);
        } else {
            return find_node_by_value(node->right, target_value);
        }
    }

    void display_children(Node* node, int parent_value) {
        Node* parent = find_node_by_value(node, parent_value);
        if (parent == nullptr) {
            cout << "Node with value " << parent_value << " not found." << endl;
            return;
        }

        if (parent->left) {
            cout << "Left Child of " << parent_value << ": " << parent->left->value << endl;
        } else {
            cout << "Left Child of " << parent_value << ": nullptr" << endl;
        }

        if (parent->right) {
            cout << "Right Child of " << parent_value << ": " << parent->right->value << endl;
        } else {
            cout << "Right Child of " << parent_value << ": nullptr" << endl;
        }
    }
};

int main() {
    Tree bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    cout << "Root: " << bst.root->value << endl;

    bst.display_children(bst.root, 50);
    bst.display_children(bst.root, 30);
    bst.display_children(bst.root, 70);

    // Binary search test
    int search_value = 60;
    Node* found = bst.find_node_by_value(bst.root, search_value);
    if (found) {
        cout << "Value " << search_value << " found in the tree." << endl;
    } else {
        cout << "Value " << search_value << " not found in the tree." << endl;
    }

    return 0;
}
