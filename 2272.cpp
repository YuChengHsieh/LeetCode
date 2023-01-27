#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int largestVariance(std::string s) {
        std::unordered_set<char> exist_chars;
        int ans = 0;

        for (char c : s) {
            exist_chars.insert(c);
        }

        for (char char1 : exist_chars) {
            for (char char2 : exist_chars) {
                if (char1 == char2) {
                    continue;
                }

                for (int i = 0; i < 2; i++) {
                    int cnt1 = 0, cnt2 = 0;

                    for (char c : s) {
                        if (c != char1 and c != char2) continue;
                        if (c == char1) {
                            cnt1++;
                        }
                        if (c == char2) {
                            cnt2++;
                        }

                        if (cnt2 > cnt1) {
                            cnt1 = 0;
                            cnt2 = 0;
                        }

                        if (cnt1 > 0 && cnt2 > 0) {
                            ans = std::max(ans, cnt1 - cnt2);
                        }
                    }

                    std::reverse(s.begin(), s.end());
                }
            }
        }

        return ans;
    }
};

// python code
// class Solution:
//     # kadane's algorithm
//     def largestVariance(self, s: str) -> int:
//         # chars = [chr(i) for i in range(ord('a'),ord('z')+1)]
//         ans = 0
//         pairs = [(c1,c2) for c1 in set(s) for c2 in set(s) if c1 != c2 ]
        
//         for char1,char2 in pairs:
//             for i in range(2):
//                 cnt1 = cnt2 = 0
//                 for char in s:
//                     if char not in [char1,char2]:
//                         continue
//                     if char == char1:
//                         cnt1 += 1
//                     if char == char2:
//                         cnt2 += 1
//                     # kadane's algorithm
//                     if cnt2 > cnt1:
//                         cnt1 = cnt2 = 0
//                     elif cnt1 > 0 and cnt2 > 0:
//                         ans = max(ans,cnt1-cnt2)
//                 s = s[::-1]
//         return ans