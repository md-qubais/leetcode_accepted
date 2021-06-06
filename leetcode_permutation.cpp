class Solution {
public:
	void permute(vector<int>&nums,vector<vector<int>>&ans,int i=0){
		if(i>=nums.size()){
			ans.push_back(nums);
			return;
		}
		for(int j=i;j<nums.size();j++){
			swap(nums[i],nums[j]);
			permute(nums,ans,i+1);
			swap(nums[i],nums[j]);
		}

	}
    vector<vector<int>> permute(vector<int>& nums){
    	vector<vector<int>> ans;
    	permute(nums,ans);
    	return ans;
    }
};