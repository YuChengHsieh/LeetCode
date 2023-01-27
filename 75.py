class Solution:
    def sortColors(self, nums: list[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # make sure that idx < idx_0 is all 0 and idx > idx_2 is all 2
        # idx_left, idx_right are moving cursors
        idx_0 = idx_left = 0
        idx_2 = idx_right = len(nums)-1

        while idx_left < idx_2 and idx_right > idx_0:
            if nums[idx_left] == 2:
                tmp = nums[idx_2]
                nums[idx_2] = nums[idx_left]
                nums[idx_left] = tmp
                idx_2 -= 1
            else:
                idx_left += 1
            if nums[idx_right] == 0:
                tmp = nums[idx_0]
                nums[idx_0] = nums[idx_right]
                nums[idx_right] = tmp
                idx_0 += 1
            else:
                idx_right -= 1
        print(nums)

if __name__ == '__main__':
    a = Solution()                       
    # a.sortColors([2,0,2,1,1,0])
    # a.sortColors([2,0,1])
    a.sortColors([2,2,2,2,1,1])
                