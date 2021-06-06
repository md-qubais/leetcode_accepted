class Graph{
public:
    map<int,list<int>> l;
    void insert(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void dfs_helper(int n,unordered_map<int,bool>&visited,vector<int>&ans){
        visited[n]=true;
        ans.push_back(n);
        for(auto&it:l[n]){
            if(!visited[it]){
                dfs_helper(it,visited,ans);
            }
        }
    }
    void dfs(vector<int>&ans){
        unordered_map<int,bool> visited;
        for(auto&it:l){
            if(!visited[it.first])
            dfs_helper(it.first,visited,ans);
        }
    }
};
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        Graph g;
        for(int i=0;i<adjacentPairs.size();i++){
            g.insert(adjacentPairs[i][0],adjacentPairs[i][1]);
        }
        vector<int> ans;
        g.dfs(ans);
        return ans;
    }
};