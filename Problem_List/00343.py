# o(n)
class Solution:
    def integerBreak(self, n: int) -> int:
        tmp = [1,1]
        for i in range(n-1):
            ans = 1
            for j in tmp:
                ans *= j
            tmp.sort()
            tmp[0] += 1
            if tmp[0] == 4:
                tmp[0] = 2
                tmp.append(2)
                tmp.sort()
        return ans

# o(n^2)
class Solution:
    def integerBreak(self, n: int) -> int:
        dp = [0 for _ in range(n+1)]
        dp[0] = 1
        for i in range(1,len(dp)):
            for j in range(1,min(n,i+1)):
                dp[i] = max(dp[i],j*dp[i-j])
        return dp[-1]