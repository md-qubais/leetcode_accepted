class Solution
{
    public:
    vector<int> topView(Node *root){
        map<int,int> m;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            pair<Node*,int> temp=q.front();
            q.pop();
            if(m.count(temp.second)!=0){
            	m[temp.second]=temp.first->data;
            }
            else{
            	continue;
            }
            if(temp.first->left) q.push({temp->first->left,temp.second-1});
            if(temp.first->right) q.push({temp->first->right,temp.second+1});
        }
        vector<int> ans;
        for(auto&it:m){
        	ans.push_back(it.second);
        }


        return ans;
    }
};

