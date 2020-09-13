class Solution {
public:
    bool canPartitionHelper(vector<int>& nums, int sum)
    {
        int size = nums.size();
        bool dp[size+1][sum+1];
        for(int i=0; i<=sum; i++)
            dp[0][i] = false;
        for(int i=0; i<=size; i++)
            dp[i][0] = true;
        for(int i=1; i<=size; i++)
            for(int j=1; j<=sum; j++)
            {
                if(nums[i-1] > j)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i-1]];
            }
        return dp[size][sum];
    }
    bool canPartition(vector<int>& nums)
    {
        int sum=0;
        for(int x:nums)
            sum += x;
        if(sum&1)
            return false;
        return canPartitionHelper(nums, sum/2);
    }
};