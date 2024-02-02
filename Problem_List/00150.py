class Solution:
    def evalRPN(self, tokens: list[str]) -> int:
        stack = []
        for token in tokens:
            if(token == '+' or token == '-' or token == '*' or token == '/'):
                first = int(stack.pop())
                second = int(stack.pop())
                if(token == '+'): val = second + first 
                if(token == '-'): val = second - first
                if(token == '*'): val = second * first
                if(token == '/'): val = int (second / first)
                stack.append(val)
            else: stack.append(token)
        return int(stack[0])