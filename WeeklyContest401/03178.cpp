class Solution {
public:
    int numberOfChild(int n, int k) {
        int cnt = 0;
        bool c = true;
        for(int i=0; i<k; i++){
            if(c) cnt += 1;
            else cnt -= 1;
            if(cnt == n-1 || cnt == 0) c = !c;
        }
        return cnt;
    }
};