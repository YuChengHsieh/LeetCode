#include <vector>
#include <string>
using namespace std;

// prefix sum, time o(n), space o(1)
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        int moves = 0, balls = 0;
        vector<int> ans(n,0);

        for(int i=0; i<n; i++){
            ans[i] += moves;
            balls += boxes[i] == '1';
            moves += balls;
        }

        moves = 0, balls = 0;
        for(int i=n-1; i>=0; i--){
            ans[i] += moves;
            balls += boxes[i] == '1';
            moves += balls;
        }

        return ans;
    }
};  

// prefix sum, time o(n), space o(n)
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> prefix(n,0), suffix(n,0);
        prefix[0] = boxes[0] == '1';
        suffix[n-1] = boxes[n-1] == '1';

        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] + (boxes[i] == '1');
        }

        for(int i=n-2; i>=0; i--){
            suffix[i] = suffix[i+1] + (boxes[i] == '1');
        }

        vector<int> ans;
        int val = 0;
        for(int i=0; i<n; i++){
            if(boxes[i] == '1') val += i;
        }

        ans.push_back(val);
        for(int i=1; i<n; i++){
            val += prefix[i];
            val -= suffix[i];
            if(boxes[i] == '1') val --;
            ans.push_back(val);
        }
        return ans;
    }
};