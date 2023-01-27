# class Solution:
#     def subsetsWithDup(self, nums: list[int]) -> list[list[int]]:
#         check_dict = {}
#         ans_list = []
#         nums_len = len(nums)
#         def rec(idx,tmp_list):
#             if check_dict.get(tuple(sorted(tmp_list))) is None:
#                 ans_list.append(tmp_list.copy())
#                 check_dict[tuple(sorted(tmp_list))] = 1
#             for i in range(idx,nums_len):
#                 tmp_list.append(nums[i])
#                 rec(i+1,tmp_list)
#                 tmp_list.pop()
#             return
#         rec(0,[])
#         return ans_list

class Solution:
    def subsetsWithDup(self, nums: list[int]) -> list[list[int]]:
        ans_list = []
        nums.sort()
        nums_len = len(nums)
        def rec(idx,tmp_list):
            ans_list.append(tmp_list.copy())
            for i in range(idx,nums_len):
                if i > idx and nums[i] == nums[i-1]: continue
                tmp_list.append(nums[i])
                rec(i+1,tmp_list)
                tmp_list.pop()
            return
        rec(0,[])
        return ans_list


if __name__ == '__main__':
    a = Solution()
    print(a.subsetsWithDup([1,2,2]))
    print(a.subsetsWithDup([4,4,4,1,4]))