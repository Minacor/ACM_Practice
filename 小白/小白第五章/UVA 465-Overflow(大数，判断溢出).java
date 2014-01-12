
  注意前导零，输出的时候是按照原样输出，而BigDecimal会把前导零忽略
  BigDecimal的比较用compareTo()
 

import java.util.;
import java.math.;

public class Main{
	public static void main(String[] argv)
	{
		Scanner in = new Scanner(System.in);
		BigDecimal bd1,bd2,Int = new BigDecimal(Integer.MAX_VALUE);
		String op;
		
		while(in.hasNext())
		{
			String s1 = in.next();
			op = in.next();
			String s2 = in.next();
			
			bd1 = new BigDecimal(s1);
			bd2 = new BigDecimal(s2);
			
			System.out.println(s1 +   + op +   + s2);
			
			if(bd1.compareTo(Int)  0)
				System.out.println(first number too big);
			if(bd2.compareTo(Int)  0)
				System.out.println(second number too big);
			if(op.equals(+) && bd1.add(bd2).compareTo(Int)  0)
				System.out.println(result too big);
			if(op.equals() && bd1.multiply(bd2).compareTo(Int)  0)
				System.out.println(result too big);
					
		}
	}
}