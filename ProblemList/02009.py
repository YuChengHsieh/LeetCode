class Solution:
    def minOperations(self, nums: list[int]) -> int:
        n = len(nums)
        nums = sorted(set(nums))

        ans = float('inf')
        for i,num in enumerate(nums):
            search_val = num+n-1

            start = 0; end = len(nums)-1
            while start <= end:
                mid = start+(end-start)//2
                if nums[mid] <= search_val: start = mid+1
                else: end = mid-1
            ans = min(ans, n-start+i)
        return ans

# Use bisect_right to speed up the search
from bisect import bisect_right
class Solution:
    def minOperations(self, nums: list[int]) -> int:
        n = len(nums)
        nums = sorted(set(nums))

        ans = float('inf')
        for i,num in enumerate(nums):
            search_val = num+n-1
            idx = bisect_right(nums,search_val)
            ans = min(ans, n-idx+i)
        return ans