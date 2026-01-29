class Solution {
  public:
    string firstNonRepeating(string &str) {
        // code here
        // frequency array to track the frequency of elements
            
            int freq[26] = {0};
            
            // queue to track the elements of the stream with one frequency
            
            queue<char>que;
            
            string ans = "";
            
            for( int i = 0 ; i < str.length() ; i++)
            {
                freq[str[i]-'a']++;
                
                if( freq[str[i]-'a'] == 1)
                {
                    que.push(str[i]);
                }
                
                // remove all the element from the begining of queue which are having frequency greater than 1
                
                while(que.empty() == false && freq[que.front()-'a'] > 1)
                {
                    que.pop();
                }
                
                // if que is empty then append  # to answer otherwise append the character 
                
                if( que.empty())
                {
                    ans += "#";
                }
                else
                {
                    ans += que.front();
                }
            }
            
            // finally return the answer
            
            return ans;
    }
};
