# Prefix and suffix
class Solution:
    def productExceptSelf(self, nums: list[int]) -> list[int]:
        n = len(nums)
        prefix = [1 for _ in range(n)]
        suffix = [1 for _ in range(n)]
        prefix[0] = nums[0]
        suffix[-1] = nums[-1]
        for i in range(1,n):
            prefix[i] = prefix[i-1]*nums[i]
        for i in range(n-2,-1,-1):
            suffix[i] = suffix[i+1]*nums[i]
        ans = []
        ans.append(suffix[1])
        for i in range(1,n-1):
            ans.append(prefix[i-1]*suffix[i+1])
        ans.append(prefix[-2])
        return ans