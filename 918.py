# TLE
# class Solution:
#     def maxSubarraySumCircular(self, nums: list[int]) -> int:
#         min_num = min(nums)
#         # rotate nums
#         for i,num in enumerate(nums):
#             if num == min_num:
#                 min_idx = i
        
#         for _ in range(min_idx,len(nums)-1):
#             tmp = nums.pop()
#             nums.insert(0,tmp)
        
#         self.nums = nums
#         self.max = -999999999
#         self.first = True
#         self.rec(0,0)
#         return self.max
        
#     def rec(self,idx,sum):
#         if sum > self.max:
#             if self.first:
#                 self.first = False
#             else:    
#                 self.max = sum
#         if idx >= len(self.nums):
#             return
#         for i in range(idx,len(self.nums)):
#             self.rec(i+1,sum+self.nums[i])
#             sum = 0
        
#         return

# Kedane's algorithm
class Solution:
    def maxSubarraySumCircular(self, nums: list[int]) -> int:
        total_sum,global_min,global_max,cur_minSum,cur_maxSum = 0,30000,-30000,0,0

        for num in nums:
            cur_maxSum = max(num,cur_maxSum+num)
            global_max = max(global_max,cur_maxSum)
            
            cur_minSum = min(num,cur_minSum+num)
            global_min = min(global_min,cur_minSum)
            
            total_sum += num
            
        
        return global_max if global_max < 0 else\
            max(global_max,total_sum-global_min)


if __name__ == '__main__':
    a = Solution()
    print(a.maxSubarraySumCircular([-3,-2,-3]))
    print(a.maxSubarraySumCircular([1,-2,3,-2]))
    print(a.maxSubarraySumCircular([5,-3,5]))
    print(a.maxSubarraySumCircular([-5,4,-6]))
    print(a.maxSubarraySumCircular([-2,4,-5,4,-5,9,4]))
    