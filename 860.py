class Solution:
    def buddyStrings(self, s: str, goal: str) -> bool:
        if len(set(s)) < len(s) and s==goal:
            return True
        if len(s) != len(goal):
            return False
        
        cnt = []
        for i in range(len(s)):
            if s[i] != goal[i]:
                cnt.append((s[i],goal[i]))
            if len(cnt) > 2:
                return False
        return True if len(cnt) == 2 and cnt[0][0] == cnt[1][1] and cnt[0][1] == cnt[1][0] else False