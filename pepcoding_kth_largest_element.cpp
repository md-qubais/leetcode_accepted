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
int32_t main(){
	qubais_judge;
	IOS;
	Minheap pq;
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int k;
	cin>>k;
	int i=0;
	while(i<k){
		pq.push(arr[i++]);
	}
	while(i<n){
		if(arr[i]>pq.top()){
			pq.pop();
			pq.push(arr[i]);
		}
		i++;
	}
	while(!pq.empty()){
		cout<<pq.top()<<endl;
		pq.pop();
	}
	return 0;
}