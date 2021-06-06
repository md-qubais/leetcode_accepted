class Solution{
public:
    int numTeams(vector<int>& arr){
        if(arr.size()<3){
            return 0;
        }
        int ans=0;
        for(int i=0;i<arr.size()-2;i++){
            for(int j=i+1;j<arr.size()-1;j++){
                for(int k=j+1;k<arr.size();k++){
                    if(arr[i]<arr[j] and arr[j]<arr[k]){
                        ans++;
                    }else if(arr[i]>arr[j] and arr[j]>arr[k]){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};