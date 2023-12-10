class Solution:
    def countTestedDevices(self, batteryPercentages: list[int]) -> int:
        ans = 0
        for i in range(len(batteryPercentages)):
            if batteryPercentages[i] > 0:
                ans += 1
                for j in range(i+1,len(batteryPercentages)):
                    batteryPercentages[j] -= 1
        return ans