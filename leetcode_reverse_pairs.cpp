class Solution {
public:
	int answer=0;
	void merge_and_count(vector<int>&nums,int s,int mid,int e){
		int i=s;
		int j=mid+1;
		while(i<=mid and j<=e){
			if((long)nums[i]>(long)2*nums[j]){
				j++;
			}else{
				i++;
				answer+=j-(mid+1);
			}
		}
		while(i<=mid and j>e){
			answer+=j-(mid+1);
			i++;
		}

		//it uses quick sort
		//it uses heapsort
		//it uses insertion sort
		//depends upon the input
		//worst case O(N*logN)
		sort(nums.begin()+s,nums.begin()+e+1);
	}
	void reversePairs(vector<int>& nums,int s,int e){
		if(s>=e){
			return;
		}
		int mid=(s+e)/2;
		reversePairs(nums,s,mid);
		reversePairs(nums,mid+1,e);
		merge_and_count(nums,s,mid,e);
	}

    int reversePairs(vector<int>& nums){
    	reversePairs(nums,0,nums.size()-1);
    	return answer;
    }
};