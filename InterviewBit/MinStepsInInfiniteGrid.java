import java.lang.Math;
public class Solution 
{
    public int coverPoints(int[] A, int[] B) 
    {
        int sum = 0, count = 0, i;
        int aDiff = 0, bDiff = 0;
        for( i = 0 ; i < A.length-1 ; i++ )
        {
            aDiff = Math.abs(A[i] - A[i+1]);
            bDiff = Math.abs(B[i] - B[i+1]);
            
            if( aDiff <= bDiff )
            {
                count = aDiff + Math.abs(bDiff - aDiff);
            }
            else
            {
                count = bDiff + Math.abs(aDiff -  bDiff);
            }
            
            sum += count;
        }
        
        return sum;
        
    }
}