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
		int n;
		cin>>n;
		vector<string> arr(n);
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		bool ans=false;
		for(auto&it:arr){
			bool small=false;
			bool big=false;
			for(auto&chars:it){
				if(chars>='a' and chars<='m'){
					small=true;
				}else if(chars>='N' and chars<='Z'){
					big=true;
				}else{
					ans=true;
					break;
				}
				if(small and big ){
					ans=true;
					break;
				}
			}
			if(ans){
				break;
			}
		}
		if(ans){
			cout<<"NO"<<endl;
		}else{
			cout<<"YES"<<endl;
		}

	}
	return 0;
}