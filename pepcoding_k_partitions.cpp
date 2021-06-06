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
int c=0;
void partition_subsets(int n,vector<vector<int>> arr,int i=1){
	if(i>n){
		for(int i=0;i<arr.size();i++){
			if(arr[i].size()==0){
				return;
			}
		}
		c++;
		cout<<c<<"."<<" ";
		for(int j=0;j<arr.size();j++){
			cout<<"[";
			for(int k=0;k<arr[j].size()-1;k++){
				cout<<arr[j][k]<<", ";
			}
			cout<<arr[j][arr[j].size()-1]<<"] ";
		}
		cout<<endl;
		return;
	}
	for(int j=0;j<arr.size();j++){
		if(arr[j].size()==0){
			arr[j].push_back(i);
			partition_subsets(n,arr,i+1);
			return;
		}else{
			arr[j].push_back(i);
			partition_subsets(n,arr,i+1);
			arr[j].erase(arr[j].begin()+(arr[j].size()-1),arr[j].begin()+(arr[j].size()));
		}
	}

}

int32_t main(){
	qubais_judge;
	IOS;
	int n;
	cin>>n;
	int k;
	cin>>k;
	vector<vector<int>> arr(k);
	for(int i=0;i<arr.size();i++){

	}
	partition_subsets(n,arr);
	return 0;
}