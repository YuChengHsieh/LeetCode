class Solution:
    def maxHeight(self, cuboids: list[list[int]]) -> int:
        for i in cuboids:
            i.sort()
        cuboids.sort(key = lambda a: [-i for i in a])
        dp = [0]*len(cuboids)
        for i in range(len(cuboids)):
            dp[i] = cuboids[i][2]
            for j in range(i):
                if cuboids[i][0] <= cuboids[j][0] and cuboids[i][1] <= cuboids[j][1] and cuboids[i][2] <= cuboids[j][2]:
                    dp[i] = max(dp[i],dp[j]+cuboids[i][2]) 
        return max(dp)