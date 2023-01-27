class Solution:
    def maxArea(self, height: list[int]) -> int:
        max_area = 0
        start = 0
        end = len(height)-1
        while start < end:
            area = min(height[start],height[end])*(end-start)
            #import pdb; pdb.set_trace()
            if area > max_area:
                max_area = area
            
            if height[end] > height[start]:
                start += 1 
            else: 
                end -= 1 
                
        return max_area
    
if __name__ == '__main__':
    a =Solution()
    print(a.maxArea([1,8,6,2,5,4,8,3,7]))
    