#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n,-1));
        int cur_r = 0, cur_c = 0, chg_idx = 0;
        vector<int> dr = {0,1,0,-1};
        vector<int> dc = {1,0,-1,0};
        ListNode* cur = head;
        
        int left = 0, up = 1, right = n-1, down = m-1;
        while(cur != nullptr){
            ans[cur_r][cur_c] = cur -> val;
            if(chg_idx == 0 && cur_c == right){
                right -= 1;
                chg_idx = (chg_idx+1)%4;
            }else if(chg_idx == 2 && cur_c == left){
                left += 1;
                chg_idx = (chg_idx+1)%4;
            }else if(chg_idx == 1 && cur_r == down){
                down -= 1;
                chg_idx = (chg_idx+1)%4;
            }else if(chg_idx == 3 && cur_r == up){
                up += 1;
                chg_idx = (chg_idx+1)%4;
            }
            
            cur_r += dr[chg_idx];
            cur_c += dc[chg_idx];
            cur = cur -> next;
        }
        return ans;
    }
};