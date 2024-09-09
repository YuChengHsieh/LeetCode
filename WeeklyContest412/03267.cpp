#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
private:
    bool almost_equal(int a_val, int b_val){
        int a[8] = {0}, b[8] = {0};
        int cnt = 0;
        while(a_val || b_val){
            a[cnt] = a_val%10 + '0';
            a_val /= 10;
            b[cnt] = b_val%10 + '0';
            b_val /= 10;
            cnt ++;
        }

        int diff_cnt = 0;
        int diff[4];
        for(int k=0; k<7; k++){
            if(a[k] != b[k]){
                if(diff_cnt == 4) return false;
                diff[diff_cnt++] = k;
            } 
        }

        if(diff_cnt == 2){
            return a[diff[1]] == b[diff[0]] && a[diff[0]] == b[diff[1]];
        }else if(diff_cnt == 3){
            return ((a[diff[2]] == b[diff[0]] && a[diff[0]] == b[diff[1]] && a[diff[1]] == b[diff[2]]) ||
                    (a[diff[2]] == b[diff[1]] && a[diff[1]] == b[diff[0]] && a[diff[0]] == b[diff[2]]));
        }else if(diff_cnt == 4){
            return ((a[diff[1]] == b[diff[0]] && a[diff[0]] == b[diff[1]] && a[diff[2]] == b[diff[3]] && a[diff[3]] == b[diff[2]]) || 
                    (a[diff[2]] == b[diff[0]] && a[diff[0]] == b[diff[2]] && a[diff[1]] == b[diff[3]] && a[diff[3]] == b[diff[1]]) ||
                    (a[diff[3]] == b[diff[0]] && a[diff[0]] == b[diff[3]] && a[diff[1]] == b[diff[2]] && a[diff[2]] == b[diff[1]]));
        }
        return false;
    }
public:
    int countPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> modified;
        for(auto& num: nums){
            if(mp[num] == 0) modified.push_back(num);
            mp[num] ++;
        }
        int ans = 0;
        for(int i=0; i<modified.size(); i++) {
            for(int j = i+1; j<modified.size(); j++){
                if(almost_equal(modified[i],modified[j])){
                    ans += mp[modified[i]]*mp[modified[j]];
                }
            }
        }

        for(auto& item: mp){
            ans += item.second*(item.second-1)/2;
        }

        return ans;  
    }
};

