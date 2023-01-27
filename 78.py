# backtracking 
class Solution:
    def subsets(self, nums: list[int]) -> list[list[int]]:
        ans_list = []
        def rec(idx,tmp_list):
            ans_list.append(tmp_list.copy())

            for i in range(idx,len(nums)):
                tmp_list.append(nums[i])
                rec(i+1,tmp_list)
                tmp_list.pop()
            return
        
        rec(0,[])
        return ans_list

# another backtracking
# class Solution:
#     def subsets(self, nums: list[int]) -> list[list[int]]:
#         ans_list = []
#         def rec(idx,tmp_list):
#             if idx == len(nums): # end condition
#                 ans_list.append(tmp_list.copy())
#                 return

            
#             tmp_list.append(nums[idx])
#             rec(idx+1,tmp_list) # add
#             tmp_list.pop()
#             rec(idx+1,tmp_list)# not add
            
#             return
        
#         rec(0,[])
#         return ans_list

if __name__ == '__main__':
    a = Solution()
    print(a.subsets([1,2,3]))
    print(a.subsets([0]))
        