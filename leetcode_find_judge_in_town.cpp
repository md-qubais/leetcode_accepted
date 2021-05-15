class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust){
    	unordered_map<int,int> in_degree;
    	unordered_map<int,int> out_degree;
    	for(int i=1;i<=n;i++){
    		in_degree[i]=0;
    		out_degree[i]=0;
    	}
    	for(int i=0;i<trust.size();i++){
    		out_degree[trust[i][0]]++;
    		in_degree[trust[i][1]]++;
    	}
    	for(int i=1;i<=n;i++){
    		if(out_degree[i]==0 and in_degree[i]==n-1){
    			return i;
    		}
    	}
    	return -1;
    }
};