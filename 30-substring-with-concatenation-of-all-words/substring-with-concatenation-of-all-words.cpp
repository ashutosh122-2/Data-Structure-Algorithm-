class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ans;

        if (s.empty() || words.empty())
            return ans;

        int wordLen = words[0].size();
        int totalWords = words.size();
        int windowSize = wordLen * totalWords;

        unordered_map<string, int> mp;

        // Store frequency of words
        for (string word : words)
            mp[word]++;

        // Try every possible starting offset
        for (int i = 0; i < wordLen; i++) {

            unordered_map<string, int> seen;

            int left = i;
            int count = 0;

            for (int right = i; right + wordLen <= s.size(); right += wordLen) {

                string word = s.substr(right, wordLen);

                // Valid word
                if (mp.count(word)) {

                    seen[word]++;
                    count++;

                    // Remove extra occurrences
                    while (seen[word] > mp[word]) {

                        string leftWord = s.substr(left, wordLen);

                        seen[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    // Found a valid window
                    if (count == totalWords) {

                        ans.push_back(left);

                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                }
                else {

                    // Invalid word -> Reset
                    seen.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }

        return ans;
    }
};