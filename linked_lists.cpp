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
            Node* new_node = new Node(value, NULL);
            Node node = this->tail;

            node.next_node = new_node;
            this->tail = *new_node;
            this->length++;
        }

        void Prepend(int value) {
            Node* new_node = new Node(value, NULL);
            Node node = this->head;

            new_node->next_node = &node;
            this->head = *new_node;
            this->length++;
        }

        void Insert(int value, int position) {
            Node* new_node = new Node(value, NULL);
            Node* node;
            *node = this->head;

            if (position >= this->length || position < 0) {
                cout << "Out of bounds";
                return;
            }
            
            for (int i = 0; i < position; i++) {
                node = node->next_node;
            }
            
            new_node->next_node = node->next_node;
            node->next_node = new_node;
            this->length++;
        }

        void PrintList() {
            Node* curr_node;
            *curr_node = this->head;
            while (curr_node->next_node) {
                curr_node = curr_node->next_node;
                cout << curr_node->value << " ";
            }
        }
};

int main() {
    LinkedList list(Node(6, NULL));
    list.Prepend(4);
    list.Append(2);
    list.Insert(5, 1);
    list.PrintList();
    list.Insert(0, 4);
}