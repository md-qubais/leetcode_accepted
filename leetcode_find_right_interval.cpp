class Solution {
public:
	int find_right_interval(int s,int e,vector<pair<pair<int,int>,int>>&pairs,pair<pair<int,int>,int> val){
		int ans=-1;
		while(s<=e){
			int mid=s+(e-s)/2;
			if(pairs[mid].first.first>=val.first.second){
				ans=pairs[mid].second;
				e=mid-1;
			}else{
				s=mid+1;
			}
		}
		return ans;
	}
    vector<int> findRightInterval(vector<vector<int>>& intervals){
    	vector<pair<pair<int,int>,int>> pairs;
    	for(int i=0;i<intervals.size();i++){
    		pairs.push_back({{intervals[i][0],intervals[i][1]},i});
    	}
    	sort(pairs.begin(),pairs.end());
    	vector<int> ans(intervals.size());
    	for(int i=0;i<pairs.size();i++){
    		ans[pairs[i].second]=find_right_interval(i,pairs.size()-1,pairs,pairs[i]);
    	}
    	return ans;
    }
};