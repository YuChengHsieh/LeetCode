#include <string>
#include <vector>
using namespace std;
class Solution {
private:
    int rec(int idx, int numCarpets, string& floor, int carpetLen, vector<int>& prefix, vector<vector<int>>& mem){
        if(idx >= floor.size() || numCarpets == 0) return 0;
        if(mem[idx][numCarpets] != -1) return mem[idx][numCarpets];
        int ans = 0;
        if(floor[idx] == '1'){
            ans = rec(idx+carpetLen, numCarpets-1, floor, carpetLen, prefix, mem)+prefix[min((int)floor.size(),idx+carpetLen)] - prefix[idx];
        }
        ans = max(ans, rec(idx+1, numCarpets, floor, carpetLen, prefix, mem));
        return mem[idx][numCarpets] = ans;
    }
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int white_cnt = 0;
        for(auto& ch: floor) if(ch == '1') white_cnt += 1;
        vector<int> prefix(floor.size()+1,0);
        for(int i=1; i<=floor.size(); i++){
            prefix[i] = prefix[i-1] + (floor[i-1] == '1');
        }
        vector<vector<int>> mem(floor.size(), vector<int>(numCarpets+1,-1));
        return white_cnt - rec(0,numCarpets,floor,carpetLen,prefix,mem);
    }
};