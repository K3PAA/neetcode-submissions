class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> occurance;
        for(int i = 0; i < nums.size(); ++i) {
            if(occurance.count(nums[i])) {
                occurance[nums[i]] += 1;
            } else {
                occurance[nums[i]] = 1;
            }
        }
        priority_queue<pair<int, int>> max_heap;
        // Nie modyfikujemy oryginalnej mapy, nie kopiujemy wartości a referencję mamy
        for (const auto& element : occurance) {
            max_heap.push({ element.second, element.first });
        }

        vector<int> sol;
        pair<int, int> tv;
        int i = 0;
        while(i < k && !max_heap.empty()) {
            tv = max_heap.top();
            max_heap.pop();
            sol.push_back(tv.second);
            i++;
        }

        return sol;
    }
};
