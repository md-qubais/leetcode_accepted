class Solution {
public:
	void generate_subsets(vector<int>&nums,vector<int> temp,int i,int j,vector<vector<int>>&ans){
		if(j==nums.size()){
			
			return;
		}
		for(int k=j;k<nums.size();k++){
			temp[i]=nums[k];
			generate_subsets(nums,temp,i+1,k+1,ans);
		}
		
	}
    vector<vector<int>> subsets(vector<int>& nums){
    	vector<vector<int>> ans;
    	vector<int> temp(nums.size());
    	generate_subsets(nums,temp,0,0,ans);
    	return ans;
    }
};