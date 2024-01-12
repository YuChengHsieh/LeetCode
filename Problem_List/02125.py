class Solution:
    def numberOfBeams(self, bank: list[str]) -> int:
        
        ans = 0
        prev_sec = 0
        for row in bank:
            num_sec = 0
            for pos in row:
                if pos == '1': num_sec += 1
            ans += num_sec*prev_sec
            if num_sec != 0: prev_sec = num_sec
        return ans