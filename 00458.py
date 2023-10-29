import math
class Solution:
    # find minimum x such that (T+1)^x >= N where T = number of test, x: big's number and N: number of buckets
    def poorPigs(self, buckets: int, minutesToDie: int, minutesToTest: int) -> int:
        test = minutesToTest//minutesToDie
        return math.ceil(round(math.log(buckets,test+1),2))