class Solution {
public:
    int subarraySum(vector<int>& nums, int k){
        int ans=0;
        vector<int> presum(nums.size());
        presum[0]=nums[0];
        for(int i=1;i<presum.size();i++){
            presum[i]=presum[i-1]+nums[i];
        }
        for(int i=0;i<presum.size();i++){
            for(int j=i;j<presum.size();j++){
                if(i==0){
                    if(presum[j]==k){
                        ans++;
                    }
                }else{
                    if((presum[j]-presum[i-1])==k){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};