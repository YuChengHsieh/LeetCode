class MinStack:
    def __init__(self):
        self.stack = []
    
    def push(self, val: int) -> None:
        if len(self.stack) == 0:
            self.stack.append((val,val))
        else:
            cur_min = self.stack[-1][1]
            self.stack.append((val,min(cur_min,val)))

    def pop(self) -> None:
        self.stack.pop()
        

    def top(self) -> int:
        return self.stack[-1][0]

    def getMin(self) -> int:
        return self.stack[-1][1]