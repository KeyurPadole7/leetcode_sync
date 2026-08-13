class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        // 1. Guard against s1 being longer than s2
        if (n1 > n2) return false;

        vector<int> freq(26, 0), wfre(26, 0);

        for (int i = 0; i < n1; i++) {
            freq[s1[i] - 'a']++;
            wfre[s2[i] - 'a']++;
        }

        if (freq == wfre) return true;

        // 2. Safe loop using signed integers
        for (int i = 0; i < n2 - n1; i++) {
            wfre[s2[i] - 'a']--;
            wfre[s2[i + n1] - 'a']++;

            if (freq == wfre) return true;
        }

        return false;
    }
};