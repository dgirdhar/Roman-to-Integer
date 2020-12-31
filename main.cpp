class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        
        // Creating map
        unordered_map<char, int> romanCharOrderMap;
        
        romanCharOrderMap.insert(pair<char, int>('I', 0));
        romanCharOrderMap.insert(pair<char, int>('V', 1));
        romanCharOrderMap.insert(pair<char, int>('X', 2));
        romanCharOrderMap.insert(pair<char, int>('L', 3));
        romanCharOrderMap.insert(pair<char, int>('C', 4));
        romanCharOrderMap.insert(pair<char, int>('D', 5));
        romanCharOrderMap.insert(pair<char, int>('M', 6));
        
        int romanCharValue[] = {1, 5, 10, 50, 100, 500, 1000};
        
        for (int i = 0; i < s.size(); ++i) {
            char currentChar = s[i];
            int currentCharOrder = romanCharOrderMap[currentChar];
            int currentCharValue = romanCharValue[currentCharOrder];
            
            if (i + 1 < s.size()) {
                char nextChar = s[i + 1];
                
                int nextCharOrder = romanCharOrderMap[nextChar];
                
                if (currentCharOrder < nextCharOrder) {
                    currentCharValue = romanCharValue[nextCharOrder] - currentCharValue;
                    i++;
                }
            }
            
            result += currentCharValue;
        }
        
        return result;
    }
};
