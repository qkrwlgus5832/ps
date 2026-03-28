class Solution {
    fun solution(seoul: Array<String>): String {
        var answer = ""
        
        for (i in 0 until seoul.size) {
            if (seoul[i] == "Kim") {
                return "김서방은 " + i + "에 있다"
            }
        }
        return "-1"
    }
}