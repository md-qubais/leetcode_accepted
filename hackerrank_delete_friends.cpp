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
	list<int> l;
	bool deleted=false;
	int i=0;
	for(;i<arr.size() and k>0 ;i++){
		if(l.empty()){
			l.push_back(arr[i]);
		}
		else{
			while(!l.empty() and k>0 and l.back()<arr[i]){
				deleted=true;
				auto it=l.begin();
				advance(it,l.size()-1);
				l.erase(it);
				k--;
			}
			l.push_back(arr[i]);
		}
	}
	while(i<arr.size()){
		l.push_back(arr[i++]);
	}
	
	if(!deleted){
		for(auto&it:l){
			cout<<it<<" ";
		}
		return;
	}
	for(auto&it:l){
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