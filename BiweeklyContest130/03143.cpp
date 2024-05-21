#include <vector>
#include <string>
using namespace std;
// binary search
class Solution {
private:
    int check(int num, vector<vector<int>>& points, string& s){
        vector<bool> cnts(26,false);
        int cnt = 0;
        for(int i=0; i<s.size(); i++){
            if((points[i][0] >= -num && points[i][0] <= num) && (points[i][1] >= -num && points[i][1] <= num)){  
                if(cnts[s[i]-'a']) return -1;
                cnts[s[i]-'a'] = true;
                cnt += 1;
            }
        }
        return cnt;
    }
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        // binary search
        int start = 0, end = pow(10,9);
        int max_val = 0;
        while(start <= end){
            int mid = start + (end-start)/2;
            int val = check(mid,points,s);
            max_val = max(max_val, val);
            if(val != -1) start = mid+1;
            else end = mid-1;
        }
        return max_val;
    }
};