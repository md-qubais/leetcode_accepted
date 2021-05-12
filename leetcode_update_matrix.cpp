int r[]={1,-1,0,0};
int c[]={0,0,1,-1};
class Solution {
public:
	int dp[1000][1000]={0};
	bool visited[1000][1000];
	int min_nearest(vector<vector<int>>& mat,int rows,int cols){
		if(rows<0 or cols<0 or rows>=mat.size() or cols>=mat[0].size() or visited[rows][cols] ){
			return INT_MAX;
		}
		if(mat[rows][cols]==0){
			return 0;
		}
		if(dp[rows][cols]!=0){
			return dp[rows][cols];
		}
		visited[rows][cols]=true;
		int ans=INT_MAX;
		for(int k=0;k<4;k++){
			ans=min(ans,min_nearest(mat,rows+r[k],cols+c[k]));
		}
		visited[rows][cols]=false;
		if(ans!=INT_MAX){
			return dp[rows][cols]=ans+1;
		}
		return ans;
	}

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat){
    	vector<vector<int>> ans;
    	for(int i=0;i<mat.size();i++){
    		vector<int> temp;
    		for(int j=0;j<mat[i].size();j++){
    			temp.push_back(0);
    		}
    		ans.push_back(temp);
    	}
    	for(int i=0;i<mat.size();i++){
    		for(int j=0;j<mat[i].size();j++){
    			if(mat[i][j]==1){
    				ans[i][j]=min_nearest(mat,i,j);
    			}
    		}
    	}
    	return ans;
    }

};