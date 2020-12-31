class Solution {
public:
    int GetOrder(char romanChar) {
        int response = 0;
        
        switch (romanChar) {
            case 'I':
                response = 0;
                break;
            case 'V':
                response = 1;
                break;
            case 'X':
                response = 2;
                break;
            case 'L':
                response = 3;
                break;
            case 'C':
                response = 4;
                break;
            case 'D':
                response = 5;
                break;
            case 'M':
                response = 6;
                break;
            default:
                break;
                
        }
        
        return response;
    }
    int romanToInt(string s) {
        int result = 0;
        
        int romanCharValue[] = {1, 5, 10, 50, 100, 500, 1000};
        
        for (int i = 0; i < s.size(); ++i) {
            char currentChar = s[i];
            int currentCharOrder = GetOrder(currentChar);
            int currentCharValue = romanCharValue[currentCharOrder];
            
            if (i + 1 < s.size()) {
                char nextChar = s[i + 1];
                
                int nextCharOrder = GetOrder(nextChar);
                
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
