class Solution{
public:
	void inorder(TreeNode*root,vector<int>&arr){
		if(!root) return;
		inorder(root->left,arr);
		arr.push_back(root->val);
		inorder(root->right,arr);
	}
    int getMinimumDifference(TreeNode* root){
    	vector<int> arr;
    	inorder(root,arr);
    	int ans=INT_MAX;
    	for(int i=0;i<arr.size();i++){
    		for(int j=i+1;j<arr.size();j++){
    			ans=min(ans,abs(arr[i]-arr[j]));
    		}
    	}
    	return ans;
    }
};