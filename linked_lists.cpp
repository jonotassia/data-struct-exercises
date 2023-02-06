#include <vector>
#include <iostream>

using std::cout;
using std::vector;

class Node {
    public:
        int value;
        Node* next_node{NULL};

        Node(int value, Node* next_node) : value(value), next_node(next_node) {};
};

class LinkedList {
    public:
        Node head;
        Node tail;
        int length{1};

        LinkedList(Node h) : head(h), tail(h) {};

        void Append(int value) {
            Node new_node(value, NULL);
            Node* node = this->tail.next_node;

            node->next_node = &new_node;
            this->tail = new_node;
            this->length++;
        }

        void Insert(int value) {
            Node new_node(value, NULL);
            Node* node = this->head.next_node;
            
            while (node->next_node) {
                node = node->next_node;
            }

            node->next_node = &new_node;
            this->tail = new_node;
            this->length++;
        }
};

int main() {
    LinkedList list(Node(6, NULL));
    list.Append(2);
    cout << list.length << "\n";
    cout << list.head.next_node << "\n";
}