
void diagonal(Node*root,map<int,vector<int>>&m,int level=0){
	if(!root) return;
	m[level].push_back(root->data);
	diagonal(root->left,m,level+1);
	diagonal(root->right,m,level);
}

vector<int> diagonal(Node *root){
	map<int,vector<int>> m;
	diagonal(root,m);
	vector<int> ans;
	for(auto&it:m){
		for(auto&i:it.second){
			ans.push_back(i);
		}
	}
	return ans;
}