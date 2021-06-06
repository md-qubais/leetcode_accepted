class Solution {
public:

    bool canPartition(vector<int>&nums,int target,int sum=0,int i=0){
        if(sum==target){
            return true;
        }
        if(sum>target or i>=nums.size()){
            return false;
        }
        if(canPartition(nums,target-nums[i],sum+nums[i],i+1)){
            return true;
        }
        if(canPartition(nums,target,sum,i+1)){
            return true;
        }
        return false;
    }

    bool canPartition(vector<int>& nums){
        int tot=0;
        for(auto&it:nums){
            tot+=it;
        }
        return canPartition(nums,tot);
    }

};