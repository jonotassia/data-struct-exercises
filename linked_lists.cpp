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

        LinkedList(Node h) : head(h), tail(head) {};

        void Append(int value) {
            Node new_node(value, NULL);
            Node node = this->tail;

            node.next_node = &new_node;
            this->tail = new_node;
            this->length++;
        }

        void Prepend(int value) {
            Node new_node(value, NULL);
            Node node = this->head;

            new_node.next_node = &node;
            this->head = new_node;
            this->length++;
        }

        void Insert(int value, int position) {
            Node new_node(value, NULL);
            Node node = this->head;

            if (position >= this->length) {
                cout << "Out of bounds";
                return;
            }
            
            for (int i = 0; i < position; i++) {
                node = *node.next_node;
            }
            
            new_node.next_node = node.next_node;
            node.next_node = &new_node;
            this->length++;
        }
};

int main() {
    LinkedList list(Node(6, NULL));
    list.Prepend(4);
    list.Append(2);
    list.Insert(5, 1);
    cout << list.length << "\n";
    cout << list.head.next_node << "\n";
    list.Insert(0, 4);
}