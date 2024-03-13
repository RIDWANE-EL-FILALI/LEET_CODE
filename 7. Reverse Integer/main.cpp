class Solution {
public:
    int reverse(int x) 
    {
        if (x > INT_MAX || x < INT_MIN)
        return (0);
        bool negative = false;
        long long tmp = x;
        long long rev = 0;
        if (tmp < 0)
        {
            negative = true;
            tmp *= -1;
        }
        while (tmp != 0)
        {
            int digit = tmp % 10;
            tmp = tmp / 10;
            rev = rev * 10 + digit;
        }
        if (negative)
            rev *= -1;
        if (rev > INT_MAX || rev < INT_MIN)
            return (0);
        return (rev);
    }
};
