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
void print_permutation(int *arr,int n,int num,int k){
	if(num>k){
		for(int i=0;i<n;i++){
			cout<<arr[i];
		}
		cout<<endl;
		return;
	}
	for(int j=0;j<n;j++){
		if(arr[j]==0){
			arr[j]=num;
			print_permutation(arr,n,num+1,k);
			arr[j]=0;
		}
	}
}
int32_t main(){
	qubais_judge;
	IOS;
	int n;
	cin>>n;
	int k;
	cin>>k;
	int arr[n]={0};
	print_permutation(arr,n,1,k);
	return 0;
}