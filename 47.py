# class Solution:
#     def permuteUnique(self, nums: list[int]) -> list[list[int]]:
#         self.nums = nums
#         self.ans = []
#         self.rec([],[])
#         return self.ans
        
#     def rec(self,index_list,ans_per):
#         if len(ans_per) == len(self.nums):
#             if ans_per not in self.ans:
#                 self.ans.append(ans_per.copy())
#             return
        
#         for i in range(len(self.nums)):
#             if i not in index_list:
#                 ans_per.append(self.nums[i])
#                 index_list.append(i)
#                 self.rec(index_list,ans_per)
#                 ans_per.pop()
#                 index_list.pop()
#         return

class Solution:
    def permuteUnique(self, nums: list[int]) -> list[list[int]]:
        self.nums = nums
        self.ans = []
        self.rec([],[])
        return self.ans
        
    def rec(self,index_list,ans_per):
        if len(ans_per) == len(self.nums):
            if ans_per not in self.ans:
                self.ans.append(ans_per.copy())
            return

        appear_list = [] # to determine nums that see in this for loop
        for i in range(len(self.nums)):
            if i not in index_list and self.nums[i] not in appear_list:
                ans_per.append(self.nums[i])
                index_list.append(i)
                appear_list.append(self.nums[i])
                self.rec(index_list,ans_per)
                ans_per.pop()
                index_list.pop()
        return


if __name__ == '__main__':
    a = Solution()
    print(a.permuteUnique([1,1,2]))
    print(a.permuteUnique([0,1]))
    print(a.permuteUnique([1]))