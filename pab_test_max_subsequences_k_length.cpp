#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);  cin.tie(NULL)
#define int long long
#define endl "\n"
#define pb push_back
#define p push
#define fori(n) for(int i=0;i<n;i++)
#define ford(n) for(int i=n-1;i>=0;i--)
#define fl(x,n) for(int i=x;i<n;i++)
#define Maxheap priority_queue<int>
#define Minheap priority_queue<int,vector<int>,greater<int>>
#define qubais_judge freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
using namespace std;
int dp[1000][1000];
int max_sum(int *arr,int n,int k,int i){
	if(i==n or k<=0){
		return 0;
	}
	int ans=0;
	if(dp[i][k]!=INT_MIN){
		return dp[i][k];
	}
	for(int j=i+2;j<n;j++){
		ans=max(ans,max_sum(arr,n,k-1,j));
	}
	if(arr[i]<0){
		return dp[i][k]=ans;
	}
	return dp[i][k]=arr[i]+ans;
}

int32_t main(){
	qubais_judge;
	IOS;
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int k;
	cin>>k;
	for(int i=0;i<1000;i++){
		for(int j=0;j<1000;j++){
			dp[i][j]=INT_MIN;
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		ans=max(ans,max_sum(arr,n,k,i));
	}
	cout<<ans<<endl;
	return 0;
}