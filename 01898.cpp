#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int start = 0;
        int end = removable.size();

        auto check = [&](int mid) {
            string tmp_s = s;
            for (int idx = 0; idx < mid; ++idx) {
                int remove_idx = removable[idx];
                tmp_s[remove_idx] = 'A';
            }

            int p_idx = 0;
            for (char ch : tmp_s) {
                if (ch == p[p_idx]) {
                    ++p_idx;
                    if (p_idx == p.length()) {
                        return true;
                    }
                }
            }
            return false;
        };

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (check(mid)) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return end;
    }
};