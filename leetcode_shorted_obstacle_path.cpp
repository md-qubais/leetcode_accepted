int rows[]={1,-1,0,0};
int cols[]={0,0,1,-1};
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        queue<pair<pair<int,int>,pair<int,int>>> q;
        bool visited[1000][1000]={0};
        if(grid[0][0]!=0){
        	return -1;
        }
        q.push({{0,0},{0,0}});
        while(!q.empty()){
        	pair<pair<int,int>,pair<int,int>> temp=q.front();
        	q.pop();
        	if(temp.first.first==grid.size()-1 and temp.first.second==grid[0].size()-1){
        		if(temp.second.first<=k){
        			return temp.second.second;
        		}
        		continue;
        	}
        	if(temp.second.first>k){
        		visited[temp.first.first][temp.first.second]=true;
        		continue;
        	}
        	if(visited[temp.first.first][temp.second.second]){
        		continue;
        	}
        	visited[temp.first.first][temp.first.second]=true;
        	for(int k=0;k<4;k++){
        		int r=temp.first.first+rows[k];
        		int c=temp.first.second+cols[k];
        		if(r<0 or c<0 or r>=grid.size() or c>=grid[0].size() or visited[r][c]){
        			continue;
        		}
        		if(grid[r][c]==1){
        			q.push({{r,c},{temp.second.first+1,temp.second.second+1}});
        		}else{
        			q.push({{r,c},{temp.second.first,temp.second.second+1}});
        		}
        	}
        }
        return -1;
    }
};