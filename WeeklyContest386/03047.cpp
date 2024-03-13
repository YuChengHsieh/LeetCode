#include <vector>
using namespace std;
class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long max_square = 0;
        for(int i=0; i<bottomLeft.size(); i++){
            for(int j=i+1; j<bottomLeft.size(); j++){
                int leftX = max(bottomLeft[i][0], bottomLeft[j][0]);
                int rightX = min(topRight[i][0], topRight[j][0]);
                int bottomY = max(bottomLeft[i][1], bottomLeft[j][1]);
                int topY = min(topRight[i][1], topRight[j][1]);

                int width = rightX - leftX;
                int height = topY - bottomY;
                long long min_ = min(width,height);
                if (width <= 0 || height <= 0) continue;
                max_square = max(max_square, min_ * min_);
            }
        }
        return max(max_square,0LL);
    }
};