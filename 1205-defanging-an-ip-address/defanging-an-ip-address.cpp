class Solution {
public:
    string defangIPaddr(string address) {
        string ans="";
        for(int i=0 ; i<address.size() ; i++){
            if(address[i]=='0' ||address[i]=='1' ||address[i]=='2' ||address[i]=='3' ||address[i]=='4' ||address[i]=='5' ||address[i]=='6' ||address[i]=='7'||address[i]=='8' ||address[i]=='9'){
                ans+=address[i];
            }
            else{
                ans=ans+"[.]";
            }
        }
        return ans;
    }
};