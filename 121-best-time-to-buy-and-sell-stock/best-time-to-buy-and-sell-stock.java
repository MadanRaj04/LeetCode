class Solution {
    public int maxProfit(int[] prices) {
        int curind=prices[0];
        int maxprof=0;
        for (int i=1;i<prices.length;i++)
        {
            if(prices[i]-curind < 0)
            {
                curind = prices[i];
            }
            maxprof = Math.max(prices[i]-curind,maxprof);
        }
        return maxprof;
    }

    
}