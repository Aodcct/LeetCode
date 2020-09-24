class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        
        newRoom = 0
        
        opened = []
        for i in range(len(rooms)):
            opened.append(0)
        
        queue = []
        queue.append(newRoom)
        opened[0] = 1
        cnt = 1
        
        while(len(queue) != 0):
            topRoom = queue.pop(0)
            for i in rooms[topRoom]:
                if(opened[i] == 0):
                    queue.append(i)
                    opened[i] = 1
                    cnt += 1
        
        if(cnt == len(rooms)):
            return True
        return False
                