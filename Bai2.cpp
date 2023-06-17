#include<stdio.h>

int N,T,S,R;
int t[1000]={0},s[1000]={0},r[1000]={0};
int tmp[1000]={0};
int min=99999;




int main()
{
  scanf("%d %d %d %d",&N,&T,&S,&R);
  int cot;
  int i;
  for(cot=0;cot<N;cot++)
  {
    scanf("%d",&i);
    scanf("%d",&t[i]);
    scanf("%d",&s[i]);
    scanf("%d",&r[i]);
    tmp[s[i]] ++; 
  }
  for(i=1;i<=S;i++)
  {
    if(tmp[i] < min) min = tmp[i];
  }
  printf("%d",T-min);
}