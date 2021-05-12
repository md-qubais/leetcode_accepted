class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges){
    	unordered_map<int,int> in_degree;
    	for(int i=0;i<edges.size();i++){
    		in_degree[edges[i][1]]++;
    	}
    	vector<int> ans;
    	for(int i=0;i<edges.size();i++){
    		if(in_degree[edges[i][0]]==0){
    			in_degree[edges[i][0]]=1;
    			ans.push_back(edges[i][0]);
    		}
    	}
    	return ans;
    }
};