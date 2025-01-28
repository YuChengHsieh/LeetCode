#include <vector>
using namespace std;
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int sum = 0, n = code.size();
        vector<int> ans;
        if(k > 0){
            for(int i=1; i<=k; i++){
                sum += code[i];
            }
            ans.push_back(sum);
            for(int i=1; i<n; i++){
                sum -= code[i];
                sum += code[(k+i)%n];
                ans.push_back(sum);
            }
        }else if(k < 0){
            k = abs(k);
            for(int i=n-1; i>n-1-k; i--){
                sum += code[i];
            }
            ans.push_back(sum);
            for(int i=1; i<n; i++){
                sum += code[i-1];
                sum -= code[(n-1-k+i)%n];
                ans.push_back(sum);
            }
        }else{
            for(int i=0; i<n; i++){
                ans.push_back(0);
            }
        }
        return ans;
    }
};