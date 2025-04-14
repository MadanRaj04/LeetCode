class Solution {
    public void moveZeroes(int[] nums) {
        int left = 0;
        int tvar=0;
        for (int i =0;i<nums.length;i++)
        {
            if(nums[i] != 0)
            {
                tvar = nums[left];
                nums[left] = nums[i];
                nums[i]=tvar;
                left++;
            }
        }
    }
}