class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drankBottles = numBottles;
        int emptyBottles = numBottles;
        
        while (emptyBottles >= numExchange) {
            int exchangedBottles = emptyBottles / numExchange;
            drankBottles += exchangedBottles;
            
            // Update empty bottles:
            // Remaining bottles that couldn't be exchanged + newly emptied bottles
            emptyBottles = (emptyBottles % numExchange) + exchangedBottles;
        }
        
        return drankBottles;
    }
};