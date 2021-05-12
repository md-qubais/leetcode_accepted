int rows[]={1,-1,0,0};
int cols[]={0,0,1,-1};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid){
        int ans=0;
        queue<pair<pair<int,int>,int>> q;
        bool visited[1000][1000]={false};
        bool b=false;
        int count_fresh=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==2){
                     b=true;   
                     q.push({{i,j},0});   
                }
                if(grid[i][j]==1){
                    count_fresh++;
                }
            }
        }
        if(!b){
            if(count_fresh>0){
                return -1;
            }
            return 0;
        }
        while(!q.empty()){
            pair<pair<int,int>,int> temp=q.front();
            q.pop();
            if(visited[temp.first.first][temp.first.second]){
                continue;
            }
            visited[temp.first.first][temp.first.second]=true;
            ans=max(ans,temp.second); 
            for(int k=0;k<4;k++){
                int r=temp.first.first+rows[k];
                int c=temp.first.second+cols[k];
                if(r<0 or c<0 or r>=grid.size() or c>=grid[r].size() or grid[r][c]==0 or visited[r][c] or grid[r][c]==2){
                    continue;
                }
                grid[r][c]=2;
                count_fresh--;
                q.push({{r,c},temp.second+1});
            }
        }
        if(count_fresh>0){
            return -1;
        }
        return ans;
    }
};