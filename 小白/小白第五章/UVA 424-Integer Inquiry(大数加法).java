/*裸大数加法*/

import java.util.*;
import java.math.*;

public class Main{
	public static void main(String[] argv)
	{
		Scanner in = new Scanner(System.in);
		String line;
		BigDecimal bd = new BigDecimal("0");
		
		while(in.hasNext())
		{
			line = in.nextLine();
			
			if(line.equals("0"))
				break;
			
			bd = bd.add(new BigDecimal(line));
		}
		
		System.out.println(bd);
	}
}