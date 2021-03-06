/*300. Longest Increasing Subsequence
Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
 

Constraints:

1 <= nums.length <= 2500
-10^4 <= nums[i] <= 10^4
*/
//the explanation is very simple just find out the Longest_common_subsequence(nums and sorted(nums));
class Solution {
public:
        int lcs(vector<int>&x,vector<int>&y,int n,int m)
        {
                int dp[n+1][m+1];
                for(int i=0;i<=n;i++)
                {
                        
                        for(int j=0;j<=m;j++)
                        {
                                if(i==0 or j==0)
                                        dp[i][j]=0;
                                else if(x[i-1]==y[j-1])
                                        dp[i][j]=1+dp[i-1][j-1];
                                else
                                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                        }
                }
                return dp[n][m];
                
        }
    int lengthOfLIS(vector<int>& nums) {
           
            int n=nums.size();
            set<int>s(nums.begin(),nums.end());
            vector<int>nums1(s.begin(),s.end());
            int m=nums1.size();
            //sort(nums.begin(),nums.end());
            return lcs(nums1,nums,m,n);
        
    }
};
