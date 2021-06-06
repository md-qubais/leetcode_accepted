
class Solution {
public:
	int sumOfLeftLeaves(TreeNode* root){
    	if(!root) return 0;
    	if(root->left!=NULL and root->left->left==NULL and root->left->right==NULL){
    		ans+=root->left->val;
    	}
    	sumOfLeftLeaves(root->left);
    	sumOfLeftLeaves(root->right);
    	return ans;
    }
};