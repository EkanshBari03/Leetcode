class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {

        stack<int> s;
        for (auto c : tokens)
        {
            if (c == "+")
            {
                int val1 = s.top();
                s.pop();
                int val2 = s.top();
                s.pop();
                s.push(val2 + val1);
            }
            else if (c == "-")
            {
                int val1 = s.top();
                s.pop();
                int val2 = s.top();
                s.pop();
                s.push(val2 - val1);
            }
            else if (c == "*")
            {
                int val1 = s.top();
                s.pop();
                int val2 = s.top();
                s.pop();
                s.push(val2 * val1);
            }
            else if (c == "/")
            {
                int val1 = s.top();
                s.pop();
                int val2 = s.top();
                s.pop();
                s.push(val2 / val1);
            }
            else
            {
                s.push(stoi(c));
            }
        }

        return s.top();
    }
};