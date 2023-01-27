class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        flower_len = len(flowerbed)
        if flower_len == 1:
            return True if n == 0 or (flowerbed[0] == 0 and n == 1) else False
        if flowerbed[0] == 0 and flowerbed[1] == 0:
            flowerbed[0] = 1
            n-=1
        if flowerbed[flower_len-1] == 0 and flowerbed[flower_len-2] == 0:
            flowerbed[flower_len-1] = 1
            n-=1
        if n<=0:
            return True
        for i in range(1,flower_len-1):
            if flowerbed[i-1] == 0 and flowerbed[i] == 0 \
            and flowerbed[i+1] == 0:
                flowerbed[i] = 1
                n-=1
            if n==0:
                return True
        return False