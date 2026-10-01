class MinStack:

    def __init__(self):
        self.st = []
        self.minStack = []

    def push(self, val: int) -> None:
        self.st.append(val)
        if not self.minStack or val <= self.minStack[-1]:
            self.minStack.append(val)

    def pop(self) -> None:
        if self.st[-1] == self.minStack[-1]:
            self.minStack.pop()
        self.st.pop()
        

    def top(self) -> int:
        return self.st[-1]
        

    def getMin(self) -> int:
        return self.minStack[-1]
        
