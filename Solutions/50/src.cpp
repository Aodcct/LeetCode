class Solution {
public:
    double myPow(double x, int n) {
        bool symbolOfExponent = ( (n >= 0) ? true : false);
        double ret = 1, base = x;
        while(n != 0)
        {
            if(n % 2)
                ret *= base;
            base *= base;
            n /= 2;
        }
        return symbolOfExponent ? ret : 1.0 / ret;
    }
};
