class Solution {
public:
    int minimumCost(int m, int n, std::vector<int>& horizontalCut, std::vector<int>& verticalCut) {
        // Sort the horizontal and vertical cuts in descending order
        std::sort(horizontalCut.begin(), horizontalCut.end(), std::greater<int>());
        std::sort(verticalCut.begin(), verticalCut.end(), std::greater<int>());

        // Indices to keep track of the cuts
        int h = 0, v = 0;

        // Number of pieces in horizontal and vertical direction
        int hPieces = 1, vPieces = 1;

        // Total minimum cost
        int minCost = 0;

        // Loop until we process all cuts
        while (h < horizontalCut.size() && v < verticalCut.size()) {
            if (horizontalCut[h] > verticalCut[v]) {
                // Apply the horizontal cut
                minCost += horizontalCut[h] * vPieces;
                hPieces++;
                h++;
            } else {
                // Apply the vertical cut
                minCost += verticalCut[v] * hPieces;
                vPieces++;
                v++;
            }
        }

        // If there are remaining horizontal cuts
        while (h < horizontalCut.size()) {
            minCost += horizontalCut[h] * vPieces;
            hPieces++;
            h++;
        }

        // If there are remaining vertical cuts
        while (v < verticalCut.size()) {
            minCost += verticalCut[v] * hPieces;
            vPieces++;
            v++;
        }

        return minCost;
    }
};