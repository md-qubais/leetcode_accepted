class Solution {
public:
	int permutation_count(vector<int> arr,int i=0){
		if(i==arr.size()){
			return 1;
		}
		int ans=0;
		for(int j=0;j<arr.size();j++){
			if(arr[j]==0){
				if((i+1)%(j+1)!=0 and (j+1)%(i+1)!=0){
					continue;
				}
				arr[j]=i+1;
				ans+=permutation_count(arr,i+1);
				arr[j]=0;
			}
		}
		return ans;
	}
    int countArrangement(int n){
    	vector<int> temp(n);
    	for(int i=0;i<n;i++){
    		temp[i]=0;
    	}
    	return permutation_count(temp);
    }
};