#include <vector>
using namespace std;
class Solution {
private:
    int dp(int idx, int max_height, int width, int shelfWidth, vector<vector<int>>& books, vector<vector<int>>& mem){
        if(idx == mem.size()) return max_height;
        if(mem[idx][width] != -1) return mem[idx][width];
        int ans = dp(idx+1,books[idx][1],books[idx][0],shelfWidth,books,mem)+max_height;
        if(width+books[idx][0] <= shelfWidth) ans = min(ans,dp(idx+1,max(max_height,books[idx][1]),width+books[idx][0],shelfWidth,books,mem));
        return mem[idx][width] = ans;
    }
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<vector<int>> mem(books.size(), vector<int>(shelfWidth+1,-1));
        return dp(0,0,0,shelfWidth,books,mem);
    }
};