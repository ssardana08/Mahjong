#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<stdlib.h>
struct cell{int a[4];
	    };

cell playgrid[5][10];
int a[5][10];

void blank_tile(int row,int col,int layer)
{int i,j,x1,y1,x2,y2;
 setcolor(0);
 x1=(col*50)+50+(layer*10);
 x2=x1+50;
 y1=(row*80)+50-(layer*10);
 y2=y1+80;
 rectangle(x1,y1,x2,y2);
 setcolor(15);
 for(i=x1+1;i<=x2;i++)
  line(i,y1,i,y2-1);
 setcolor(0);
 rectangle(x1+10,y1-10,x2+10,y2-10);
 setcolor(15);
 for(i=x1+10;i<=x2+9;i++)
  line(i,y1-9,i,y2-10);
 setcolor(0);
 line(x1,y1,x1+10,y1-10);
 line(x2,y2,x2+10,y2-10);
 setfillstyle(1,15);
 floodfill(x1+2,y1-1,0);
 setcolor(8);
 for(i=0;i<=9;i++)
  line(x1+1+i,y2-1-i,x2+i,y2-1-i);
 setcolor(7);
 for(i=x1+1;i<=x1+10;i++)
 {line(i,y1,i,y2-1);
  y1--;
  y2--;
 }


}

 void selector(int row,int col,int layer)
 {int x1,y1;
   x1=(col*50)+60+(layer*10);
   y1=(row*80)+40-(layer*10);
   setcolor(1);
   circle(x1+40,y1+7,4);
   setfillstyle(1,9);
   floodfill(x1+40,y1+7,1);

 }

 int fix(int row,int col,int layer)
 {int x1,y1;
  int l=layer,val=0;

  while((playgrid[row][col].a[l]==0)&&(l>0))
   l--;
  if(l>0)
     {if((playgrid[row][col-1].a[l]==0)||(playgrid[row][col+1].a[l]==0)||(col==0)||(col==9))
      {x1=(col*50)+40+(layer*10);
       y1=(row*80)+40-(layer*10);
       setcolor(4);
       circle(x1+40,y1+7,4);
       setfillstyle(1,12);
       floodfill(x1+40,y1+7,4);
       val=playgrid[row][col].a[l];
      }
     }
  return val;
 }
 int b[120],po;
 int check()
 {int i=0,p,t,row,col,l,k,temp;
  po=0;
  for(row=0;row<=4;row++)
  for(col=9;col>=0;col--)
  {l=a[row][col];
   while((playgrid[row][col].a[l]==0)&&(l>0))
   l--;
  if(l>0)
   {if((playgrid[row][col-1].a[l]==0)||(playgrid[row][col+1].a[l]==0)||(col==0)||(col==9))
   {b[po]=playgrid[row][col].a[l];
    po++;
  }
  }
  }
   for(t=0;t<=po-2;t++)
   for(k=t+1;k<=po-1;k++)
   if(b[k]<b[t])
   {temp=b[t];
    b[t]=b[k];
    b[k]=temp;
   }
  for(t=0;t<=po-2;t++)
  if(b[t]==b[t+1])
  {i=2;
   break;
  }
  return i;
   }

 void remove1(int row,int col,int layer)
 {int x1,y1;
  x1=(col*50)+40+(layer*10);
  y1=(row*80)+40-(layer*10);
  setcolor(1);
  circle(x1+40,y1+7,4);
  setfillstyle(1,15);
  floodfill(x1+40,y1+7,1);
  setcolor(15);
  circle(x1+40,y1+7,4);
 }
 void remove2(int row,int col,int layer)
 {int x1,y1;
  x1=(col*50)+60+(layer*10);
  y1=(row*80)+40-(layer*10);
  setcolor(1);
  circle(x1+40,y1+7,4);
  setfillstyle(1,2);
  floodfill(x1+40,y1+7,1);
  setcolor(2);
  circle(x1+40,y1+7,4);
 }
 void remove(int row,int col,int layer)
 {int x1,y1;
  x1=(col*50)+60+(layer*10);
  y1=(row*80)+40-(layer*10);
  setcolor(1);
  circle(x1+40,y1+7,4);
  setfillstyle(1,15);
  floodfill(x1+40,y1+7,1);
  setcolor(15);
  circle(x1+40,y1+7,4);
 }


 void tile1(int row,int col,int layer)
 { int x,y,j,i;
   for(j=0;j<=2;j++)
   for(i=0;i<=2;i++)
    {x=(i*15)+(col*50)+70+(layer*10);
    y=(j*20)+(row*80)+55-(layer*10);
     if(i==1)
     setcolor(4);
     else
     setcolor(2);
     ellipse(x,y,0,360,4,1);
     line(x-1,y+2,x-1,y+12);
     line(x+1,y+2,x+1,y+12);
     ellipse(x,y+13,0,360,4,1);
     ellipse(x,y+7,0,360,4,1);
     setcolor(15);
     line(x-1,y+1,x+1,y+1);
     line(x-1,y+12,x+1,y+12);
 }}

 void tile3(int row,int col,int layer)
  {int x,y;
   x=(col*50)+60+(layer*10);
    y=(row*80)+40-(layer*10);
    setcolor(1);
    settextstyle(1,0,5);
    outtextxy(x,y+8,"ÞÞ");
   }
 void tile4(int row,int col,int layer)
  {int x,y;
   x=(col*50)+65+(layer*10);
    y=(row*80)+50-(layer*10);
    setcolor(13);
    settextstyle(4,0,4);
    outtextxy(x+5,y,"[è]");
   }

 void tile2(int row,int col,int layer)
  {int x,y;
   x=(col*50)+73+(layer*10);
    y=(row*80)+35-(layer*10);
    setcolor(6);
    settextstyle(3,0,6);
    outtextxy(x,y+10,"{}");
   }

 void tile5(int row,int col,int layer)
  {int x,y;
   x=(col*50)+73+(layer*10);
    y=(row*80)+35-(layer*10);
    setcolor(4);
    settextstyle(3,0,6);
    outtextxy(x,y+10,"Û");
   }

 void tile6(int row,int col,int layer)
  {int x,y;
   x=(col*50)+67+(layer*10);
    y=(row*80)+50-(layer*10);
    setcolor(8);
    settextstyle(3,0,4);
    outtextxy(x+4,y+4,"³²³");
   }

  void tile7(int row,int col,int layer)
  {int x,y;
   x=(col*50)+67+(layer*10);
    y=(row*80)+50-(layer*10);
    setcolor(8);
    rectangle(x+2,y+5,x+34,y+55);
    circle(x+18,y+30,12);
    setfillstyle(9,4);
    floodfill(x+10,y+25,8);
    setfillstyle(1,7);
    floodfill(x+3,y+6,8);
   }

 //selection of pattern on tile
 void eturn(int p,int r,int c,int l)
 {  if(p==1)
      tile1(r,c,l);

     if(p==2)
      tile3(r,c,l);

      if(p==3)
       tile4(r,c,l);

     if(p==4)
      tile2(r,c,l);

     if(p==5)
      tile5(r,c,l);

     if(p==6)
      tile6(r,c,l);

     if(p==7)
      tile7(r,c,l);
      }

 int r,e,p,c,l,startr=0,count=0,endr=4,startc=0,endc=9,enl,startl=1,i=0;

 //function to build tiles
 void init()
 {for(r=0;r<=4;r++)
  for(c=0;c<=9;c++)
   for(l=0;l<=3;l++)
    playgrid[r][c].a[l]=0;


 for(r=startr;r<=endr;r++)
  for(c=endc;c>=startc;c--)
   {enl=random(4);
    for(l=startl;l<=enl;l++)
     {blank_tile(r,c,l);
      p=1+random(7);
      eturn(p,r,c,l);
      playgrid[r][c].a[l]=p;
      if(l==enl)
      a[r][c]=enl;
    }
 count+=enl;
 }

}
 void main()
{int i,j,p,gdriver=DETECT,gmode;
 initgraph(&gdriver,&gmode," ");
 randomize();
 int d,t,k,s;
  setcolor(8);
  rectangle(0,0,639,479);
  setfillstyle(1,7);
  floodfill(10,10,8);
  d=40;t=0;
  s=d;
 settextstyle(4,0,7);
  for(k=1;k<=3;k++)
  {d=s;
   for(i=t;i<=77;i+=3)
   {if(i%2==0)
    d--;
    setcolor(0);
    outtextxy(170,i,"M");
    delay(d);
    setcolor(7);
    outtextxy(170,i,"M");
   }
  t+=30;
  s-=15;
  for(i=77;i>=t;i-=2)
  { if(i%2==0)
    d++;
    setcolor(0);
    outtextxy(170,i,"M");
    delay(d);
    setcolor(7);
    outtextxy(170,i,"M");
   }
  }
  setcolor(0);
  outtextxy(170,77,"M");



  d=40;t=0;
  s=d;
 settextstyle(4,0,7);
  for(k=1;k<=3;k++)
  {d=s;
   for(i=t;i<=77;i+=3)
   {if(i%2==0)
    d--;
    setcolor(0);
    outtextxy(220,i,"a");
    delay(d);
    setcolor(7);
    outtextxy(220,i,"a");
   }
  t+=30;
  s-=15;
  for(i=77;i>=t;i-=2)
  { if(i%2==0)
    d++;
    setcolor(0);
    outtextxy(220,i,"a");
    delay(d);
    setcolor(7);
    outtextxy(220,i,"a");
   }
  }
  setcolor(0);
  outtextxy(220,i,"a");




  d=40;t=0;
  s=d;
 settextstyle(4,0,7);
  for(k=1;k<=3;k++)
  {d=s;
   for(i=t;i<=77;i+=3)
   {if(i%2==0)
    d--;
    setcolor(0);
    outtextxy(250,i,"h");
    delay(d);
    setcolor(7);
    outtextxy(250,i,"h");
   }
  t+=30;
  s-=15;
  for(i=77;i>=t;i-=2)
  { if(i%2==0)
    d++;
    setcolor(0);
    outtextxy(250,i,"h");
    delay(d);
    setcolor(7);
    outtextxy(250,i,"h");
   }
  }
  setcolor(0);
  outtextxy(250,i,"h");



  d=40;t=0;
  s=d;
 settextstyle(4,0,7);
  for(k=1;k<=3;k++)
  {d=s;
   for(i=t;i<=77;i+=3)
   {if(i%2==0)
    d--;
    setcolor(0);
    outtextxy(285,i,"j");
    delay(d);
    setcolor(7);
    outtextxy(285,i,"j");
   }
  t+=30;
  s-=15;
  for(i=77;i>=t;i-=2)
  { if(i%2==0)
    d++;
    setcolor(0);
    outtextxy(285,i,"j");
    delay(d);
    setcolor(7);
    outtextxy(285,i,"j");
   }
  }
  setcolor(0);
  outtextxy(285,i,"j");



  d=40;t=0;
  s=d;
 settextstyle(4,0,7);
  for(k=1;k<=3;k++)
  {d=s;
   for(i=t;i<=77;i+=3)
   {if(i%2==0)
    d--;
    setcolor(0);
    outtextxy(300,i,"o");
    delay(d);
    setcolor(7);
    outtextxy(300,i,"o");
   }
  t+=30;
  s-=15;
  for(i=77;i>=t;i-=2)
  { if(i%2==0)
    d++;
    setcolor(0);
    outtextxy(300,i,"o");
    delay(d);
    setcolor(7);
    outtextxy(300,i,"o");
   }
  }
  setcolor(0);
  outtextxy(300,i,"o");




  d=40;t=0;
  s=d;
 settextstyle(4,0,7);
  for(k=1;k<=3;k++)
  {d=s;
   for(i=t;i<=77;i+=3)
   {if(i%2==0)
    d--;
    setcolor(0);
    outtextxy(340,i,"n");
    delay(d);
    setcolor(7);
    outtextxy(340,i,"n");
   }
  t+=30;
  s-=15;
  for(i=77;i>=t;i-=2)
  { if(i%2==0)
    d++;
    setcolor(0);
    outtextxy(340,i,"n");
    delay(d);
    setcolor(7);
    outtextxy(340,i,"n");
   }
  }
  setcolor(0);
  outtextxy(340,i,"n");



  d=40;t=0;
  s=d;
 settextstyle(4,0,7);
  for(k=1;k<=3;k++)
  {d=s;
   for(i=t;i<=77;i+=3)
   {if(i%2==0)
    d--;
    setcolor(0);
    outtextxy(370,i,"g");
    delay(d);
    setcolor(7);
    outtextxy(370,i,"g");
   }
  t+=30;
  s-=15;
  for(i=77;i>=t;i-=2)
  { if(i%2==0)
    d++;
    setcolor(0);
    outtextxy(370,i,"g");
    delay(d);
    setcolor(7);
    outtextxy(370,i,"g");
   }
  }
  setcolor(0);
  outtextxy(370,i,"g");



  d=40;t=0;
  s=d;
 settextstyle(4,0,7);
  for(k=1;k<=3;k++)
  {d=s;
   for(i=t;i<=77;i+=3)
   {if(i%2==0)
    d--;
    setcolor(0);
    outtextxy(400,i,"g");
    delay(d);
    setcolor(7);
    outtextxy(400,i,"g");
   }
  t+=30;
  s-=15;
  for(i=77;i>=t;i-=2)
  { if(i%2==0)
    d++;
    setcolor(0);
    outtextxy(400,i,"g");
    delay(d);
    setcolor(7);
    outtextxy(400,i,"g");
   }
  }
  setcolor(0);
  outtextxy(400,i,"g");
  e=425;
  setcolor(0);
  for(i=425;i>=175;i--)
  {if(i<=325)
   {setcolor(7);
    e=325;
   }
   line(e,160,i,160);
   setcolor(0);
   line(425,165,i,165);
   delay(2);
  }

  setcolor(15);
  settextstyle(3,0,6);
  outtextxy(100,170,"Play");
  outtextxy(100,230,"Instructions");
  outtextxy(100,285,"Quit");
  setcolor(4);
  outtextxy(100,170,"P");
  outtextxy(100,230,"I");
  outtextxy(100,285,"Q");
  setcolor(12);
  settextstyle(3,0,2);
  outtextxy(400,400,"Press any key..........");

  char ca=' ';
 while(ca!='q')
 {ca=getch();
  switch(ca)
  {case'p':setcolor(1);
 rectangle(0,0,639,479);
 setfillstyle(1,2);
 floodfill(100,100,1);

 init();
  gotoxy(75,1);
  cout<<count;
  char ch='a',br='a';
  int ptrr,ptrc,ptrl,t1=0,t2=0,r1,r2,c1,c2,l1,l2,chk;
  ptrr=3;ptrc=5;ptrl=a[3][5];
  while((ch!='b')&&(count!=0))
 {ch=getch();
  selector(ptrr,ptrc,ptrl);
  switch(ch)
  {case'a':if(ptrc>0)
	     {if(ptrl==0)
	      remove2(ptrr,ptrc,ptrl);
	      else
	      remove(ptrr,ptrc,ptrl);
	      ptrl=a[ptrr][ptrc-1];
	      ptrc--;
	      selector(ptrr,ptrc,ptrl);
	     }
	   break;
   case'd':if(ptrc<9)
	    {if(ptrl==0)
	     remove2(ptrr,ptrc,ptrl);
	     else
	     remove(ptrr,ptrc,ptrl);
	      ptrl=a[ptrr][ptrc+1];
	       ptrc++;
	       selector(ptrr,ptrc,ptrl);
	      }
	   break;
   case'w':if(ptrr>0)
	    {if(ptrl==0)
	     remove2(ptrr,ptrc,ptrl);
	     else
	     remove(ptrr,ptrc,ptrl);
	      ptrl=a[ptrr-1][ptrc];
	      ptrr--;
	      selector(ptrr,ptrc,ptrl);
	     }
	   break;
   case's':if(ptrr<4)
	    {if(ptrl==0)
	     remove2(ptrr,ptrc,ptrl);
	     else
	     remove(ptrr,ptrc,ptrl);
	     ptrl=a[ptrr+1][ptrc];
	      ptrr++;
	      selector(ptrr,ptrc,ptrl);
	     }
	   break;
   case 'p':if(t1==0)
	     {t1=fix(ptrr,ptrc,ptrl);
	      r1=ptrr;c1=ptrc;l1=ptrl;
	      break;
	     }
	    if(t1!=0)
	     {t2=fix(ptrr,ptrc,ptrl);
	      r2=ptrr;c2=ptrc;l2=ptrl;
	      if((r1==r2)&&(c1==c2)&&(l1==l2))
	      {remove1(r1,c1,l1);
	       t2=0;
	       t1=0;
	      }
	     }

	    if(t2!=0)
	     {if(t1==t2)
	       {playgrid[r1][c1].a[a[r1][c1]]=0;
		playgrid[r2][c2].a[a[r2][c2]]=0;
		a[r1][c1]--;
		a[r2][c2]--;
		chk=check();
		count-=2;
	       if((chk==2)&&(count!=0))
	       {clrscr();
		setcolor(1);
	       rectangle(0,0,639,479);
	       setfillstyle(1,2);
	       floodfill(100,100,1);
	       for(r=0;r<=4;r++)
	       for(c=9;c>=0;c--)
	       for(l=1;l<=a[r][c];l++)
	       {blank_tile(r,c,l);
		eturn(playgrid[r][c].a[l],r,c,l);
	       }
		gotoxy(75,1);
		cout<<count;
		ptrr=3;
		ptrc=5;
		ptrl=a[3][5];
	      }
	      if((chk==0)||(count==0))
	      {clrscr();
		setcolor(1);
	       rectangle(0,0,639,479);
	       setfillstyle(1,2);
	       floodfill(100,100,1);
	       for(i=1;i<=8;i++)
	       {settextstyle(1,0,i);
	       setcolor(4);
	       outtextxy(200-(i*10),200,"YOU WON!!!!");
	       delay(50);
	       setcolor(2);
	       outtextxy(200-(i*10),200,"YOU WON!!!!");
	       }
	       settextstyle(1,0,8);
	       setcolor(4);
	       outtextxy(200-(i*10),200,"YOU WON!!!!");
	       getch();
	       clrscr();
		setcolor(1);
	       rectangle(0,0,639,479);
	       setfillstyle(1,2);
	       floodfill(100,100,1);
	       setfillstyle(1,7);
	       floodfill(100,450,1);
	     settextstyle(4,0,7);
	     setcolor(0);
	     outtextxy(170,77,"Mahjongg");
	     line(325,160,425,160);
	     line(425,165,175,165);
	     setcolor(15);
	     settextstyle(3,0,6);
	     outtextxy(100,170,"Play");
	     outtextxy(100,230,"Instructions");
	     outtextxy(100,285,"Quit");
	     setcolor(4);
	     outtextxy(100,170,"P");
	     outtextxy(100,230,"I");
	     outtextxy(100,285,"Q");
	     setcolor(12);
	     settextstyle(3,0,2);
	     outtextxy(400,400,"Press any key..........");
	      ch='b';
	       }
		}

	       else
		{remove1(r1,c1,l1);
		 remove1(r2,c2,l2);
		 }
		t1=0;
		t2=0;

	     }
	   break;
   case'b':clrscr();
		setcolor(1);
	       rectangle(0,0,639,479);
	       setfillstyle(1,2);
	       floodfill(100,100,1);
	       setfillstyle(1,7);
	       floodfill(100,450,1);
	     settextstyle(4,0,7);
	     setcolor(0);
	     outtextxy(170,77,"Mahjongg");
	     line(325,160,425,160);
	     line(425,165,175,165);
	     setcolor(15);
	     settextstyle(3,0,6);
	     outtextxy(100,170,"Play");
	     outtextxy(100,230,"Instructions");
	     outtextxy(100,285,"Quit");
	     setcolor(4);
	     outtextxy(100,170,"P");
	     outtextxy(100,230,"I");
	     outtextxy(100,285,"Q");
	     setcolor(12);
	     settextstyle(3,0,2);
	     outtextxy(400,400,"Press any key..........");
	    break;
   }
   }
   break;
   case'i':clrscr();
	   setcolor(7);
	   settextstyle(3,0,2);
	   outtextxy(400,400,"Press any key..........");
	   outtextxy(400,400,"Wrong Input....try again");
	   setcolor(1);
	   settextstyle(7,0,2);
	   outtextxy(25,50,"Mahjong is very similar to Rummy and is played with");
	   outtextxy(10,100,"tiles . The main objective is to build sets with the tiles");
	   outtextxy(10,150,"through drawing and discarding them . There are total");
	   outtextxy(10,200,"7 patterns of tiles arranged randomly . The person who");
	   outtextxy(10,250,"ends up the game in less tiles remaining WINS the GAME. ");
	   outtextxy(10,270,"                  GOOD LUCK...... ");

	   settextstyle(1,0,3);
	   setcolor(0);
	   outtextxy(50,300,"'a'/'d'--> move pointer to left and right tile");
	   outtextxy(50,350,"'w'/'s'--> move pointer to upper and lower tile");
	   outtextxy(100,400,"'p'--> select the tile");
	   setcolor(15);
	   outtextxy(400,450,"<--Back");
	   setcolor(4);
	   outtextxy(400,450,"<--B");
	   while(br!='b')
	   { br=getch();
	    if(br=='b')
	    {clrscr();
	     setcolor(7);
	     outtextxy(400,450,"<--Back");
	     settextstyle(1,0,3);
	     outtextxy(100,400,"'p'--> select the tile");
	     settextstyle(4,0,7);
	     setcolor(0);
	     outtextxy(170,77,"Mahjongg");
	     line(325,160,425,160);
	     line(425,165,175,165);
	     setcolor(15);
	     settextstyle(3,0,6);
	     outtextxy(100,170,"Play");
	     outtextxy(100,230,"Instructions");
	     outtextxy(100,285,"Quit");
	     setcolor(4);
	     outtextxy(100,170,"P");
	     outtextxy(100,230,"I");
	     outtextxy(100,285,"Q");
	     setcolor(12);
	     settextstyle(3,0,2);
	     outtextxy(400,400,"Press any key..........");
	   }
	   }
	    br='a';
	   break;

  case 'q':exit(0);
	   break;
  default:setcolor(7);
	  settextstyle(3,0,2);
	  outtextxy(400,400,"Press any key..........");
	  setcolor(12);
	  outtextxy(400,400,"Wrong Input....try again");
	  }
   }
 getch();
}
