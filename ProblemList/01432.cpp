#include <string>
using namespace std;
class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string t = s;
        size_t pos1 = s.find_first_not_of('9');
        if (pos1 != string::npos) {
            char a = s[pos1];
            replace(s.begin(), s.end(), a, '9');
        }

        size_t pos2 = t.find_first_not_of("10");
        if (pos2 != string::npos) {
            char a = t[pos2];
            // cout << a << ' ' << pos2 << endl;
            if(pos2 == 0) replace(t.begin(), t.end(), a, '1');
            else replace(t.begin(), t.end(), a, '0');
        }
        return stoi(s) - stoi(t);
    }
};