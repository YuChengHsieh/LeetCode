class Solution:
    def missingInteger(self, nums: list[int]) -> int:
        prev = nums[0]
        seq = [nums[0]]
        for num in nums[1:]:
            if num ==  prev + 1:
                seq.append(num)  
            else: break
            prev = num
        
        nums.sort()
        while x in nums:
            x += 1
        return x