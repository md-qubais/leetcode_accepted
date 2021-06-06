/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int e){
    	int s=1;
    	while(s<=e){
    		int mid=s + ((e - s) / 2);
    		int num=guess(mid);
    		if(num==0){
    			return mid;
    		}
    		if(num==1){
    			s=mid+1;
    		}else{
    			e=mid-1;
    		}
    	}
    	return -1;
    }
};