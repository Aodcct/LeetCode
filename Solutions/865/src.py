# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def subtreeWithAllDeepest(self, root: TreeNode) -> TreeNode:
        def calHeight(node: TreeNode):
            
            if not hasattr(node,'height'):
                setattr(node,'height', 0)
                
            if(node.left != None and node.right != None):
                calHeight(node.left)
                calHeight(node.right)
                node.height = max(node.left.height, node.right.height) + 1
            elif(node.left == None and node.right == None):
                node.height = 1
            elif(node.left != None):
                calHeight(node.left)
                node.height = node.left.height + 1
            else:
                calHeight(node.right)
                node.height = node.right.height + 1
            
        def solve(node: TreeNode):
            leftHeight = 0
            rightHeight = 0
            
            if(node.left != None):
                leftHeight = node.left.height
            if(node.right != None):
                rightHeight = node.right.height
            
            if(leftHeight == rightHeight):
                return node
            elif(leftHeight > rightHeight):
                return solve(node.left)
            else:
                return solve(node.right)
                
        calHeight(root)
        return solve(root)