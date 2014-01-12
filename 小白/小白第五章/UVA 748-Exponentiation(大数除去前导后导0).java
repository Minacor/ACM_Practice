/*
 * 求A的B次幂，忽略前导零和后缀零
 * 
 * stripTrailingZeros()：去除末尾的0(注意整数的后缀零也会被抹掉，输出变成科学计数法，所以要用到下面的函数)
 * toPlainString() ： 返回不带指数字段的字符串表示 ， 防止高精度数表示成科学计数法
 * replaceFirst("^0*","") : ^匹配字符串的开始，*表示重复零次或更多次,用""代替"0"
 * 
 */

import java.util.*;
import java.math.*;

public class Main{
	public static void main(String[] argv)
	{
		Scanner in = new Scanner(System.in);
		BigDecimal bd1,bd2;
		
		while(in.hasNext())
		{
			String s1 = in.next();
			String s2 = in.next();
			
			bd1 = new BigDecimal(s1);
			bd2 = new BigDecimal(s2);
			
			String str = bd1.pow(bd2.intValue()).stripTrailingZeros().toPlainString();
			
			if(str.indexOf("0") < str.indexOf("."))
				str = str.replaceFirst("^0*","");
			
			System.out.println(str);
		}
	
	}
}