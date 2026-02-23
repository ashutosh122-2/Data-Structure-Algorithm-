class Solution {
public:
    string reverseWords(string s) {
        //pahle poore statement ko reverse kr lo 
        reverse(s.begin(),s.end());
        int n=s.length();
        //ek empty string jisme ans store hoga 
        string ans = "";
        // ab jab hamne poori string ko reverse kia hai "the pen"="nep eht"
        //ab hum individual word ko alag kare ge 

        for(int i=0 ; i<=n ; i++){
            string word="";
            //word hamara kab tk word mana jata hai jab tk space na aae or agar last word hai to uska size poore string se chota ho 
            while(i<n && s[i]!=' ' ){
                word = word + s[i];
                i++;
            }
            //ab individual words ko utaege or reverse karege 
            reverse(word.begin() , word.end());
            //ab agar word ki length 0 se badi hai to vo word hai otherwise vo space hai 
            if(word.length()>0){
                //to hum log usko ans me add kar lege 
                ans=ans+" "+word;
            }

        }
        //isme hum substring bna ke one se isliye return kr rhe hai kyo ki hamara starting mr ek additional space add ho jaega 
        return ans.substr(1);
        
    }
};