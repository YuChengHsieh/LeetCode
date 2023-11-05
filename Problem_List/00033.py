# class Solution:
#     def search(self, nums: list[int], target: int) -> int:
        
#         start_idx,end_idx = 0,len(nums)-1
#         middle_idx = (start_idx+end_idx+1)//2
        
#         if nums[middle_idx] == target:
#             return middle_idx
        
#         while start_idx < end_idx:
#             middle_idx = (start_idx+end_idx)//2
#             middle_num = nums[middle_idx]
#             start_num = nums[start_idx]
            
#             if target == middle_num:
#                 return middle_idx
            
#             if middle_num >= start_num:
#                 if target < middle_num and target >= start_num:
#                     end_idx = middle_idx
#                 elif target > middle_num or target < start_num:
#                     start_idx = middle_idx+1
#             else:
#                 if target > middle_num and target < start_num:
#                     start_idx = middle_idx+1
#                 elif target < middle_num or target >= start_num:
#                     end_idx = middle_idx
        
#         return start_idx if nums[start_idx] == target else -1

class Solution:
    def search(self, nums: list[int], target: int) -> int:
        nums_len = len(nums)
        start,end = 0,nums_len-1
        
        while start <= end:
            mid = start+(end-start)//2
            print(start,mid,end)
            if target == nums[mid]:
                return mid
            elif nums[mid] >= nums[start]: # minimum number is inside mid~end
                if target < nums[mid] and target >= nums[start]:
                    end = mid-1
                else:
                    start = mid+1
            else: # nums[mid] < nums[start], minimum number is inside start~mid
                if target <= nums[end] and target > nums[mid]:
                    start = mid+1
                else:
                    end = mid-1
        return -1

if __name__ == '__main__':
    a = Solution()
    print(a.search([4,5,6,7,0,1,2],0))
    print(a.search([4,5,6,7,0,1,2],3))
    print(a.search([1,2,3,4,5],4))