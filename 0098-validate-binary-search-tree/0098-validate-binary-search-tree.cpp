/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
   if (root == nullptr) {
    return true;
  }

  // Check if the left and right subtrees are valid binary search trees.
  if (!isValidBST(root->left) || !isValidBST(root->right)) {
    return false;
  }

  // Check if all nodes in the left subtree are less than the root node.
  for (TreeNode* node = root->left; node != nullptr; node = node->right) {
    if (node->val >= root->val) {
      return false;
    }
  }

  // Check if all nodes in the right subtree are greater than the root node.
  for (TreeNode* node = root->right; node != nullptr; node = node->left) {
    if (node->val <= root->val) {
      return false;
    }
  }

  // All checks passed, so the tree is a valid binary search tree.
  return true;
}
};