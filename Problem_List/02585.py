class Solution:
    def waysToReachTarget(self, target: int, types: list[list[int]]) -> int:
        dp = [[-1 for _ in range(target+1)] for _ in range(len(types))]
        mod = 1e9+7
        def rec(target,i):
            if target == 0: return 1
            if target < 0 or i >= len(types): return 0
            if dp[i][target] != -1: return dp[i][target]
            cnt = 0
            cur = target
            for j in range(types[i][0]+1):
                cnt = int((cnt+rec(cur,i+1))%mod)
                cur -= types[i][1]
                if cur < 0: break
            dp[i][target] = cnt
            return cnt
        return rec(target,0)
