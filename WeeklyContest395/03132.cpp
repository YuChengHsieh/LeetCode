#include <vector>
using namespace std;

// o(n^3)
class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        int ans = INT_MAX;
        for(int i=0; i<nums1.size(); i++){
            for(int j=i+1; j<nums1.size(); j++){
                int idx2 = 0;
                int tmp = INT_MAX, cnt = 0;
                for(int k=0; k<nums1.size(); k++){
                    if(k == i || k == j) continue;
                    if(tmp == INT_MAX || nums2[idx2] - nums1[k] == tmp){
                        tmp = nums2[idx2] - nums1[k];
                        cnt += 1;
                        idx2 += 1;
                    }else break;
                }
                if(cnt == nums2.size()) ans = min(ans,tmp);
            }
        }
        return ans;
    }
};

// o(n^2)
class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        int ans = INT_MAX;
        int cnt = 0;
        for(int i=0; i<nums1.size(); i++){
            int diff = nums2[0] - nums1[i], idx2 = 0, cnt = 0;
            for(int j=0; j<nums1.size() && idx2 < nums2.size(); j++){
                if(nums2[idx2]-nums1[j] != diff) cnt += 1;
                else idx2 += 1;
                if(cnt > 2) break;
            }
            if(cnt <= 2) ans = min(ans, diff);
        }
        return ans;
    }
};

// o(n^2)
class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        reverse(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        int ans = INT_MAX;
        int cnt = 0;
        for(int i=0; i<nums1.size(); i++){
            int diff = nums2[0] - nums1[i], idx2 = 0, cnt = 0;
            for(int j=nums1.size()-1; j>=0 && idx2 < nums2.size(); j--){
                if(nums2[idx2]-nums1[j] != diff) cnt += 1;
                else idx2 += 1;
                if(cnt > 2) break;
            }
            if(cnt <= 2) return diff;
        }
        return -1;
    }
};