#define HOME 0
#define PLAY 1
#define SHOW 5

/*..................................variable declaration..............................*/

int bar_x1=20,bar_x2=350,bar_x3=680,bar_y1=50,bar_y2=200,bar_y3=350;
int bar_length=300;
int bar_speed=1;
int mode;
int life=8;
int naruto_cordinate_x=380, naruto_cordinate_y=210,naruto_mood=0;
int naruto_speed;
int gameMode;
int sc=0;




/*..........................................FOR BAR CHANGING................................*/


void barchange()
{
    if(mode==PLAY && gameMode==PLAY)
    {
        bar_y1 += bar_speed;
    if(bar_y1 >= 500)
        bar_y1 = 0;
    bar_y2 += bar_speed;
    if(bar_y2 >= 500)
        bar_y2 = 0;
    bar_y3 +=bar_speed;
    if(bar_y3 >= 500)
        bar_y3 = 0;


//.....................................................SETTING NARUTO ON BAR...


     naruto_cordinate_y -= naruto_speed;
    if((abs(naruto_cordinate_y - bar_y1)<12 && naruto_cordinate_x+80>=bar_x1 && naruto_cordinate_x<=bar_x1+bar_length) ||
        (abs(naruto_cordinate_y - bar_y2)<12 && naruto_cordinate_x+80>=bar_x2 && naruto_cordinate_x<=bar_x2+bar_length) ||
        abs(naruto_cordinate_y - bar_y3)<12 && naruto_cordinate_x+80>=bar_x3 && naruto_cordinate_x<=bar_x3+bar_length)
        naruto_speed = -bar_speed;
    else
        naruto_speed = 1;



//.............................................LIFE CHANGING....


            if(naruto_cordinate_y==50 || naruto_cordinate_y+30>=500) {
                mode=HOME;
                life--;
                if(life == 0) {
                gameMode=HOME;
                mode = SHOW;
                int score=sc;

                FILE *fp;


                fp=fopen("top3.txt","r");
                int place[3],topscore[3];
                int i,j;
                for(i=0; i<3; i++)
                {
                    fscanf(fp,"%d.%d",&place[i],&topscore[i]);
                }
                i=0;
                for(i=0; i<3; i++)
                {
                    printf("%d  %d\n",place[i],topscore[i]);
                }
                for(i=0; i<3; i++)
                {
                    if(score>topscore[i])
                    {
                        for(j=2; j>i; j--)
                        {
                            topscore[j]=topscore[j-1];


                        }
                        topscore[i]=score;
                        break;
                    }
                }
                fclose(fp);
                fp=fopen("top3.txt","w");
                i=0;
                for(i=0; i<3; i++)
                {
                    fprintf(fp,"%d.%d\n",place[i],topscore[i]);
                }
                fclose(fp);



                }
                naruto_cordinate_x=500;
                naruto_cordinate_y=400;
            }
    }

}






void bar_random()
{
    if(mode == 1)
    {

        if(bar_y1 < 50) bar_x1=rand()%600;
        if(bar_y2 < 50) bar_x2=rand()%600;
        if(bar_y3 < 50) bar_x3=rand()%600;
    }
}
