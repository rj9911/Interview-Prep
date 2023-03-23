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
/*  There are total three cases :
    1. leaf nodes.
    2. Nodes with only left or right.
    3. Both left and right exists. // Find inorder successor and swap root and successor then simply Solve like 2. step.
*/
class Solution {
public:
    TreeNode* insucc(TreeNode* root){
        TreeNode* p = root->right;    // Turn towards right
        while(p->left) p=p->left; // Extreme left
        return p;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(key>root->val) root->right = deleteNode(root->right, key);
        else if(key<root->val) root->left = deleteNode(root->left, key);
        else{
            // Here root->val == key
            if(!root->right){  // Leaf Nodes ( Step1 and Step2 Both follows this statement)
               TreeNode* temp = root->left; // When leaf nodes then ( temp = NULL )
               delete(root);            // Deleting the leaf node
               return temp;             // Now Attach NUll to Previous nodes
            }else if(!root->left){      
               TreeNode* temp = root->right;   // Right node exist
               delete(root);
               return temp;
            }else{
                TreeNode* temp = insucc(root); // Find Successor
                swap(root->val, temp->val);    // Swap the root and successor node
                root->right = deleteNode(root->right, key); // Recursion call again in the right same as Step 2.
            }
        }
        return root;
    }
};