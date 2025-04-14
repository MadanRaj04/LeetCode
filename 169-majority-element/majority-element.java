class Solution {
    public int majorityElement(int[] nums) {
        int count=0,res=0;
        for(int i=0;i<nums.length;i++)
        {
            if(count==0)
            {
                res=nums[i];
            }
            if(res==nums[i])
            {
                count+=1;
            }
            else
            {
                count-=1;
            }
        }
        return res;
    }
}