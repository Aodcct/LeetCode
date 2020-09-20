# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def bfs(root, ans):
    queue = []
    depth = []
    queue.append(root)
    depth.append(1)

    lastNodeDepth = 1
    lastTopNode = root

    while(len(queue) != 0):

        topNode = queue.pop(0)
        topNodeDepth = depth.pop(0)
        
        # print(topNode.val)
        # print(topNode.left)
        # print(topNode.right)
        
        if(topNode.left != None):
            queue.append(topNode.left)
            depth.append(topNodeDepth + 1)
        if(topNode.right != None):
            queue.append(topNode.right)
            depth.append(topNodeDepth + 1)

        # print(topNodeDepth)
        # print(lastNodeDepth)
        
        if(topNodeDepth != lastNodeDepth):
            ans.append(lastTopNode.val)
            
        lastTopNode = topNode
        lastNodeDepth = topNodeDepth
        
        if(len(queue) == 0):
            ans.append(topNode.val)

    return ans
    
class Solution:
    
    def rightSideView(self, root: TreeNode) -> List[int]:
        if(root == [] or root == None):
            return []
        ans = []
        bfs(root, ans)
        return ans