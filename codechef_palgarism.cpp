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
		int n,m,k;
		cin>>n>>m>>k;
		vector<int> arr(k);
		vector<int> ans;
		for(int i=0;i<k;i++){
			cin>>arr[i];
		}
		unordered_map<int,int> freq;
		for(auto&it:arr){
			if(it>=1 and it<=n){
				if(freq[it]>0 and freq[it]==1){
					freq[it]++;
					ans.push_back(it);
				}else{
					freq[it]++;
				}
			}
		}
		sort(ans.begin(),ans.end());
		cout<<ans.size()<<" ";
		for(auto&it:ans){
			cout<<it<<" ";
		}
		cout<<endl;
	}
	return 0;
}