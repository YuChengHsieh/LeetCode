# Only DP (TLE) o(n*2)
from numpy import inf
class Solution:
    def maxResult(self, nums: list[int], k: int) -> int:
        dp = [-inf for _ in range(len(nums))]
        dp[0] = nums[0]
        for i in range(1,len(nums)):
            for j in range(i-k,i):
                if j>=0:
                    dp[i] = max(dp[j]+nums[i],dp[i])
        return dp[-1]

# DP + deque o(n)
from collections import deque
class Solution:
    def maxResult(self, nums: list[int], k: int) -> int:
        dp = [0 for _ in range(len(nums))]
        deq = deque()
        left=0
    
        for i in range(len(nums)):
            dp[i] = dp[deq[0]] + nums[i] if len(deq) > 0 else nums[i]
            while len(deq) != 0 and dp[i] > dp[deq[-1]]:
                deq.pop()
            deq.append(i)
            if left > deq[0]: deq.popleft()
            if i+1>=k: left += 1
        print(dp)
        return dp[-1]