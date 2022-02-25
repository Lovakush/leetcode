class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int cursum = 0;
        int maxsum = INT_MIN;
        
        if(n==1)
        {
            return nums[0];
        }
        for(int i=0;i<n;i++)
        {
            cursum+= nums[i];
            maxsum = max(cursum,maxsum);
            
            if(cursum<0)
                cursum = 0;
        }
           return maxsum;
    }
 
};