class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum=0,curMax=0,maxSum=INT_MIN,curMin=0,minSum=INT_MAX;
        for(int x:nums){
            curMax=max(x,curMax+x);
            maxSum=max(maxSum,curMax);
            curMin=min(x,curMin+x);
            minSum=min(minSum,curMin);
            sum+=x;
        }
        return maxSum<0?maxSum:max(maxSum,sum-minSum);
    }
};