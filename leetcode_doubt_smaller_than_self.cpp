class Solution{
public:
void merge(vector<pair<int, int>> &nums, int low, int high, vector<int> &ans){
	int mid = (low + high)>>1;
	int l = low;
	int r = mid+1;
	while(l<=mid && r<=high){
		if(nums[l].first <= nums[r].first){
			ans[nums[l].second]+=r-(mid+1);
			l++;
		}else{
			r++;
		}
	}
	while(l<=mid and r>high){
		ans[nums[l++].second]+=r-(mid+1);
	}
sort(nums.begin()+low, nums.begin()+high+1);
}

	void mergeSort(vector<pair<int, int>> &nums, int low, int high, vector<int> &ans){
		
               if(low<high){
			int mid = (low + high)>>1;
			mergeSort(nums, low, mid, ans);
			mergeSort(nums, mid+1, high, ans);
			merge(nums, low, high, ans);
		}
	}
	
	vector<int> countSmaller(vector<int> &nums){
		int low = 0;
		int high = nums.size()-1;
		vector<int> ans(high+1, 0);
		vector<pair<int, int>> numsPair;
		for(int i=0; i<=high; i++){
			numsPair.push_back({nums[i], i});
		}
		mergeSort(numsPair, low, high, ans);
		return ans;
	}
};
