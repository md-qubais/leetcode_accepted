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
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		bool seven=false,three=false;
		bool b=false;
		for(int i=0;i<s.length();i++){
			if(s[i]=='7' ){
				seven=true;
			}else if(s[i]=='3'){
				three=true;
			}
			if(seven and three){
				cout<<"LUCKY"<<endl;
				b=true;
				break;
			}
		}
		if(!b){
			cout<<"BETTER LUCK NEXT TIME"<<endl;
		}
	}
	return 0;
}