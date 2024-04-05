class Solution {
private:
    bool check(int val, int k){
        return val%2 == 1 ? (val/2+2)*(val/2+1) >= k || (val/2+1)*(val/2+2) >= k : (val/2+1)*(val/2+1) >= k;
    }
public:
    int minOperations(int k) {
        int start = 0, end = k;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(check(mid,k)) end  = mid - 1;
            else start = mid + 1;
        }
        return start;
    }
};