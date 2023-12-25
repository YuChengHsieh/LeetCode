class Solution:
    def incremovableSubarrayCount(self, nums: list[int]) -> int:
        if len(nums) == 1: return 1
        elif len(nums) == 2: return 3
        n = len(nums)
        left_arr = [nums[0]]
        right_arr = [nums[-1]]
        
        for i in range(1,n):
            if nums[i] <= nums[i-1]: break
            left_arr.append(nums[i])
        
        for j in range(n-2,-1,-1):
            if nums[j] >= nums[j+1]: break
            right_arr.append(nums[j])
        right_arr.reverse()

        i -= 1; j += 1
        if i > j: return (n+1)*n//2
        
        len_left = len(left_arr)
        len_right = len(right_arr)
        ans = len_left + len_right
        i = 0; j = 0 

        while i < len_left and j < len_right:
            if left_arr[i] < right_arr[j]:
                ans += len_right-j
                i += 1
            else: j += 1 

        return ans+1