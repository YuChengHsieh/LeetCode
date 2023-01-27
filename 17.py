# class Solution:
#     def letterCombinations(self, digits: str) -> list[str]:
#         num_dict = {'2':['a','b','c'],'3':['d','e','f'],'4':['g','h','i'],'5':['j','k','l'],'6':['m','n','o'],
#                     '7':['p','q','r','s'],'8':['t','u','v'],'9':['w','x','y','z']}

#         dig_len = len(digits)
        
#         ret_list = []
        
#         if digits == '':
#             return ret_list
        
#         for char_1 in num_dict[digits[0]]:
#             try:
#                  for char_2 in num_dict[digits[1]]:
#                     try:
#                         for char_3 in num_dict[digits[2]]:
#                             try:
#                                 for char_4 in num_dict[digits[3]]:
#                                     ret_list.append(char_1+char_2+char_3+char_4)
#                             except:
#                                 ret_list.append(char_1+char_2+char_3)
#                     except:
#                         ret_list.append(char_1+char_2)
#             except:
#                 ret_list.append(char_1)
        
#         return ret_list

class Solution:
    
    def letterCombinations(self, digits: str) -> list[str]:
        ret_list = []
        num_dict = {'2':['a','b','c'],'3':['d','e','f'],'4':['g','h','i'],'5':['j','k','l'],'6':['m','n','o'],
                    '7':['p','q','r','s'],'8':['t','u','v'],'9':['w','x','y','z']}
        def rec(digits:str,ans_str:str):
            if len(ans_str) == len(digits):
                ret_list.append(ans_str)
            else:
                for char in num_dict[digits[len(ans_str)]]:
                    ans_str += char
                    rec(digits,ans_str)
                    ans_str = ans_str[:-1]
        
        rec(digits,'')
        
        return [] if len(ret_list) == 1 else  ret_list

if __name__ == '__main__':
    a = Solution()
    print(a.letterCombinations('22'))
    print(a.letterCombinations('2'))
    print(a.letterCombinations(''))