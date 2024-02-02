from collections import defaultdict
class Solution:
    def maxFrequencyElements(self, nums: list[int]) -> int:
        freq_dict = defaultdict(int)
        
        for num in nums:
            freq_dict[num] += 1
        
        max_freq = 0
        max_num = 0
        for val in freq_dict.values():
            if val > max_freq:
                max_num = val
                max_freq = val
            elif val == max_freq:
                max_num += val
        
        return max_num