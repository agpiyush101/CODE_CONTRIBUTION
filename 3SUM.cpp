Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 

Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105


//      set<vector<int>>ans;
       
//         int n=nums.size();
//      unordered_map<int,int>m;
//      for(auto x:nums)
//      {
//          m[x]++;
//      }
//      for(int i=0;i<n;i++)
//      {
//          m[nums[i]]--;
//          for(int j=i+1;j<n;j++)
//          {
//             m[nums[j]]--;
//             int k=-1*(nums[i]+nums[j]);
//             if(m[k]!=0)
//             {
//                 vector<int>temp;
//                 temp.push_back(nums[i]);
//                 temp.push_back(nums[j]);
//                 temp.push_back(k);
//                 sort(temp.begin(),temp.end());
//                 ans.insert(temp);
//             }

//             m[nums[j]]++;
//          }
//          m[nums[i]]++;
//      }
// vector<vector<int>>ansf(ans.begin(),ans.end());
//      return ansf;
       



sort(nums.begin(),nums.end());

int n=nums.size();
vector<vector<int>>ans;
for(int i=0;i<n;i++)
{
    if(i>0 and nums[i]==nums[i-1])
    continue;
    int left=i+1;
    int right=n-1;
while(left<right)
{
    int s=-1*(nums[i]);
    int k=nums[left]+nums[right];
    if(k>s)
    right--;
    else if(k<s)
    left++;
    else
    {
        ans.push_back({nums[i],nums[left],nums[right]});
        while(left<right and nums[left]==nums[left+1]) left++;
        while(left<right and nums[right]==nums[right-1]) right--;
        left++;
        right--;

    }

}
}
return ans; 