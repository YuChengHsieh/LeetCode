# hash map + two pointer o(n^2)
# class Solution:
#     def totalFruit(self, fruits: list[int]) -> int:
#         max_ = 0
#         fruits_len = len(fruits)
#         choose = {fruits[0]:1}
#         left_bound = 0
#         next_condition = []
#         for i in range(1,fruits_len):
#             if choose.get(fruits[i]) is None:
#                 choose[fruits[i]] = 0

#             # if fruits change ==> means max_ maybe change 
#             if fruits[i] != fruits[i-1]:
#                 next_condition.append(i)

#             # make sure that we just have two fruits
#             while len(choose) > 2:
#                 tmp = 0
#                 for key in choose:
#                     tmp += choose[key]
#                 if tmp > max_:
#                     max_ = tmp
                
#                 for j in range(left_bound,next_condition[0]):
#                     choose[fruits[j]] -= 1
#                     if choose[fruits[j]] == 0:
#                         del choose[fruits[j]]
#                 left_bound = next_condition.pop(0)
                

#             choose[fruits[i]] += 1
#         else:
#             # print(choose)
#             tmp = 0
#             for key in choose:
#                 tmp += choose[key]
#             if tmp > max_:
#                 max_ = tmp

#         return max_

# two pointer(sliding window) + hash map
class Solution:
    def totalFruit(self, fruits: list[int]) -> int:
        max_ = 0
        left_bound, right_bound = 0,0
        hash_map = {}

        # start with left_bound can get (right_bound-left_bound) fruits
        # only check [left_bound,right_bound] window
        while right_bound < len(fruits):
            if hash_map.get(fruits[right_bound]) is None:
                hash_map[fruits[right_bound]] = 0 
            
            # more than two fruits => can not get more fruits => discard at least one kind of fruit
            if len(hash_map) > 2:
                hash_map[fruits[left_bound]] -= 1
                if hash_map[fruits[left_bound]] == 0:
                    del hash_map[fruits[left_bound]]
                left_bound += 1
            # can get more fruits
            else:
                hash_map[fruits[right_bound]] += 1
                right_bound += 1
                if right_bound - left_bound > max_:
                    max_ = right_bound - left_bound
    
        return max(max_,right_bound - left_bound)