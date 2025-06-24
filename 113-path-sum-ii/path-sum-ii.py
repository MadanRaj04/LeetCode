# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        lst=[]
        res=[]
        def dfs(root,targetSum):
            if root == None:
                return []
            lst.append(root.val)
            targetSum-=root.val
            if(root.left == None and root.right == None and targetSum==0):
                res.append(lst[:])
            dfs(root.left,targetSum)
            dfs(root.right,targetSum)

            lst.pop()

            return res
        return dfs(root,targetSum)
