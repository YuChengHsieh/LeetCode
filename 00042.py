# monotonic stack
# class Solution:
#     def trap(self, height: list[int]) -> int:
#         height_len = len(height)
#         to_left = [i for i in range(height_len)]
#         to_right = [i for i in range(height_len)]
#         to_left_height = [0 for _ in range(height_len)]
#         to_right_height = [0 for _ in range(height_len)]
        
#         # from left push to right bound
#         stack = []
#         for i in range(height_len):
#             prev_height = 0
#             while len(stack) > 0 and height[stack[-1]] <= height[i]:
#                 stack_idx = stack.pop()
#                 to_right[stack_idx] = i
#                 to_right_height[stack_idx] = height[stack_idx] - prev_height
#                 prev_height = height[stack_idx]
#             stack.append(i)
        
#         # from right push to left bound
#         stack = []
#         for i in reversed(range(height_len)):
#             prev_height = 0
#             while len(stack) > 0 and height[stack[-1]] < height[i]:
#                 stack_idx = stack.pop()
#                 to_left[stack_idx] = i
#                 to_left_height[stack_idx] = height[stack_idx] - prev_height
#                 prev_height = height[stack_idx]
#             stack.append(i)
        
#         area = 0
#         for i in range(height_len):
#             tmp_area = (to_right[i]-i-1)*to_right_height[i] + (i-to_left[i]-1)*to_left_height[i]
#             area += tmp_area
        
#         # print(to_right,to_left,to_right_height,to_left_height)
#         return area

# use max left and max right to find answer o(n)
class Solution:
    def trap(self, height: list[int]) -> int:
        left,right = 0, len(height)-1
        area = 0
        
        height_left,height_right = height[left],height[right]
        
        while left < right:
            
            if height_left > height_right:
                right -= 1
                height_right = max(height_right,height[right])
                area += max(0,min(height_left,height_right)-height[right])
            else:
                left += 1
                height_left = max(height_left,height[left])
                area += max(0,min(height_left,height_right)-height[left])
            
        return area
            
if __name__ == '__main__':
    a = Solution()
    print(a.trap([0,1,0,2,1,0,1,3,2,1,2,1]))
    print(a.trap([4,2,0,3,2,5]))