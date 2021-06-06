class Solution {
public:
	void permute(vector<int>&nums,vector<int> temp,map<int,int> freq,vector<vector<int>>&ans,int i=0){
		if(i==nums.size()){
			ans.push_back(temp);
			return;
		}
		for(auto it:freq){
			if(freq[it.first]>0){
				freq[it.first]--;
				temp[i]=it.first;
				permute(nums,temp,freq,ans,i+1);
				freq[it.first]++;
			}
		}
	}
    vector<vector<int>> permuteUnique(vector<int>& nums){
    	sort(nums.begin(),nums.end());
    	map<int,int> freq;
    	for(auto&it:nums){
    		freq[it]++;
    	}
    	vector<vector<int>> ans;
    	vector<int> temp(nums.size());
    	permute(nums,temp,freq,ans);
    	return ans;
    }
};