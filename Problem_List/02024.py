class Solution:
    def maxConsecutiveAnswers(self, answerKey: str, k: int) -> int:
        T_num = 0
        F_num = 0
        max_cont = 0
        left,right= 0,0

        while right < len(answerKey):
            if min(T_num,F_num) <= k:
                if answerKey[right] == 'T':
                    T_num += 1
                else:
                    F_num += 1
                if right-left > max_cont:
                    max_cont = right-left
                right += 1
            else:
                if answerKey[left] == 'T':
                    T_num -= 1
                else:
                    F_num -= 1
                left += 1
        else:
            if min(T_num,F_num) <= k and right-left > max_cont:
                max_cont = right-left
        return max_cont
            