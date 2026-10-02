class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> answer;   // stores all valid combinations
        string current = "";     // the string we are building right now

        build(answer, current, 0, 0, n);
        return answer;
    }

private:
    // open  = how many '(' we have used so far
    // close = how many ')' we have used so far
    // n     = total pairs we need
    void build(vector<string>& answer, string& current,
               int open, int close, int n) {

        // BASE CASE: if the string has 2*n characters, it is complete.
        // Because of our rules below, it is always valid.
        if (current.size() == 2 * n) {
            answer.push_back(current);   // save it
            return;
        }

        // RULE 1: We can add '(' only if we haven't used all n of them.
        if (open < n) {
            current.push_back('(');              // choose '('
            build(answer, current, open + 1, close, n);
            current.pop_back();                  // undo (backtrack) so we can try other options
        }

        // RULE 2: We can add ')' only if there is an unmatched '(' before it.
        // That means close must be less than open.
        // Example: "(" -> we can add ")" , but "" -> we cannot add ")" first.
        if (close < open) {
            current.push_back(')');              // choose ')'
            build(answer, current, open, close + 1, n);
            current.pop_back();                  // undo (backtrack)
        }
    }
};