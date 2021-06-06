class Graph{
public:
	map<int,list<int>> g;
	Graph(){
	}
	void add_edge(int u,int v,bool bdir=true){
		g[u].push_back(v);
		if(bdir){
			g[v].push_back(u);
		}
	}
	void bfs(vector<int>&ans){
		queue<pair<int,int>> q;
		q.push({-1,1});
		unordered_map<int,bool> visited;
		while(!q.empty()){
			pair<int,int> p=q.front();
			q.pop();
			if(visited[p.second]){
				ans.push_back(p.first);
				ans.push_back(p.second);
				return;
			}
			visited[p.second]=true;
			for(auto&it:g[p.second]){
				if(!visited[it]){
					q.push({p.second,it});
				}
			}
		}
	}
};

class Solution{
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges){
    	vector<int> ans;
    	Graph g;
    	for(int i=0;i<edges.size();i++){
    		g.add_edge(edges[i][0],edges[i][1]);
    	}
    	g.bfs(ans);
    	sort(ans.begin(),ans.end());
    	return ans;
    }
};