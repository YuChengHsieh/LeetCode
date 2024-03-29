# swap
class Solution:
    def findErrorNums(self, nums: list[int]) -> list[int]:
        n = len(nums)
        i = 0
        while i < n:
            if i+1 != nums[i]:
                if nums[nums[i]-1] == nums[i]: 
                    ans = nums[i]
                    break
                tmp = nums[nums[i]-1]
                nums[nums[i]-1] = nums[i]
                nums[i] = tmp
            else:
                i += 1
        return [ans] + [n*(n+1)//2-(sum(nums)-ans)]

# use sum
class Solution:
    def findErrorNums(self, nums: list[int]) -> list[int]:
        n = len(nums)
        miss_val = n*(n+1)//2 - sum(set(nums))
        duplicated_num = sum(nums) + miss_val - n*(n+1)//2 
        return [duplicated_num, miss_val]