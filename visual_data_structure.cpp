/* Program for visual data structure algorithms */
/* Date: 14 July 2003 */
/* Author: Srinivas Nayak */
/* Compile using Turbo C++ */

/* This code is distributed under the GPL License. */
/* For more info check: */
/* http://www.gnu.org/copyleft/gpl.html */


#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>

union REGS i,o;
int x,y,button/*used in mouse functions*/,nodenum=0,edgenum=0/*used in node &edge classes*/,flag=1/*in while lopes*/;
int x1,y1,x2,y2,n_num1,n_num2;//used in givemid()
void mouse(),showmouseptr(),restrictmouseptr(),getmousepos(),hidemouseptr();
int initmouse();
int givemid(int,int,int,int);
int a1,b1,a2,b2;//for storing two points after click on edge button
struct nodestr
{
	int id,x,y;
	char name[20];
}n[30];
struct edgestr
{
	int id,x1,y1,x2,y2,weight;
}e[30];
//////////////////////////////////////////////////////////////////////////
class screen
{
       public:
       void display();
};
void screen::display()
{      setbkcolor(1);
       rectangle(0,459,639,479); //task bar
       rectangle(0,459,100,479);//node button
       char *a="node",*b="edge",*c="node name",*d="edge weightage",*e="programs",*f="new",*g="exit";
       outtextxy(20,465,a);
       rectangle(100,459,200,479); //edge button
       outtextxy(120,465,b);
       rectangle(200,459,300,479);//node name button
       outtextxy(210,465,c);
       rectangle(300,459,417,479);//edge waitage button
       outtextxy(304,465,d);
       rectangle(417,459,500,479);//program button
       outtextxy(425,465,e);
       rectangle(500,459,539,479);//new button
       outtextxy(505,465,f);
       rectangle(539,459,639,479);//exit button
       outtextxy(559,465,g);


}
//////////////////////////////////////////////////////////////////////////
class node
{
       public:
       void display(int x,int y,int num);
       int check(int x,int y);
       void onclick();
       void changename();

};
void node::display(int a,int b,int c)
{

	//int id;

	setfillstyle(SOLID_FILL,RED);
	setcolor(RED);
	fillellipse(a,b,10,10);
	setcolor(15);
	char h[1],g[2];int p,q;
	if(c<=9)
	{
	*h=c+48;
	*(h+1)='\0';
	outtextxy(a-3,b-3,h);
	}
	else
	{ p=c/10;
	 q=c%10;
	 *g=p+48;
	 *(g+1)=q+48;
	 *(g+2)='\0';
	 outtextxy(a-6,b-3,g);
	}
	setcolor(RED);

}
int node::check(int a,int b)
{
	int ans=1,i;
     for(i=0;i<=nodenum;i++)
     {
	if((a>n[i].x-30)&&(a<n[i].x+30)&&(b>n[i].y-30)&&(b<n[i].y+30))
	{ans=0;break;}
	else
	continue;
     }
   return(ans);
}
void node::onclick()
{
	setfillstyle(SOLID_FILL,YELLOW);
	setcolor(RED);
	hidemouseptr();
	bar(1,460,99,478);
	char *a="node";
	outtextxy(20,463,a);
	showmouseptr();
	setfillstyle(SOLID_FILL,RED);
	      while(flag==1)
	      {
		getmousepos();
		if(button==1&&x<639&&x>0&&y<459&&y>0&&nodenum<30&&(node::check(x,y)==1)) //if you click on workspace
		{
		nodenum++;
		n[nodenum].id=nodenum;
      //	n[nodenum].name
		n[nodenum].x=x;
		n[nodenum].y=y;

		hidemouseptr();
		node::display(x,y,nodenum);    // a node will be displayed
		showmouseptr();
		break;
		}
		if(nodenum>=30||(button==1&&(node::check(x,y)==0)))//if node is present
		{break;}
	      }
	setfillstyle(SOLID_FILL,1);
	setcolor(15);
	hidemouseptr();
	bar(1,460,99,478);
	outtextxy(20,463,a);
	showmouseptr();
	setfillstyle(SOLID_FILL,RED);
}
void node::changename()
{       int i=0;
       //	setviewport(200,200,400,250,0);
	setfillstyle(SOLID_FILL,9);
       //	bar(200,200,400,252);
	////////////
	unsigned size;
	void far*q;
	size=imagesize(200,200,400,252);
	q=(void far*)malloc(size);
	getimage(200,200,400,252,q);
	//////////////
       //	putimage(20,20,q,0);
	bar(200,200,400,252);
	char *a="change",*b="next",*c="close";
	rectangle(200,230,260,250);//change button
	outtextxy(205,233,a);
	rectangle(267,230,330,250);//next button
	outtextxy(274,233,b);
	rectangle(334,230,400,250);//close button
	outtextxy(338,233,c);
      //	textbackground(9);
       //	textcolor(6);

	int k=1;
	while(flag==1&&i<=nodenum)
	{
	//gotoxy(28,14);
       //	textbackground(3);
	//textcolor(12);
	//cprintf("dsfr");
      //	if(k==1)
       //	{
	outtextxy(210,210,"to change;click change");k++;
      //	}
	getmousepos();
	if(button==1&&x<260&&x>200&&y<250&&y>230)  //change
	{    /*gotoxy(33,14);
	     char cc;
	     int j=0;
	     while((cc=getchar())!='\n')
	     {n[i].name[j]=cc;j++;}*/
	     bar(200,200,400,229);
	     char h[2];
	     *h=i+48;
	     *(h+1)=':';
	     *(h+2)='\0';
	     outtextxy(210,210,h);
	     char cc;
	     int j=0;
	     while((cc=getchar())!='\n')
	     {n[i].name[j]=cc;j++;}

	}
	if(button==1&&x<330&&x>267&&y<250&&y>230)   //next
	{
	   i++;
	  /* gotoxy(28,14);
	  cprintf(" %d :%s         ",n[i].id,n[i].name);
	  continue;*/

	}
	if(button==1&&x<400&&x>334&&y<250&&y>230)    //close
	{
	  hidemouseptr();
	  putimage(200,200,q,0);
	  showmouseptr();
	  break;
	}

	}

}
/////////////////////////////////////////////////////////////////////////

class edge
{
       public:
       void display(int ,int ,int,int);
       void onclick();
       int checkedge(int,int,int,int);

};
void edge::display(int aa1,int bb1,int aa2,int bb2)
{
	e[edgenum].id=edgenum;
	e[edgenum].x1=aa1;
	e[edgenum].y1=bb1;
	e[edgenum].x2=aa2;
	e[edgenum].y2=bb2;
	setcolor(RED);
	line(aa1,bb1,aa2,bb2);
   /////////////display 1st node again////////////////
   setfillstyle(SOLID_FILL,RED);
	setcolor(RED);
	fillellipse(aa1,bb1,10,10);
	setcolor(15);
	char h[1],g[2];int p,q;
	if(n_num1<=9)
	{
	*h=n_num1+48;
	*(h+1)='\0';
	outtextxy(aa1-3,bb1-3,h);
	}
	else
	{ p=n_num1/10;
	 q=n_num1%10;
	 *g=p+48;
	 *(g+1)=q+48;
	 *(g+2)='\0';
	 outtextxy(aa1-6,bb1-3,g);
	}
       //	setcolor(RED);
     //////////////////////display 2nd node again////////////////
   setfillstyle(SOLID_FILL,RED);
	setcolor(RED);
	fillellipse(aa2,bb2,10,10);
	setcolor(15);
      //	char h[1],g[2];int p,q;
	if(n_num2<=9)
	{
	*h=n_num2+48;
	*(h+1)='\0';
	outtextxy(aa2-3,bb2-3,h);
	}
	else
	{ p=n_num2/10;
	 q=n_num2%10;
	 *g=p+48;
	 *(g+1)=q+48;
	 *(g+2)='\0';
	 outtextxy(aa2-6,bb2-3,g);
	}
	setcolor(RED);


}
void edge::onclick()
{
	setfillstyle(SOLID_FILL,YELLOW);
	setcolor(RED);
	hidemouseptr();
	bar(101,460,199,478);
	char *a="edge";
	outtextxy(120,463,a);
	showmouseptr();
	setfillstyle(SOLID_FILL,RED);

	       while(flag==1)
	       {
		getmousepos();
		if(button==1&&x<639&&x>0&&y<459&&y>0&&edgenum<30) //if you click on workspace
		{
		   a1=x;b1=y;
		    while(flag==1)  // waits for second click
		    {
		    getmousepos();
		    if(button==1&&x!=a1&&y!=b1)
		      {
		    a2=x;b2=y;break;
		      } //takes second point when you click
		    } // while end
		edgenum++;
		hidemouseptr();
		givemid(a1,b1,a2,b2);  //gives centers of two points
		if(givemid(a1,b1,a2,b2)==1&&edge::checkedge(x1,y1,x2,y2)==1) //condition false if you click outside the points
		{
		edge::display(x1,y1,x2,y2); //displays an edge
		}
		x1=y1=x2=y2=0;
		showmouseptr();
		break;
		} //if end
	       } // while end
	setfillstyle(SOLID_FILL,1);
	setcolor(15);
	hidemouseptr();
	bar(101,460,199,478);
	outtextxy(120,463,a);
	showmouseptr();
	setfillstyle(SOLID_FILL,RED);

}

int edge::checkedge(int a1,int b1,int a2,int b2)
{     int ans=1,i;
      for(i=0;i<30;i++)
      {
      if(a1==e[i].x1&&b1==e[i].y1&&a2==e[i].x2&&b2==e[i].y2)
      ans=0;
      }
  return(ans);
}

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
void mouse()
{
	initmouse();
	restrictmouseptr();
	showmouseptr();
}

int initmouse()
{
	i.x.ax=0;
	int86(0x33,&i,&o);
	return(o.x.ax);
}
void showmouseptr()
{
	i.x.ax=1;
	int86(0x33,&i,&o);
}
void restrictmouseptr()
{
	i.x.ax=7;
	i.x.cx=0;
	i.x.dx=639;
	int86(0x33,&i,&o);
	i.x.ax=8;
	i.x.cx=0;
	i.x.dx=479;
	int86(0x33,&i,&o);
}
void getmousepos()
{
	i.x.ax=3;
	int86(0x33,&i,&o);
	button=o.x.bx;
	x=o.x.cx;
	y=o.x.dx;
}
void hidemouseptr()
{
	i.x.ax=2;
	int86(0x33,&i,&o);
}
int givemid(int a,int b,int c,int d)
{
     int i,ret1=0,ret2=0,ret=0;
     for(i=0;i<=nodenum;i++)
     {
     if((a>n[i].x-20)&&(a<n[i].x+20)&&(b>n[i].y-20)&&(b<n[i].y+20))
     {
     x1=n[i].x;
     y1=n[i].y;
     n_num1=n[i].id;
     ret1=1;
     }
      }

     ////////////

     for(i=0;i<=nodenum;i++)
     {
     if((c>n[i].x-20)&&(c<n[i].x+20)&&(d>n[i].y-20)&&(d<n[i].y+20))
     {
    x2=n[i].x;
     y2=n[i].y;
     n_num2=n[i].id;
    ret2=1;
     }
     }
     if(ret1==1&&ret2==1)
     {ret=1;}
    return(ret);
}
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
void main()
{
	int a=DETECT,b,i,j;
	initgraph(&a,&b,"");
	for(i=0;i<30;i++)
	{ n[i].id=0;n[i].x=0;n[i].x=0;
	  for(j=0;j<20;j++)
	  n[i].name[j]=0;
	}
	for(i=0;i<30;i++)
	{ e[i].id=0;e[i].x1=0;e[i].y1=0;e[i].x2=0;e[i].y2=0;e[i].weight=0;
	}
	nodenum=0;edgenum=0;
	setfillstyle(SOLID_FILL,RED);
	screen homepage;
	node nod;
	edge edg;
	mouse();
	homepage.display();
	while(!kbhit())    //till you want to work
	{
	  getmousepos();
	  //////////////////////
	  if(button==1)   //if you click anywhere
	  {
	      if(button==1&&x<100&&x>0&&y<479&&y>459)//if you click on node button
	      {
		     nod.onclick();
	      }
	  //////////////////////
	      if(button==1&&x<200&&x>100&&y<479&&y>459) // if you click on edge button
	      {
		     edg.onclick();
	      }   //edge if end
	      if(button==1&&x<300&&x>200&&y<479&&y>459) //if click on nodename button
	      {   //  nod.changename();
	      }
	      if(button==1&&x<417&&x>300&&y<479&&y>459)//if click on edge weightage button
	      {
	      }
	      if(button==1&&x<500&&x>417&&y<479&&y>459)//if click on program button
	      {
	      }
	      if(button==1&&x<539&&x>500&&y<479&&y>459) //if click on new button
	      {
	      main();
	      }
	      if(button==1&&x<639&&x>539&&y<479&&y>459) //if click on exit button
	      {
	      exit(0);
	      }
	  } //if(button==1) end
	}  //main while end
	getch();
	closegraph();
}























