#include <vector>
using namespace std;

class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string t = s;
        size_t pos = s.find_first_not_of('9');
        if (pos != string::npos) {
            char a = s[pos];
            replace(s.begin(), s.end(), a, '9');
        }
        char b = t[0];
        replace(t.begin(), t.end(), b, '0');
        return stoi(s) - stoi(t);
    }
};

class Solution {
public:
    int minMaxDifference(int num) {
        int tmp = num;
        int digits = 0;
        while(tmp != 0){
            digits ++;
            tmp /= 10;
        }

        int tmp_val = num, max_target = 9, min_target = 0;
        bool max_lock = false, min_lock = false;
        while(digits){
            int val = tmp_val / (int)pow(10,digits-1);
            tmp_val -= val*(int)pow(10,digits-1);
            if(val != 9 && !max_lock){
                max_target = val;
                max_lock = true;
            } 
            if(val != 0 && !min_lock){
                min_target = val;
                min_lock = true;
            } 
            digits --;
        }
        

        int max_val = 0, min_val = 0, cnt = 1;
        while(num != 0){
            int val = num % 10;
            if(val == max_target) max_val += 9 * cnt;
            else max_val += val * cnt;

            if(val != min_target) min_val += val * cnt;
            num /= 10;
            cnt *= 10;
        }
        return max_val - min_val;
    }
};