# class Solution:
#     def validateStackSequences(self, pushed: list[int], popped: list[int]) -> bool:
#         push_idx = 0
#         while len(popped) > 0:
#             if pushed[push_idx] != popped[0] and push_idx+1 < len(pushed):
#                 push_idx += 1
#             else:
#                 if push_idx < len(pushed) and pushed[push_idx] == popped[0]:
#                     pushed.pop(push_idx)
#                     if push_idx != 0:
#                         push_idx -= 1
#                 else:
#                     return False
#                 popped.pop(0)
#         return True

# stack
class Solution:
    def validateStackSequences(self, pushed: list[int], popped: list[int]) -> bool:
        stack = []
        for val in pushed:
            stack.append(val)
            while(len(stack)!= 0 and stack[-1] == popped[0]):
                popped.pop(0)
                stack.pop(-1)
        return len(stack) == 0