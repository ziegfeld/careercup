package Question1_3;

import CareerCupLibrary.*;

/* did twice, the second time on 2012-1-26 23:57:39
 */

public class Q1_3 {

	public static void removeDuplicate(char[] str) {
		if (null == str) return;
		int len = str.length;
		System.out.println(AssortedMethods.charArrayToString(str) + " : " + len);
		if (len <= 1) return;
		int tail = 1;
		for (int i = 1; i < len; ++ i) {
			int j;
			for (j = 0; j< tail; ++ j) {
				if (str[i] == str[j]) break;
			}
			if (j == tail) {
				str[tail] = str[i];
				++ tail;
			}
			str[tail] = 0;
		}
		
//		
//		if (null == str) return;
//		int len = str.length; // char array has .length no () property!
//		System.out.println(AssortedMethods.charArrayToString(str) + " : " + len); // 直接打印 str 结果是： [C@c17164
//		if (len <= 1) return;
//		int tail = 1; // char array starts from 0 and ends at length-1 !
//		for (int i = 1; i < len; i++ ) {
//			int j; // 退出循环后还要用的，所以不能像 i 一样在定义在循环域内
//			INNTERLOOP: for (j = 0; j<tail; j++ ) {    // 循环可以加  label 来直接从内层跳出到外层【这里其实不用】
//				if ( str[j] == str[i]) break INNTERLOOP; //str[j] == str[tail] 是错误的，一旦有一个重复字符，之后的循环就全没用了
//			}
//			if (j == tail){
//				str[tail] = str[j];
//				tail ++;
//			}
//		}
//		str[tail]=0; //结束字符串数组的方法：放置 \0.
		
	}
	
	public static void removeDuplicateEff(char[] str) {
		if (str == null) return;
		int len = str.length;
		if (len <= 1) return;
		boolean [] hit = new boolean[256];
		for (int i = 0; i < 256; ++ i) hit[i] = false;
		hit[str[0]] = true;
		int  tail = 1;
		for (int i = 1; i< len; ++i) {
			if (!hit[str[i]]) {
				hit[str[i]] = true;
				str[tail] = str[i];
				tail ++;
			}
		}
		str[tail] = 0;
	}
			
//	public static void removeDuplicatesEff(char[] str) {
//		if (str == null) return;
//		int len = str.length;
//		if (len < 2) return;
//
//		boolean[] hit = new boolean[256];
//		for (int i = 0; i < 256; ++i) {
//			hit[i] = false;
//		}
//		hit[str[0]] = true;// 别人的算法，确实，也先把第一个直接弄上去了。所以这种循环开头或结尾的另外补充（初始化）是应该的，不怕增长代码
//
//		int tail = 1;
//		for (int i = 1; i < len; ++i) {
//			if (!hit[str[i]]) {
//				str[tail] = str[i];
//				++tail;
//				hit[str[i]] = true;
//			}
//		}
//		str[tail] = 0;
//	}
//	
	public static void main(String[] args) {
		String s = "helloiloveyou";
		char[] arr = s.toCharArray();
//		removeDuplicatesEff(arr);
		removeDuplicateEff(arr);
		System.out.print(AssortedMethods.charArrayToString(arr));
	}

}
