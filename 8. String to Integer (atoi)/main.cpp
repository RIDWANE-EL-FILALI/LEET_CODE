class Solution {
public:
    int myAtoi(string s) 
    {
        int sign = 1;
        long long result = 0;
        int i = 0;

        while (s[i] == ' ') {
            i++;
        }

        if (s[i] == '-' || s[i] == '+') {
            sign = (s[i++] == '-') ? -1 : 1;
        }

        while (isdigit(s[i])) {
            result = result * 10 + (s[i++] - '0');
            
            if (result * sign > INT_MAX) {
                return INT_MAX;
            } else if (result * sign < INT_MIN) {
                return INT_MIN;
            }
        }

        return static_cast<int>(result * sign);
    }
};
