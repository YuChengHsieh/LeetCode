class Solution:
    def arrayRankTransform(self, arr: list[int]) -> list[int]:
        arr = [(i,num) for i,num in enumerate(arr)]
        arr.sort(key=lambda a : (a[1],a[0]))
        
        ans = [0 for _ in range(len(arr))]
        rank = 0
        prev = 1e9+7
        for idx,num in arr:
            if num != prev: 
                rank += 1
            ans[idx] = rank
            prev = num
        return ans

# Dict, much faster
class Solution:
    def arrayRankTransform(self, arr: list[int]) -> list[int]:
        arr_set = list(set(arr))
        arr_dict = {}

        arr_set.sort()
        for i,num in enumerate(arr_set):
            arr_dict[num] = i+1
        for i in range(len(arr)):
            arr[i] = arr_dict[arr[i]]
        return arr