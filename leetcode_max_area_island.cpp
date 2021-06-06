int row_dir[]={1,-1,0,0};
int col_dir[]={0,0,1,-1};
class Solution {
public:
    vector<int> rows;
    vector<int> cols;
    bool visited[1000][1000];
    int max_area(int i,int j,vector<vector<int>>&grid){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[i].size() or visited[i][j] or grid[i][j]==0){
            return 0;
        }
        visited[i][j]=true;
        int ans=0;
        for(int k=0;k<4;k++){
            ans+=max_area(i+row_dir[k],j+col_dir[k],grid);
        }
        return ans+1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid){
        int one=0;
        int zero=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    rows.push_back(i);
                    cols.push_back(j);
                    one++;
                }else{
                    zero++;
                }
            }
        }
        if(zero==0){
            return one;
        }
        if(one==0){
            return 0;
        }
        int ans=0;
        int n=rows.size();
        for(int i=0;i<n;i++){
            if(!visited[rows[i]][cols[i]]){
                ans=max(ans,max_area(rows[i],cols[i],grid));
            }
        }
        return ans;
    }
};