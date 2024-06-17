#include <vector>
using namespace std;
class Solution {
private:
    int ans = 0;
    void rec(int idx, vector<bool>& mem, vector<vector<int>>& statements){
        if(idx == mem.size()){
            int n = mem.size();
            int cnt = 0; bool success = true;
            for(int i=0; i<n; i++){
                if(mem[i]){
                    cnt += 1;
                    for(int j=0; j<n; j++){
                        if( (statements[i][j] == 1 && !mem[j]) || (statements[i][j] == 0 && mem[j])){
                            success = false;
                            break;
                        }
                    }
                }
            }

            if(success) ans = max(ans,cnt);
            return;
        }
        mem[idx] = true;
        rec(idx+1,mem,statements);
        mem[idx] = false;
        rec(idx+1,mem,statements);
        return;
    }
public:
    int maximumGood(vector<vector<int>>& statements) {
        vector<bool> mem(statements.size(),false);
        rec(0,mem,statements);
        return ans;
    }
};

// bit manipulation
class Solution {
private:
    int ans = 0;
    void rec(int idx, int mask, vector<vector<int>>& statements){
        if(idx == statements.size()){
            int n = statements.size();
            int cnt = 0; bool success = true;
            for(int i=0; i<n; i++){
                if(mask & (1 << i)){
                    cnt += 1;
                    for(int j=0; j<n; j++){
                        if((statements[i][j] == 1 && !(mask & (1 << j))) || (statements[i][j] == 0 && (mask & (1 << j)))){
                            success = false;
                            break;
                        }
                    }
                }
            }

            if(success) ans = max(ans,cnt);
            return;
        }
        mask |= (1 << idx);
        rec(idx+1,mask,statements);
        mask ^= (1 << idx);
        rec(idx+1,mask,statements);
        return;
    }
public:
    int maximumGood(vector<vector<int>>& statements) {
        int mask = (1 << statements.size())-1;
        rec(0,mask,statements);
        return ans;
    }
};