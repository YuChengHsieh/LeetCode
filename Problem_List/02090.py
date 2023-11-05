class Solution:
    def getAverages(self, nums: list[int], k: int) -> list[int]:
        # prefix sum 
        len_ = len(nums)
        rets = [-1 for _ in range(len_)]
        left,right,window_num,dia = 0,0,0,k*2+1
        for i in range(len_):
            window_num += nums[i]
            if right - left == dia-1:
                rets[(right+left)//2] =  window_num//dia
                window_num -= nums[left]
                left += 1; 
            right += 1
            if right == len_:
                break
        return rets