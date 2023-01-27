# time complexity o(n), space complexity o(n)
# class Solution:
#     def firstMissingPositive(self, nums: list[int]) -> int:
#         li = [0 for _ in range(len(nums))]
        
#         for num in  nums:
#             if num <= len(li) and num>0:
#                 li[num-1] = 1
        
#         for i in range(len(li)):
#             if li[i] == 0:
#                 return i+1
        
#         # if i not meet range, i will not add 1
#         return len(li)

# time complexity o(n), space complexity o(1)
class Solution:
    def firstMissingPositive(self, nums: list[int]) -> int:
        
        i = 0
        while i < len(nums):
            if nums[i] <= len(nums) and nums[i] > 0 and \
                nums[i] != nums[nums[i]-1]:
                # swap
                tmp = nums[nums[i]-1]
                nums[nums[i]-1] = nums[i]
                nums[i] = tmp
                i -= 1
            i += 1

        for i,num in enumerate(nums):
            if num != i+1:
                return i+1
        
        # if i not meet range, i will not add 1
        return len(nums)+1

if __name__ == '__main__':
    a = Solution()
    print(a.firstMissingPositive([-1,4,2,1,9,10]))
    print(a.firstMissingPositive([3,4,-1,1]))
    print(a.firstMissingPositive([7,8,9,11,12]))
    