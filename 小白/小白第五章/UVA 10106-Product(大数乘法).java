/*Âã´óÊý³Ë·¨*/

import java.util.*;
import java.math.*;

public class Main{
	public static void main(String[] argv)
	{
		Scanner in = new Scanner(System.in);
		
		while(in.hasNext())
		{
			System.out.println(new BigDecimal(in.next()).multiply(new BigDecimal(in.next())));
		}
	}
}