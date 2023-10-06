#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    vector<int> array;
    // analogous to binary search
    TreeNode* generate_tree(int start, int end){
        if(start>end) return nullptr;
        int mid = start+(end-start)/2;
        TreeNode* leftTree = generate_tree(start,mid-1);
        TreeNode* rightTree = generate_tree(mid+1,end);
        return new TreeNode(array[mid],leftTree,rightTree);
    }
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* cur = head;
        while(cur!=nullptr){
            array.push_back(cur->val);
            cur = cur->next;
        }
        TreeNode* root = generate_tree(0,array.size()-1);
        return root;
    }
};