class Solution:
    def longestValidParentheses(self, s: str) -> int:
        valid_idx_list = []
        stack = []
        
        for i,char in enumerate(s):
            if char == '(':
                stack.append(i)
            elif len(stack) > 0: # receive ')'
                start = stack.pop()
                # record the start parenthesis idx (start) and end parenthesis idx (i)
                valid_idx_list.extend((start,i))
        
        if len(valid_idx_list) == 0: # no matching parenthesis
            return 0
        
        valid_idx_list.sort()
        maximum_valid,valid = 0,1
        prev = valid_idx_list[0]
        # counting continuous indices
        for cur in valid_idx_list[1:]:
            if cur - prev != 1:
                maximum_valid = valid if valid > maximum_valid else maximum_valid
                valid = 0
            
            valid += 1
            prev = cur
        else:
            maximum_valid = valid if valid > maximum_valid else maximum_valid
        
        return maximum_valid

if __name__ == '__main__':
    a = Solution()
    print(a.longestValidParentheses("(()"))
    print(a.longestValidParentheses(")()())")) 
    print(a.longestValidParentheses("())()((()()())"))   
    print(a.longestValidParentheses("())()((()()))())(())"))                   