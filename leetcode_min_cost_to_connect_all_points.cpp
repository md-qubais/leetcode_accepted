#define pb push_back

class compare_to{
public:
	bool operator()(pair<int,pair<int,int>> p1,pair<int,pair<int,int>> p2){
		return p1.second.second>p2.second.second;
	}
};

template<class T>

class Graph{
public:
	map<T,list<pair<T,int>>> l;
	void add_edge(T src,T dest,int dist=-1,bool bdir=true){
		l[src].pb({dest,dist});
		if(bdir) l[dest].pb({src,dist});
	}
	int prims_mst(){
		int ans=0;
		unordered_map<int,bool> visited;
		priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,compare_to> pq;
		pq.push({0,{-1,0}});
		pair<int,pair<int,int>> temp=pq.top();
		pq.pop();
		visited[temp.first]=true;
		for(auto&it:l[temp.first]){
            pq.push({it.first,{temp.first,it.second}});
        }

        while(!pq.empty()){
            temp=pq.top();
            pq.pop();
            if(visited[temp.first]){
                continue;
            }
            visited[temp.first]=true;
            ans+=temp.second.second;
            for(auto&it:l[temp.first]){
                if(!visited[it.first]) pq.push({it.first,{temp.first,it.second}});
            }
        }
        return ans;
	}
};

class Solution{
public:
    int minCostConnectPoints(vector<vector<int>>& points){
    	Graph<int> g;
    	for(int i=0;i<points.size();i++){
    		for(int j=i+1;j<points.size();j++){
    			int val=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
    			g.add_edge(i,j,val);
    		}
    	}
    	return g.prims_mst();
    }
};