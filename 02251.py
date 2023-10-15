from bisect import bisect_left,bisect_right
class Solution:
    def fullBloomFlowers(self, flowers: list[list[int]], people: list[int]) -> list[int]:
        zip_flower = list(zip(*flowers))
        flowers_start, flowers_end = sorted(zip_flower[0]),sorted(zip_flower[1])

        return [bisect_right(flowers_start,person)-bisect_left(flowers_end,person) for person in people]