#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>

union REGS in,out;
int x,y;
int Xpos,Ypos,button;

 void print()
 { gotoxy(20,100);
   outtextxy(96,213,"new game");
 }
 void prints()
 { gotoxy(20,100);
   outtextxy(96,293,"Solution");
 }
 void display()
 { gotoxy(20,100);
   outtextxy(132,373,"Rules");
 }

void detect_mouse();
void show_mouse();
void check_button();

void mouseinfo(int *button,int *Xpos,int *Ypos)
{
 union REGS in,out;
 in.x.ax=3;
 int86(0x33,&in,&out);
 *Xpos=out.x.cx;
 *Ypos=out.x.dx;
 *button=out.x.bx;
}
void detect_mouse()
{
   in.x.ax=0;
   int86(0x33,&in,&out);
   if(out.x.ax==0)
   printf("the mouse fails to initialize");
   else
   printf("\n\t\tmouse initialize sucessfully !\n");

}
void show_mouse()
{
 in.x.ax=1;
 int86(0x33,&in,&out);
}
void check_button()
{
 while(!kbhit())
 {
  in.x.ax=3;
  int86(0x33,&in,&out);
  if(out.x.bx==1)
 {
   x=out.x.cx;
   y=out.x.dx;
   if(x>80 && x<300 && y>200 && y<250)
   print();
   if(x>80 && x<300 && y>280 && y<330)
   prints();
   if(x>80 && x<300 && y>360 && y<410)
   display();
 }
   delay(100);
 }
}

