class Solution {
    fun solution(s: String): Int {
        var answer = 0
        
        var startIndex = 0
        
        if (s[0] == '-' || s[0] == '+') {
            startIndex = 1
        }
        
        for (i in startIndex until s.length) {
            answer = answer * 10 + (s[i] - '0')    
        }
        
        if (s[0] == '-') {
            answer = answer * -1;
        }
        return answer
    }
}