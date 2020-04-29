#include <stdio.h>
#include <stdlib.h>

int main()
{

    int RailFenceArray[4][17]; //Declaring a 2D array for use in encrypting and decrypting
    int i=0, j=0; //Declaring i and j to use them to specify certain characters in the 2D array
    int bound;

    while (i < 4) //Making all elements of the array a '-' char, but it is stored as its ASCII value
        {
            RailFenceArray[i][j] = 45;
            j++;
            if (j == 17)
                {
                    i++;
                    j=0;
                }
        }
        i=0;
        j=0;
            while (j < 17) //Making elements of the array where a letter would be a '#' character
            {
                bound = 0;

                if (i == 0 && bound == 0) //Determining the state such that the cipher goes down the long zig-zag
                {
                    while (i < (4-1)) //Setting all elements that fall along the large down zig to the '#' character as its ASCII value
                    {
                        RailFenceArray[i][j] = 35;
                        i++;
                        j++;
                    }
                    bound = 1;
                }
                else if (i == (4-1) && bound == 1) //Determining the state such that the cipher goes up the small zig-zag
                {
                    while (i > (4-2)) //Setting all elements that fall along the small up zag to the '#' character as its ASCII value
                    {
                        RailFenceArray[i][j] = 35;
                        i--;
                        j++;
                    }
                    bound = 2;
                }
                else if (i == (4-2) && bound == 2) //Determining the state such that the cipher goes down the small zig-zag;
                {
                    while (i < (4-1)) //Setting all elements that fall along the small down zig to the '#' character as its ASCII value
                    {
                        RailFenceArray[i][j] = 35;
                        i++;
                        j++;
                    }
                    bound = 3;
                }
                else if (i == (4-1) && bound == 3) //Determining the state such that the cipher goes up the large zig-zag
                {
                    while (i < 0) //Setting all elements that fall along the large up zag to the '#' character as its ASCII value
                    {
                        RailFenceArray[i][j] = 35;
                        i--;
                        j++;
                    }
                    bound = 0;
                }
            }
    for(i=0; i<4; i++)
        {
            for(j=0;j<17;j++)
            {
                printf("%d ", RailFenceArray[i][j]);
                if(j==16)
                {
                    printf("\n");
                }
            }
        }

    return 0;
}
