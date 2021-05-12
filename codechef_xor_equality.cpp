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
int power(int x,int y,int p){
	int res=1;
	x=x%p;
	if(x==0) return 0;
	while(y>0){
		if(y&1) res=(res*x)%p;
		y=y>>1;
		x=(x*x)%p;
	}
	return res;
}
int32_t main(){
	qubais_judge;
	IOS;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<power(2,n-1,1000000000+7)<<endl;
	}
	return 0;
}