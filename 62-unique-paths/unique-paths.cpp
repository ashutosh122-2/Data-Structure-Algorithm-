class Solution {
public:
    long long fact[201];
    long long M = 2e9+11;
    long long exp(long long n, long long x){
        if(x == 0)return 1;
        long long half = exp(n, x/2);
        if(x&1){
            return (n*((half*half)%M))%M;
        }
        return (half*half)%M;

    }
    void init(){
        fact[0] =1;
        fact[1] =1;
        for(long long i = 2; i <= 200;++i){
            fact[i] = i*fact[i-1];
            fact[i]%=M;
        }
    }
    long long factDiv(long long n){
        return exp(fact[n],M-2);
    }
    int uniquePaths(int m, int n) {
        init();
        long long ans = (fact[m+n-2]*((factDiv(m-1)*factDiv(n-1))%M))%M;
        return ans;
    }
};