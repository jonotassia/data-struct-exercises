#include <string>
#include <iostream>

using std::string;
using std::cout;

class HashNode {
    public:
        string key;
        string value;

        HashNode(string key, string value) : key(key), value(value) {};
};

class HashTable {
    public:
        HashNode** data;
        int size;
        
        HashTable(int size) {
            this->data = new HashNode*[size];
            this->size = size;
            for (int i = 0; i < size; i++) {
                data[i] = NULL;
            }
        };

        string GetValue(string key) {
            int index = _hash(key);
            //TODO: Handle Collision
            if (data[index] == NULL) {
                return "Undefined";
            }

            return data[index]->value;
        }

        void SetValue(string key, string value) {
            int index = _hash(key);
            if (data[index] != NULL) {
                delete data[index];
            }
            data[index] = new HashNode(key, value);
        }

    private:
        int _hash(string key) {
            int hash = 0;
            for (int i = 0; i < key.size(); i++){
                hash = (hash + (int)key[i] * i) % this->size;
            }
            return hash;
        }
};

int main() {
    // initialize object
    HashTable hash(50);

    // Getter by key
    hash.SetValue("Apple", "Bird");
    hash.SetValue("Orange", "Dog");

    // Setter by key
    cout << hash.GetValue("Orange") << "\n";
    cout << hash.GetValue("Apple");
}

