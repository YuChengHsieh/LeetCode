class Solution:
    def isReachableAtTime(self, sx: int, sy: int, fx: int, fy: int, t: int) -> bool:
        return False if sx == fx and sy == fy and t == 1 else abs(fx-sx) <= t and abs(fy-sy) <= t