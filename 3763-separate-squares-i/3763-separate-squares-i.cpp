class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double total_area = 0;
        for (const auto& square : squares) {
            total_area += (double)square[2] * (double)square[2];
        }

        vector<pair<int, pair<int, int>>> events;
        for (const auto& square : squares) {
            int x = square[0], y = square[1], l = square[2];
            events.push_back({y, {1, l}});       // Start of square
            events.push_back({y + l, {0, l}});  // End of square
        }

        // Sort events by y-coordinate
        sort(events.begin(), events.end());

        double combined_width = 0;
        double curr_area = 0;
        int prev_height = 0;

        for (int i = 0; i < events.size(); i++) {
            int y = events[i].first;
            int start = events[i].second.first;
            int l = events[i].second.second;

            double height_diff = y - prev_height;
            double area_diff = combined_width * height_diff;

            if (curr_area + area_diff >= total_area / 2) {
                // Calculate the optimal height difference
                double optimal_height_diff = (total_area / 2 - curr_area) / combined_width;
                return prev_height + optimal_height_diff;
            }

            combined_width += start ? l : -l;
            curr_area += area_diff;
            prev_height = y;
        }

        return -1; // This should never be reached
    }
};