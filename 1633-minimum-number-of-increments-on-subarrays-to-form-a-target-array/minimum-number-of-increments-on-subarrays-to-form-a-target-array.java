class Solution {
    public int minNumberOperations(int[] target) {
        int diffarr[] = new int[target.length];
        diffarr[0]=target[0];
        for (int i=1;i<target.length;i++)
        {
            diffarr[i]=target[i]-target[i-1];
        }
        int count=0;
        for (int i=0;i<target.length;i++)
        {
            if(diffarr[i]>0)
            {
                count+=diffarr[i];
            }
        }
        return count;
    }
}