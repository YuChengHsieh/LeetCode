class Solution:
    def longestSubsequence(self, arr: list[int], difference: int) -> int:
        #DP
        record = {}
        max_len = 0
        for i in arr:
            if not record.get(i-difference):
                record[i] = 1
            else:
                record[i] = 1+record[i-difference]
            if record[i] > max_len:
                max_len = record[i]
        
        return max_len