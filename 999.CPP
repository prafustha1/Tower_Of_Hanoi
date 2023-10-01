#include "9841.h"
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<dos.h>
#include<stdlib.h>

#define MAX 10
#define Begpos 105
#define Auxpos 305
#define Endpos 505
int k=1;
int i;
char dis[10];
int width;
int p;
 typedef struct disc
    {
       char val[MAX];
       char top,pos;
    };
  disc beg,aux,end;
 void push(disc **tt,int x);
 int pop(disc *tt);
 void tower(int,disc *,disc *,disc *);
 void stack(disc *beg,disc *,disc *);
   void page();
void push(disc *tt,int x)
{
 tt->val[tt->top]=x;
 tt->top++;
}
int pop(disc *tt)
{
  int a;
  tt->top--;
  a=tt->val[tt->top];
  tt->val[tt->top]=0;
  return a;

}
void tower(int n,disc *beg,disc *aux,disc *end)
{
    if(n>0 && n<9)
 {
   tower(n-1,beg,end,aux);
   push(end,pop(beg));
   stack(beg,end,aux);
   tower(n-1,aux,beg,end);
  }
}
void stack(disc *beg,disc *end,disc *aux)
{
    int ypos=295,i,height=10,xpos,ver=0;
       cleardevice();
	setfillstyle(1,3);
	bar(100,100,110,300);
	bar(300,100,310,300);
	bar(500,100,510,300);
	setfillstyle(1,9);
	rectangle(100,100,110,300);
	rectangle(300,100,310,300);
	rectangle(500,100,510,300);
	setfillstyle(1,9);
	rectangle(20,295,180,305);
	rectangle(225,295,385,305);
	rectangle(425,295,584,305);
	setfillstyle(1,7);
	bar(20,295,180,305);
	bar(225,295,385,305);
	bar(425,295,584,305);

	outtextxy(100,315,"S");
	outtextxy(300,315,"T");
	outtextxy(500,315,"D");


	/* end tower   */
	if(end->pos==1)
	    xpos=Begpos;
       else if(end->pos==2)
	    xpos=Auxpos;
       else if(end->pos==3)
	    xpos=Endpos;

	ypos=295;
       for(i=0;i<end->top;i++)
       {
	setfillstyle(end->val[i],end->val[i]);

	bar(xpos-(end->val[i]*width),ypos,xpos+(end->val[i]*width),ypos-height);
	rectangle(xpos-(end->val[i]*width),ypos,xpos+(end->val[i]*width),ypos-height);
	  ypos-=(height+2);

       }

	 ver=end->pos;

	/* beg tower */
	if(beg->pos==1)
	    xpos=Begpos;
       else if(beg->pos==2)
	    xpos=Auxpos;
       else if(beg->pos==3)
	    xpos=Endpos;

	ypos=295;
       for(i=0;i<beg->top;i++)
       {
	setfillstyle(beg->val[i],beg->val[i]);

	bar(xpos-(beg->val[i]*width),ypos,xpos+(beg->val[i]*width),ypos-height);
	rectangle(xpos-(beg->val[i]*width),ypos,xpos+(beg->val[i]*width),ypos-height);
	  ypos-=(height+2);

       }

       ver=ver*10+beg->pos;
	      printf("%d",ver);
       /* aux tower */
	 if(ver<20)
	 {
	     if(ver%10==2)
	       xpos=Endpos;
	     else
	       xpos=Auxpos;
	  }
	  else if(ver<30)
	  {
	     if(ver%10==1)
		xpos=Endpos;
	     else
		xpos=Begpos;
	  }
	  else if(ver<40)
	  {
	    if(ver%10==1)
	      xpos=Auxpos;
	    else
	      xpos=Begpos;
	  }
		ypos=295;
       for(i=0;i<aux->top;i++)
       {
	setfillstyle(aux->val[i],aux->val[i]);

	bar(xpos-(aux->val[i]*width),ypos,xpos+(aux->val[i]*width),ypos-height);
	rectangle(xpos-(aux->val[i]*width),ypos,xpos+(aux->val[i]*width),ypos-height);
	  ypos-=(height+2);

       }


     getch();

}

void titless()
{
	show_mouse();
	setbkcolor(3);
	settextstyle(0,0,5);

	outtextxy(160,50,"TOWER OF");
	settextstyle(0,0,5);

	outtextxy(220,100,"HANOI");
	rectangle(80,200,300,250);
	settextstyle(0,0,3);
	outtextxy(96,213,"NEW GAME");
	rectangle(80,280,300,330);
	settextstyle(0,0,3);
	outtextxy(96,293,"RULES");
	rectangle(80,360,300,410);
	settextstyle(0,0,3);
	outtextxy(132,373,"EXIT");
	for(int i=0;i<14;i++)
	{	setfillstyle(SOLID_FILL,i);
		setcolor(i+1);
		bar(350,380,600,400);
		setfillstyle(SOLID_FILL,i+2);
		bar(360,360,590,380);
		setfillstyle(SOLID_FILL,i+9);
		bar(370,340,580,360);
		setfillstyle(SOLID_FILL,i+1);
		bar(380,320,570,340);
		setfillstyle(SOLID_FILL,i+4);
		bar(390,300,560,320);
		setfillstyle(SOLID_FILL,i+5);
		bar(400,280,550,300);
		setfillstyle(SOLID_FILL,i+10);
		bar(410,260,540,280);
		setfillstyle(SOLID_FILL,i+7);
		bar(420,240,530,260);
		setfillstyle(SOLID_FILL,i+8);
		bar(430,220,520,240);
		delay(300);

	}

}
void title()
{ show_mouse();
	setbkcolor(3);
	settextstyle(0,0,5);

	outtextxy(160,50,"TOWER OF");
	settextstyle(0,0,5);

	outtextxy(220,100,"HANOI");
	rectangle(80,200,300,250);
	settextstyle(0,0,3);
	outtextxy(96,213,"NEW GAME");
	rectangle(80,280,300,330);
	settextstyle(0,0,3);
	outtextxy(96,293,"RULES");
	rectangle(80,360,300,410);
	settextstyle(0,0,3);
	outtextxy(132,373,"EXIT");
}
void page()
{
   cleardevice();
   int gd=DETECT,gm;
  int errorcode;
    settextstyle(8,0,5);
    outtextxy(50,10,"TOWER OF HANOI");


   printf("\n\n\n\n\n\n\n\n\n\n\tHow many disks[1-8]:-\t ");
   gotoxy(20,40);
   scanf("%d",&p);


   if(p>9)
  {  printf("\nThis program specifies aboout 9 disks.\n So enter the number of disaks from 1 to 9\n");
  page();
  }
  else
  {
    initgraph(&gd,&gm,"c:\\tc\\bgi");
    errorcode=graphresult();

    if(errorcode!= grOk)
    {
     printf("graphic error: %s",grapherrormsg(errorcode));
       printf("press any key to halt:") ;
       getch();
       exit(1);
     }
    width=50/p;

    beg.top=end.top=aux.top=0;
    beg.pos=1;
    end.pos=3;
    aux.pos=2;

     for(i=0;i<p;i++)
      {	push(&beg,(p-i)+1);
       }
   stack(&beg,&end,&aux);
  tower(p,&beg,&aux,&end);

   cleardevice();
   title();

  }

      title();
}
void rules()
{
 cleardevice();
  int gd=DETECT,gm;
  initgraph(&gd,&gm,"c:\\tc\\bgi");
 outtextxy(100,10,"rules");
 outtextxy(50,80,"> only one disk can be move at a time");
 outtextxy(50,100,"> no larger disk can be placed above smaller disk");
 outtextxy(50,120,"> after removing disk it should placed in suitable tower ");
 delay(3000);
 cleardevice();
 title();
}
void main()
{
  int gd=DETECT,gm;
  initgraph(&gd,&gm,"c:\\tc\\bgi");
    show_mouse();
      title();
     //check_button();


  while(!kbhit())
  {
   in.x.ax=3;
   int86(0x33,&in,&out);
   if(out.x.bx==1)
     {
     x=out.x.cx;
     y=out.x.dx;
     if(x>80 && x<300 && y>200 && y<250)
       { page();
       }
     if(x>80 && x<300 && y>280 && y<330)
       { rules();
       }
	if(x>80 && x<300 && y>360 && y<410)
       { exit(0);
       }

     }
   delay(100);
  }




 getch();
}










