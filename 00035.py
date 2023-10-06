class Solution:
    def searchInsert(self, nums: list[int], target: int) -> int:
        
        start_idx, end_idx = 0,len(nums)-1
        
        if len(nums) == 1:
            return start_idx if target <= nums[start_idx] else end_idx+1
        
        # while True:
        #     middle_idx = (start_idx+end_idx)//2
        #     middle_val = nums[middle_idx]
            
        #     if target == middle_val:
        #         return middle_idx
        #     elif target > middle_val:
        #         start_idx = middle_idx
        #     else:
        #         end_idx = middle_idx
            
        #     if start_idx+1 >= end_idx:
        #         return start_idx if target <= nums[start_idx] else \
        #                 end_idx+1 if target > nums[end_idx] else \
        #                 end_idx
        
        start_idx,end_idx = 0, len(nums)-1
        
        while start_idx <= end_idx:
            mid_idx = (start_idx+end_idx)//2
            mid_val = nums[mid_idx]
            
            if mid_val == target:
                return mid_idx
            elif target < mid_val:
                end_idx = mid_idx-1
            else:
                start_idx = mid_idx+1
        
        return start_idx 
        
if __name__ == '__main__':
    a = Solution()
    print(a.searchInsert([1,3,5,6],7))
    print(a.searchInsert([1,3,5,6],2))
    print(a.searchInsert([1,3],0))