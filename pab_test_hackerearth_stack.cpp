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

void delete_k_frinds(vector<int>&arr,int k){
	stack<int> s;
	bool deleted=false;
	int i=0;
	for(;i<arr.size() and k>0 ;i++){
		if(s.empty()){
			s.push(arr[i]);
		}
		else{
			while(!s.empty() and k>0 and s.top()<arr[i]){
				deleted=true;
				s.pop();
				k--;
			}
			s.push(arr[i]);
		}
	}
	while(i<arr.size()){
		s.push(arr[i++]);
	}
	vector<int> temp;
	while(!s.empty()){
		temp.push_back(s.top());
		s.pop();
	}
	reverse(temp.begin(),temp.end());
	if(!deleted){
		for(auto&it:temp){
			cout<<it<<" ";
		}
		return;
	}
	for(auto&it:temp){
		cout<<it<<" ";
	}
}

int32_t main(){
	qubais_judge;
	IOS;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int k;
		cin>>k;
		vector<int> arr(n);
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		delete_k_frinds(arr,k);
		cout<<endl;
	}
	return 0;
}