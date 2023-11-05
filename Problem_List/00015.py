# class Solution:
#     def threeSum(self, nums: list[int]) -> list[list[int]]:
#         ans_list = []
#         nums.sort()
#         check_dict = {}
#         num_len = len(nums)
        
#         for i in range(num_len):
#             left = i-1
#             right = i+1
            
#             while left>=0 and right<num_len:
#                 sum_ = nums[i] + nums[left] + nums[right]
#                 if sum_ > 0:
#                     left -= 1
#                 elif sum_ < 0:
#                     right += 1
#                 else:
#                     if check_dict.get(tuple([nums[left],nums[i],nums[right]])) is None:
#                         ans_list.append([nums[left],nums[i],nums[right]])
#                         check_dict[tuple([nums[left],nums[i],nums[right]])] = 1
#                     left -= 1
#                     right += 1
        
#         return ans_list

class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        ans_list = []
        nums.sort()
        check_dict = {}
        num_len = len(nums)
        
        for i in range(num_len):
            left = i+1
            right = num_len-1
            
            while left < right:
                sum_ = nums[i] + nums[left] + nums[right]
                if sum_ > 0:
                    right -= 1
                elif sum_ < 0:
                    left += 1
                else:
                    if check_dict.get(tuple([nums[i],nums[left],nums[right]])) is None:
                        ans_list.append([nums[i],nums[left],nums[right]])
                        check_dict[tuple([nums[i],nums[left],nums[right]])] = 1
                    left += 1
                    right -= 1
        
        return ans_list

if __name__ == '__main__':
    a = Solution()
    print(a.threeSum([-1,0,1,2,-1,-4]))
    print(a.threeSum([0,1,1]))
    print(a.threeSum([0,0,0,0]))