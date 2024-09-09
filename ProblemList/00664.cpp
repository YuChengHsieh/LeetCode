#include <vector>
#include <string>
using namespace std;
class Solution {
private:
    int dp(int start, int end, string& s, vector<vector<int>>& mem){
        if(start == end) return 1;
        if(mem[start][end] != -1) return mem[start][end];
        int ans = INT_MAX;
        for(int i=start; i<end; i++){
            ans = min(ans, dp(start,i,s,mem)+dp(i+1,end,s,mem));
        }
        return mem[start][end] = ans - (s[start] == s[end] ? 1 : 0);
    }
public:
    int strangePrinter(string s) {
        vector<vector<int>> mem(s.size(), vector<int>(s.size(),-1));
        return dp(0,s.size()-1,s,mem);
    }
};