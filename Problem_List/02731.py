class Solution:
    def sumDistance(self, nums: list[int], s: str, d: int) -> int:
        mod = 10**9+7
        n = len(nums)

        for i in range(n):
            if s[i] == 'L': nums[i] -= d
            else: nums[i] += d
        
        cnt = 0
        nums.sort()
        prefix_sum = nums[0]
        """
            if nums = [-3,-1,1]
            we want to compute 2-0, 2-1, 1-0 = 2-(0+1), 1-0
            so use prefix sum
        """
        for i in range(1,n):
            cnt += (nums[i]*i-prefix_sum)%mod
            cnt %= mod
            prefix_sum += nums[i]

        return cnt
