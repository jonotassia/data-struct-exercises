#include <iostream>
#include <string>

using std::cout;
using std::string;

class Node {
    public:
        string value;
        Node* next_node{NULL};

        Node(string value, Node* next_node) : value(value), next_node(next_node) {};
};

class Queue {
    public:
        Node* front{NULL};
        Node* back{NULL};
        int length{0};

        string peek() {
            // Show first item
            if (length == 0) {
                return "Queue is empty";
            }

            return this->front->value;
        }

        void enqueue(string value) {
            // Add new value to back of queue
            Node* new_node = new Node(value, NULL);
            
            if (length == 0) {
                this->front = new_node;
                this->back = new_node;
                this->length++;
                return;
            }
            
            this->back->next_node = new_node;
            this->back = new_node;
            this->length++;
        }

        void dequeue() {
            // Remove from front of queue
            this->front = this->front->next_node;
            this->length--;
        }

};

int main() {
    Queue my_queue;
    my_queue.enqueue("Jono");
    cout << my_queue.peek() << "\n";
    my_queue.enqueue("Kate");
    cout << my_queue.peek() << "\n";
    my_queue.dequeue();
    cout << my_queue.peek() << "\n";
}