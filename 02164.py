class Solution:
    def sortEvenOdd(self, nums: list[int]) -> list[int]:
        nums_odd = []
        nums_even = []
        for i in range(len(nums)):
            if i%2 == 0:
                nums_even.append(nums[i])
            else:
                nums_odd.append(nums[i])
        
        nums_even.sort()
        nums_odd.sort(reverse=True)
        ans = []
        for i in range(len(nums_even)):
            ans.append(nums_even[i])
            if i < len(nums_odd):
                ans.append(nums_odd[i])
        return ans