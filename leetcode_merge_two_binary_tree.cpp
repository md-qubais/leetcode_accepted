class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2){
        if(!root1 and !root2){
        	return NULL;
        }
        TreeNode*root=NULL;
        



        if(root1 and root2){
        	root=new TreeNode(root1->val+root2->val);
        }
        if(root1->left and root2->left){
        	root->left=mergeTrees(root1->left,root2->left);
        }
        if(root1->right and root2->right){
        	root->right=mergeTrees(root1->right,root2->right);
        }





        return root;
    }
};