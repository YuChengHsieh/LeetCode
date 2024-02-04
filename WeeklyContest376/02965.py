class Solution:
    def findMissingAndRepeatedValues(self, grid: list[list[int]]) -> list[int]:
        n = len(grid)
        ans = [-1]*2
        not_seen = set([i for i in range(1,n*n+1)])
        for i in range(n):
            for j in range(n):
                if grid[i][j] not in not_seen: ans[0] = grid[i][j]
                else: not_seen.remove(grid[i][j])
        ans[1] = list(not_seen)[0]
        return ans