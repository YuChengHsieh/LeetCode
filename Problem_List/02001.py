from collections import defaultdict
class Solution:
    def interchangeableRectangles(self, rectangles: list[list[int]]) -> int:
        cnt = 0
        pair = defaultdict(int)
        for width,height in rectangles:
            cnt += pair[width/height] 
            pair[width/height] += 1
        return cnt