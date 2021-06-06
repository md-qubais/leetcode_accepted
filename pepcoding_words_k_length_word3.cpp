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
void words_k_length(string s,map<char,int> lastocc,vector<char> arr,int k,int asf=0,int i=0){
	if(i==s.length()){
		if(asf==k){
			for(auto&it:arr){
				cout<<it;
			}
			cout<<endl;
		}
		return;
	}
	int num=lastocc[s[i]];
	for(int j=lastocc[s[i]]+1;j<k;j++){
		if(arr[j]==' '){
			arr[j]=s[i];
			lastocc[s[i]]=j;
			words_k_length(s,lastocc,arr,k,asf+1,i+1);
			arr[j]=' ';
			lastocc[s[i]]=num;
		}
	}
	if(lastocc[s[i]]==-1){
		words_k_length(s,lastocc,arr,k,asf,i+1);
	}
	return;
}
int32_t main(){
	qubais_judge;
	IOS;
	string s;
	cin>>s;
	int k;
	cin>>k;
	map<char,int> lastocc;
	for(auto&it:s){
		lastocc[it]=-1;
	}
	vector<char> arr(k);
	for(int i=0;i<k;i++){
		arr[i]=' ';
	}
	words_k_length(s,lastocc,arr,k);
	return 0;
}