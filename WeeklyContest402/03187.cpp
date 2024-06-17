#include <vector>
using namespace std;
class Solution {
private:
    int bs(int idx, vector<int>& inc){
        int start = 0, end = inc.size()-1;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(idx > inc[mid]) start = mid+1;
            else end = mid-1;
        }
        return start;
    }
public:
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        // binary search
        vector<int> inc;
        for(int i=1; i<nums.size()-1; i++){
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1]) inc.push_back(i);
        }
        
        
        vector<int> result;
        
        for(auto& q: queries){
            if(q[0] == 1){ 
                if(q[2]-q[1] < 2) result.push_back(0);
                else{
                    int upper = bs(q[2]-1,inc);
                    if(upper < inc.size() && q[2]-1 == inc[upper]) upper ++;
                    int lower = bs(q[1]+1,inc);
                    result.push_back(upper-lower);
                }
            }else{
                nums[q[1]] = q[2];
                
                int idx = bs(q[1]-1,inc);
                if(q[1]-2 >= 0 && (nums[q[1]-1] > nums[q[1]-2] && nums[q[1]-1] > nums[q[1]])){
                    if(idx >= inc.size() || inc[idx] != q[1]-1) inc.insert(inc.begin()+idx,q[1]-1);
                }else if(idx < inc.size() && inc[idx] == q[1]-1) inc.erase(inc.begin()+idx);
                
                
                idx = bs(q[1],inc);
                if(q[1]-1 >= 0 && q[1] + 1 < nums.size() && (nums[q[1]] > nums[q[1]-1] && nums[q[1]] > nums[q[1]+1])){
                    if(idx >= inc.size() || inc[idx] != q[1]) inc.insert(inc.begin()+idx,q[1]);
                }else if(idx < inc.size() && inc[idx] == q[1]) inc.erase(inc.begin()+idx);
                
                
                idx = bs(q[1]+1,inc);
                if(q[1]+2 < nums.size() && (nums[q[1]+1] > nums[q[1]] && nums[q[1]+1] > nums[q[1]+2])){
                    if(idx >= inc.size() || inc[idx] != q[1]+1) inc.insert(inc.begin()+idx,q[1]+1);
                }
                else if(idx < inc.size() && inc[idx] == q[1]+1) inc.erase(inc.begin()+idx);
            }
        }
        
        return result;
    }
};