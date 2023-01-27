# Pascal's Triangle
class Solution:
    def generate(self, numRows: int) -> list[list[int]]:
        ans = [[1]]
        for i in range(1,numRows):
            tmp = [1]
            for j in range(1,i):
                tmp.append(ans[i-1][j-1]+ans[i-1][j])
               
            tmp.append(1)
            ans.append(tmp.copy())
        return ans