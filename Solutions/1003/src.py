class Solution:
    def isValid(self, S: str) -> bool:
        stack = []
        for c in S:
            if len(stack) >= 2 and c == 'c' and stack[len(stack) - 1] == 'b' and stack[len(stack) -2] == 'a':
                stack.pop()
                stack.pop()
            else:
                stack.append(c)
        if len(stack) != 0:
            return False
        else:
            return True