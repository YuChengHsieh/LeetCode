class Solution:
    def constructProductMatrix(self, grid: list[list[int]]) -> list[list[int]]:
        MOD = 12345; all_product = 1
        n = len(grid); m = len(grid[0])
        prefix = [1]
        suffix = [1]
        
        for i in range(n):
            for j in range(m):
                prefix.append((prefix[-1]*grid[i][j])%MOD)
        
        for i in range(n-1,-1,-1):
            for j in range(m-1,-1,-1):
                suffix.append((suffix[-1]*grid[i][j])%MOD)
        suffix.reverse()

        ans = []
        for i in range(n):
            tmp = []
            for j in range(m):
                cnt = i*m+j+1
                tmp.append((prefix[cnt-1]*suffix[cnt])%MOD)
            ans.append(tmp.copy())
        return ans