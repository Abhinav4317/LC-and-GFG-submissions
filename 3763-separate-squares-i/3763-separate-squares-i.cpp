class Solution {
public:
    /**
        Intuition
After doing a good amount of these problems, you tend to get some sort of intuition on what techniques you need to solve problems manipulating groups of polygons on a grid. Usually these are either segment trees, hashsets, or line sweeps (Note that in the sequel to this problem, we actually do end up using segment trees!)

Approach
Imagine sliding a horizontal line upward from the bottom of all the squares. As you move the line, you gradually “collect” area from the squares below it. Instead of testing every possible position, we focus on the key moments when a square starts contributing its area (at its bottom edge) or stops contributing (at its top edge). Between these moments, the area accumulates at a constant rate—almost as if we are condensing these overlapping quadrilaterals into one whose area increases linearly with the height.

We first calculate the total area of all squares, then “sweep” from bottom to top while keeping track of the total width of squares that the line is currently cutting through (this width tells us how much area is added per unit height). When the accumulated area is greater than half of the total, we know the optimal line lies somewhere within this sector. Now we can find this optimal line using some basic math.

Finding the Exact Height
When you’re sweeping upward, at each step you know:

curr-area: the area accumulated below the last processed event.
prev-height: they-value of the last processed event.
curr-height: they-value of the currently processed event.
combined-width: the sum of the side lengths of all squares currently “active” (i.e., the squares that intersect the horizontal line at that moment). This value tells you how quickly the area increases as you move upward - because between events, the area grows by a fixed rate: for every unit you move up, you addcombined-widthunits of area.
Now, imagine you’re about to process a new event at a certain y-coordinate. You first calculate the area that would be added if you moved fromprev-heighttocurr-height. This added area is:

area-diff=combined-width×(curr-height−prev-height)

Before processing this event, you check: Will adding this entirearea-diffpush our total accumulated area over half the total area?

If yes, that means the perfect splitting line (where the area below equals half of the total area) lies somewhere in betweenprev-heightandcurr-height. Since the area increases linearly as you move upward in that interval, you can precisely pinpoint the exact height where the accumulated area equals half the total area.

We set up the equation:

curr-area+(combined-width×optimal-height-diff)= 
2
total-area
​
 

Here,optimal-height-diffis the extra height aboveprev-heightthat we need to add to reach half the area. Rearranging the equation to solve foroptimal-height-diff:

optimal-height-diff= 
combined-width
2
total-area
​
 −curr-area
​
 

Finally, the y-coordinate for our splitting line is:

optimal-height=prev-height+optimal-height-diff

Complexity
We sort the events, which takes timeO(nlogn). After that, we simply do one pass through the events, which is linear time. Storing the events takes linear space.
    */
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