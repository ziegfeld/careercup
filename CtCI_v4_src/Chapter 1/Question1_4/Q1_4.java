package Question1_4;

public class Q1_4 {
	public static boolean anagram(String s1, String s2) {
		int len = s1.length();
		if (len != s2.length()) return false;
		short[] flag = new short[256]; // 可以只用 short 吗？如果short够大大于256，或者string的长度小于256。 查了一下，short有 -32,768 ~ 32,767
		int numUniqueChars = 0;
		int numCompletedT = 0;
		char[] s1_arr = s1.toCharArray();
		for (char c: s1_arr) { // 循环枚举方法！！
			if ( 0 == flag[c] ) {
				numUniqueChars ++;
			}
			flag[c] ++; //这条语句之前我写在了if之内。。 所以错误了。专心！！
		}
//		for (int i = 0; i < 256; ++i )
//			if (0!= flag[i])
//			  System.out.println( (char)i + " : " + flag[i]);
//		System.out.println("afterward:");
		for (int i = 0; i < len; ++i ) {
			char c = s2.charAt(i);
			if ( 0 == flag[c]) // new char in s2 but not in s1; ( or more this char in s2 than s1
				return false; //break; //
			flag[c]--;
			if ( 0 == flag[c]) {
				numCompletedT  ++;
				if (numCompletedT == numUniqueChars)
					return (1 == len - i);
			}
		}
//		for (int i = 0; i < 256; ++i ) 
//			if (0!= flag[i])
//				  System.out.println( (char)i + " : " + flag[i]);
		return false;
	}

	public static void main(String[] args) {
		String[][] pairs = {{"apple", "papel"}, {"carrot", "tarroc"}, {"hello", "llloh"}}; // PAIRS!!!
		for (String[] pair : pairs) {
			String word1 = pair[0];
			String word2 = pair[1];
			boolean anagram = anagram(word1, word2);
			System.out.println(word1 + ", " + word2 + ": " + anagram);
		}
	}
}
