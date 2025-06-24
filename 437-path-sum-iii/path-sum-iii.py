# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        prefix_sums = {0: 1}  # sum 0 appears once (empty path)
        count = 0
        
        def dfs(node, current_sum):
            nonlocal count
            if not node:
                return
            
            # Update the current sum
            current_sum += node.val
            
            # Check if there is a prefix sum that we can subtract to get targetSum
            count += prefix_sums.get(current_sum - targetSum, 0)
            
            # Add current sum to prefix_sums dictionary
            prefix_sums[current_sum] = prefix_sums.get(current_sum, 0) + 1
            
            # Traverse left and right children
            dfs(node.left, current_sum)
            dfs(node.right, current_sum)
            
            # Remove current sum from prefix_sums to backtrack
            prefix_sums[current_sum] -= 1
        
        dfs(root, 0)
        return count