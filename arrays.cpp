#include <string>
#include <iostream>
#include <vector>

using std::string;
using std::cout;
using std::vector;

string ReverseString(string s) {
    string rev_string;
    for (char letter: s) {
        rev_string.insert(rev_string.begin(), letter);
    }
    return rev_string;
}

void PrintString(string reverse_string) {
    try {
        cout << reverse_string << "\n";
    }
    catch (...) {
        cout << "Not a string." << "\n";
    }
}

vector<int> MergeSorted(vector<int> v1, vector<int> v2) {
    if (v1.size() == 0) {
        return v2;
    }

    if (v2.size() == 0) {
        return v1;
    }

    vector<int> merged_vector;
    for (int i: v1) {
        for (int j: v2) {
            if (j < i) {
                merged_vector.push_back(j);
            }
        }
        merged_vector.push_back(i);
    }
    return merged_vector;
}

void PrintVector(vector<int> v) {
    for (int i: v) {
        cout << i;
    }
    cout << "\n";
}

int main() {
    PrintString(ReverseString("I am called Jono"));
    PrintVector(MergeSorted({0, 3, 4, 31}, {4, 6, 30}));
}

