# o(n^3)
class Solution:
    def countTriplets(self, arr: list[int]) -> int:
        n = len(arr)
        cnt = 0
        for i in range(n):
            xi = arr[i]
            for j in range(i+1,n):
                xj = 0
                for k in range(j,n):
                    xj ^= arr[k]
                    if xi == xj: cnt += 1
                xi ^= arr[j]
        return cnt

# o(n^2)
class Solution:
    def countTriplets(self, arr: list[int]) -> int:
        arr.insert(0,0)
        n = len(arr)
        for i in range(n-1):
            arr[i+1] ^= arr[i]
        
        cnt = 0
        for i in range(n):
            for j in range(i+1,n):
                if arr[i] == arr[j]:
                    cnt += j-i-1
        return cnt