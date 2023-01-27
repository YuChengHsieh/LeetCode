class Solution:
    def largestRectangleArea(self, heights: list[int]) -> int:
        to_left = [-1 for _ in range(len(heights))]
        to_right = [len(heights) for i in range(len(heights))]
        
        # extend to right in each height
        stack = []
        for i in range(len(heights)):
            while len(stack) != 0 and heights[stack[-1]] > heights[i]:
                to_right[stack[-1]] = i
                stack.pop()
            stack.append(i)
        
        # extend to left in each height
        stack = []
        for i in reversed(range(len(heights))):
            while len(stack) != 0 and heights[stack[-1]] > heights[i]:
                to_left[stack[-1]] = i
                stack.pop()
            stack.append(i)
        
        max_area = 0
        for i in range(len(heights)):
            area = heights[i]*(to_right[i]-to_left[i]-1)
            max_area = max(max_area,area)
        
        return max_area

if __name__ == '__main__':
    a = Solution()
    print(a.largestRectangleArea([2,1,5,6,2,3]))
    print(a.largestRectangleArea([2,4]))   
    print(a.largestRectangleArea([1]))          
                
