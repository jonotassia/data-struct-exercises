#include <iostream>

using std::cout;

class Node {
    public:
        int value;
        Node* next_node{NULL};

        Node(int value, Node* next_node) : value(value), next_node(next_node) {};
};

class Stack {
    public:
        Node* top{NULL};
        Node* bottom{NULL};
        int length{0};

        Node peek() {
            // See top element of Stack
            return *this->top;
        }

        void push(int value) {
            // Push new element onto top of Stack
            Node* new_node = new Node(value, NULL);

            if (this->length == 0) {
                this->top = new_node;
                this->bottom = new_node;
                this->length++;
            } else {
                new_node->next_node = this->top;
                this->top = new_node;
                this->length++;   
            }
        }

        void pop() {
            // Remove top element from stack
            if (this->length == 0) {
                cout << "Nothing in the stack." << "\n";
                return;
            }

            this->top = this->top->next_node;
            this->top->next_node = NULL;
            this->length--;

            if (this->length == 1) {
                this->bottom = NULL;
            }
        }
};

int main() {
    Stack my_stack;
    my_stack.push(1);
    cout << my_stack.peek().value << "\n";
    my_stack.push(2);
    cout << my_stack.peek().value << "\n";
    my_stack.pop();
    cout << my_stack.peek().value << "\n";  
}