class Solution:
    def targetIndices(self, nums: list[int], target: int) -> list[int]:
        nums.sort()
        def choose(idx,right):
            if right: return nums[idx] <= target
            else: return nums[idx] < target
        
        def bs(target,right):
            start = 0; end = len(nums)-1
            while start <= end:
                mid = start+(end-start)//2
                if choose(mid,right): start = mid+1 
                else: end = mid-1
            return end if right else start
        
        start = bs(target,False)
        if start >= len(nums) or nums[start] != target: return []
        end = bs(target,True)
        return [i for i in range(start,end+1)]