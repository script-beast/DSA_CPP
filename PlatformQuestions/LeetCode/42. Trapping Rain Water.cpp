#include <bits/stdc++.h>
using namespace std;

int trap(vector<int> &height)
{
    //using stack
    stack<int> st;
    int ans = 0;

    for (int i = 0; i < height.size(); i++)
    {
        while (!st.empty() && height[st.top()] < height[i])
        {
            int top = st.top();
            st.pop();

            if (st.empty())
                break;

            int distance = i - st.top() - 1;
            int bounded_height = min(height[i], height[st.top()]) - height[top];
            ans += distance * bounded_height;
        }
        st.push(i);
    }

    return ans;
}