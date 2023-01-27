class Solution:
    def romanToInt(self, s: str) -> int:
        sum = 0
        money_dict = {'M':1000,'D':500,'C':100,'L':50,'X':10,'V':5,'I':1}
        cursor = 0
        str_len = len(s)
        while cursor < str_len:
            if cursor +1 < str_len:
                if s[cursor] == 'I'and s[cursor+1] =='V':
                    sum += 4
                    cursor += 2
                elif s[cursor] == 'I'and s[cursor+1] =='X':
                    sum += 9
                    cursor += 2
                elif s[cursor] == 'X'and s[cursor+1] =='L':
                    sum += 40
                    cursor += 2
                elif s[cursor] == 'X'and s[cursor+1] =='C':
                    sum += 90
                    cursor += 2
                elif s[cursor] == 'C'and s[cursor+1] =='D':
                    sum += 400
                    cursor += 2
                elif s[cursor] == 'C'and s[cursor+1] =='M':
                    sum += 900
                    cursor += 2
                    
                else:
                    sum += money_dict[s[cursor]]
                    cursor += 1
            
            else:
                sum += money_dict[s[cursor]]
                cursor += 1
        return sum
                
if __name__ == '__main__':
    a = Solution()
    print(a.romanToInt('III'))
    print(a.romanToInt('LVIII'))
    print(a.romanToInt('MCMXCIV'))