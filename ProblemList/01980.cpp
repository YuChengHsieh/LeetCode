#include <set>
#include <string>
using namespace std;

// o(n), different in every position in every string 
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans;
        for(int i=0; i<nums.size(); i++){
            ans += nums[i][i] == '0' ? '1' : '0';
        }
        return ans;
    }
};

// o(n^2)
class Solution {
private:
    bool find = false;
    string ans;
    void dfs(string digits, int length, set<string>& container){
        if(digits.size() == length){
            if(!container.count(digits)){
                find = true;
                ans = digits;
            } 
            return;
        }
        dfs(digits + "0", length, container);
        if(find) return;
        dfs(digits + "1", length, container);
        return;
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        set<string> st(nums.begin(),nums.end());
        dfs("",nums[0].size(),st);
        return ans;
    }
};