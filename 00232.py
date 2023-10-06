class MyQueue:

    def __init__(self):
        self.stack = []
        self.tmp_stack = []

    def push(self, x: int) -> None:
        self.stack.append(x)

    def pop(self) -> int:
        while len(self.stack) != 0:
            self.tmp_stack.append(self.stack.pop())
        rem_ele = self.tmp_stack.pop()
        while len(self.tmp_stack) != 0:
            self.stack.append(self.tmp_stack.pop())
        return rem_ele
    def peek(self) -> int:
        while len(self.stack) != 0:
            self.tmp_stack.append(self.stack.pop())
        rem_ele = self.tmp_stack[-1]
        while len(self.tmp_stack) != 0:
            self.stack.append(self.tmp_stack.pop())
        return rem_ele

    def empty(self) -> bool:
        return len(self.stack) == 0 

# input stack and output stack
class MyQueue:

    def __init__(self):
        self.input_stack = []
        self.output_stack = []

    def push(self, x: int) -> None:
        self.input_stack.append(x)

    def pop(self) -> int:
        if len(self.output_stack) == 0:
            while len(self.input_stack) != 0:
                self.output_stack.append(self.input_stack.pop())
        return self.output_stack.pop() 
    def peek(self) -> int:
        if len(self.output_stack) == 0:
            while len(self.input_stack) != 0:
                self.output_stack.append(self.input_stack.pop())
        return self.output_stack[-1]

    def empty(self) -> bool:
        return len(self.input_stack) == 0 and len(self.output_stack) == 0 