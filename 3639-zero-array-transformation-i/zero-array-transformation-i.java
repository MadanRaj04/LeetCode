class Solution {
    public boolean isZeroArray(int[] nums, int[][] queries) {
        int diffarr[] = new int[nums.length];
        diffarr[0] = nums[0];
        for (int i =1;i<nums.length;i++)
        {
            diffarr[i] = nums[i]-nums[i-1];
        }
        for (int i=0;i<queries.length;i++)
        {
            diffarr[queries[i][0]] += -1;
            if(queries[i][1]+1 < nums.length)
            {
            diffarr[queries[i][1]+1] -= -1;
            }
        }
        int tsum=0;
        for (int i=0;i<diffarr.length;i++)
        {
                tsum+=diffarr[i];
                if(tsum > 0)
                {
                    return false;
                }
        }

       return true; 
    }
}