#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdio.h>

void start();
void fncalling(); //main function that calls all the other functions
void rcksmoke(int ydecr); //function for main rocket smoke
void thrustsmoke(int count); //function for rocket thrusters smoke
void rocket(); //main function of rocket
void earth(); //function for earth
void rocketup(int j); //function that control the up movenment of rocket
void building(); //main function of building
void buildown(); //function control the decrement of building
void thrdispatch(int ct); //rocket thruster dispatch
void mainrckdis(); //main rocket body dispatch
void justrocket(); //function is for make rocket fix without thrusters
void lander(); //main function of lander
void landersmoke(int ydec); //function of lander smoke
void planet(); //main function of other planet
void landerdown(); //function control the lander landing
void end(); //Program is end now

void main()
{
 int i;
 int gd = DETECT , gm;
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 start();
 fncalling();
 end();
 getch();
}

void fncalling()
{
 int bt=0; //building counter
 while(!kbhit())
 {

 bt++;
 if(bt<150)
 {
 building();
 rocketup(bt);
 }
 else
 {
  if(bt==150)
  {
    rocket();
    buildown(bt);

  }
  else
  {
    if(bt==151)
    {
      earth();
    }
    if(bt==152)
    {
      thrdispatch(bt);
      mainrckdis();
      }
    }
  }
  delay(50);
  cleardevice();
 }
}
void end()
{
settextstyle(1,0,5);
outtextxy(80,200,"Mission Complete\n");
delay(500);
getch();
}
void start()
{
 char str[]={"Welcome to the launch of space shuttle by Smile.             Launch starts in\n"};
 int i=0,j=0;
 while(str[i]!=NULL)
 {
   printf("%c",str[i]);
   i++;
   delay(100);
 }

 for(j=10; j>=0; j--)
 {

  printf("%d",j);
  delay(500);
  cleardevice();
 }
 cleardevice();
}

void rocketup(int j)
{
int i=j;
//rocket body
rectangle(340,320-i,360,460-i);
//rocket body right side
line(360,440-i,380,460-i);
line(380,460-i,360,460-i);
//rocket body left side
line(340,440-i,320,460-i);
line(320,460-i,340,460-i);
thrdispatch(i);
//attachment of support 1
rectangle(330,370-i,340,380-i);
//attachment of support 2
rectangle(360,370-i,370,380-i);
//rocket body top
line(340,320-i,350,300-i);
line(350,300-i,360,320-i);
//support 2 top
line(370,340-i,375,320-i);
line(375,320-i,380,340-i);
//support 1 top
line(320,340-i,325,320-i);
line(325,320-i,330,340-i);
thrustsmoke(i);
rcksmoke(i);
}

void rcksmoke(int ydecr)
{
 int i,j;
 for(i=0; i<20; i++)
 {
   circle(350,475-ydecr,i);
 }
 for(i=0; i<10; i++)
 {
   circle(325,420-ydecr,i);
   circle(375,420-ydecr,i);
 }
}

void thrustsmoke(int count)
{
 int j;

 if(count==1)
 {
 for(j=0; j<50; j++)
 {
 circle(325,460,j);
 circle(375,460,j);
 circle(350,460,j);
 delay(50);
}
}
}

void buildown()
{
int y;
for( y=0; y<280; y++)
{
rectangle(0,465+y,150,475+y);
rectangle(50,380+y,150,465+y);
rectangle(0,380+y,50,465+y);
rectangle(50,370+y,150,380+y);
rectangle(50,280+y,150,370+y);
rectangle(0,250+y,50,310+y);
line(35,310+y,50,335+y);
line(25,310+y,50,350+y);
rectangle(90,280+y,150,310+y);
line(110,280+y,110,270+y);
rectangle(90,420+y,150,465+y);
rectangle(0,260+y,50,280+y);
rectangle(10,390+y,40,455+y);
line(20,260+y,20,280+y);
line(30,260+y,30,280+y);
line(40,260+y,40,280+y);
line(10,260+y,10,280+y);
line(110,420+y,110,465+y);
line(130,420+y,130,465+y);
line(90,455+y,150,455+y);
line(90,440+y,150,440+y);
circle(30,210+y,5);
line(30,210+y,15,225+y);
line(15,225+y,15,250+y);
arc(30,210+y,130,310,20);
//solar plate
line(90,240+y,170,240+y);
line(170,240+y,155,270+y);
line(155,270+y,70,270+y);
line(70,270+y,90,240+y);
line(110,240+y,90,270+y);
line(150,240+y,135,270+y);
line(80,255+y,160,255+y);
//rocket side tower
rectangle(230,300+y,250,500+y);
rectangle(215,330+y,310,340+y);
rectangle(290,460+y,410,477+y);
line(230,300+y,250,350+y);
line(230,350+y,250,400+y);
line(230,400+y,250,450+y);
line(230,450+y,250,500+y);
line(250,350+y,310,350+y);
//setelite dish
arc(480,380+y,230,20,50);
arc(580,380+y,230,20,50);
circle(470,370+y,10);
circle(570,370+y,10);
line(470,370+y,510,423+y);
line(570,370+y,610,423+y);
line(510,423+y,510,460+y);
line(610,423+y,610,460+y);
rectangle(490,460+y,630,477+y);
rocket();
delay(50);
cleardevice();
}
}

void building()
{
rectangle(0,465,150,475);
rectangle(50,380,150,465);
rectangle(0,380,50,465);
rectangle(50,370,150,380);
rectangle(50,280,150,370);
rectangle(0,250,50,310);
line(35,310,50,335);
line(25,310,50,350);
rectangle(90,280,150,310);
line(90,295,150,295);
rectangle(90,420,150,465);
rectangle(0,260,50,280);
rectangle(10,390,40,455);
line(20,260,20,280);
line(30,260,30,280);
line(40,260,40,280);
line(10,260,10,280);
line(110,420,110,465);
line(130,420,130,465);
line(90,455,150,455);
line(90,440,150,440);
circle(30,210,5);
line(30,210,15,225);
line(15,225,15,250);
arc(30,210,130,310,20);
//solar plate
line(90,240,170,240);
line(170,240,155,270);
line(155,270,70,270);
line(70,270,90,240);
line(110,240,90,270);
line(150,240,135,270);
line(80,255,160,255);
line(110,270,110,280);
//rocket side tower
rectangle(230,300,250,500);
rectangle(215,330,310,340);
rectangle(290,460,410,477);
line(230,300,250,350);
line(230,350,250,400);
line(230,400,250,450);
line(230,450,250,500);
line(250,350,310,350);
//setelite dish
arc(480,380,230,20,50);
arc(580,380,230,20,50);
circle(470,370,10);
circle(570,370,10);
line(470,370,510,423);
line(570,370,610,423);
line(510,423,510,460);
line(610,423,610,460);
rectangle(490,460,630,477);

}
void rocket()
{

int i=150;
rectangle(340,320-i,360,460-i);
//rocket body right side
line(360,440-i,380,460-i);
line(380,460-i,360,460-i);
//rocket body left side
line(340,440-i,320,460-i);
line(320,460-i,340,460-i);

//attachment of support 1
rectangle(330,370-i,340,380-i);
//attachment of support 2
rectangle(360,370-i,370,380-i);
//rocket body top
line(340,320-i,350,300-i);
line(350,300-i,360,320-i);
thrdispatch(i);
rcksmoke(i);
}

void earth()
{
int i;
for(i=0; i<500; i++)
{
//setcolor(BLUE);
circle(315,750+i,800);
delay(40);
cleardevice();
rocket();
}
}

void thrdispatch(int ct)//counter
{
if(ct<151)
{
int i=ct;
//support 1 body
rectangle(320,340-i,330,420-i);
//support 1 left side
line(320,410-i,315,420-i);
line(315,420-i,320,420-i);
//support 1 right side
line(330,410-i,335,420-i);
line(335,420-i,330,420-i);
//support 2 body
rectangle(370,340-i,380,420-i);
//support 2 left side
line(370,410-i,365,420-i);
line(365,420-i,370,420-i);
//support 2 right side
line(380,410-i,385,420-i);
line(385,420-i,380,420-i);
//support 2 top
line(370,340-i,375,320-i);
line(375,320-i,380,340-i);
//support 1 top
line(320,340-i,325,320-i);
line(325,320-i,330,340-i);
}
else
{
int i;
for(i=0; i<260; i++)
{
//support 1 body
rectangle(320-i,190+i,330-i,270+i);
//support 1 left side
line(320-i,260+i,315-i,270+i);
line(315-i,270+i,320-i,270+i);
//support 1 right side
line(330-i,260+i,335-i,270+i);
line(335-i,270+i,330-i,270+i);
//support 2 body
rectangle(370+i,190+i,380+i,270+i);
//support 2 left side
line(370+i,260+i,365+i,270+i);
line(365+i,270+i,370+i,270+i);
//support 2 right side
line(380+i,260+i,385+i,270+i);
line(385+i,270+i,380+i,270+i);
//support 2 top
line(370+i,190+i,375+i,170+i);
line(375+i,170+i,380+i,190+i);
//support 1 top
line(320-i,190+i,325-i,170+i);
line(325-i,170+i,330-i,190+i);
delay(50);
cleardevice();
justrocket();
}
}
}

void mainrckdis()
{
int i;
for(i=0; i<=230; i++)
{
if(i<230)
{
rectangle(340,170+i,360,310+i);
//rocket body right side
line(360,290+i,380,310+i);
line(380,310+i,360,310+i);
//rocket body left side
line(340,290+i,320,310+i);
line(320,310+i,340,310+i);
//attachment of support 1
rectangle(330,220+i,340,230+i);
//attachment of support 2
rectangle(360,220+i,370,230+i);
//lander or rocket top
line(340,170,350,150);
line(350,150,360,170);
line(340,170,360,170);
}

else
{
lander();
}
delay(50);
cleardevice();
}
}

void justrocket()
{
int i=150;
rectangle(340,320-i,360,460-i);
//rocket body right side
line(360,440-i,380,460-i);
line(380,460-i,360,460-i);
//rocket body left side
line(340,440-i,320,460-i);
line(320,460-i,340,460-i);
rectangle(330,370-i,340,380-i);
//attachment of support 2
rectangle(360,370-i,370,380-i);
//rocket body top
line(340,320-i,350,300-i);
line(350,300-i,360,320-i);
}

void lander()
{

int i;

for(i=0; i<=210; i++)
{
if(i==210)
{
planet();
}

else
{
line(340,170-i,350,150-i);
line(350,150-i,360,170-i);
line(340,170-i,360,170-i);
landersmoke(i);
}

delay(50);
cleardevice();
}
}

void landersmoke(ydec)
{
int i;

 for(i=0; i<15; i++)
 {
 circle(350,190-ydec,i);
}

}

void planet()
{

int i;
for(i=0; i<420; i++)
{

//planet base
line(0,450,630,450);
line(0,440,70,410);
line(70,410,140,440);
line(140,440,190,420);
line(190,420,240,440);
line(240,440,320,440);
line(320,440,390,400);
line(390,400,460,440);
line(460,440,520,380);
line(520,380,550,400);
line(550,400,630,340);
line(0,450,0,440);
line(630,450,630,340);
landerdown(i);
delay(100);
cleardevice();
}
}

void landerdown(i)
{

line(270,0+i,280,-20+i);
line(280,-20+i,290,0+i);
line(270,0+i,290,0+i);
line(270,0+i,265,5+i);
line(290,0+i,295,5+i);

}