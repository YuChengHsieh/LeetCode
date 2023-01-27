class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        cnt = 1
        cnt_2 = 1
        for i in range(1,len(nums)):
            if nums[i-1] < nums[i]:
                nums[cnt] = nums[i]
                cnt_2 = 1
                cnt += 1
            elif nums[i-1] == nums[i] and cnt_2 < 2: # move at most one identical element
                nums[cnt] = nums[i]
                cnt += 1
                cnt_2 += 1
        return cnt

if __name__ == '__main__':
    a = Solution()
    print(a.removeDuplicates([1,1,1,2,2,3]))
    print(a.removeDuplicates([0,0,1,1,1,1,2,3,3]))
                