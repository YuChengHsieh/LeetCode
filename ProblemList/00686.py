class Solution:
    def repeatedStringMatch(self, a: str, b: str) -> int:
        def check(times):
            tmp_a = a*times
            return True if b in tmp_a else False
        
        start = 1; end = len(b)//len(a)+2
        while start <= end:
            mid = start + (end-start)//2
            if check(mid): end -= 1
            else: start += 1
        return start if start != len(b)//len(a)+3 else -1  