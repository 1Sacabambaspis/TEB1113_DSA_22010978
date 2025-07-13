#include <iostream>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string n) {
        name = n;
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

    void add_root(string name) {
        root = new Node(name);
    }


    Node* find_node_by_name(Node* root, const string& target_name) {
        if (root == nullptr) {
            return nullptr;
        }

        if (root->name == target_name) {
            return root;
        }

        Node* found_in_left = find_node_by_name(root->left, target_name);
        if (found_in_left) {
            return found_in_left;
        }

        return find_node_by_name(root->right, target_name);
    }

    void add_children_by_name(Node* root, string parent, string child_name, string direction) {

        Node* target = find_node_by_name(root, parent);
        if (direction == "Right") {
            target->right = new Node(child_name);
        }
        else {
            target->left = new Node(child_name);
        }
    
    }

    void display_child(Node* root,string parent){
        Node* target = find_node_by_name(root, parent);
        if (target == nullptr) {
            cout << "Parent node '" << parent << "' not found.\n";
        }
        cout << "Left Child of " << parent << ": " << target->left->name << endl;
        cout << "Right Child of " << parent << ": " << target->right->name << endl;

        if (target->left == nullptr) {
            cout << "Left Child of " << parent << ": nullptr" << endl;
        } 

        if (target->right == nullptr) {
            cout << "Right Child of " << parent << ": nullptr" << endl;
        } 
    }

    
};

int main() {
    Tree tree;

    tree.add_root("A");
    tree.add_children_by_name(tree.root, "A", "B","Left");
    tree.add_children_by_name(tree.root, "A", "C","Right");
    tree.add_children_by_name(tree.root, "B", "D","Left");
    tree.add_children_by_name(tree.root, "B", "E","Right");
    tree.add_children_by_name(tree.root, "C", "F","Left");
    tree.add_children_by_name(tree.root, "C", "G","Right");
    
    cout << "Root: " << tree.root->name << endl;
    tree.display_child(tree.root, "A");
    tree.display_child(tree.root, "B");
    tree.display_child(tree.root, "C");


    return 0;
}