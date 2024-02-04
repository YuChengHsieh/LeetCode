class MyStack:

    def __init__(self):
        self.q = []
        self.tmp_q = []

    def push(self, x: int) -> None:
        self.tmp_q.append(x)
        while len(self.q) != 0:
            self.tmp_q.append(self.q.pop(0))
        self.q = self.tmp_q
        self.tmp_q = []

    def pop(self) -> int:
        return self.q.pop(0)

    def top(self) -> int:
        return self.q[0]

    def empty(self) -> bool:
        return len(self.q) == 0