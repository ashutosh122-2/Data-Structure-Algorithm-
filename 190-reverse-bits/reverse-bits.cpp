class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string num1 = "";
        for(int i = 0; i < 32; i++) {
            num1 += (n % 2) + '0';
            n /= 2;
        }

        int ans = 0;

        for(char bit : num1) {
            ans = ans * 2 + (bit - '0');
        }

        return ans;
    }
};