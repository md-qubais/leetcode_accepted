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
char highest_frequency(string s){
	unordered_map<char,int> m;
	for(auto&it:s){
		m[it]++;
	}
	char char_ans;
	int max_freq=INT_MIN;
	for(auto&it:m){
		if(max_freq<m[it.first]){
			max_freq=m[it.first];
			char_ans=it.first;
		}
	}
	return char_ans;
}
int32_t main(){
	qubais_judge;
	IOS;
	string s;
	cin>>s;
	cout<<highest_frequency(s)<<endl;
	return 0;
}
