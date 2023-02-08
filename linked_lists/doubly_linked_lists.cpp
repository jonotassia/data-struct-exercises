#include <vector>
#include <iostream>

using std::cout;
using std::vector;

class Node {
    public:
        int value;
        Node* next_node{NULL};
        Node* prev_node{NULL};

        Node(int value, Node* next_node, Node* prev_node) : value(value), next_node(next_node), prev_node(prev_node) {};
};

class LinkedList {
    public:
        Node* head;
        Node* tail;
        int length{1};

        LinkedList(int value) {
            Node* new_node = new Node(value, NULL, NULL);
            head = new_node;
            tail = new_node;
        };

        void Append(int value) {
            Node* new_node = new Node(value, NULL, NULL);

            this->tail->next_node = new_node;
            new_node->prev_node = this->tail;
            this->tail = new_node;
            
            this->length++;
        }

        void Prepend(int value) {
            Node* new_node = new Node(value, NULL, NULL);

            new_node->next_node = this->head;
            this->head->prev_node = new_node;
            this->head = new_node;
            this->length++;
        }

        void Insert(int value, int position) {
            Node* new_node = new Node(value, NULL, NULL);
            Node* node;
            node = this->head;

            if (position >= this->length || position < 0) {
                cout << "Out of bounds";
                return;
            }

            if (position == 0) {
                this->Prepend(value);
                return;
            }

            if (position == this->length) {
                this->Append(value);
                return;
            }
            
            for (int i = 0; i < position; i++) {
                node = node->next_node;
            }
            
            new_node->next_node = node->next_node;
            new_node->prev_node = node;
            node->next_node = new_node;
            this->length++;
        }

        void Remove(int position) {
            Node* node;
            node = this->head;

            for (int i = 0; i < position; i++) {
                node = node->next_node;
            }

            Node* rem_node = node->next_node;
            node->next_node = rem_node->next_node;
            node->next_node->prev_node = node;
            delete rem_node;
        }

        void PrintList() {
            Node* curr_node;
            curr_node = this->head;
            while (curr_node->next_node) {
                cout << curr_node->value << " ";
                curr_node = curr_node->next_node;
            }
            cout << curr_node->value << "\n";
        }
};

int main() {
    LinkedList list(6);
    list.Append(2);
    list.PrintList();
    list.Prepend(4);
    list.PrintList();
    list.Insert(5, 1);
    list.PrintList();
    list.Remove(1);
    list.PrintList();
    list.Insert(0, 4);
}