# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        freq = {0:1}
        count=0
        def dfs(root,targetSum,prefsum):
            nonlocal count
            if root == None:
                return 

            prefsum+=root.val
            if(freq.get(prefsum-targetSum,0)):
                print("entered")
                count+=freq[prefsum - targetSum]


            freq[prefsum] = freq.get(prefsum,0)+1


            dfs(root.left,targetSum,prefsum)
            dfs(root.right,targetSum,prefsum)
            freq[prefsum] -= 1

        dfs(root,targetSum,0)

        return count