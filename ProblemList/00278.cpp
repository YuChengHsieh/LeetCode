class Solution {
public:
    int firstBadVersion(int n) {
        // Binary Search
        int start = 0, end = n;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(isBadVersion(mid)) end = mid-1;
            else start = mid+1;
        }
        return start;
    }
};