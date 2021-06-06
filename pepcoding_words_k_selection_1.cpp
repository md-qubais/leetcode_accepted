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
void words_k_selection(int k,string temp,map<char,int> freq,string ans=""){
	if(ans.size()==k){
		cout<<ans<<endl;
		return;
	}
	for(auto it:temp){
		if(freq[it]>0){
			freq[it]--;
			words_k_selection(k,temp.substr(1),freq,ans+it);
		}
	}
}
int32_t main(){
	qubais_judge;
	IOS;
	string s;
	cin>>s;
	int k;
	cin>>k;
	map<char,int> freq;
	for(auto it:s){
		freq[it]=1;
	}
	words_k_selection(k,s,freq);
	return 0;
}