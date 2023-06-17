#include<stdio.h>
#include<math.h>
#include<string.h>

int n;
char s[5];


int check(int num)
{
    // printf("%d",num);
    int i,j=0;
    for(i=(int)pow(2,n-1);i>=1;i = i/2)
    {
        char cs;
        if((num & i) == 0) cs ='0';
        else cs = '1';
        // printf("\n%d & %d = %d",num,i,num & i);

        // printf("\n%d & %d = cs = %c",num,i,cs);

        if(cs == s[j])
        {
            j++;
            if(j == strlen(s))
            {
                return 0;
            }
        }
        else
        {
            j=0;
            if(cs == s[j])
            {
                j++;
            }
        }
    }
    return 1;
}


int main()
{
    int cout = 0;
    scanf("%d",&n);
    scanf("%s",s);
    int i;
    for(i=0;i<=(int)pow(2,n)-1;i++)
    {
        if(check(i) == 1) 
        {
            // printf("i=%d",i);
            cout ++;
        }
    }
    printf("%d",cout);
    
}