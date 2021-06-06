class Solution{
public:
    int longestOnes(vector<int>& nums, int k){
        int ans=0;
        int curr_count=0;
        int i=0;
        int j=0;
        if(k==0){
            for(int i=0;i<nums.size();i++){
                if(nums[i]==1){
                    curr_count++;
                }else{
                    ans=max(ans,curr_count);
                    curr_count=0;
                }
            }
            return max(ans,curr_count);
        }
        while(j<nums.size()){
            if(nums[j]==1){
                j++;
                curr_count++;
            }else{
                if(k==0){
                    ans=max(ans,curr_count);      
                    while(i<j and k==0){
                        if(nums[i]==0){
                            k++;
                        }
                        curr_count--;
                        i++;
                    }
                }else{
                    curr_count++;
                    k--;
                    j++;
                }
            }
        }
        return max(ans,curr_count);
    }
};