class Solution{
public:
	
	void preorder(TreeNode*root,vector<int>&arr){
		if(!root) return ;
		arr.push_back(root->val);
		preorder(root->left,arr);
		preorder(root->right,arr);
	}

    int findSecondMinimumValue(TreeNode* root){
    	vector<int> arr;
    	preorder(root,arr);
    	sort(arr.begin(),arr.end());
    	deque<int> q;
    	for(int i=0;i<arr.size();i++){
    		if(q.empty()){
    			q.push_back(arr[i]);
    		}else{
    			while(!q.empty() and q.back()==arr[i]){
    				q.pop_back();
    			}
    			q.push_back(arr[i]);
    		}
    	}
    	for(auto&it:q){
    		cout<<it<<" ";
    	}
    	cout<<endl;
    	return q.size()>1?q[1]:-1;
    }
};