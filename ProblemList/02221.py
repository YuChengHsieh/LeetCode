# o(n^2)
class Solution:
    def triangularSum(self, nums: list[int]) -> int:
        len_ = len(nums)
        for i in range(len_-1):
            tmp = []
            for j in range(len(nums)-1):
                tmp.append((nums[j]+nums[j+1])%10)
            nums = tmp.copy()
        return nums[0]

# o(n)
class Solution:
    def triangularSum(self, nums: list[int]) -> int:
        result = 0
        m = len(nums) - 1
        mCk = 1
        for k, num in enumerate(nums):
            result = (result + mCk * num) % 10
            mCk *= m - k
            mCk //= k + 1
        return result
        