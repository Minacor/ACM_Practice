/*
 * 注意:通过BigDecimal的divide(BigDecimal)方法进行除法时当不整除，出现无限循环小数时，就会抛异常
 * 所以使用这样的divide(BigDecimal , int a, int b) , a是保留几位小数，b是舍入的模式，
 * 如ROUND_DOWN就是不进行任何进位，直接舍去多余位数
 * 取余是remainder()
 */

import java.util.*;
import java.math.*;

public class Main{
	public static void main(String[] argv)
	{
		Scanner in = new Scanner(System.in);
		BigDecimal bd1,bd2;
		String op;
		
		while(in.hasNext())
		{
			String s1 = in.next();
			op = in.next();
			String s2 = in.next();
			
			bd1 = new BigDecimal(s1);
			bd2 = new BigDecimal(s2);
			
			if(op.equals("/"))
			{
				System.out.println(bd1.divide(bd2 , 0 , BigDecimal.ROUND_DOWN));
			}
			else
			{
				System.out.println(bd1.remainder(bd2));
			}
				
				
		}
	
	}
}