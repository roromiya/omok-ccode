#include<stdio.h>
#include<string.h>
#include<time.h>
#include <conio.h>
#include<stdlib.h>
#define Size 19
#define LEFT   97
#define RIGHT  100
#define UP     119
#define DOWN   115
#define spacebar 32
#define ESC      27


void makeomok();
void move();
void winner();
char omokdoll[Size][Size] = {0};
int d = 0,b = 9,c = 9;

int main()
{
 printf("아무키나 누르십시오"); 
 getch();
 system("cls");
 for(int i = 0; i < 19; i++)
  for(int j = 0; j < 19; j++)
   omokdoll[i][j] = 0;
 makeomok();
 move();
}

void makeomok()
{
 system("cls");
 for(int i = 0; i < 19; i++)
 {
  for(int j = 0; j < 19; j++)
  {
   if(omokdoll[i][j] == 0)
    printf("┼");
   else if(omokdoll[i][j] == 1)
    printf("○");
   else if(omokdoll[i][j] == 2)
    printf("●");
   else if(omokdoll[i][j] == 3)
    printf("☜"); 
  }
  if(i == 2)
   printf(" 조작법:w,a,s,d");
  if(i == 3)
   printf(" 돌 놓기:스페이스 바"); 
  printf("\n");
 }
 move();
}

void move()
{
 while(1)
 {
  int a = getch();
  if(a == RIGHT&&c != 0)
  {
   if(omokdoll[b][c] == 3)
    omokdoll[b][c] = 0;
   c++;
   if(omokdoll[b][c] == 0)
    omokdoll[b][c] = 3;
  }
  else if(a == LEFT&&c != 19)
  {
   if(omokdoll[b][c] == 3)
    omokdoll[b][c] = 0;
   c--;
   if(omokdoll[b][c] == 0)
    omokdoll[b][c] = 3;
  }
  else if(a == UP&&b != 0)
  {
   if(omokdoll[b][c] == 3)
    omokdoll[b][c] = 0;
   b--;
   if(omokdoll[b][c] == 0)
    omokdoll[b][c] = 3;
  }
  else if(a == DOWN&&b != 19)
  {
   if(omokdoll[b][c] == 3)
    omokdoll[b][c] = 0;
   b++;
   if(omokdoll[b][c] == 0)
    omokdoll[b][c] = 3;
  }
  else if(a == spacebar&&omokdoll[b][c] == 3)
  {
   if(d == 0)
   {
    omokdoll[b][c] = 1;
    d = 1;
    winner();
   }
   else if(d == 1)
   {
    omokdoll[b][c] = 2;
    d = 0;
    winner();
   }
  }
  break;
 }
 makeomok();
}

void winner()
{
 for(int i = 0; i < 19; i++)
 {
  for(int j = 0; j < 19; j++)
  {
   if(omokdoll[i][j]==1&&omokdoll[i][j+1]==1&&omokdoll[i][j+2]==1&&omokdoll[i][j+3]==1&&omokdoll[i][j+4]==1)
   {
    printf("흑이 승리하였습니다.");
    getchar(); 
    for(int i = 0; i < 19; i++)
     for(int j = 0; j < 19; j++)
      omokdoll[i][j] = 0;
   }
   else if(omokdoll[i][j]==1&&omokdoll[i+1][j]==1&&omokdoll[i+2][j]==1&&omokdoll[i+3][j]==1&&omokdoll[i+4][j]==1)
   {
    printf("흑이 승리하였습니다.");
    getchar();
    for(int i = 0; i < 19; i++)
     for(int j = 0; j < 19; j++)
      omokdoll[i][j] = 0;
   }
   else if(omokdoll[i][j]==1&&omokdoll[i+1][j+1]==1&&omokdoll[i+2][j+2]==1&&omokdoll[i+3][j+3]==1&&omokdoll[i+4][j+4]==1)
   {
    printf("흑이 승리하였습니다.");
    getchar();
    for(int i = 0; i < 19; i++)
     for(int j = 0; j < 19; j++)
      omokdoll[i][j] = 0;
   }
   else if(omokdoll[i][j]==2&&omokdoll[i][j+1]==2&&omokdoll[i][j+2]==2&&omokdoll[i][j+3]==2&&omokdoll[i][j+4]==2)
   {
    printf("백이 승리하였습니다.");
    getchar();
    for(int i = 0; i < 19; i++)
     for(int j = 0; j < 19; j++)
      omokdoll[i][j] = 0;
   }
   else if(omokdoll[i][j]==2&&omokdoll[i+1][j]==2&&omokdoll[i+2][j]==2&&omokdoll[i+3][j]==2&&omokdoll[i+4][j]==2)
   {
    printf("백이 승리하였습니다.");
    getchar();
    for(int i = 0; i < 19; i++)
     for(int j = 0; j < 19; j++)
      omokdoll[i][j] = 0;
   }
   else if(omokdoll[i][j]==2&&omokdoll[i+1][j+1]==2&&omokdoll[i+2][j+2]==2&&omokdoll[i+3][j+3]==2&&omokdoll[i+4][j+4]==2)
   {
    printf("백이 승리하였습니다.");
    getchar();
    for(int i = 0; i < 19; i++)
     for(int j = 0; j < 19; j++)
      omokdoll[i][j] = 0;
   }
  }
 }
} 
