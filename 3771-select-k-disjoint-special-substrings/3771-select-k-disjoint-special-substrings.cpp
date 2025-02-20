class Solution
{
public:
/**
The problem requires us to find at leastk non-overlappingvalidsegmentsin thestring, where a valid segment containsall occurrences of each characterwithin itsfirstandlastappearance. To achieve this, we first determine thefirstandlast occurrence of each character, then identifypotential segmentswhere nocharacterappearsoutside its boundaries. We thensortthesesegmentsbased on theirending indicesandcountthe number ofnon-overlapping ones. If we find at leastksuchsegments, we returntrue; otherwise, we returnfalse.

Approach
Step 1 Initialize first and last occurrence arrays

Createarraysto store thefirstandlast positionof eachcharacter.
FillfirstOccurwith a large valuenandlastOccurwith-1.
Iterate through thestring, updating thesearrays.
Step 2 Identify valid segments

Loop through thestringand findsegmentsstarting at thefirst occurrenceof a character.
Expand thesegment until all characterswithin it are fully enclosed.
If the segment satisfies theconditions, store it.
Step 3 Sort the segments

Sort allvalid segmentsbased on their endingindextomaximize non-overlappingselections.
Step 4 Count non-overlapping segments

Iterate throughsorted segmentsand count the number of non-overlappingones.
If thecountis at leastk, returntrue; otherwise, returnfalse.
*/
    bool maxSubstringLength(std::string s, int k)
    {
        int strLen = s.size();
        if (k == 0)
        {
            return true;
        } 
        
        std::vector<int> firstOccur(26, strLen), lastOccur(26, -1);
        
        // Step 1: Find first and last occurrence of each character
        for (int pos = 0; pos < strLen; pos++)
        {
            int charIdx = s[pos] - 'a';
            firstOccur[charIdx] = std::min(firstOccur[charIdx], pos);
            lastOccur[charIdx] = std::max(lastOccur[charIdx], pos);
        }

        std::vector<std::pair<int, int>> segments;
        
        // Step 2: Find valid segments
        for (int start = 0; start < strLen; start++)
        {
            if (start != firstOccur[s[start] - 'a'])
            {
                continue;
            } 

            int farthest = lastOccur[s[start] - 'a'];
            int current = start;
            bool isValid = true;

            while (current <= farthest)
            {
                if (firstOccur[s[current] - 'a'] < start)
                {
                    isValid = false;
                    break;
                }
                
                farthest = std::max(farthest, lastOccur[s[current] - 'a']);
                current++;
            }

            if (isValid && !(start == 0 && farthest == strLen - 1))
            {
                segments.emplace_back(start, farthest);
            }
        }

        // Step 3: Sort the segments based on ending index
        std::sort(segments.begin(), segments.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b)
        {
            return a.second < b.second;
        });

        // Step 4: Count non-overlapping segments
        int segmentCount = 0, lastIndex = -1;
        for (const auto& bounds : segments)
        {
            if (bounds.first > lastIndex)
            {
                segmentCount++;
                lastIndex = bounds.second;
            }
        }

        return segmentCount >= k;
    }
};