def isOutOfBoard(posx, posy, maxX, maxY) -> bool:
    if posx < 0 or posx >= maxX:
        return False
    if posy < 0 or posy >= maxY:
        return False
    return True
    
class Solution:
    
    def numRookCaptures(self, board: List[List[str]]) -> int:
        
        # init
        delta = [ [0] * 2 for i in range(4)]
        delta[0][0] = -1; delta[0][1] = 0  # up
        delta[1][0] = 1;  delta[1][1] = 0  # down
        delta[2][0] = 0;  delta[2][1] = -1 # left
        delta[3][0] = 0;  delta[3][1] = 1  # right
        
        for index, item in enumerate(board):
            if "R" in item:
                Rposx, Rposy = index, item.index("R")
        ans = 0
        for i in range(0, 4):
            posx = Rposx
            posy = Rposy
            
            posx += delta[i][0]
            posy += delta[i][1]
            while isOutOfBoard(posx, posy, 8, 8) == True:
                if board[posx][posy] == 'B':
                    break
                if board[posx][posy] == 'p':
                    ans += 1
                    break
                posx += delta[i][0]
                posy += delta[i][1]
        return ans
