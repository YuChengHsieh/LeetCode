#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<int, int> freqMap;
        for (int num : nums2) {
            freqMap[num]++;
        }
        
        long long goodPairs = 0;
        for (auto num1 : nums1) {
            if(num1 % k != 0) continue;
            int num = num1/k;
            for (int i = 1; i <= sqrt(num); ++i) {
                if (num % i == 0) {
                    if (freqMap.count(i)) goodPairs += freqMap[i];
                    if (i != (num/i) && freqMap.count(num/i)) goodPairs += freqMap[num/i];
                }
            }
        }
        return goodPairs;
    }
};