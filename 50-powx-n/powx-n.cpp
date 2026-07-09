class Solution {
public:
    double power(double x, long long n){
        if(n == 0) return 1;
        if(n%2==0){
            double half = power(x,n/2);
            return half * half;
        }
        return x*power(x,n-1);
    }
    double myPow(double x, int n) {
        long long N = n;
        if(N<=0){
            x=1/x;
            N=-N;
        }
        return power(x,N);
    }
};