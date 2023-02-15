#include <iostream>
#include <vector>
#include <list>

using std::cout;
using std::vector;
using std::list;

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

        vector<Node*> BreadthFirstSearch(Node* node) {
            // Create a list for tracking all nodes and one for tracking vertices to come back to (ie nodes with left and right children)
            Node* curr_node = node;
            vector<Node*> node_list;
            list<Node*> child_queue;

            // Add first node to vertex list
            child_queue.push_back(curr_node);

            // Loop through the vertex list adding children from left to right, then pop the front node after each loop
            while (child_queue.size() > 0) {
                node_list.push_back(curr_node);

                if (curr_node->left) {
                    child_queue.push_back(curr_node->left);
                }

                if (curr_node->right) {
                    child_queue.push_back(curr_node->right);
                }

                child_queue.pop_front();
                curr_node = child_queue.front();
            }
        return node_list;
        }

        vector<Node*> BreadthFirstSearchRecursive(Node* node) {
            // Create a list for tracking all nodes and one for tracking vertices to come back to (ie nodes with left and right children)
            vector<Node*> node_list;

            // Recurse through each set of children, then stitch together after reaching the end of each path
            vector<Node*> children = BreadthFirstSearch(node);
            node_list.insert(node_list.end(), children.begin(), children.end());

            return node_list;
        }

        vector<Node*> DepthFirstSearchInOrder(Node* node) {
            // Search down each left-most path first, then move to the right path at each vertex
            vector<Node*> node_list;

            // Add first node to vertex list. This will end up in the middle since left nodes will be inserted before
            node_list.push_back(node);

            // Recurse all the way down each left most path first
            if (node->left) {
                vector<Node*> left_nodes = DepthFirstSearchInOrder(node->left);
                node_list.insert(node_list.begin(), left_nodes.begin(), left_nodes.end());
            }

            // Then recurse down the right-most path of each node as you retreat back up the tree
            if (node->right) {
                vector<Node*> right_nodes = DepthFirstSearchInOrder(node->right);
                node_list.insert(node_list.end(), right_nodes.begin(), right_nodes.end());
            }

            return node_list;
        }

        vector<Node*> DepthFirstSearchPreOrder(Node* node) {
            // Search down each left-most path first, then move to the right path at each vertex
            vector<Node*> node_list;

            // Add first node to vertex list. This will stay at the start because it is added before the insertions
            node_list.push_back(node);

            // Recurse all the way down each left most path first
            if (node->left) {
                vector<Node*> left_nodes = DepthFirstSearchPreOrder(node->left);
                node_list.insert(node_list.end(), left_nodes.begin(), left_nodes.end());
            }

            // Then recurse down the right path of each vertex as you go down the tree
            if (node->right) {
                vector<Node*> right_nodes = DepthFirstSearchPreOrder(node->right);
                node_list.insert(node_list.end(), right_nodes.begin(), right_nodes.end());
            }

            return node_list;
        }

        vector<Node*> DepthFirstSearchPostOrder(Node* node) {
            // Search down each left-most path first, then move to the right path at each vertex
            vector<Node*> node_list;

            // Recurse all the way down each left most path first
            if (node->left) {
                vector<Node*> left_nodes = DepthFirstSearchPostOrder(node->left);
                node_list.insert(node_list.begin(), left_nodes.begin(), left_nodes.end());
            }

            // Then recurse down the right-most path of each node as you retreat back up the tree
            if (node->right) {
                vector<Node*> right_nodes = DepthFirstSearchPostOrder(node->right);
                node_list.insert(node_list.end(), right_nodes.begin(), right_nodes.end());
            }

            // Add node to vertex list. This will bubble to tne end as it happens after all insertions
            node_list.push_back(node);

            return node_list;
        }

        void PrintList(vector<Node*> list) {
            for (Node* node: list) {
                cout << node->value << " ";
            }
            cout << "\n";
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
    bst.PrintList(bst.BreadthFirstSearch(bst.root));
    bst.PrintList(bst.BreadthFirstSearchRecursive(bst.root));
    bst.PrintList(bst.DepthFirstSearchInOrder(bst.root));
    bst.PrintList(bst.DepthFirstSearchPreOrder(bst.root));
    bst.PrintList(bst.DepthFirstSearchPostOrder(bst.root));
}