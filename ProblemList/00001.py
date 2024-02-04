class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        for i,val in enumerate(nums):
            other = target - val
            print(i,other)
            try:
                idx = nums[i+1:].index(other)
                return (i,idx+i+1)
            except:
                continue
            
if __name__ == '__main__':
    a = Solution()
    print(a.twoSum([2,7,11,15],9))