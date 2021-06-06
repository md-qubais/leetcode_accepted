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
/*
Chefland is holding a virtual 
marathon for the categories 10 km, 21 km and 42 km 
having prizes A,B,C (A<B<C) respectively to promote
 physical fitness. In order to claim the prize in a
  particular category the person must 
cover the total distance for that category within D days
. Also a single person cannot apply in multiple categories.
*/
int32_t main(){
	qubais_judge;
	IOS;
	int t;
	cin>>t;
	while(t--){
		int D,d,a,b,c;
		cin>>D>>d>>a>>b>>c;
		int num=D*d;
		if(num>=10 and num<21){
			cout<<a<<endl;
			continue;
		}else if(num>=21 and num<42){
			cout<<b<<endl;
			continue;
		}else if(num>=42){
			cout<<c<<endl;
			continue;
		}else{
			cout<<0<<endl;
		}
	}
	return 0;
}