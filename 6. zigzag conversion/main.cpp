class Solution {
public:
    string convert(string s, int numRows) {
       if (numRows == 1)
        return s;
        std::vector<std::string> rows(numRows);
        int row = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[row] += c;

            if (row == 0 || row == numRows - 1)
                goingDown = !goingDown;

            row += goingDown ? 1 : -1;
        }
        std::string result;
        for (const std::string& rowStr : rows) {
            result += rowStr;
        }
        return result; 
    }
};
