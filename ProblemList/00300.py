#  DP o(n^2)
class Solution:
    def lengthOfLIS(self, nums: list[int]) -> int:
        dp = [1 for _ in range(len(nums))]
        for i in range(1,len(nums)):
            for j in range(i):
                if nums[i] > nums[j] and dp[i] < dp[j]+1:
                    dp[i] = dp[j]+1
        return max(dp)
# DP o(n^2)
class Solution:
    def lengthOfLIS(self, nums: list[int]) -> int:
        dp = [1 for _ in range(len(nums))]
        for i in range(len(nums)):
            for j in range(i):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i],dp[j]+1)
        return max(dp)

# greedy+BS 0(nlogn)
class Solution:
    def lengthOfLIS(self, nums: list[int]) -> int:
        sub = []
        def check(val):
            start,end = 0,len(sub)-1
            while start <= end:
                mid = start + (end-start)//2
                if val <= sub[mid]: end = mid-1
                else: start = mid+1
            return start
        for num in nums:
            if len(sub) == 0 or num > sub[-1]:
                sub.append(num)
            else:
                idx =check(num)
                sub[idx] = num
        return len(sub)