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
int count_number(int n,int k){
	int l=1, r=n/2;
    while(l <= r){
        int mid = l + (r-l)/2;

        if(mid*(n-mid) <= n*k) l=mid+1;
        else r=mid-1;
    }
    return r*2;
}
int32_t main(){
	qubais_judge;
	IOS;
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		cout<<count_number(n,k)<<endl;
	}
	return 0;
}