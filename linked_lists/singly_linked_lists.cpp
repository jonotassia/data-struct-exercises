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
        Node* head;
        Node* tail;
        int length{1};

        LinkedList(int value) {
            Node* new_node = new Node(value, NULL);
            head = new_node;
            tail = new_node;
        };

        void Append(int value) {
            Node* new_node = new Node(value, NULL);

            this->tail->next_node = new_node;
            this->tail = new_node;
            this->length++;
        }

        void Prepend(int value) {
            Node* new_node = new Node(value, NULL);

            new_node->next_node = this->head;
            this->head = new_node;
            this->length++;
        }

        void Insert(int value, int position) {
            Node* new_node = new Node(value, NULL);
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
            node->next_node = new_node;
            this->length++;
        }

        LinkedList Reverse() {
            if (length == 1) {
                return *this;
            }
            
            LinkedList temp(this->head->value);
            Node* node = this->head;

            for (int i = 1; i < this->length; i++) {
                node = node->next_node;
                temp.Prepend(node->value);
            }

            return temp;
        }

        void Remove(int position) {
            Node* node;
            node = this->head;

            for (int i = 0; i < position; i++) {
                node = node->next_node;
            }

            Node* rem_node = node->next_node;
            node->next_node = rem_node->next_node;
            delete rem_node;
            this->length--;
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
    list = list.Reverse();
}