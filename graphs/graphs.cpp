#include <iostream>
#include <unordered_map>
#include <vector>

using std::cout;
using std::unordered_map;
using std::vector;

class Graph { 
  public:
    int numberOfNodes = 0;
    unordered_map<int, vector<int>> adjacent_list;

    void addVertex(int node)  { 
        if (this->adjacent_list.size() == 0) {
            vector<int> new_vector;
            this->adjacent_list[node] = new_vector;
            numberOfNodes++;
        }
        else if (adjacent_list.find(node) == adjacent_list.end()) {
            vector<int> new_vector;
            this->adjacent_list[node] = new_vector;
            numberOfNodes++;
        } 
        else {
            cout << "Already in list";
        }
    };
    
    void addEdge(int node1, int node2) { 
        if (this->adjacent_list.find(node1) == this->adjacent_list.end() || this->adjacent_list.find(node2) == this->adjacent_list.end()) {
            cout << "Invalid combination";
        }

        this->adjacent_list[node1].push_back(node2);
        this->adjacent_list[node2].push_back(node1);
    };
};

int main() {
    Graph myGraph;
    myGraph.addVertex(0);
    myGraph.addVertex(1);
    myGraph.addVertex(2);
    myGraph.addVertex(3);
    myGraph.addVertex(4);
    myGraph.addVertex(5);
    myGraph.addVertex(6);
    myGraph.addEdge(3, 1); 
    myGraph.addEdge(3, 4); 
    myGraph.addEdge(4, 2); 
    myGraph.addEdge(4, 5); 
    myGraph.addEdge(1, 2); 
    myGraph.addEdge(1, 0); 
    myGraph.addEdge(0, 2); 
    myGraph.addEdge(6, 5);

    //Answer:
    // 0-->1 2 
    // 1-->3 2 0 
    // 2-->4 1 0 
    // 3-->1 4 
    // 4-->3 2 5 
    // 5-->4 6 
    // 6-->5
}
