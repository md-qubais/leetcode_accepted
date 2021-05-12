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

void longest_consecutive_sequence(vector<int>&arr){
	unordered_map<int,bool> m;
	for(auto&it:arr){
		m[it]=true;
	}
	for(auto&it:arr){
		if(m.count(it-1)){
			m[it]=false;
		}
	}
	int max_length=INT_MIN;
	int start_val;
	for(auto&it:m){
		if(m[it.first]){
			int len=0;
			int val=it.first;
			int temp=val;
			while(m.count(val)){
				
				len++;
				val++;
			}
			if(max_length<len){
				max_length=len;
				start_val=temp;
			}else if(max_length==len){
				if(start_val>temp){
					start_val=temp;
				}
			}
		}
	}
	for(int i=1;i<=max_length;i++){
		cout<<start_val++<<endl;
	}
}

int32_t main(){
	qubais_judge;
	IOS;
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	longest_consecutive_sequence(arr);
	return 0;
}