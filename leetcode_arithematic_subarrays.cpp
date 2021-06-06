class Solution{
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r){
    	int n=l.size();
    	vector<bool> ans;
    	for(int i=0;i<n;i++){
    		vector<int> temp(nums.begin()+l[i],nums.begin()+r[i]+1);
    		sort(temp.begin(),temp.end());
            if(temp.size()==1){
                ans.push_back(false);
            }else if(temp.size()==2){
                ans.push_back(true);
            }else{
                int diff=temp[1]-temp[0];
                bool b=false;
                for(int k=2;k<temp.size();k++){
                    if(temp[k]-temp[k-1]!=diff){
                        b=true;
                        break;
                    }
                }
                if(b){
                    ans.push_back(false);
                }else ans.push_back(true);
            }
    	}
    	return ans;
    }
};