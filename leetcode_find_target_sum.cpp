class Solution {
public:
    int dp[10000];
    int findTargetSumWays(vector<int>& nums, int target,int sum,int i){
        if(i==nums.size()){
            if(sum==target){
                return dp[i]=1;
            }
            return dp[i]=0;
        }
        if(dp[i]!=-1){
            return 1;
        }
        int op1=findTargetSumWays(nums,target,sum+(nums[i]),i+1);
        int op2=findTargetSumWays(nums,target,sum+(-nums[i]),i+1);
        return dp[i]=op1+op2;
    }
    int findTargetSumWays(vector<int>& nums, int target){
        for(int i=0;i<10000;i++){
            dp[i]=-1;
        }
        return findTargetSumWays(nums,target,0,0);
    }
};