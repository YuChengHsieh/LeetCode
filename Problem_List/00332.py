class Solution:
    def findItinerary(self, tickets: list[list[str]]) -> list[str]:
        hash = {}

        def check(str1,str2):
            for i in range(3):
                if ord(str1[i]) > ord(str2[i]): return False
                elif ord(str1[i]) < ord(str2[i]): return True

        def BS(li,place):
            start = 0; end = len(li) -1
            while start <= end:
                mid = start + (end-start)//2
                # o(3)
                if check(li[mid],place): start += 1
                else: end -= 1
            return start
        
        self.ans = ['JFK']
        self.done = False
        def dfs(cur):
            if len(self.ans) == len(tickets)+1: self.done = True
            if hash.get(cur) is None or len(hash[cur]) == 0: return
            for i in range(len(hash[cur])):
                next_ = hash[cur].pop(i)
                self.ans.append(next_)
                dfs(next_)
                if self.done: break
                self.ans.pop()
                hash[cur].insert(i,next_)

        for from_,to in tickets:
            if hash.get(from_) is None: hash[from_] = []
            idx = BS(hash[from_],to)
            hash[from_].insert(idx,to)
        
        dfs('JFK')
        return self.ans

from collections import defaultdict
class Solution:
    def findItinerary(self, tickets: list[list[str]]) -> list[str]:
        graph = defaultdict(list)

        for src,dst in sorted(tickets):
            graph[src].append(dst)

        self.ans = ['JFK']
        self.done = False
        def dfs(cur):
            if len(self.ans) == len(tickets)+1: self.done = True
            for i in range(len(graph[cur])):
                next_ = graph[cur].pop(i)
                self.ans.append(next_)
                dfs(next_)
                if self.done: break
                self.ans.pop()
                graph[cur].insert(i,next_)
        
        dfs('JFK')
        return self.ans

class Solution:
    def findItinerary(self, tickets: list[list[str]]) -> list[str]:
        graph = defaultdict(list)

        for src,dst in sorted(tickets, reverse=True):
            graph[src].append(dst)

        ans = []
        def dfs(cur):
            while graph[cur]:
                dfs(graph[cur].pop())
            ans.append(cur)
        dfs('JFK')
        return ans[::-1]