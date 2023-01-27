class Solution:
    def nextPermutation(self, nums: list[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        prev = nums[-1]
        cnt = [nums[-1]]
        for i,cur in reversed(list(enumerate(nums[:-1]))):
            cnt.append(cur)
            
            # finding nums[i+1] > num[i] change num[i] to closet value j (j>num[i]), 
            # the rest of values will be sort in lexigraphical 
            if cur - prev < 0:
                cnt.sort()
                for j,ele in enumerate(cnt):
                    if ele - cur > 0:
                        min_idx = j
                        break
                nums[i] = cnt.pop(min_idx)
                nums[i+1:] = cnt
                break
            prev = cur
        else:
            # could not find nums[i+1] > num[i], the next permutation just reverse of original nums
            nums.reverse()
        print(nums)

if __name__ == '__main__':
    a = Solution()
    a.nextPermutation([1,2,3])
    a.nextPermutation([3,2,1])
    a.nextPermutation([1,5,5])
    a.nextPermutation([2,1,4,3])
    a.nextPermutation([2,3,1,4])
    a.nextPermutation([1,3,6,5,2])