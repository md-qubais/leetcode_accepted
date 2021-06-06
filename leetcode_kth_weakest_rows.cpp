class Solution{
public:
	static bool compare(pair<int,int> p1,pair<int,int> p2){
		if(p1.second==p2.second){
			return p1.first<p2.first;
		}
		return p1.second<p2.second;
	}
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k){
    	vector<pair<int,int>> temp;
    	for(int i=0;i<mat.size();i++){
    		int count=0;
    		for(int j=0;j<mat[i].size();j++){
    			if(mat[i][j]==1){
                    count++;
                }
    		}
    		temp.push_back({i,count});
    	}
    	sort(temp.begin(),temp.end(),compare);
    	vector<int> ans;
    	for(int i=0;i<k;i++){
    		ans.push_back(temp[i].first);
    	}
    	return ans;
    }
};