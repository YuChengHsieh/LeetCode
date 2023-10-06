# slow fast pointer
class Solution:
    def findDuplicate(self, nums: list[int]) -> int:
        
        slow, fast = nums[0], nums[0]

        while True:
            slow = nums[slow]
            fast = nums[nums[fast]]
            if slow == fast:
                break
        
        slow = nums[0]
        while slow != fast:
            slow = nums[slow]
            fast = nums[fast]
        
        return fast

# nagative solution
class Solution:
    def findDuplicate(self, nums: list[int]) -> int:
        for num in nums:
            idx = abs(num)
            if nums[idx] < 0: return idx
            nums[idx] = -nums[idx]
        return len(nums)