from collections import deque
class Solution:
    def canReach(self, s: str, minJump: int, maxJump: int) -> bool:
        # DP
        if s[0] != '0' or s[-1] != '0': return False
        dp = [False for _ in range(len(s))]
        deq = deque()
        dp[0] = True
        deq.append(0)
        left = 0
        for i in range(1,len(s)):
            if len(deq) > 0 and left > deq[0]: deq.popleft()
            dp[i] = deq[0] <= i-minJump and s[i] == '0' if len(deq) > 0 else False
            if dp[i]: deq.append(i)
            if i >= maxJump: left += 1
        
        return dp[-1]