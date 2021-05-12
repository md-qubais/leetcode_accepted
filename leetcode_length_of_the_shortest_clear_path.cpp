int rows[]={1,-1,0,0,-1,1,1,-1};
int cols[]={0,0,1,-1,-1,1,-1,1};
class Solution{
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid){
    	if(grid[0][0]!=0){
    		return -1;
    	}
    	queue<pair<pair<int,int>,int>> q;
    	bool visited[1000][1000]={false};
    	q.push({{0,0},1});
    	while(!q.empty()){
    		pair<pair<int,int>,int> temp=q.front();
    		q.pop();
    		if(temp.first.first==grid.size()-1 and temp.first.second==grid[0].size()-1){
    			return temp.second;
    		}
    		if(visited[temp.first.first][temp.first.second]){
    			continue;
    		}
    		visited[temp.first.first][temp.first.second]=true;
    		for(int k=0;k<8;k++){
    			int r=temp.first.first+rows[k];
    			int c=temp.first.second+cols[k];
    			if(r<0 or c<0 or r>=grid.size() or c>=grid[0].size() or visited[r][c] or grid[r][c]==1){
    				continue;
    			}
    			q.push({{r,c},temp.second+1});
    		}
    	}
    	return -1;
    }
};