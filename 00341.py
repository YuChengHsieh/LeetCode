class NestedIterator:
    def __init__(self, nestedList: [NestedInteger]):
        self.ans = []
        def rec(nested):
            for i in nested:
                if i.isInteger(): self.ans.append(i.getInteger())
                else: rec(i.getList())
        rec(nestedList)
        self.ans.reverse()

    def next(self) -> int:
        return self.ans.pop()
    def hasNext(self) -> bool:
        return len(self.ans) != 0