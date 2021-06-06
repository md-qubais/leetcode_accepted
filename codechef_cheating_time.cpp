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
		int n,k,f;
		cin>>n>>k>>f;
		vector<pair<int,int>> arr(n);
		for(int i=0;i<arr.size();i++){
			int n1;
			int n2;
			cin>>n1>>n2;
			arr[i]=make_pair(n1,n2);
		}
		int tot=0;
		bool b=false;
		sort(arr.begin(),arr.end());
		vector<pair<int,int>> temp;
		for(int i=0;i<arr.size();i++){
        	if(temp.size()==0){
        		temp.push_back(arr[i]);
        	}else{
        		int index=temp.size()-1;
        		if(temp[index].second>=arr[i].first and (temp[index].second<=arr[i].second or temp[index].second>=arr[i].second) ){
        			pair<int,int> p;
        			if(temp[index].second<=arr[i].second) p=make_pair(temp[index].first,arr[i].second);
        			if(temp[index].second>=arr[i].second) p=make_pair(temp[index].first,temp[index].second);
        			temp[index]=p;
        		}else{
        			temp.push_back(arr[i]);
        		}
        	}
        }
        tot+=temp[0].first;
        for(int i=1;i<temp.size();i++){
			tot+=temp[i].first-temp[i-1].second;
		}
		tot+=f-temp[temp.size()-1].second;
		if(tot>=k){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}