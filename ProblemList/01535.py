class Solution:
    def getWinner(self, arr: list[int], k: int) -> int:
        if k > len(arr): return max(arr)
        arr += arr
        cur = arr[0]
        cnt = 0
        n = len(arr)
        for i in range(n-1):
            if cur > arr[i+1]:
                cnt += 1
            else:
                cur = arr[i+1]
                cnt = 1
            if cnt == k: return cur