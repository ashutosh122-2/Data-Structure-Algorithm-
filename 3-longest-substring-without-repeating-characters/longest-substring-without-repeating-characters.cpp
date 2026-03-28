class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //character may be abc ABC 0123 @#$% so total 256
        vector<bool>count(256 , 0);
        int first=0 , second=0 , len=0;
        //kab tk hamara loop chalega
        while(second<s.size()){
            //repeating character aa gye to window ko slide karege 
            while(count[s[second]]){
                count[s[first]]=0;
                first++;
            }
            count[s[second]]=1;
            len=max(len , second-first+1);
            second++;
        }
        return len;
    }
};

// This approach is also called sliding window approach In this approach We consider two variables first and second which are initially pointing to the zero of the given string Then remaining first on zero we start moving second Till we get the unique character Once we get the repeating character We delete the character which we get previously And make it count 0 in the count table and repeate the process .