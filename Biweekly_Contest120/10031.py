class Solution:
    def incremovableSubarrayCount(self, nums: list[int]) -> int:
        len_nums = len(nums)
        ans = 0
        
        def check(li):
            prev = -1
            for num in li:
                if num <= prev: return False
                prev = num
            return True
        
        for i in range(1,len_nums+1):
            for j in range(len_nums-i+1):
                li = nums[:j]+nums[j+i:]
                if(check(li)): ans += 1
        
        return ans