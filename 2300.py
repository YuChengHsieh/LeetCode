# BST
class Solution:
    def successfulPairs(self, spells: list[int], potions: list[int], success: int) -> list[int]:
        potions.sort()
        potions_len = len(potions)
        ans = []
        for spell in spells:
            start = 0; end = potions_len-1
            while start<=end :
                mid = start+(end-start)//2
                if spell*potions[mid] >= success:
                    end = mid-1
                else:
                    start = mid+1
            ans.append(potions_len-start)
        return ans