# not subarray
# class Solution:
#     def subarraysDivByK(self, nums: list[int], k: int) -> int:
#         self.nums = nums
#         self.k = k
#         self.cnt = 0
#         self.first = False
#         self.rec(0,0)
#         return self.cnt
    
#     def rec(self, idx:int, cur_sum:int):
#         if cur_sum%self.k == 0:
#             if not self.first:
#                 self.first = True
#             else:
#                 self.cnt += 1
#                 print(cur_sum)
#                 # print('in')
            
#         for i,num in enumerate(self.nums[idx:]):
#             cur_sum += num
#             self.rec(idx+i+1,cur_sum)
#             cur_sum -= num
        
#         return

# o(n^2) not gonna pass
# class Solution:
#     def subarraysDivByK(self, nums: list[int], k: int) -> int:
#         cnt = 0
#         cur_sum = 0
        
#         for idx,first_num in enumerate(nums):
#             cur_sum += first_num
#             if cur_sum % k == 0:
#                 cnt += 1
#             for num in nums[idx+1:]:
#                 cur_sum += num 
#                 if cur_sum % k == 0:
#                     cnt += 1
#             cur_sum = 0
        
#         return cnt

# o(n) use prefix sum
class Solution:
    def subarraysDivByK(self, nums: list[int], k: int) -> int:
        same_residual  = [0 for _ in range(k)]
        same_residual[0] += 1 # 0 means can divide
        cur_sum = 0
        cnt = 0 
        for i in range(len(nums)):
            cur_sum = (cur_sum+nums[i])%k #use prefix sum
            cnt += same_residual[cur_sum]
            same_residual[cur_sum] += 1

        return cnt
    
if __name__ == '__main__':
    a = Solution()
    print(a.subarraysDivByK([-4,-5,0,2,3,1],5))
    print(a.subarraysDivByK([5],9))