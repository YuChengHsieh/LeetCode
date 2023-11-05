class Solution:
    def findChampion(self, grid: list[list[int]]) -> int:
        ans = -1
        n = len(grid)
        for i,j in enumerate(grid):
            if sum(j) == n-1: return i
                