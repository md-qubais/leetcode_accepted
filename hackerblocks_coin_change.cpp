#include<iostream>
using namespace std;
int coin_change(int coin,vector<int>&arr,int n,int i){
	if(i>=n or coin<0){
		return INT_MAX;
	}
	if(coin==0){
		return 0;
	}
	int ans=0;
	for(int j=i;j<n;j++){
		ans=min(ans,coin_change(coin-arr[j],arr,n,j));
	}
	if(ans==INT_MAX){
		return 0;
	}
	return ans+1;
}
int main() {
	int coin;
	cin>>coin;
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<coin_change(coin,arr,n,0);
	return 0;
}