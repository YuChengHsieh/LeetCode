class Solution:
    def canCross(self, stones: list[int]) -> bool:
        if stones[1] != 1: return False
        dp = {stone:set() for stone in stones}
        dp[0].add(0)
        for stone in stones:
            for j in dp[stone]:
                for step in range(j-1,j+2):
                    if step and stone+step in dp:
                        dp[stone+step].add(step)
        return not dp[stones[-1]] == set()
