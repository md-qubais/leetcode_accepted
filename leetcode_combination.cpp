class Solution {
public:
	void combination1(int n,int k,vector<int>&arr,int num,vector<vector<int>>&ans,int ssf=0,int idx=0){
		if(ssf==k){
			ans.push_back(arr);
			return ;
		}
		for(int i=num;i<=n;i++){
			arr[idx]=i;
			combination1(n,k,arr,i+1,ans,ssf+1,idx+1);
		}
	}
	void combination2(int n,int k,vector<int>&arr,int num,vector<vector<int>>&ans,int ssf=0,int idx=0){
		if(ssf==k){
			ans.push_back(arr);
			return ;
		}
		if(num>n){
			return;
		}
		arr[idx]=num;
		combination2(n,k,arr,num+1,ans,ssf+1,idx+1);
		combination2(n,k,arr,num+1,ans,ssf,idx);
	}
    vector<vector<int>> combine(int n, int k){
    	vector<int> arr(k);
    	for(int i=0;i<k;i++){
    		arr[i]=0;
    	}
    	vector<vector<int>> ans;
    	combination2(n,k,arr,1,ans);
    	return ans;
    }
};