class Solution {
public:
    int longestSubarray(vector<int>& nums,int k=1){
        int i=0;
        int j=0;
        int ans=0;
        int curr_count=0;
        bool deleted=false;
        while(j<nums.size()){
            if(nums[j]==1){
                curr_count++;
                j++;
            }else{
                ans=max(ans,curr_count);
                if(k==0){
                    while(k==0){
                        if(nums[i]==0) k++;
                        if(nums[i]!=0) curr_count--;
                        i++;
                    }
                    continue;
                }
                deleted=true;
                k--;
                j++;
            }
        }
        ans=max(ans,curr_count);
        if(!deleted){
            if(ans==0){
                return 0;
            }
            return ans-1;
        }
        return ans;
    }
};