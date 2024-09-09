#include <vector>
using namespace std;

class Solution {
private:
    vector<int> ans;
    void traverse(Node* cur){
        for(auto& nextn: cur -> children){
            traverse(nextn);
        }
        ans.push_back(cur -> val);
    }
public:
    vector<int> postorder(Node* root) {
        if(root) traverse(root);
        return ans;
    }
};