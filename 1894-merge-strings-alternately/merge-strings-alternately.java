class Solution {
    public String mergeAlternately(String word1, String word2) {
        StringBuilder st = new StringBuilder();
        int n = word1.length();
        int m = word2.length();
        int i=0;
        while(i < n || i < m)
        {
            if( i< n)
            {
                st.append(word1.charAt(i));
            }
            if(i<m)
            {
                st.append(word2.charAt(i));
            }
            i++;
        }
        return st.toString();
    }
}