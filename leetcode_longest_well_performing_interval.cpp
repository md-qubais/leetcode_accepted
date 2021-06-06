class Solution {
public:
    int longestWPI(vector<int>& hours){
        vector<int> temp(hours.size());
        for(int i=0;i<hours.size();i++){
            if(hours[i]>8){
                temp[i]=1;
            }else{
                temp[i]=-1;
            }
        }
        int ans=0;
        vector<int> presum(temp.size());
        presum[0]=temp[0];
        for(int i=1;i<temp.size();i++){
            presum[i]=presum[i-1]+temp[i];
        }
        for(int i=0;i<presum.size();i++){
            for(int j=i;j<presum.size();j++){
                if(i==j){
                    if(temp[j]>=0){
                        ans=max(ans,j-i+1);
                    }
                }else{
                    if((presum[j]-presum[i])>=0){
                        ans=max(ans,j-i+1);
                    }
                }
            }
        }
        return ans;
    }
};