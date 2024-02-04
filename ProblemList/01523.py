class Solution:
    def countOdds(self, low: int, high: int) -> int:
        return (high-low)//2+1 if (high-low)%2 == 1 or ((high-low)%2 == 0 and high%2==1 and low%2 == 1) else (high-low)//2