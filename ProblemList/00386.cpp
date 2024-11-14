#include <vector>
using namespace std;
class Solution {
private:
    vector<int> ans;
    void rec(int val, int n){
        if(val > n) return;
        if(val != 0) ans.push_back(val);
        for(int i=0; i<=9; i++){
            if(val == 0 && i == 0) continue;
            rec(val*10+i,n);
        }
        return;
    }
public:
    vector<int> lexicalOrder(int n) {
        rec(1,n);
        return ans;
    }
};