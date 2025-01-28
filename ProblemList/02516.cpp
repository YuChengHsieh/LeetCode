#include <vector>
#include <string>
using namespace std;

// binary search
class Solution {
private:
    bool check(vector<int>& vec, vector<vector<int>>& prefix, int val){
        for(int i=0; i<3; i++){
            if(vec[i] > prefix[val][i]) return false;
        }
        return true;
    }
    int bs(vector<int>& vec, vector<vector<int>>& prefix){
        int start = 0, end = prefix.size()-1;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(check(vec,prefix,mid)) end = mid - 1;
            else start = mid + 1;
        }
        return start;
    }
public:
    int takeCharacters(string s, int k) {
        if(k == 0) return 0;
        vector<vector<int>> prefix;
        vector<int> vec(3,0);
        prefix.push_back(vec);
        int n = s.size();

        for(int i=0; i<n; i++){
            vec[s[i]-'a'] = min(vec[s[i]-'a']+1,k);
            prefix.push_back(vec);
            if(vec[0] == k && vec[1] == k && vec[2] == k) break;
        }

        int ans = prefix.size()-1;
        if(vec[0] != k || vec[1] != k || vec[2] != k) return -1;

        for(int i=n-1; i>=0; i--){
            vec[s[i]-'a'] = max(vec[s[i]-'a']-1,0);
            ans = min(ans,n-i+bs(vec,prefix));
        }
        return ans;
    }
};