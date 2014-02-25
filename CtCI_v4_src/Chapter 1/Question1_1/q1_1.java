package Question1_1;

public class q1_1 {
	public static boolean isUniqueChars (String str){
		int checker = 0;
		for (int i=0; i < str.length(); i++){
			int val = 1<< (str.charAt(i) - 'a');
			if ((checker & val) != 0)  //&要括起来。 int 不能直接转换成 boolean
				return false;
			checker |= val;
		}
		return true;
	}

	public static boolean isUniqueChars3(String str) {
		boolean[] char_set = new boolean[256];
		for (int i = 0; i < str.length(); i++) {
			int val = str.charAt(i);
			if (char_set[val]) return false; // char 可以直接转换成 boolean
			char_set[val] = true;
		}
		return true;
	}
	public static boolean isUniqueChars2(String str) {
		boolean[] char_set = new boolean[256];
		for (int i = 0; i < str.length(); i++) {
			int val = str.charAt(i);
			if (char_set[val]) return false;
			char_set[val] = true;
		}
		return true;
	}

	public static void main(String[] args) {
		long startTime=System.currentTimeMillis();   //获取开始时间  
		String[] words = {"asdflkj","hello","banana","bicycle","triand"};
		for (int i=0; i<1e+6; i++){
			for (String word : words) { // 循环枚举方法！！
				System.out.println(word + ": " + isUniqueChars(word) + " " + isUniqueChars3(word));
//				isUniqueChars(word);
//				isUniqueChars3(word);				
			}
		}
		long endTime=System.currentTimeMillis(); //获取结束时间  
		System.out.println("程序运行时间： "+(endTime-startTime)+"ms");   		

	}
}