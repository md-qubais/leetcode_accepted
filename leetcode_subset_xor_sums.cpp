class Solution {
public:
    int ans=0;
    int subsetXORSum(vector<int>& nums,int i=0,int sum=0){
        if(i==nums.size()){
            ans+=sum;
            return ans;
        }
        subsetXORSum(nums,i+1,sum^nums[i]);
        subsetXORSum(nums,i+1,sum);
        return ans;
    }
};