/* This program returns the numeric position of the first occurrence of the 
string 'needle' in the string 'haystack' without the use of any inbuilt 
C libraries. The program returns -1 if there is no match. Here offset is the 
starting point in the string 'haystack' from where the search for string
'needle' could be started.  
*/

#include <stdio.h>
#include <string.h>

int main()
{
   char label1[] = "Program";
   char *labelPtr = label1;
   char label2[] = "ra";
   char *labelPtr2 = label2;
   int a;
   a = stringops (labelPtr, labelPtr2, 0);
   printf("\na = %d\n", a);
}
int stringops (char* haystack, char* needle, int offset)
{
    int len_needle =0;
    int match =0, temp = -1, occ = -1;
    int i,x;
    for (i=0; needle[i]!= '\0'; i++)
        len_needle++;
    printf("Length of needle = %d\n", len_needle);
    for(i = offset; haystack[i]!= '\0'; i++)
    {
        if(haystack[i]==needle[0])
        {
            temp = i;
            if(len_needle ==1)
            {
                x=1;
                match=1;
            }
            for(x=1; x < len_needle; )
            {
                i++;
                if(haystack[i]==needle[x])
                {
                    match = 1;
                    x++;
                }
                else
                {
                    printf("\ni = %d\n", i);
                    printf("\nEntered else loop and executed break");
                    break;
                }   
            }
        }
        if(match==1 && x==len_needle)
        {
            occ = temp;
            break;
        }
    }
    if(occ==-1)
        return -1;
    else 
        return (occ);
}
