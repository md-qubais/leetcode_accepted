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
void coin_change(vector<int>&arr,int target,int i=0,string asf=""){
	if(target<0){
		return;
	}
	if(target==0){
		cout<<asf<<"."<<endl;
		return;
	}
	for(int j=i;j<arr.size();j++){
		if((target-arr[j])<0){
			return;
		}
		coin_change(arr,target-arr[j],j,asf+to_string(arr[j])+"-");
	}

}
int32_t main(){
	qubais_judge;
	IOS;
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int k;
	cin>>k;
	coin_change(arr,k);	
	return 0;
}