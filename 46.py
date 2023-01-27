# class Solution:
#     def permute(self, nums: list[int]) -> list[list[int]]:
#         self.nums = nums
#         self.ans = []
#         self.rec([])
#         return self.ans
        
#     def rec(self,ans_per):
#         if len(ans_per) == len(self.nums):
#             self.ans.append(ans_per.copy())
#             return
        
#         for num in self.nums:
#             if num not in ans_per:
#                 ans_per.append(num)
#                 self.rec(ans_per)
#                 ans_per.pop()
#         return

class Solution:
    def permute(self, nums: list[int]) -> list[list[int]]:
        ans_list = []
        def rec(ans_permu,avail_list):
            if len(avail_list) == 0:
               ans_list.append(ans_permu.copy())
               return
           
            for i in range(len(avail_list)):
                tmp_num = avail_list.pop(i)
                ans_permu.append(tmp_num)
                rec(ans_permu,avail_list)
                ans_permu.pop()
                avail_list.insert(i,tmp_num)    
            return
        rec([],nums)
        return ans_list

if __name__ == '__main__':
    a = Solution()
    print(a.permute([1,2,3]))
    print(a.permute([0,1]))
    print(a.permute([1]))