class BrowserHistory:

    def __init__(self, homepage: str):
        self.history = [homepage]
        self.cursor = 0

    def visit(self, url: str) -> None:
        self.history = self.history[:self.cursor+1]
        self.history.append(url)
        self.cursor = len(self.history)-1

    def back(self, steps: int) -> str:
        self.cursor = 0 if self.cursor-steps < 0 else self.cursor-steps
        return self.history[self.cursor]

    def forward(self, steps: int) -> str:
        self.cursor = len(self.history)-1  \
        if self.cursor+steps >= len(self.history) else self.cursor+steps 
        return self.history[self.cursor]