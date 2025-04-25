#include <vector>
using namespace std;
class BIT{
    private:
        int sz;
        vector<int> trees;
    public:
        BIT(int n) : trees(n+1,0), sz(n+1) {};
    
        void update(int idx, int delta){
            idx ++;
            while(idx < sz){
                trees[idx] += delta;
                idx += idx & -idx;
            }
        }
    
        int query(int idx){
            idx ++;
            int sum = 0;
            while(idx > 0){
                sum += trees[idx];
                idx -= idx & -idx;
            }
            return sum;
        }
    };
    class Solution {
    public:
        long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
            int n = nums1.size();
            vector<int> idx2s(n,0), reverse(n,0);
            
            for(int i=0; i<n; i++) idx2s[nums2[i]] = i;
    
            for(int i=0; i<n; i++) reverse[i] = idx2s[nums1[i]];
    
            BIT bit(n);
            long long ans = 0;
            for(int i=0; i<n; i++){
                int pos = reverse[i];
                int left = bit.query(pos);
                bit.update(pos,1);
                int right = (n-1-pos) - (i-left);
                ans += (long long)left*right;
            }
            return ans;
    
        }
    };