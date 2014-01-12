/*
 * ע��:ͨ��BigDecimal��divide(BigDecimal)�������г���ʱ������������������ѭ��С��ʱ���ͻ����쳣
 * ����ʹ��������divide(BigDecimal , int a, int b) , a�Ǳ�����λС����b�������ģʽ��
 * ��ROUND_DOWN���ǲ������κν�λ��ֱ����ȥ����λ��
 * ȡ����remainder()
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