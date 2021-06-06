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
vector<vector<int>> dp(1001);
void fill_diagonally(vector<vector<int>>&arr){
	int num=1;
	vector<int> temp(1001,-1);
	for(int i=0;i<=1000;i++){
		arr[i]=temp;
		dp[i]=temp;
	}
	for(int j=0;j<=1000;j++){
		int rows=0;
		int cols=j;
		while(rows<=1000 and cols>=0){
			arr[rows++][cols--]=(num++);
		}
	}

}

int max_path(vector<vector<int>>&arr,int i,int j,int endi,int endj){
	if(i>endi-1 or j>endj-1 or i<0 or j<0){
		return 0;
	}
	if(i==endi-1 and j==endj-1){
		return arr[i][j];
	}
	int down=max_path(arr,i+1,j,endi,endj);
	int right=max_path(arr,i,j+1,endi,endj);
	return max(down,right)+arr[i][j];
}

int32_t main(){
	qubais_judge;
	IOS;
	int t;
	cin>>t;
	vector<vector<int>> arr(1001);
	fill_diagonally(arr);
	while(t--){
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
	    cout<<max_path(arr,x1-1,y1-1,x2,y2)<<endl;
	}
	return 0;
}