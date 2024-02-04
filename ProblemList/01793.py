# Two pointer
class Solution:
    def maximumScore(self, nums: list[int], k: int) -> int:
        n = len(nums)
        left = k-1; right = k+1
        height = nums[k]
        max_area = nums[k]
        while left >= 0 and right < n:
            # both heights < nums[k]
            if nums[left] > nums[right]: 
                height = min(height,nums[left])
                area = (right-left)*height
                left -= 1
            else:
                height = min(height,nums[right])
                area = (right-left)*height
                right += 1
            max_area = max(max_area,area)
        else:
            while left >= 0:
                height = min(height,nums[left])
                area = (right-left)*height
                left -= 1
                max_area = max(max_area,area)
            
            while right < n:
                height = min(height,nums[right])
                area = (right-left)*height
                right += 1
                max_area = max(max_area,area)
        return max_area
        