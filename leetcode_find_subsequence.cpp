class Solution{
public:
    set<vector<int>> s;

    void findSubsequences(vector<int>&nums,int i,vector<int> temp){
        if(i==nums.size()){
            if(temp.size()>1){
                s.insert(temp);
            }
            return;
        }
        findSubsequences(nums,i+1,temp);
        if(temp.size()==0){
            temp.push_back(nums[i]);
        }else{
            if(temp[temp.size()-1]<=nums[i]){
                temp.push_back(nums[i]);
            }
        }
        findSubsequences(nums,i+1,temp);
        return;
    }

    vector<vector<int>> findSubsequences(vector<int>& nums){
        vector<int> temp;
        findSubsequences(nums,0,temp);
        vector<vector<int>> ans;
        for(auto&it:s){
            ans.push_back(it);
        }
        return ans;
    }
    
};