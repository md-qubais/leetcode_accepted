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
void print_permutation(int *arr,int n,int k,int asf=0,string ans="",int len=0){
	if(len>=n){
		if(asf==k){
			cout<<ans<<endl;
			return;
	}
	return;
}
	for(int i=0;i<k;i++){
		if(arr[i]==0){
			arr[i]=1;
			print_permutation(arr,n,k,asf+1,ans+to_string(i+1),len+1);
			arr[i]=0;
		}
	}
	print_permutation(arr,n,k,asf,ans+"0",len+1);
}
int32_t main(){
	qubais_judge;
	IOS;
	int n;
	cin>>n;
	int k;
	cin>>k;
	int arr[n]={0};
	print_permutation(arr,n,k);
	return 0;
}