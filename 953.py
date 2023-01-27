# hash table
class Solution:
    def isAlienSorted(self, words: list[str], order: str) -> bool:
        order_dict = {}
        for i in range(len(order)):
            order_dict[order[i]] = i+1
        
        for i in range(1,len(words)):
            for j in range(len(words[i-1])):
                if j >= len(words[i]): return False  # e.g.  apple, app, butshould be app, apple
                if order_dict[words[i][j]] > order_dict[words[i-1][j]]:
                    break
                elif order_dict[words[i][j]] == order_dict[words[i-1][j]]:
                    continue
                else:
                    return False
        return True

# hash table and sort
class Solution:
    def isAlienSorted(self, words: list[str], order: str) -> bool:
        
        order_dict = {}
        for i in range(len(order)):
            order_dict[order[i]] = i+1
        
        def cmp(word):
            ret = []
            for i in word:
                ret.append(order_dict[i])
            ret.append(0) #apple, app, butshould be app, apple
            return tuple(ret)
        
        sorted_words = sorted(words,key=cmp)
        return sorted_words == words
        
