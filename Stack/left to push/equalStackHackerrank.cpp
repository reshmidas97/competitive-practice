nt equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
    
    int sum1=0, sum2=0, sum3=0, min=0;
    for(int i = 0 ; i < (int)h1.size() ; i++)
        sum1 += h1[i];

    for(int i = 0 ; i < (int)h2.size() ; i++)
        sum2 += h2[i];

    for(int i = 0 ; i < (int)h3.size() ; i++)
        sum3 += h3[i];

    int size1 = 0; 
    int size2 = 0;
    int size3 = 0;

    while(size1 < h1.size() || size2 < h2.size() || size3 < h3.size())
    {
        
        if(sum1 == sum2 && sum1 == sum3)
        {
            cout << size1 << " " << size2 << " " << size3 <<" ";
            return sum1;
        }
        else if(sum1 >= sum2 && sum1 >= sum3)
        {
            if(sum2 < sum3)
                min = sum2;
            else 
                min = sum3;

            while(sum1 > min)
              {  
                  sum1 = sum1 - h1[size1];
                  size1++;
              }

        }
        
        else if(sum2 >= sum1 && sum2 >= sum3)
        {
            if(sum1 < sum3)
                min = sum1;
            else 
                min = sum3;

            while(sum2 > min)
                sum2 -= h2[size2++];

        }
        else if(sum3 >= sum1 && sum3 >= sum2)
        {
            if(sum1 < sum2)
                min = sum1;
            else 
                min = sum2;

            while(sum3 > min)
                sum3 -= h3[size3++];

        }
    }
    return 0;
    

}