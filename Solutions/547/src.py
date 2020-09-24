class Solution:
    def findCircleNum(self, M: List[List[int]]) -> int:
        
        parent = []
        for i in range(len(M)):
            parent.append(i)
        
        def findRoot(x):
            root = x
            while(root != parent[root]):
                root = parent[root]
            now = x;  
            while(now != root):   
                temp = parent[now] 
                parent[now] = root
                now = temp    
            return root
        
        def merge(a, b):
            parent[b] = a
            
        for i in range(len(M)):
            for j in range(len(M[0])):
                if(i != j and M[i][j] == 1):
                    di = findRoot(i)
                    dj = findRoot(j)
                    if(di != dj):
                        merge(di, dj)
        
        cnt = 0                
        for i in range(len(parent)):
            if(i == parent[i]):
                cnt += 1
        
        return cnt