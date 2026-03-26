class Solution {
public:
    string sortSentence(string s) {
        vector<string> ans(10);
        string temp;
        int i = 0;
        int count = 0;

        s.push_back(' ');
        while (i < s.size()) {
            if (s[i] == ' ') {
                int pos = temp[temp.size() - 1] - '0';
                temp.pop_back(); // remove number
                ans[pos] = temp;
                temp = "";
                count++;
                i++;
            } else {
                temp += s[i];
                i++;
            }
        }
        for (int i = 1; i <= count; i++) {
            temp += ans[i];
            temp += " ";
        }
        temp.pop_back(); // Last space
        return temp;
    }
};