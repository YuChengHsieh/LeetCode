class Solution:
    def countKeyChanges(self, s: str) -> int:
        prev = s[0]
        ans = 0
        for ch in s[1:]:
            if ch == prev or abs(ord(ch) - ord(prev)) == 32: pass
            else: ans += 1
            prev = ch
        return ans