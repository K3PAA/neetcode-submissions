class Solution {
public:
    bool can_eat(vector<int>& piles, int count, int h) {  
        bool can = true;
        int pile = 0, c, r;
        while(pile < piles.size() && can) {
            r = (piles[pile] % count > 0 ? 1 : 0);
            c = piles[pile] / count;
            if(h >= r + c) {
                h -= r + c;
                pile++;
            } else {
                can = false;
            }
        }

        return can;
    }


    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = piles[0], s;
        for(int i = 1; i < piles.size(); ++i) {
            if(piles[i] > r) r = piles[i];
        }

        while(l < r) {
            s = l + (r - l) / 2;
            if(can_eat(piles, s, h)) {
                r = s;
            } else {
                l = s + 1;
            }        
        }

        return l;
    }
};
