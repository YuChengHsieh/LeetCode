#include <vector>
using namespace std;
class Solution {
public:
    bool check(int val, int n){
        int ret = 1;
        for(int i=0; i<val; i++) ret *= 3;
        return n >= ret;
    }
    bool checkPowersOfThree(int n) {
        vector<bool> cnt(15,false);
        int global_end = 15;
        while(true){
            int start = 0, end = global_end;
            while(start <= end){
                int mid = start + (end-start)/2;
                if(check(mid,n)) start = mid + 1;
                else end = mid - 1;
            }
            global_end = end;
            if(cnt[end]) return false;
            cnt[end] = true;
            int val = 1;
            for(int i=0; i<end; i++) val *= 3;
            n -= val;
            if(n == 0) return true;
        }
        return false;
    }
};

class Solution {
private:
    bool backtracking(int power, int n){
        if(n == 0) return true;
        if(pow(3,power) > n) return false;
        return backtracking(power+1,n-pow(3,power)) || backtracking(power+1,n);
    }
public:
    bool checkPowersOfThree(int n) {
        return backtracking(0,n);
    }
};