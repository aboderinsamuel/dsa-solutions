class Solution {
public:
    /**
     * Validates if the input string contains valid parentheses.
     * A string is valid if:
     * - Open brackets are closed by the same type of brackets
     * - Open brackets are closed in the correct order
     * - Every close bracket has a corresponding open bracket
     *
     * @param s Input string containing only '(', ')', '{', '}', '[', ']'
     * @return true if the string is valid, false otherwise
     */
    bool isValid(string s) {
        // Use string as a stack to store opening brackets
        string stack;

        // Iterate through each character in the input string
        for (char current_char : s) {
            // If current character is an opening bracket, push it onto the stack
            if (current_char == '(' || current_char == '{' || current_char == '[') {
                stack.push_back(current_char);
            }
            // If it's a closing bracket
            else if (stack.empty() || !isMatchingPair(stack.back(), current_char)) {
                // Stack is empty (no matching opening bracket) or
                // brackets don't match - return false
                return false;
            }
            else {
                // Valid matching pair found, remove the opening bracket from stack
                stack.pop_back();
            }
        }

        // Valid only if all opening brackets have been matched (stack is empty)
        return stack.empty();
    }

private:
    /**
     * Checks if the given left and right brackets form a matching pair.
     *
     * @param left_bracket The opening bracket character
     * @param right_bracket The closing bracket character
     * @return true if they form a valid pair, false otherwise
     */
    bool isMatchingPair(char left_bracket, char right_bracket) {
        return (left_bracket == '(' && right_bracket == ')') ||
               (left_bracket == '[' && right_bracket == ']') ||
               (left_bracket == '{' && right_bracket == '}');
    }
};
