/*
 * ��A��B���ݣ�����ǰ����ͺ�׺��
 * 
 * stripTrailingZeros()��ȥ��ĩβ��0(ע�������ĺ�׺��Ҳ�ᱻĨ���������ɿ�ѧ������������Ҫ�õ�����ĺ���)
 * toPlainString() �� ���ز���ָ���ֶε��ַ�����ʾ �� ��ֹ�߾�������ʾ�ɿ�ѧ������
 * replaceFirst("^0*","") : ^ƥ���ַ����Ŀ�ʼ��*��ʾ�ظ���λ�����,��""����"0"
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