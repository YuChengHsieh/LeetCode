#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    queue<Node*> myqueue;
    Node* connect(Node* root) {
        if(root!=nullptr){
            myqueue.push(root);
        }
        while(!myqueue.empty()){
            Node* cur;
            int cur_size = myqueue.size();
            for(int i=0; i<cur_size; i++){
                cur = myqueue.front();
                if(cur->left != nullptr){
                    myqueue.push(cur->left);
                }
                if(cur->right != nullptr){
                    myqueue.push(cur->right);
                }

                myqueue.pop();
                if(i!= cur_size-1){
                    Node* nextn = myqueue.front();
                    cur->next = nextn;
                }
                
            }
        }
        return root;
    }
};