class Solution:
    def areNumbersAscending(self, s: str) -> bool:
        splited_li = s.split(" ")
        val = 0
        for cur_s in splited_li:
            if cur_s.isdigit():
                if(int(cur_s) <= val): return False
                else: val = int(cur_s)
        return True