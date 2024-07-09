class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double totalWaitingTime = 0;
        int currentTime = 0;
        
        for (const auto& customer : customers) {
            int arrivalTime = customer[0];
            int preparationTime = customer[1];
            
            // Update current time to the later of current time or arrival time
            currentTime = max(currentTime, arrivalTime);
            
            // Calculate finish time for this customer
            int finishTime = currentTime + preparationTime;
            
            // Calculate waiting time for this customer
            int waitingTime = finishTime - arrivalTime;
            
            // Add to total waiting time
            totalWaitingTime += waitingTime;
            
            // Update current time to finish time
            currentTime = finishTime;
        }
        
        // Calculate and return average waiting time
        return totalWaitingTime / customers.size();
    }
};