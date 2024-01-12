class Solution:
    def minMovesToCaptureTheQueen(self, a: int, b: int, c: int, d: int, e: int, f: int) -> int:
        min_move = 2
        if a == e:
            if a ==c and (b < d < f or f < d < b): pass
            else: min_move = 1
        elif b == f:
            if b == d and (a < c < e or e < c < a): pass
            else: min_move = 1
        if c-d == e-f:
            if a-b == e-f and (c < a < e  or e < a < c ): pass
            else: min_move = 1
        elif c+d == e+f:
            if a+b == e+f and (c < a < e  or e < a < c ): pass
            else: min_move = 1
        
        return min_move