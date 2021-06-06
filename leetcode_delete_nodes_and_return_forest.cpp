class Solution{
public:
	unordered_map<int,bool> present;
	TreeNode* delNodes(TreeNode*root,vector<int>&to_delete,vector<TreeNode*>&ans,int&i){
		if(!root or i>=to_delete.size()){
			return root;
		}
		if(present[root->val]){
			present[root->val]=false;
			i++;
			if(root->left){
				if(present[root->left->val]){
					root->left=delNodes(root->left,to_delete,ans,i);
				}else{
					ans.push_back(root->left);
					root->left=delNodes(root->left,to_delete,ans,i);
				}
			}
			if(root->right){
				if(present[root->right->val]){
					root->right=delNodes(root->right,to_delete,ans,i);
				}else{
					ans.push_back(root->right);
					root->right=delNodes(root->right,to_delete,ans,i);
				}
			}
			return NULL;
		}
		if(ans.size()==0){
			ans.push_back(root);
		}
		root->left=delNodes(root->left,to_delete,ans,i);
		root->right=delNodes(root->right,to_delete,ans,i);
		return root;
	}
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete){
    	vector<TreeNode*> ans;
        int i=0;
        for(auto&it:to_delete){
        	present[it]=true;
        }
    	delNodes(root,to_delete,ans,i);
    	return ans;
    }
};