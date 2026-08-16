class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;
        int currGas = 0;
        int resIdx = 0;

        for(int i=0; i<gas.size(); i++){
            currGas += gas[i] - cost[i];
            totalGas +=  gas[i] - cost[i];

            if(currGas < 0){
                currGas = 0;
                resIdx  = i+1;
            }
        }

        return totalGas >= 0 ? resIdx : -1;
    }
};
