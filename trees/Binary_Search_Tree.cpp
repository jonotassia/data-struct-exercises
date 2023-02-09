#include <iostream>

using std::cout;

class Node {
    public:
        int value;
        Node* left{NULL};
        Node* right{NULL};

        Node(int value, Node* left, Node* right) : value(value) {};
};

class BinarySearchTree {
    public:
        Node* root{NULL};
    
        void insert(int value) {
            // Insert a value into the tree
            Node* new_node = new Node(value, NULL, NULL);
            
            if (!root) {
                root = new_node;
                return;
            }

            Node* curr_node = traverse(this->root, value);
            
            if (value < curr_node->value) {
                curr_node->left = new_node;
            }
            else if (value > curr_node->value) {
                curr_node->right = new_node;
            }
        };

        Node* lookup(int value) {
            //Find a value in the tree
            if (!root) {
                return NULL;
            }

            // Traverse to get to node before current node
            Node* curr_node = traverse(this->root, value);
            // Traverse to get to actual node
            curr_node = traverse(curr_node, value);

            if (curr_node->value == value){
                return curr_node;
            } else {
                return NULL;
            }
            
        };

        int remove(int value) {
            // Removes and returns node
            if (!root) {
                return NULL;
            }

            // Traverse to get to node before current node
            Node* curr_node = traverse(this->root, value);

            // Begin tracking location of current node for replacement

                // If end of branch

                // if not end of branch

        }

        Node* traverse(Node* curr_node, int value) {
            if (value < curr_node->value && curr_node->left) {
                curr_node = curr_node->left;
                traverse(curr_node, value);
            }

            else if (value > curr_node->value && curr_node->right) {
                curr_node = curr_node -> right;
                traverse(curr_node, value);
            }
            
            return curr_node;
        }
};

int main() {
    BinarySearchTree bst;
    bst.lookup(9);
    bst.insert(9);
    bst.insert(4);
    bst.insert(6);
    bst.insert(20);
    bst.insert(170);
    bst.insert(15);
    bst.insert(1);
    Node* node = bst.lookup(171);
    cout << (node ? node->value : 0) << "\n";
    node = bst.lookup(6);
    cout << (node ? node->value : 0) << "\n";
}