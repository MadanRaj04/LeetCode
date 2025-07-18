# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        
        def dfs(root,targetSum):
            if root==None:
                return False
        
            targetSum-=root.val
            if (not root.left and not root.right and targetSum==0):
                return True
            l=dfs(root.left,targetSum)
            r=dfs(root.right,targetSum)
            if(l or r):
                return True
            return False

        return dfs(root,targetSum)
        

        