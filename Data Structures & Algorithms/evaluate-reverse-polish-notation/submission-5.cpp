class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string &t : tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                int y = st.top(); st.pop();
                int x = st.top(); st.pop();

                if (t == "+") st.push(x + y);
                else if (t == "-") st.push(x - y);
                else if (t == "*") st.push(x * y);
                else st.push(x / y);
            } else {
                st.push(stoi(t));
            }
        }

        return st.top();
    }
};