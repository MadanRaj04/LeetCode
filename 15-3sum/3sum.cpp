class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums[0]>0)
        {
            return {};
        }
        vector<vector<int>> res;
        for(int i=0;i<nums.size();i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicate i

            int left = i+1;
            int right = nums.size()-1;
            while(left<right)
            {
                int total = nums[i]+nums[left]+nums[right];
                if(total > 0)
                {
                    right--;
                }
                else if(total < 0)
                {
                    left++;
                }
                else
                {
                    res.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    while( left < right && nums[left]==nums[left-1])
                    {
                        left++;
                    }

                }
                
            }
        }
        return res;

    }
};