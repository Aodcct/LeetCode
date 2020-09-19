class Solution:
    def isValid(self, s: str) -> bool:
        
        # 优化
        if len(s) % 2 != 0:
            return False

        stack = []
        for c in s:
            if (len(stack) != 0) and \
            ( (c == ')' and stack[len(stack) - 1] == '(') or \
            (c == ']' and stack[len(stack) - 1] == '[') or \
            (c == '}' and stack[len(stack) - 1] == '{') ):
                stack.pop()
            else:
                stack.append(c)
        if len(stack) == 0:
            return True
        else:
            return False