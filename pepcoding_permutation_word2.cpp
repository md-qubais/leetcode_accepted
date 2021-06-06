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
void permute(int n,vector<char> ans,map<char,int> freq,int asf,string temp){
	if(asf==n or temp.length()==0){
		for(auto&it:ans){
			cout<<it;
		}
		cout<<endl;
		return ;
	}
	for(int i=freq[temp[0]]+1;i<ans.size();i++){
		if(ans[i]==' '){
			ans[i]=temp[0];
			permute(n,ans,freq,asf+1,temp.substr(1));
			freq[temp[0]]=i;
			ans[i]=' ';
		}
	}
}
int32_t main(){
	qubais_judge;
	IOS;
	string s;
	cin>>s;
	map<char,int> freq;
	for(int i=0;i<s.length();i++){
		freq[s[i]]=-1;
	}
	vector<char> ans(s.length());
	for(int i=0;i<ans.size();i++){
		ans[i]=' ';
	}
	permute(s.length(),ans,freq,0,s);
	return 0;
}