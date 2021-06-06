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
void words_k_selection(int k,string temp,vector<char> arr,int i=0,int j=0){
	if(i==k){
		for(auto&it:arr){
			cout<<it;
		}
		cout<<endl;
		return;
	}
	for(int i1=j;i1<temp.length();i1++){
		arr[i]=temp[i1];
		words_k_selection(k,temp,arr,i+1,i1+1);
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
	vector<char> arr(k);
	string temp="";
	for(auto it:s){
		if(freq[it]==1){
			freq[it]=0;
			temp+=it;
		}
	}
	words_k_selection(k,temp,arr,0);
	return 0;
}