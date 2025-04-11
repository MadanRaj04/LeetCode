class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> hmap = new HashMap<Integer,Integer>();
        for(int i=0;i<nums.length;i++)
        {
            if(hmap.get(target-nums[i]) != null)
            {
                return new int[] {i,hmap.get(target-nums[i])};
            }
            hmap.put(nums[i],i);
        }
        return new int[]{};
    }
}