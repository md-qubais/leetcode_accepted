class Solution{
public:
	int subsetXORSum(vector<int>&nums,vector<int>&out,int i,int j){
		if(i==nums.size()){
			int sum=0;
			for(int k=0;k<j;k++){
				sum^=out[k];
			}
			return sum;
		}
		int left=subsetXORSum(nums,out,i+1,j);
		out[j]=nums[i];
		int right=subsetXORSum(nums,out,i+1,j+1);
		return left+right;
	}
    int subsetXORSum(vector<int>& nums){
    	vector<int> out(nums.size());
    	return subsetXORSum(nums,out,0,0);
    }
};