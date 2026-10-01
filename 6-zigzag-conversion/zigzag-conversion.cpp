class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        vector<string> rows(min(numRows, (int)s.size()));
        int curRow = 0;
        bool goingDown = false;

        for(char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1)
                goingDown = !goingDown; // flip at the  edges
            curRow += goingDown ? 1 : -1; // ternary: move down or up
        }

        string ret;
        for (string& row : rows) ret += row;
        return ret;  
    }
};
// if numRows == 1, return s (no zigzag possible)
// make min(numRows, s.size()) strings, one per row
// Walk through s. Append each char to rwos[curRow]
// when curRow hit row 0 or the last row, flop the directon (goingDown = !goingDown)
// Move curRow by +1 or -1
// Concatenate all rows


/// complexity 
// time: O(n), one pass plus one join
// space: O(n) for the row strings