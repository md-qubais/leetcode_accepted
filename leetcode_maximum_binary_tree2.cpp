class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val){
    	if(!root){
    		return new TreeNode(val);
    	}
    	if(root->val<val){
    		TreeNode*temp=new TreeNode(val);
    		temp->left=root;
    		return temp;
    	}
    	root->right=insertIntoMaxTree(root->right,val);
    }
};