#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<int> st;
        st.push(heights[0]);
        stack<int> indices;
        indices.push(0);
        for (int i = 1; i < heights.size(); ++i) {
            if (heights.at(i) < st.top()) {
                //int popped = 0;
                int last_index;
                while (!st.empty() && st.top() > heights.at(i)) {
                    int current_area = st.top()*(i-indices.top());
                    if (current_area > maxArea) maxArea = current_area;
                    st.pop();
                    last_index = indices.top();
                    indices.pop();
                    //popped++;
                }
                if (indices.empty()) {
                    indices.push(0);
                } else {
                    indices.push(last_index);
                }
            } else {
                indices.push(i);
            }
            st.push(heights.at(i));
        }
        while (!st.empty()) {
            int current_area = (heights.size() - indices.top())*st.top();
            if (current_area > maxArea) maxArea = current_area;
            st.pop();
            indices.pop();
        }
        return maxArea;

    }
};