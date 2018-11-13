# include "iGraphics.h"
#include<windows.h>



struct bullet_prop{
    int x;
    int y;
    int bulletmode;
};








struct 	bullet_prop bullets[100];
int x=20,x2=350,x3=680,y=50,y2=200,y3=350;
int i=1,j=0;
int r=0,g=0,b=0;
int mode, gamemode, kuramamode1=1, kuramamode2=1, bossmode;
int level=1,bar_length=300;

int sc=0,temp_sc, num_position, position;
int boom=0,boom_position_l,boom_position_r;///image when bullets touch kurama
int musicmode=1;
int homemode=0;

int level_count=0;
int music_count=0;
int in_count=0;
int hs_count=0;
int ex_count=0;
int exit_mode=0;
int highscore_mode=0;


int life=8;

	char narutorunR[6][30]={"image//right//naruto_run1.bmp","image//right//naruto_run2.bmp","image//right//naruto_run3.bmp","image//right//naruto_run4.bmp","image//right//naruto_run5.bmp","image//right//naruto_run6.bmp"};
	char narutorunL[6][30]={"image//left//naruto_run1.bmp","image//left//naruto_run2.bmp","image//left//naruto_run3.bmp","image//left//naruto_run4.bmp","image//left//naruto_run5.bmp","image//left//naruto_run6.bmp"};

	char narutoduck[2][40]={"image//boss//naruto//duck//4.bmp","image//boss//naruto//duck//3.bmp"};


    char lifepic[9][30] = {"image//life//life0.bmp","image//life//life1.bmp","image//life//life2.bmp","image//life//life3.bmp","image//life//life4.bmp","image//life//life5.bmp","image//life//life6.bmp","image//life//life7.bmp","image//life//life8.bmp"};
    char levelpic[10][30]={"image//0.bmp","image//1.bmp","image//2.bmp","image//3.bmp","image//4.bmp","image//5.bmp","image//6.bmp","image//7.bmp","image//8.bmp","image//9.bmp"};
    char scorepic[10][30]={"image//0.bmp","image//1.bmp","image//2.bmp","image//3.bmp","image//4.bmp","image//5.bmp","image//6.bmp","image//7.bmp","image//8.bmp","image//9.bmp"};

    char bullet_naruto_l[3][30]={"image//shuri//left//1.bmp","image//shuri//left//2.bmp","image//shuri//left//3.bmp"};
    char bullet_naruto_r[3][30]={"image//shuri//right//1.bmp","image//shuri//right//2.bmp","image//shuri//right//3.bmp"};


    int narutocordinatex=380, narutocordinatey=210,narutoindex=0,narutomood=0;

int barspeed=1, ballspeed, sidespeed;
int bulletcounta=0 ;

int sideballlx=0,sideballly=50,sideballrx=1000,sideballry=50;

int in_mode=0,in_1mode=0;








void iDraw() {
	iClear();

    if(gamemode == 1)
    {


       iShowBMP(0,550,lifepic[life]);
       iShowBMP(560,550,"image//sc.bmp");
       iShowBMP(330,550,"image//lv.bmp");
       iShowBMP(480,550,levelpic[level]);



    temp_sc = sc;
    position = 0;
    while(temp_sc != 0)
    {
        num_position = position*50;
        iShowBMP(950-num_position,550,scorepic[(temp_sc%10)]);
        position++;
        temp_sc = temp_sc/10;
    }






        iSetColor(255,0,0);
        iFilledRectangle(x, y, bar_length, 10);
        iFilledRectangle(x2, y2, bar_length, 10);
        iFilledRectangle(x3, y3, bar_length, 10);

        iShowBMP(0,500,"image//khach2.bmp");
        iShowBMP(0,0,"image//khach3.bmp");



        if(narutomood==1) 	iShowBMP(narutocordinatex,narutocordinatey,narutorunR[i]);
        if(narutomood==2) 	iShowBMP(narutocordinatex,narutocordinatey,narutorunL[i]);




        iSetColor(200,100,0);

        for(j=0;j<bulletcounta;j++) {
           if(bullets[j].bulletmode == 1)
            {
                iShowBMP(bullets[j].x,bullets[j].y,"image//bl.bmp");

            }

           if(bullets[j].bulletmode == 2)
                iShowBMP(bullets[j].x,bullets[j].y,"image//br.bmp");

           }





    if(kuramamode1 == 1)
    {
        iShowBMP(0,sideballly,"image//kurama.bmp");

    }
    if(kuramamode2==1){
        iShowBMP(1000-40,sideballry,"image//kurama.bmp");
    }


    if(boom == 1)
    {
        iShowBMP(5,boom_position_l,"image//boom.bmp");
        boom=0;
    }
    if(boom == 2)
    {
        iShowBMP(955,boom_position_r,"image//boom.bmp");
        boom=0;
    }
    if(kuramamode1==0) {
            sideballly=-100;
            kuramamode1=1;
    }

    if(kuramamode2==0) {
        sideballry=-100;
        kuramamode2=1;
    }

    }



     else
     {


         if(mode == 2) {

                char your_score[100] = {0};

                itoa(sc, your_score,10);


                iShowBMP(0,0,"image//gameover.bmp");
         iText(450,50,"your score",GLUT_BITMAP_TIMES_ROMAN_24);
         iText(500,25,your_score,GLUT_BITMAP_TIMES_ROMAN_24);
         }

         else{
         iShowBMP(0,0,"image//home1.bmp");

        iShowBMP(0,550, "image//play_game.bmp");
        iShowBMP(190, 550, "image//instructions1.bmp");
        iShowBMP(600,550,"image//highscore.bmp");
        iShowBMP(830,550,"image//exit_1.bmp");


        if(musicmode == 1) iShowBMP(400,550,"image//sound_on.bmp");
        else iShowBMP(400,550,"image//sound_off.bmp");

         if(in_mode == 1) {
            iShowBMP(0,0,"image//in_1.bmp");
            iShowBMP(500,0,"image//in_naruto.bmp");
         }
        else if(in_mode == 2) {
            iShowBMP(500,0,"image//in_2.bmp");
            iShowBMP(0,0,"image//in_naruto.bmp");
         }

        else if(exit_mode == 1)
         {iShowBMP(0,0,"image//quit_pic.bmp");
          iShowBMP(0,0,"image//quit.bmp");

         }

         else if(highscore_mode == 1)
         {
             iSetColor(0,0,0);
             iFilledRectangle(400, 200, 200, 200 );
             iSetColor(255,0,0);
             iText(430, 370, "1 : ", GLUT_BITMAP_TIMES_ROMAN_24);
             iText(430, 290, "2 : ", GLUT_BITMAP_TIMES_ROMAN_24);
             iText(430, 210, "3 :", GLUT_BITMAP_TIMES_ROMAN_24);



             int pl[3];
             char scores[3][100];
             int l;
             FILE *f;
             f=fopen("top3.txt","r");
             for(l=0;l<3;l++){
                fscanf(f,"%d.%s",&pl[l],scores[l]);
             }

             fclose(f);

             iText(460, 370, scores[0] , GLUT_BITMAP_TIMES_ROMAN_24);
             iText(460, 290, scores[1] , GLUT_BITMAP_TIMES_ROMAN_24);
             iText(460, 210, scores[2] , GLUT_BITMAP_TIMES_ROMAN_24);
         }

         else
         {
             iShowBMP(0,0,"image//home1.bmp");
         }






         }



}

}




/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my) {

}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

            if(exit_mode!=1 && mx>=0 && mx<=175 && my>=550 && my<=600)
            {
                gamemode = 1;
                //highscore_mode = 0;
                musicmode=0;
            }
            if(exit_mode!=1 && mx>=190 && mx<=190+175 && my>=550 && my<=600)
            {
                in_mode = 1;
                in_count++;
                highscore_mode = 0;

            }
            if(exit_mode!=1 && mx>=190 && mx<=190+175 && my>=550 && my<=600 && in_count==2)
            {
                in_mode = 0;
                in_count=0;

            }

     if(exit_mode!=1 && mx>=400 && mx<=400+175 && my>=550 && my<=600 && music_count==0)
     {
         if(musicmode == 0)
            musicmode =1;
         else
            musicmode=0;

              if(musicmode == 0) PlaySound(0,0,0);

            else
            {
                musicmode=1;
                PlaySound("music\\home.wav", NULL , SND_LOOP | SND_ASYNC);
            }

         }




            if( mx>=830 && mx<=830+175 && my>=550 && my<=600)
            {
                exit_mode=1;
                in_mode = 0;
                in_1mode = 0;

            }

            if(exit_mode==1 && mx>=10 && mx<=200 && my>=10 && my<=90)
            {
                exit(0);
            }
            if(exit_mode==1 && mx>=200 && mx<=400 && my>=10 && my<=90)
            {
               exit_mode=0;
            }

            if(mx>= 600 && mx<= 600+175 && my>= 550 && my<= 600 )
            {
                if(highscore_mode == 1)
                    highscore_mode = 0;
                else
                    highscore_mode =1;
                in_mode = 0;
                in_1mode = 0;
            }


	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {

	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key) {

	//place your codes for other keys here
	if(key == 'p' || key == 'P')
    {
        mode = 0;
        musicmode=0;

    }
    if(key == '\r')
{
    mode = 1;
    in_mode = 2;
}
      if(key == 'a' || key == 'A')
        {
        bullets[bulletcounta].bulletmode = 1;
        bullets[bulletcounta].x=narutocordinatex;
        bullets[bulletcounta].y=narutocordinatey+20;
        bulletcounta++;
        if(bulletcounta==99) bulletcounta=0;
    }
     if(key == 's' || key == 'S'){
        bullets[bulletcounta].bulletmode = 2;
        bullets[bulletcounta].x=narutocordinatex+50;
        bullets[bulletcounta].y=narutocordinatey+20;
        bulletcounta++;
        if(bulletcounta==99) bulletcounta=0;

     }
     if(key == 'q' || key == 'Q')
     {
         if(musicmode == 0)
            musicmode =1;
         else
            musicmode=0;
     }
              if(musicmode == 0) PlaySound(0,0,0);

            else
            {
                musicmode=1;
                PlaySound("music\\home.wav", NULL , SND_LOOP | SND_ASYNC);
            }


}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key) {

    if(mode == 1 || bossmode==1)
    {
        if(key == GLUT_KEY_RIGHT && narutocordinatex<900)
        {
            narutomood=1;
            i++;
            narutocordinatex += sidespeed;
         if(i==6)
            i=0;


        }
        if(key == GLUT_KEY_LEFT && narutocordinatex > 0)
            //ballx += 10;
            {
              narutomood=2;
              i++;
              narutocordinatex -= sidespeed;
              if(i==6)
                i=0;

            }

        if(key == GLUT_KEY_DOWN)
        {
            r++;
            if(r==2)
                r = 0;
        }
    }

    if(key == GLUT_KEY_F1)
        {
            mode=0;
            gamemode=0;
            homemode=1;

        }


	if (key == GLUT_KEY_END) {
		exit(0);
	}
}






void barchange()
{
    if(mode==1 && gamemode==1)
    {
        y += barspeed;
    if(y >= 500)
        y = 0;
    y2 += barspeed;
    if(y2 >= 500)
        y2 = 0;
    y3 += barspeed;
    if(y3 >= 500)
        y3 = 0;

     narutocordinatey -= ballspeed;
    if((abs(narutocordinatey - y)<12 && narutocordinatex+80>=x && narutocordinatex<=x+bar_length) ||
        (abs(narutocordinatey - y2)<12 && narutocordinatex+80>=x2 && narutocordinatex<=x2+bar_length) ||
        abs(narutocordinatey - y3)<12 && narutocordinatex+80>=x3 && narutocordinatex<=x3+bar_length)
        ballspeed = -barspeed;
    else
        ballspeed = 1;

            if(narutocordinatey==50 || narutocordinatey+30>=500) {
                mode=0;
                life--;
                if(life == 0) {
                    gamemode=0;
                    mode = 2;
                    int score=sc;
         FILE *fp;


fp=fopen("top3.txt","r");
int place[3],topscore[3];
int i,j;
for(i=0;i<3;i++){
fscanf(fp,"%d.%d",&place[i],&topscore[i]);
}
i=0;
for(i=0;i<3;i++){
    printf("%d  %d\n",place[i],topscore[i]);
}
for(i=0;i<3;i++){
if(score>topscore[i]){
for(j=2;j>i;j--){
topscore[j]=topscore[j-1];


}
topscore[i]=score;
break;
}
}
fclose(fp);
fp=fopen("top3.txt","w");
i=0;
for(i=0;i<3;i++){
fprintf(fp,"%d.%d\n",place[i],topscore[i]);
}
fclose(fp);



                }
                narutocordinatex=500;
                narutocordinatey=400;
            }
    }

}






void bar_random()
{
    if(mode == 1)
    {

        if(y < 50) x=rand()%600;
        if(y2 < 50) x2=rand()%600;
        if(y3 < 50) x3=rand()%600;
    }
}



void bulletchange()
{
    int i;

    for(i = 0 ; i < bulletcounta; i++){
        if(bullets[i].bulletmode == 1){
            bullets[i].x -= 10;
        }
        if(bullets[i].bulletmode == 2){
            bullets[i].x += 10;
        }
    }


}







void sideball()
{
    if(mode == 1 && gamemode == 1)
    {
        sideballly += 5;
        sideballry += 5;

        if(sideballly > 500)
        {
            sideballly = rand()%100 - 100;
        }
        if(sideballry > 500)
        {
            sideballry = rand()%200 - 200;
        }

       // if( bullets[bulletcounta].bulletmode == 1 && bullets[bulletcounta].x<40 && bullets[bulletcounta].y >= sideballly && bullets[bulletcounta].y <= sideballly+40 )
           // sc = 0;
           int h;
           for(h=0;h<100;h++){
            if( bullets[h].bulletmode == 1 && bullets[h].x<40 && bullets[h].x>0 && bullets[h].y >= sideballly && bullets[h].y <= sideballly+40){
                    kuramamode1=0;
                    boom_position_l=sideballly;
                    boom=1;
                    sc+=10;
                    }
           }
           h=0;
           for(h=0;h<100;h++){
            if( bullets[h].bulletmode == 2 && bullets[h].x>960 && bullets[h].x<1000 && bullets[h].y >= sideballry && bullets[h].y <= sideballry+40){
                kuramamode2=0;
                boom_position_r=sideballry;
                boom=2;
                sc+=10;
            }




           }

    }
}


void scoring()
{
     if(mode == 1 && gamemode == 1)
     {
         int n,len=0,i;
    if(!((abs(narutocordinatey - y)<12 && narutocordinatex+80>=x && narutocordinatex<=x+bar_length) ||
        (abs(narutocordinatey - y2)<12 && narutocordinatex+80>=x2 && narutocordinatex<=x2+bar_length) ||
        abs(narutocordinatey - y3)<12 && narutocordinatex+80>=x3 && narutocordinatex<=x3+bar_length))
        {
                sc++;
        }

        level_count++;
        if(level_count==100)
        {
            level++;
            level_count=0;
            mode = 0;
        }


        if(level==2)
        {
            barspeed = 2;
            bar_length = 250;
            sidespeed = 15;
            //level_mode = 1;

        }

        if(level==3)
        {
            barspeed = 3;
            bar_length = 200;
            sidespeed = 20;
            //level_mode = 1;

        }

        if(level==4)
        {
            barspeed = 4;
            bar_length = 200;
            sidespeed = 25;
            //level_mode = 1
        }

        if(level == 5)
        {
            level_count = 0;
        }

     }



}








int main() {

    mode = 0;
    gamemode = 0;
    narutomood = 1;
    ballspeed = 1;
    sidespeed = 10;
    bossmode = 0;
    //level_mode = 0;


    iSetTimer(1, barchange);
    iSetTimer(1000,bar_random);
    iSetTimer(1,bulletchange);
    iSetTimer(40,sideball);
    iSetTimer(300, scoring);
   // iSetTimer(20000,levelcount);
    if(gamemode==0) PlaySound("music\\home.wav", NULL , SND_LOOP | SND_ASYNC);


    iInitialize(1000, 600 , "Rapid Action");


	return 0;
}
