#include <iostream>
#include <vector>

using std::cout;
using std::vector;

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
            // Step one more time in either direction to get to the desired node
            
            if (!curr_node->left && !curr_node->right) {
                return NULL;
            }
            else if (curr_node->left->value == value) {
                return curr_node->left;
            }
            else if (curr_node->right->value == value) {
                return curr_node->right;
            } else {
                return NULL;
            }
        };

        Node* remove(int value) {
            // Removes and returns node
            if (!root) {
                return NULL;
            }

            // Traverse to get to node before current node
            Node* prev_node = traverse(this->root, value);
            
            // Begin tracking location of current node for removal and node for replacement
            Node* rem_node;
            Node* repl_node;
            // Instantiate a tracking list to get leaf-1
            vector<Node*> temp;
            
            if (prev_node->left->value == value) {
                // Reassign to rem_node for traversal
                rem_node = prev_node->left;
                prev_node->left = repl_node;
                repl_node = rem_node;
            } 
            else if (prev_node->right->value == value) {
                // Reassign to rem_node for traversal
                rem_node = prev_node->right;
                prev_node->right = repl_node;
                repl_node = rem_node;
            }
            else if (prev_node == this->root) {
                rem_node = prev_node;
                repl_node = rem_node->right;
                temp.push_back(repl_node);
            }
            else {
                return NULL;
            }

            

            // While there is something in the left most branch, loop until it is found
            while (repl_node->left) {
                repl_node = repl_node->left;
                temp.push_back(repl_node);
            }

            if (temp.size() == 0) {
                if (prev_node->left->value > value) {
                    prev_node->left = rem_node->left;
                } 
                else if (prev_node->right->value < value) {
                    prev_node->right = rem_node->right;
                } 
                return prev_node;
            } 
            else if (temp.size() == 1) {
                if (prev_node->left->value > value) {
                    prev_node->left = repl_node;
                } 
                else if (prev_node->right->value < value) {
                    prev_node->right = repl_node;
                } 
                repl_node->right = rem_node->right;
                return repl_node;
            }
            else {
                // Remove pointer from second-to-last node to newest node
                temp[temp.size()-2]->left = NULL;
                if (repl_node->right) {
                    temp[temp.size()-2]->right = repl_node->right;
                }

                if (prev_node->value == value) {
                    // replace left and right of repl node with prev node, then remove from prev node
                    repl_node->left = rem_node->left;
                    repl_node->right = rem_node->right;

                    prev_node->left = NULL;
                    prev_node->right = NULL;

                    // Replace root with replacement node
                    this->root = repl_node;
                }
                else if (prev_node->left->value == value) {
                    prev_node->left = repl_node;
                    // Replace left and right pointers with those of the removal node
                    repl_node->left = rem_node->left;
                    repl_node->right = rem_node->right;
                } 
                else if (prev_node->right->value == value) {
                    prev_node->right = repl_node;
                    // Replace left and right pointers with those of the removal node
                    repl_node->left = rem_node->left;
                    repl_node->right = rem_node->right;
                } 

                return repl_node;
            }
        }

        Node* traverse(Node* curr_node, int value) {
            // This will traverse all nodes in a tree until it finds the node that links to the one with the desired value
            if (curr_node->value == value) {
                return curr_node;
            }
            if (value < curr_node->value && curr_node->left) {
                if (curr_node->left->value == value) {
                    return curr_node;
                } else {
                    curr_node = curr_node->left;
                    curr_node = traverse(curr_node, value);
                }
            }
            else if (value > curr_node->value && curr_node->right) {
                if (curr_node->right->value == value) {
                    return curr_node;
                } else {
                    curr_node = curr_node->right;
                    curr_node = traverse(curr_node, value);
                }
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
    node = bst.remove(9);
    cout << (node ? node->value : 0) << "\n";
    node = bst.remove(6);
    cout << (node ? node->value : 0) << "\n";
    node = bst.remove(20);
    cout << (node ? node->value : 0) << "\n";
}