#include <iostream>
#include <vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

// change to graph
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        traversal(root,nullptr);
        // print_map(graph);
        get_answer(target,0,k);
        return ans;
    }
private:
    unordered_map<TreeNode*,vector<TreeNode*>> graph;
    unordered_set<TreeNode*> visited;
    vector<int> ans;
    void print_map(std::unordered_map<TreeNode*,vector<TreeNode*>> const &m)
    {
        for (auto const &pair: m) {
            cout << pair.first->val << ": " << "{";
            for (auto const &val: pair.second){
                cout << val->val << ", ";
            }
            cout << "}" << endl;
        }
    }
    void traversal(TreeNode* cur, TreeNode* parent){
        if (cur->left != nullptr){
            graph[cur].push_back(cur->left);
            traversal(cur->left,cur);
        }
        if (cur->right != nullptr){
            graph[cur].push_back(cur->right);
            traversal(cur->right,cur);
        } 
        if (parent != nullptr) graph[cur].push_back(parent);
    }
    void get_answer(TreeNode* cur,int now,int k){
        visited.insert(cur);
        if(now == k){
            // cout << now << ' ' << k << ' ' << cur->val << endl;
            ans.push_back(cur->val);
        } 
        for(auto &node : graph[cur]){
            if(!visited.count(node)){
                get_answer(node,now+1,k);
            }
        }
    }
};

// Use Queue and BFS
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        traversal(root,nullptr);
        // print_map(graph);
        return get_answer(target,k);
        // return ans;
    }
private:
    unordered_map<TreeNode*,TreeNode*> parents;
    unordered_set<TreeNode*> visited;
    void print_map(std::unordered_map<TreeNode*,vector<TreeNode*>> const &m)
    {
        for (auto const &pair: m) {
            cout << pair.first->val << ": " << "{";
            for (auto const &val: pair.second){
                cout << val->val << ", ";
            }
            cout << "}" << endl;
        }
    }
    void traversal(TreeNode* cur, TreeNode* parent){
        if (cur == nullptr) return;
        if (parent != nullptr) parents[cur] = parent;
        traversal(cur->left,cur);
        traversal(cur->right,cur);
    }
    vector<int> get_answer(TreeNode* cur,int k){
        vector<int> ans;
        queue<pair<TreeNode*,int>> record;
        record.push(make_pair(cur,0));
        while(!record.empty()){
            auto p = record.front();
            TreeNode* cur = p.first;
            int now = p.second;
            record.pop();
            visited.insert(cur);
            if(now > k) break;
            else if(now==k) ans.push_back(cur->val);

            if (cur->left != nullptr and !visited.count(cur->left)) record.push(make_pair(cur->left,now+1));
            if (cur->right != nullptr and !visited.count(cur->right)) record.push(make_pair(cur->right,now+1));
            if (parents[cur] != nullptr and !visited.count(parents[cur])) record.push(make_pair(parents[cur],now+1));
            
        }
        return ans;
    }
};