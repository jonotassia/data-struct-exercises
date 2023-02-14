#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;
using std::cout;

vector<int> BubbleSort(vector<int> list) {
    int length = list.size();
    int temp = 0;

    // Loop through each item and compare it to its neighbor, then move the starting index forward by 1
    for (int i = 0; i < length-1; i++) {
        for (int j = 0; j < length-1; j++) {
            if (list[j] > list[j+1]) {
                temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }
    return list;
};

vector<int> SelectionSort(vector<int> list) {
    int length = list.size();
    int smallest, temp, smallest_index;

    // Loop through each item and compare against all other items, finding the smallest value
    for (int i = 0; i < length; i++) {
        smallest = list[i];
        smallest_index = i;

        for (int j = i; j < length; j++) {
            if (smallest > list[j]) {
                smallest = list[j];
                smallest_index = j;
            }
        }
        // Swap smallest value with value at index i
        temp = list[i];
        list[i] = smallest;
        list[smallest_index] = temp;
    }
    return list;
}

vector<int> InsertionSort(vector<int> list) {
    int length = list.size();
    vector<int> sorted_list;

    for (int i = 0; i < length; i++) {
        // If empty, add to sorted list
        if (sorted_list.size() == 0) {
            sorted_list.push_back(list[i]);
        }
        // If smaller than first item, insert at beginning
        else if (list[i] > sorted_list[sorted_list.size()-1]) {
            sorted_list.push_back(list[i]);
        }
        // If larger than last item, insert at end
        else if (list[i] < sorted_list[0]) {
            sorted_list.insert(sorted_list.begin(), list[i]);
        }
        // Otherwise, search through the new list to determine where to add
        else {
            for (int j = 0; j < sorted_list.size(); j++) {
                if (list[i] > sorted_list[j] && list[i] < sorted_list[j+1]) {
                    sorted_list.insert(sorted_list.begin()+j+1, list[i]);
                    break;
                }
                else if (list[i] == sorted_list[j]) {
                    sorted_list.insert(sorted_list.begin()+j, list[i]);
                    break;
                }
            }
        }
    }
    return sorted_list;
}

vector<int> Merge(vector<int> left, vector<int> right) {
    vector<int> new_list;
    
    // Compare each value within sublists and pushback smallest to largest
    for (int i = 0; i < left.size(); i++) {
        if (left[i] <= right[i]) {
            new_list.push_back(left[i]);
            new_list.push_back(right[i]);
        }
        else if (left[i] > right[i]) {
            new_list.push_back(right[i]);
            new_list.push_back(left[i]);
        }
    }
    
    // If there was a size mismatch, the extra values would not get added in the above, so append it to the larger side
    if (left.size() > right.size()) {
        new_list.push_back(left[left.size()-1]);
    }
    else if (left.size() < right.size()) {
        new_list.push_back(right[right.size()-1]);
    }

    return new_list;
}

vector<int> MergeSort(vector<int> list) {
    int length = list.size();
    
    if (length == 1) {
        return list;
    }

    // Split list into right and left
    vector<int> left = vector<int>(list.begin(), list.begin() + length/2);
    vector<int> right = vector<int>(list.begin() + length/2, list.end());

    return Merge(MergeSort(left), MergeSort(right));
}

vector<int> QuickSort(vector<int> list) {
    // Choose a pivot to center the list and intialize a list with it as the only value
    int length = list.size();
    
    if (length == 1) {
        return list;
    }
    
    int pivot = list[list.size()-1];
    vector<int> left;
    vector<int> right;

    // remove pivot from list since it will be added back later
    list.pop_back();

    for (int i: list) {
        if (i <= pivot) {
            left.push_back(i);
        } else {
            right.push_back(i);
        }
    }

    if (left.size() > 0) {
        left = QuickSort(left);
    }

    if (right.size() > 0) {
        right = QuickSort(right);
    }


    vector<int> new_list;
    new_list.insert(new_list.end(), left.begin(), left.end());
    new_list.push_back(pivot);
    new_list.insert(new_list.end(), right.begin(), right.end());

    return new_list;
}

void PrintList(vector<int> list) {
    for (int i: list) {
        cout << i << " ";
    }
    cout << "\n";
}

int main() {
    vector<int> list = {0, 5, 4, 2, 1, 6, 2, 4};
    PrintList(BubbleSort(list));
    PrintList(SelectionSort(list));
    PrintList(InsertionSort(list));
    PrintList(MergeSort(list));
    PrintList(QuickSort(list));
}