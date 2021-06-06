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
void words_k_length(int k,string temp,vector<char> ans,int asf=0){
	
	if(asf==k){
		for(auto&it:ans){
			cout<<it;
		}
		cout<<endl;
		return;
	}
	if(temp.size()==0){
		return;
	}
	for(int i=0;i<k;i++){
		if(ans[i]==' '){
			ans[i]=temp[0];
			words_k_length(k,temp.substr(1),ans,asf+1);
			ans[i]=' ';
		}
	}
	words_k_length(k,temp.substr(1),ans,asf);
}


int32_t main(){
	qubais_judge;
	IOS;
	map<char,int> freq;
	string s;
	cin>>s;
	int k;
	cin>>k;
	for(auto&it:s){
		freq[it]=2;
	}
	string temp="";
	for(auto&it:s){
		if(freq[it]>1){
			freq[it]=1;
			temp+=it;
		}
	}
	vector<char> ans(k);
	for(auto&it:ans){
		it=' ';
	}
	words_k_length(k,temp,ans);
	return 0;
}