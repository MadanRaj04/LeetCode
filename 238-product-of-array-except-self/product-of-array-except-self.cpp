class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> larr(nums.size());
        vector<int> rarr(nums.size());
        larr[0]=1;
        rarr[nums.size()-1]=1;
        for(int i=1;i<nums.size();i++)
        {
            larr[i] = nums[i-1]*larr[i-1];
        }

        for(int j=nums.size()-2;j>=0;j--)
        {
            rarr[j] = nums[j+1]*rarr[j+1];
        }
        vector<int> res(nums.size());
        for(int i=0;i<larr.size();i++)
        {
            res[i] = larr[i]*rarr[i];
        }
    return res;
    }
};