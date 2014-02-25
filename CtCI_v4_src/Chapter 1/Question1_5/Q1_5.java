package Question1_5;

import CareerCupLibrary.AssortedMethods;

public class Q1_5 {
	// Assume string has sufficient free space at the end
	public static void ReplaceFun(char[] str, int length) {
		int cntSpace = 0, newLength;
		for (int i = 0; i < length; ++i ) {
			if (' ' == str[i]) ++cntSpace;
		}
		newLength = length + 2 * cntSpace;
		str[newLength--] = 0; // newLength 的位置一定要搞清楚啊！ 还是先在纸上写伪代码，修改一遍（包括下标问题，优化等）再上机写吧！！
		for (int i = length-1 ; i >= 0; --i) {
			
			if (' ' == str[i]) {
				str[newLength] = '0';
				str[newLength-1] = '2';
				str[newLength-2] = '%';
				newLength -= 3;
			}
			else {
				str[newLength] = str[i];
				-- newLength;
			}
		}		
	}
			
	
	public static void main(String[] args) {
		String str = "abc d e f";
		char[] arr = new char[str.length() + 3 * 2 + 1];
		for (int i = 0; i < str.length(); i++) {
			arr[i] = str.charAt(i);
//			System.out.println(arr[i]);
		}
		//并不等价于 char[] arr = str.toCharArray(); 因为后面多声明了 3*2+1 个位置，虽然打印出来是 “abc d e f框框框框框框框”，但提前防止了内存泄露。
//		System.out.println(arr);
//		System.out.println(str.toCharArray());
		ReplaceFun(arr, str.length());
		System.out.println(AssortedMethods.charArrayToString(arr));
	}
}
