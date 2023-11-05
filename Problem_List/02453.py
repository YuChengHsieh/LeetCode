class Solution:
    def destroyTargets(self, nums: list[int], space: int) -> int:
        cnt = {}
        min_ = {}
        max_ = 0
        val = -1
        min
        for num in nums:
            if not cnt.get(num%space):
                cnt[num%space] = 1
                min_[num%space] = num
            else:
                cnt[num%space] += 1
                if num < min_[num%space]:
                    min_[num%space] = num
            if cnt[num%space] > max_ or (cnt[num%space] == max_ and min_[num%space] < min_[val]):
                max_ = cnt[num%space]
                val = num%space
        
        return min_[val]