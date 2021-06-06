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
void permute(int n,map<char,int> freq,string asf=""){
	if(asf.length()==n){
		cout<<asf<<endl;
		return ;
	}
	for(auto it:freq){
		if(freq[it.first]>0){
			freq[it.first]--;
			permute(n,freq,asf+it.first);
			freq[it.first]++;
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
		freq[s[i]]++;
	}
	permute(s.length(),freq);
	return 0;
}