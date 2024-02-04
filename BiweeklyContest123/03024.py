class Solution:
    def triangleType(self, nums: list[int]) -> str:
        nums.sort()
        return "none" if nums[0]+nums[1] <= nums[2] else \
                "equilateral" if nums[0] == nums[1] == nums[2] else \
                "isosceles" if nums[0] == nums[1] or nums[1] == nums[2] else \
                "scalene"