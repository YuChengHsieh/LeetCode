# BST
class Solution:
    def maxProfitAssignment(self, difficulty: list[int], profit: list[int], worker: list[int]) -> int:
        mix_array = []
        for i in range(len(difficulty)):
            mix_array.append((difficulty[i],profit[i]))
        mix_array.sort(key=lambda x: (x[0],x[1]))
        
        cur_max_profit = 0
        i = 0
        while i < len(mix_array):
            if mix_array[i][1] < cur_max_profit:
                mix_array.pop(i)
                i -= 1
            else:
                cur_max_profit = mix_array[i][1]
            i += 1
        
        mix_arr_len = len(mix_array)
        ans = 0
        for i in worker:
            start = 0; end = mix_arr_len-1
            while start <= end:
                mid = start + (end-start)//2
                if i >= mix_array[mid][0]:
                    start = mid+1
                else:
                    end = mid-1
            if end != -1:
                ans += mix_array[end][1]
        return ans
            