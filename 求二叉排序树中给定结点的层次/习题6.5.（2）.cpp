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
 
 
 #define	Mini	0xc0c0c0c0
 int	findloc(TreeNode*	root,TreeNode*	FindNode)
 {
 	if(!root)
 		return	Mini;
 	if(root==FindNode)
 		return	1;
 	if(findloc(root->right,FindNode)>0)
 		return	findloc(root->right,FindNode)+1;
 	else	
 		return	findloc(root->left,FindNode)+1;
 }
