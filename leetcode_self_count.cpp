class Solution {
public:

void merge_and_count(vector<pair<int,int>>&p,int s,int mid,int e,vector<int>&ans){
	int i=s;
	int j=mid+1;
	while(i<=mid and j<=e){
		if(p[i].first>p[j].first){
			j++;
		}else{
			ans[p[i].second]+=j-(mid+1);
			i++;
		}
	}
	while(i<=mid and j>e){
		ans[p[i++].second]+=j-(mid+1);
	}
	sort(p.begin()+s,p.begin()+e+1);
}

void countSmaller(vector<pair<int,int>>&p,int s,int e,vector<int>&ans){
	if(s>=e){
		return;
	}
	int mid=(s+e)/2;
	countSmaller(p,s,mid,ans);
	countSmaller(p,mid+1,e,ans);
	merge_and_count(p,s,mid,e,ans);
	return;
}


vector<int> countSmaller(vector<int>& nums){
	vector<pair<int,int>> p;
	for(int i=0;i<nums.size();i++){
		p.push_back({nums[i],i});
	}
	vector<int> ans(p.size(),0);
	countSmaller(p,0,p.size()-1,ans);
	return ans;
} 
};