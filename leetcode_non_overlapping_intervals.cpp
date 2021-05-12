class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals){
    	vector<pair<int,int>> arr;
    	for(int i=0;i<intervals.size();i++){
    		arr.push_back({intervals[i][0],intervals[i][1]});
    	}
    	sort(arr.begin(),arr.end());
    	int ans=0;
    	deque<pair<int,int>> q;
    	for(int i=0;i<arr.size();i++){
    		if(i==0){
    			q.push_back(arr[i]);
    		}else{
    			//till we get overlapping 
    			while(!q.empty() and q.back().first>=arr[i].first and q.back().second<=arr[i].second){
    				q.pop_back();
    				ans++;
    			}
    			q.push_back(arr[i]);
    		}
    	}
    	return ans;
    }
};