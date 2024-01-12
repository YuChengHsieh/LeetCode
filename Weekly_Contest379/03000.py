class Solution:
    def areaOfMaxDiagonal(self, dimensions: list[list[int]]) -> int:
        max_area = 0
        max_diagonal = 0
        
        for length,width in dimensions:
            if length**2+width**2 > max_diagonal or (length**2+width**2 == max_diagonal and length*width > max_area):
                max_diagonal = length**2+width**2
                max_area = length*width
        
        return max_area