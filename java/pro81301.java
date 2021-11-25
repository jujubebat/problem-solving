import java.util.*;

// 프로그래머스 - 숫자 문자열과 영단어(2021 카카오 인턴)
// 나의 풀이
class Solution {

    public int solution(String s) {
        String answer = "";

        Map<String, Integer> numberInfo = new HashMap<>(); // 숫자 정보를 map으로 관리한다.
        numberInfo.put("zero", 0);
        numberInfo.put("one", 1);
        numberInfo.put("two", 2);
        numberInfo.put("three", 3);
        numberInfo.put("four", 4);
        numberInfo.put("five", 5);
        numberInfo.put("six", 6);
        numberInfo.put("seven", 7);
        numberInfo.put("eight", 8);
        numberInfo.put("nine", 9);

        String word = "";
        for (int i = 0; i < s.length(); i++) {
            if (Character.isDigit(s.charAt(i))) {
                answer += s.charAt(i); // 숫자라면, 바로 결과에 더한다.
            } else {
                word += s.charAt(i); // 문자라면 word 변수에 더한다.
            }

            if (numberInfo.containsKey(word)) { // word가 숫자 단어인지 map에서 확인한다.
                answer += numberInfo.get(word); // word가 숫자 단어라면, 결과에 더한다.
                word = ""; // 한 번 더한 숫자 단어이므로 word를 초기화한다.
            }
        }

        return Integer.parseInt(answer); // 문자열 결과를 int로 바꿔서 리턴한다.
    }
}

// 좋은 풀이 참고해서, 다시 푼 풀이
class Solution {

    public int solution(String s) {
        String[] alphabets = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        String[] digits = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

        for (int i = 0; i < 10; i++) {
            s = s.replaceAll(alphabets[i], digits[i]); // 문자열 치환할때 replaceAll이 유용하다.
        }

        return Integer.parseInt(s);
    }
}