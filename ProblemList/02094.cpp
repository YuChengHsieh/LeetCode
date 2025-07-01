#include<vector>
#include<set>
using namespace std;
class Solution {
    public:
        vector<int> findEvenNumbers(vector<int>& digits) {
            sort(digits.begin(),digits.end());
            vector<int> ans;
            set<int> seen;
            for(int i=0; i<digits.size(); i++){
                if(digits[i] == 0 || seen.count(digits[i])) continue;
                for(int j=0; j<digits.size(); j++){
                    if(j == i || seen.count(digits[i]*10+digits[j])) continue;
                    for(int k=0; k<digits.size(); k++){
                        if(k == i || k == j || digits[k]%2 || seen.count(digits[i]*100+digits[j]*10+digits[k])) continue;
                        ans.push_back(digits[i]*100+digits[j]*10+digits[k]);
                        seen.insert(digits[i]*100+digits[j]*10+digits[k]);
                    }
                    seen.insert(digits[i]*10+digits[j]);
    
                }
                seen.insert(digits[i]);
            }
            return ans;
        }
    };