int rows[]={1,-1,0,0};
int cols[]={0,0,1,-1};
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid){
    	int zero=0;
    	int one=0;
    	//rows, cols and and starting 1's row and 1's cols
    	queue<pair<pair<int,int>,pair<int,int>>> q;
    	int ans=0;
    	bool visited[1000][1000]={false};
    	for(int i=0;i<grid.size();i++){
    		for(int j=0;j<grid[i].size();j++){
    			if(grid[i][j]==1){
    				one++;
    				q.push({{i,j},{i,j}});
    			}else{
    				zero++;
    			}
    		}
    	}
    	if(zero==0 or one==0){
    		return -1;
    	}
    	while(!q.empty()){
    		pair<pair<int,int>,pair<int,int>> temp=q.front();
    		q.pop();
    		if(visited[temp.first.first][temp.first.second]){
    			continue;
    		}	
    		int val=abs(temp.first.first-temp.second.first)+abs(temp.first.second-temp.second.second);
    		ans=max(ans,val);
    		visited[temp.first.first][temp.first.second]=true;
    		for(int k=0;k<4;k++){
    			int r=temp.first.first+rows[k];
    			int c=temp.first.second+cols[k];
    			if(r<0 or c<0 or r>=grid.size() or c>=grid[0].size() or visited[r][c] or grid[r][c]==1){
    				continue;
    			}
    			q.push({{r,c},{temp.second.first,temp.second.second}});
    		}
    	}
    	return ans;
    }
};