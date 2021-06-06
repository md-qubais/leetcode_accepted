int rows[]={1,-1,0,0};
int cols[]={0,0,1,-1};
class Solution {
public:
	bool visited[1000][1000];
	bool containsCycle(vector<vector<char>>&grid,int i,int j,char ch,int lastx=INT_MAX,int lasty=INT_MAX){
		if(i<0 or j<0 or i>=grid.size() or j>=grid[i].size() or grid[i][j]!=ch){
			return false;
		}
		if(visited[i][j]){
			return  false;
		}
		visited[i][j]=true;
		for(int k=0;k<4;k++){
			if(i+rows[k]>=0 and j+cols[k]>=0 and i+rows[k]<grid.size() and j+cols[k]<grid[i+rows[k]].size() and grid[i+rows[k]][j+cols[k]]==ch and visited[i+rows[k]][j+cols[k]]){
				if(i+rows[k]!=lastx and j+cols[k]!=lasty){
					return true;
				}
			}
			if(containsCycle(grid,i+rows[k],j+cols[k],ch,i,j)){
				return true;
			}
		}
		return false;
	}
    bool containsCycle(vector<vector<char>>& grid){
    	for(int i=0;i<grid.size();i++){
    		for(int j=0;j<grid[i].size();j++){
    			if(!visited[i][j]){
    				if(containsCycle(grid,i,j,grid[i][j])){
    					return true;
    				}
    			}
    		}
    	}
    	return false;
    }
};