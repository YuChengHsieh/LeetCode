#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
class Solution {
public:
    unordered_map <int,Node*> visited;
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return node;
        Node* newn = new Node(node->val);
        visited[node->val] = newn;
        for(int i=0; i<node->neighbors.size(); i++){
            if(!visited.count(node->neighbors[i]->val)){
                Node* ret_newn = cloneGraph(node->neighbors[i]);
                newn->neighbors.push_back(ret_newn);
            }
            else{
                newn->neighbors.push_back(visited[node->neighbors[i]->val]);
            }
            
        }
        return newn;
    }
};