//Google Question
//Given an array = [2,5,1,2,3,5,1,2,4]:
//It should return 2

//Given an array = [2,1,1,2,3,5,1,2,4]:
//It should return 1

//Given an array = [2,3,4,5]:
//It should return undefined

#include <vector>
#include <iostream>
#include <unordered_map>

using std::vector;
using std::unordered_map;
using std::cout;

int ParseArray(vector<int> series) {
    unordered_map<int, int> numbers_hash;
    for (int i: series) {
        if (numbers_hash.find(i) == numbers_hash.end()) {
            numbers_hash[i] = 1;
        } else {
            numbers_hash[i]++;
        }
        
        if (numbers_hash[i] > 1) {
            return i;
        }
    }
    return 0;
}

int main() {
    vector<int> num_series1 = {2,5,1,2,3,5,1,2,4};
    vector<int> num_series2 = {2,1,1,2,3,5,1,2,4};
    
    cout << ParseArray(num_series1);
    cout << ParseArray(num_series2);
}