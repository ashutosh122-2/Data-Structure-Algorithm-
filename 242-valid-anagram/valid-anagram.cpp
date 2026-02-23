class Solution {
 public:
  bool isAnagram(string s, string t) 
   {
        if(s.length()!=t.length())
        return false;
        
        vector<int>freq(26 , 0);

        for(char c : s)
        freq[c - 'a']++;

        
        for(char c : t)
        freq[c - 'a']--;

        for(int i=0 ; i<=25 ; i++){
            if(freq[i]!=0){
                return false;
            }
        }

    return true;
    }
   
    
};