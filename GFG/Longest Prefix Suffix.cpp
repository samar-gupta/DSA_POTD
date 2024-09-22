class Solution {
  public:
    int lps(string str) {
        // Your code goes here
        int i=0, count =0, k=1, j=1;
        while( i<str.length() && j < str.length()){
            if(str[i] == str[j]){
                i++;
                j++;
                count ++;
            }else{
                i=0;
                j=k;
                k++;
                count =0;
            }
        }
        return count;
    }
};
