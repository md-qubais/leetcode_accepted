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
void get_common(vector<int>&arr1,vector<int>&arr2){
	unordered_map<int,int> present_arr1;
	for(auto&it:arr1){
		present_arr1[it]=true;
	}
	for(auto&it:arr2){
		if(present_arr1[it]){
			present_arr1[it]=false;
			cout<<it<<endl;
		}
	}
	return;
}
int32_t main(){
	qubais_judge;
	IOS;
	int n1;
	cin>>n1;
	vector<int> arr1(n1);
	for(int i=0;i<n1;i++){
		cin>>arr1[i];
	}
	int n2;
	cin>>n2;
	vector<int> arr2(n2);
	for(int i=0;i<n2;i++){
		cin>>arr2[i];
	}
	get_common(arr1,arr2);
	return 0;
}