class Solution {
public:
    int reverse(int a) {
        long long x = a;
        bool negative = (x < 0) ? true: false;
        x = abs(x);
        int y[32];
        memset(y, 0, sizeof(y) );
        int index = 0;
        while(x > 0)
        {
            y[index++] = x % 10;
            x /= 10;
        }
        long long maxmum = (1 << 31) - 1;
        long long ret = 0;
        for(int i = 0; i < index; i++)
        {
            ret = ret * 10 + y[i];
            if(ret > maxmum)
            {
                ret = 0;
                break;
            }
        }
        if(negative) ret = -ret;
        return (int)ret;
    }
};

/*
改进：
class Solution {
public:
    int reverse(int x) {
        long long ret = 0;
        while(x != 0)
        {
            ret = (ret * 10) + (x % 10);
            if(ret > INT_MAX || ret < INT_MIN)
                return 0;
            x /= 10;
        }
        return (int)ret;
    }
};
*/