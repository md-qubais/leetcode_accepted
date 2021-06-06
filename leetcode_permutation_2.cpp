class Solution {
public:
	void permute(vector<int>&nums,vector<int>&arr,int i,int j,vector<vector<int>>&ans){
		if(i==arr.size() or j==nums.size()){
			ans.push_back(arr);
			return;
		}
		for(int k=0;k<arr.size();k++){
			if(arr[k]==INT_MIN){
				arr[k]=nums[j];
				permute(nums,arr,k,j+1,ans);
				arr[k]=INT_MIN;
			}
		}
	}
    vector<vector<int>> permuteUnique(vector<int>& nums){
    	vector<int> arr(nums.size());
    	for(int i=0;i<arr.size();i++){
    		arr[i]=INT_MIN;
    	}
    	sort(nums.begin(),nums.end());
    	vector<vector<int>> ans;
    	permute(nums,arr,0,0,ans);
    	return ans;
    }
};