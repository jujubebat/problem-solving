import java.util.*;

// 프로그래머스 - 로또의 최고 순위와 최저 순위
class Solution {
    public int[] solution(int[] lottos, int[] win_nums) {
        int[] answer = new int[2];
        int[] ranks = {6,6,5,4,3,2,1};
        int zeroCount = 0;
        int correctCount = 0;
        Set<Integer> winNumbers = new HashSet<>();
        
        // 1. 당첨 번호를 HashSet에 담는다.
        for(int number : win_nums){
            winNumbers.add(number);
        }        
        
        // 2. 배팅 번호를 조회하면서 0의 개수와, 당첨 번호 일치 개수를 카운트한다.
        for(int number : lottos) {
        
            if (number == 0) {
                zeroCount++; // 0이라면(와일드 카드) +1
            }
            
            if(winNumbers.contains(number)){
                correctCount++; // 당첨 번호랑 일치하는 숫자가 있다면 +1
           }
            
        }
        
        answer[1] = ranks[correctCount]; // 최저 순위
        answer[0] = ranks[correctCount + zeroCount]; // 0의 개수를 포함한 최대 순위 
        
        return answer;
    }
} 
