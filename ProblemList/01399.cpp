#include <vector>
using namespace std;
class Solution {
    public:
        int countLargestGroup(int n) {
            vector<int> cnts(40);
            for(int i=1; i<=n; i++){
                int cur = i, sum = 0;
                while(cur != 0){
                    sum += cur%10;
                    cur /= 10;
                }
                cnts[sum] ++;
            }
    
            int max_val = 0, num_group = 0;
            for(int i=0; i<40; i++){
                if(cnts[i] > max_val){
                    max_val = cnts[i];
                    num_group = 1;
                }else if(cnts[i] == max_val) num_group ++;
            }
            return num_group;
        }
    };