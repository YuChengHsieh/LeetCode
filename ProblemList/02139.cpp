class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int cnt = 0;
        while(target > 1 && maxDoubles > 0){
            cnt += target%2;
            target /= 2;
            cnt ++;
            maxDoubles --;
        }
        return cnt + target-1;
    }
};