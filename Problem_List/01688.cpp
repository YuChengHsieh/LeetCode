// o(1)
class Solution {
public:
    int numberOfMatches(int n) {
        return n-1;
    }
};

// log(n)
class Solution {
public:
    int numberOfMatches(int n) {
        int rev = n;
        int cnt = 0;

        while(rev>1){
            cnt += rev/2;
            if(rev%2 == 1) rev += 1;
            rev /= 2;
        }
        return cnt;
    }
};