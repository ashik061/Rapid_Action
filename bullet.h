/*............................................BULLET INITIALIZATION......................*/
struct bullet_prop{
    int x;
    int y;
    int bulletmode;
};

struct 	bullet_prop bullets[100];

int bullet_count_a=0 ;


/*.............................................FOR BULLET THROW.......................*/

void bulletchange()
{
    int i;

    for(i = 0 ; i < bullet_count_a; i++){
        if(bullets[i].bulletmode == 1){
            bullets[i].x -= 10;
        }
        if(bullets[i].bulletmode == 2){
            bullets[i].x += 10;
        }
    }


}
