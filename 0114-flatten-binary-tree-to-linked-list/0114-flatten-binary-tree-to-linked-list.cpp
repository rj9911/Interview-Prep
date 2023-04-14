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
//By Reverse PostOrder Traversal

//T->O(Number of Nodes) && S->O(Number of Nodes) [Worst ASS] \U0001f602
class Solution {
public:
    TreeNode* prev=NULL;
	void flatten(TreeNode* curr) {
		if(!curr) return;
		flatten(curr->right);
		flatten(curr->left);
		curr->right=prev;
		curr->left=NULL;
		prev=curr;
	}
};