class Solution:
    def searchRange(self, nums: list[int], target: int) -> list[int]:
        
        start_idx,end_idx = 0,len(nums)-1
        
        if len(nums) == 1 and nums[start_idx] == target:
            return [start_idx,end_idx]
        
        while start_idx < end_idx:
            middle_idx = (start_idx+end_idx+1)//2
            middle_val = nums[middle_idx]
            start_val = nums[start_idx]
            end_val = nums[end_idx]
            
            if middle_val == target:
                return self.find_first_and_last(nums,target,middle_idx)
            elif end_val == target:
                return self.find_first_and_last(nums,target,end_idx)
            elif start_val == target:
                return self.find_first_and_last(nums,target,start_idx)
            
            elif target < middle_val:
                end_idx = middle_idx-1
            else: # target > middle_val
                start_idx = middle_idx
        
        return [-1,-1]
    
    def find_first_and_last(self, nums: list[int], target: int, idx: int) -> list[int]:
        
        start = -1
        end = -1
        span = 1
        
        while start == -1 or end == -1:
            if start == -1 and (idx-span < 0 or nums[idx-span] != target):
                start = idx-span+1 
            if end == -1 and (idx + span >= len(nums) or nums[idx+span] != target):
                end = idx+span-1
            span += 1
        
        return [start,end]

class Solution:
    def searchRange(self, nums: list[int], target: int) -> list[int]:
        if len(nums) == 0: return [-1,-1]
        # Binary Search
        # find start position
        start = 0; end = len(nums)-1
        while start <= end:
            mid = start+(end-start)//2
            if(nums[mid] < target): start = mid+1
            else: end = mid-1
        if start >= len(nums) or nums[start] != target: return [-1,-1]
        # find end position
        ans_start = start
        start = 0; end = len(nums)-1
        while start <= end:
            mid = start+(end-start)//2
            if(nums[mid] <= target): start = mid+1
            else: end = mid-1
        return [ans_start,end]
if __name__ == '__main__':
    a = Solution()
    print(a.searchRange([5,7,7,8,8,10],8))
    print(a.searchRange([5,7,7,8,8,10],6))
    print(a.searchRange([1,2,3],3))