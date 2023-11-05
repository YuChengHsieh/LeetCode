class Solution:
    def sortByBits(self, arr: list[int]) -> list[int]:
        n = len(arr)
        order = [0]*n
        for i,num in enumerate(arr):
            cnt = 0
            while num != 0:
                num &= (num-1)
                cnt += 1
            order[i] = cnt
        return list(zip(*sorted(list(zip(arr,order)),key = lambda a: (a[-1],a[0]))))[0]