class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target){
        sort(nums.begin(),nums.end());
        int i=0;
        int ans=I
        int result=0;
        for(int i=0;i<nums.size()-2;i++){
            int start=i+1;
            int end=nums.size()-1;
            while(start<end){
                int sum=nums[i]+nums[start]+nums[end];
                if(sum==target){
                    return ans;
                }
                if(sum>target){
                    end--;
                }else{
                    start++;
                }
                if(abs(ans-target)>abs(sum-target)){
                    cout<<sum<<endl;
                    ans=abs(sum-target);
                    result=sum;
                }
            }
        }
        return result;
    }
};