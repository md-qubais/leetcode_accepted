class Solution{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target){
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(auto it:nums){
            cout<<it<<" ";
        }
        cout<<endl;
        for(int i=0;i<nums.size()-3;i++){
            bool b=false;
            for(int j=i+1;j<nums.size()-2;j++){
                int s=j+1;
                int e=nums.size()-1;
                int sum=0;
                while(s<e){

                    sum+=nums[i]+nums[j]+nums[s]+nums[e];
                    cout<<sum<<endl;
                    if(sum==target){
                        vector<int> temp(4);
                        temp[0]=nums[i];
                        temp[1]=nums[j];
                        temp[2]=nums[s];
                        temp[3]=nums[e];
                    }
                    if(sum<target){
                        s++;
                    }else{
                        e--;
                    }
                }
            }
        }

        return ans;
    }
};