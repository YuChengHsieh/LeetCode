# memorization
class Solution:
    def paintWalls(self, cost: list[int], time: list[int]) -> int:
        n = len(cost)
        postfix = [0 for _ in range(n+1)]
        postfix[n-1] = time[-1]
        for i in range(1,n):
            postfix[n-i-1] = postfix[n-i] + time[n-i-1]
        
        mem = {}
        def dp(idx,time_consumed):
            if (idx,time_consumed) in mem: return mem[(idx,time_consumed)]
            elif time_consumed+postfix[idx] < 0: return float('inf')
            elif idx == n or time_consumed >= n-idx: return 0
            cur_cost = min(cost[idx]+dp(idx+1,time_consumed+time[idx]), #paid painter 
            dp(idx+1,time_consumed-1)) # free painter
            mem[(idx,time_consumed)] = cur_cost
            return cur_cost
        return dp(0,0)

class Solution:
    def paintWalls(self, cost: list[int], time: list[int]) -> int:
        n = len(cost)
        dp = [0] + [float('inf')]*n

        for c,t in zip(cost,time):
            for j in range(n,0,-1):
                dp[j] = min(dp[j],dp[max(j-t-1,0)]+c)
        return dp[-1]
