#DP o(n**2), TLE
class Solution:
    def maxEnvelopes(self, envelopes: list[list[int]]) -> int:
        dp = [1 for _ in range(len(envelopes))]
        envelopes.sort(key=lambda a:a[0]+a[1])
        for i in range(len(envelopes)):
            for j in range(i):
                if envelopes[i][0] > envelopes[j][0] and envelopes[i][1] > envelopes[j][1]:
                    dp[i] = max(dp[i],dp[j]+1)
        return max(dp)
    
# LIS, o(nlogn)
class Solution:
    def maxEnvelopes(self, envelopes: list[list[int]]) -> int:
        envelopes.sort(key=lambda a:(a[0],-a[1]))
        sub = []
        def check(val):
            start = 0; end = len(sub)-1
            while start <= end:
                mid = start+(end-start)//2
                if val <= sub[mid]: end = mid-1
                else: start = mid+1
            return start

        for width,height in envelopes:
            if len(sub) == 0 or height > sub[-1]:
                sub.append(height)
            else:
                idx = check(height)
                sub[idx] = height
        return len(sub)
