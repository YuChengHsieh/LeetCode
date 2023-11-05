# class Solution:
#     def removeElement(self, nums: list[int], val: int) -> int:
#         nums_len = len(nums)
#         idx = 0
#         while idx < nums_len:
#             if nums[idx] == val:
#                 nums.pop(idx)
#                 nums_len -= 1
#             else:
#                 idx += 1
#         return nums_len

class Solution:
    def removeElement(self, nums: list[int], val: int) -> int:
        cnt = 0
        for i in range(len(nums)):
            if nums[i] != val:
                nums[cnt] = nums[i]
                cnt += 1
        return cnt
        
if __name__ == '__main__':
    a = Solution()
    print(a.removeElement([3,2,2,3],3))
    print(a.removeElement([0,1,2,2,3,0,4,2],2))