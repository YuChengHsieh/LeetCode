class Solution:
    def minimumSum(self, nums: list[int]) -> int:
        n = len(nums)
        prefix=[nums[0]]
        suffix=[nums[-1]]
        ans = float('inf')
        for i in range(1,n):
            prefix.append(min(prefix[i-1],nums[i]))
        
        for i in range(1,n):
            suffix.append(min(suffix[i-1],nums[n-i-1]))
        suffix.reverse()
        
        for i in range(1,n-1):
            if prefix[i-1] < nums[i] and suffix[i+1] < nums[i]:
                ans = min(ans,prefix[i-1]+nums[i]+suffix[i+1])
        return -1 if ans == float('inf') else ans