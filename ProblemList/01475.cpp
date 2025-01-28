#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        for(int i=0; i<prices.size(); i++){
            while(!st.empty() && prices[i] <= prices[st.top()]){
                prices[st.top()] -= prices[i];
                st.pop();
            }
            st.push(i);
        }
        return prices;
    }
};