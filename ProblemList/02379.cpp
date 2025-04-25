#include<string>
using namespace std;
class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            // sliding window 
            int w = 0;
            for(int i=0; i<k; i++){
                if(blocks[i] == 'W') w++;
            }
    
            int ans = w;
            for(int right=k; right<blocks.size(); right++){
                if(blocks[right] == 'W') w++;
                if(blocks[right-k] == 'W') w--;
                ans = min(ans,w);
            }
            return ans;
        }
    };