class Solution{
public:
    unordered_map<int,bool> present; 
    bool canPartition(vector<int>& nums,int i=0,int target=0){
        if(present[target]){
            cout<<target<<endl;
            return true;
        }
        present[target]=true;
        if(i==nums.size()){
            return false;
        }
        if(canPartition(nums,i+1,target+nums[i])){
            return true;
        }
        if(canPartition(nums,i+1,target)){
            return true;
        }
        return false;
    }
};