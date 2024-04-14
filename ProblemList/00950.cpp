#include <vector>
#include <queue>
using namespace std;

// o(nlogn) sorting
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        int n = deck.size(), deck_idx = 0;
        vector<int> ans(n,0);
        
        queue<int> q;
        for(int i=0; i<n; i++){
            q.push(i);
        }
        while(!q.empty()){
            ans[q.front()] = deck[deck_idx++];
            q.pop();
            q.push(q.front());
            q.pop();
        }
        return ans;
    }
};