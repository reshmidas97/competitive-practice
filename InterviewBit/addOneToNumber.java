import java.lang.*;
public class Solution 
{
    public int[] plusOne(int[] A) 
    {
        int i, carry = 1,index = 0;
        for(i = A.length-1 ; i >= 0 ; i--)
        {
            A[i] += carry;
            carry = A[i] / 10;
            A[i] = A[i] % 10;
            
        }
        
        if(carry == 1)
        {
            int b[] = new int[A.length + 1];
            b[0] = carry;
            System.arraycopy(A,0,b,1,A.length);
            
            return b;
        }
        else
        {
            for(i = 0 ; i < A.length; i++)
            {
                if(A[i] != 0)
                {
                    index = i;
                    break;
                }
            }
            
            int b[] = new int[A.length - index];
            System.arraycopy(A,index,b,0,b.length);
            
            return b;
        }
        
    }
}
