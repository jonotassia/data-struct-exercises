#include <vector>
#include <unordered_map>
#include <algorithm>
#include <list>

using std::vector;
using std::unordered_map;
using std::list;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        unordered_map<int, list<int>> num_positions;
        
        // Store postions of indices where a number is found in the array in a linked list.
        for (int i = 0; i < prices.size(); i++) {
            if (num_positions.find(prices[i]) == num_positions.end()) {
                num_positions[prices[i]] = list<int> {i};
            } else {
                num_positions[prices[i]].push_back(i);
            }
                
        }

        std::sort(prices.begin(), prices.end(), [](int x, int y) {return y < x;});
        
        int profit = 0;
        int max_profit = 0;

        // Search for highest pair starting at the start of the array (largest numbers) and breaking when the smallest number with a lower index is found
        for (int i = 0; i < prices.size(); i++) {
            for (int j = prices.size()-1; j > i; j--) {
                // If highest index of larger number occurs after lowest index of smaller number, calculate price
                // This is to ensure that numbers that appear multiple times are accounted for 
                if (num_positions[prices[i]].back() > num_positions[prices[j]].front()) {
                    profit = prices[i] - prices[j];
                    
                    if (profit > max_profit) {
                        max_profit = profit;
                    }

                    break;
                }
            }
        }
        
        if (max_profit > 0) {
            return max_profit;
        } else {
            return 0;
        }
    }
};

int main() {
    vector<int> prices = {1,4,1,4,3,1};
    Solution test;

    test.maxProfit(prices);
}

