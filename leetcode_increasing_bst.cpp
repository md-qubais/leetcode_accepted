class Solution{
public:
	TreeNode*root_ans=NULL;
	TreeNode*temp=NULL;
    TreeNode* increasingBST(TreeNode* root){
    	if(!root) return root_ans;
    	increasingBST(root->left);
    	if(!root_ans){
    		root_ans=new TreeNode(root->val);
    		temp=root_ans;
    	}else{
    		temp->left=NULL;
    		temp->right=new TreeNode(root->val);
    		temp=temp->right;
    	}
    	increasingBST(root->right);
    	return root_ans;
    }


};