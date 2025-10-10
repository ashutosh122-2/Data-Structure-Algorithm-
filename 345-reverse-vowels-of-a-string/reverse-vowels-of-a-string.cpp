class Solution {
public:
    bool isVovel(char ch){
        ch=tolower(ch);
        return ch== 'a'|| ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }
    string reverseVowels(string s) {
        int start=0;
        int end=s.length()-1;
        while(start<=end)
        {
            if ( isVovel(s[start])  &&  isVovel(s[end]) ){
                swap(s[start],s[end]);
                start++;
                end--;
            }
            else if(!isVovel(s[start]))
            {
                start++;
            } 
            else{
                end--;
            }
        }
        return s;
        
    }
};