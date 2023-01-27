# class Solution:
#     def removeDuplicates(self, nums: list[int]) -> int:
        
#         idx = 0
#         nums_len = len(nums)
#         prev_num = 999
#         while idx < nums_len:
#             if nums[idx] == prev_num:
#                 nums.pop(idx)
#                 nums_len -= 1
#             else:
#                 prev_num = nums[idx]
#                 idx += 1
                
#         return nums_len

class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        cnt = 1
        for i in range(1,len(nums)):
            if nums[i] > nums[i-1]: #not unique
                nums[cnt] = nums[i]
                cnt += 1
        print(nums)
        return cnt
            

if __name__ == '__main__':
    a = Solution()
    print(a.removeDuplicates([1,1,2]))
    print(a.removeDuplicates([0,0,1,1,1,2,2,3,3,4]))