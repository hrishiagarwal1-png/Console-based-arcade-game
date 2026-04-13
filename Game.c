#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include<ctype.h>
#include<stdbool.h>

typedef int position;

typedef struct {
   double health,offence,defence;
   position x,y,z;
   

}charstats;

void battle(charstats* player,charstats* goblin);
void checkgoblin(int *isGA);

int main ()
 
 {   
    
     srand(time(NULL));//seed
     char move;
     int dist,num,i,N;
     bool  gAlive=1;
     N=(rand()%6)+1;  
     
    
    charstats player={200,50,30,0,0,0};//player stats
    charstats* goblin=(charstats*) calloc(N,sizeof(charstats));//golbin stats
    char controls []="W to walk forward\n"
                      "A to walk left\n"
                      "S to walk backward\n"
                      "D to walk right\n"
                      "C to show controls\n"
                      "P to show player cooridnates\n"
                      "G to show goblins coordinates\n";//controls
    
for(int i=0;i<N;i++){


goblin[i].health=(rand()%101)+100;
goblin[i].offence=(rand()%51);
goblin[i].defence=(rand()%51);
goblin[i].x=(rand()%101);
goblin[i].z=(rand()%101);
}//3 goblins   

for(int i=0;i<N;i++){
    printf("Goblin%d spotted at cooridinates %d,0,%d\n",i,goblin[i].x,goblin[i].z);
                    }//find goblin


printf("%s\n", controls);
//player movement
do { 
    do {
printf("Where to move? ");
scanf(" %c",&move);

move = toupper(move);


}while(move!='W'&& move!='A'&& move!='S'&& move!='D'&& move!='C' && move!='P' && move!='G');
 
    if(move=='C')
    {printf("%s\n", controls);}

    else if(move=='P')
    {printf("You are at %d %d %d\n",player.x,player.y,player.z);}
    else if(move=='G'){
   for(int i=0;i<N;i++){
    printf("Goblin%d spotted at cooridinates %d,0,%d\n",i,goblin[i].x,goblin[i].z);}}

else{printf("How many steps?");
scanf("%d",&dist);}


    

switch(move)
    {
    case 'W':
    player.z+=dist;
    break;

    case 'A':
    player.x-=dist;
    break;

    case 'S':
    player.z-=dist;
    break;
    case 'D':
    player.x+=dist;
    break;
   
    }
//check if player encounters a goblin
    gAlive=0; //will be reset to one i any goblin is alive
for(int i=0;i<N;i++)
    { 
    if(goblin[i].health>0)

        {gAlive=1;//goblin is still alive
        
        if(player.x==goblin[i].x&&player.z==goblin[i].z)
            {
        printf("Goblin appeared!!!");
       printf("Goblins stats are Health: %lf Offence: %lf Defence: %lf\n", goblin[i].health,goblin[i].offence,goblin[i].defence);
       battle(&player,&goblin[i]);

       if(goblin[i].health<=0)
{
    printf("Goblin is dead\n");
    gAlive=0;
}


            }
        }
     
    }
}while(gAlive && player.health>0);
 



    if(player.health<=0){
    printf("GAME OVER");
   }

else{
    printf("CONGRATULATIONS you won!!");}



return 0;
}
   
    
    

 


void battle(charstats* player,charstats* goblin)
{
 int isPA=0,isGA=0;//player and golbin actions
 
  do { 
    do{ printf("\nPress 1 to attack: ");
    scanf("%d", &isPA);
    
    
   
   }while(isPA!=1&&isPA!=0);//player action

   checkgoblin(&isGA);//goblin action
    
   //Batlle logic
 if(isPA==1)
    {  printf("\nPlayer ATTACKED!!!\n");
        double neteff = player->offence-goblin->defence;//check net eff of players attack
        if(neteff>0){
        goblin->health-= neteff;}//deduct goblins health
        
        printf("Goblins health is %lf\n", goblin->health);//check goblin health
    }
 if(isGA==1)
     {printf("\nGolbin ATTACKED!!!\n");
        double neteff2 = goblin->offence-player->defence;//check net eff of goblins attack
        if(neteff2>0){
        player->health-=neteff2;}//deduct players health

        printf("Players health is %lf\n", player->health);//check player health

     }
    }while(player->health>0 && goblin->health>0);




}

void checkgoblin(int*isGA)
{
(*isGA)=(rand()%2);
}
