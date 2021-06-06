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
	deque<int> q;
	for(auto&it:arr){
		q.push_back(it);
	}
	bool deleted=false;
	bool b=true;
	while(k>0 and b){
		b=false;
		for(int i=0;i<q.size()-1;i++){
			while(i>=0 and i<q.size()-1 and q[i]<q[i+1] and k>0){
				b=true;
				deleted=true;
				k--;
				q.erase(q.begin()+i);
				i--;
			}
		}
			if(!b){
				break;
			}
	}
	if(!deleted){
		for(int i=0;i<q.size()-1;i++){
			cout<<q[i]<<" ";
		}
	}else{
		for(auto&it:q){
			cout<<it<<" ";
		}
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