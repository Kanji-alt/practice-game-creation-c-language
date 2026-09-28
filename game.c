#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <conio.h>
int atakdef (int atak, int def){

}
struct weapons{
    int num;
    char name[20];
    int atk;
    int price;
};
struct enemy{
    char name;
    int hp;
    int def;
    int atk;
};
int enemychoice(int a){
    if (a == 0){
        return 1;
    }
    if (a == 1){
        return 1;
    }
    if (a == 2){
        return 2;
    }
}
int main(){
    srand(time(0));
    struct weapons weapon[] = {
        {1, "katana", 40, 300},
        {2, "sword", 30, 200},
        {3, "mace", 47, 350},
        {4, "maul", 66, 670}
    };
    int num = sizeof(weapon) / sizeof(weapon[0]);
    //player
    int hp = 100;
    int damage = 0;
    int atk = 10 + damage;
    char arm[20] = "\0";
    double money = 0;
    
    char map[6][7] = {  {'H','H','H','H','H','M','\n'},
                        {'S','H','H','H','H','H','\n'},
                        {'H','H','H','H','H','H','\n'},
                        {'H','H','H','H','H','H','\n'},
                        {'H','H','H','H','H','H','\n'},
                        {'H','H','H','P','H','H','\n'}};
    bool playing = false;
    char answer = '\0';  
    int ver = 5;
    int hor = 3;
    bool shop = false;
    bool battle = false;

    printf("would you like to play?(y/n): ");
    scanf("%c", &answer);
    if (answer == 'y'){
        playing = true;
    }
    else if(answer == 'n'){
        printf("ok bye.");
    }
    else{
        printf("invalid input.");
    }

    while(playing){
        system("cls");
        printf("%s", map);
        printf("\n");
        char move = getch();
        if (move == 'i'){

        }
        else if  (move == 'w'){
            map[ver][hor] = 'H';
            ver -= 1;
            if (ver == 1 && hor == 0) {
                shop = true;
                ver += 1;
            }
            if (ver == 0 && hor == 5) {
                battle = true;
                ver += 1;
                printf("A monster before you!");
            }
            if (ver == -1) {
                ver += 1;
            }
            map[ver][hor] = 'P';
        }
        else if  (move == 'a'){
            map[ver][hor] = 'H';
            hor -= 1;
            if (ver == 1 && hor == 0) {
                shop = true;
                hor += 1; 
            }
            if (ver == 0 && hor == 5) {
                battle = true;
                hor += 1;
                printf("A monster before you!");
            }
            if (hor == -1) {
                hor += 1;
            }
            map[ver][hor] = 'P';
        }
        else if  (move == 's'){
            map[ver][hor] = 'H';
            ver += 1;
            if (ver == 1 && hor == 0) {
                shop = true;
                ver -= 1;
            }
            if (ver == 0 && hor == 5) {
                battle = true;
                ver -= 1;
                printf("A monster before you!");
            }
            if (ver == 6) {
                ver -= 1;
            }
            map[ver][hor] = 'P';
        }
        else if  (move == 'd'){
            map[ver][hor] = 'H';
            hor += 1;
            if (ver == 1 && hor == 0){
                shop = true;
                hor -= 1;
            }
            if (ver == 0 && hor == 5) {
                battle = true;
                hor -= 1;
                printf("A monster before you!");
            }
            if (hor == 6) {
                hor -= 1;
            }
            map[ver][hor] = 'P';
        }
        while(battle){
            
            struct enemy enemies[] = {
                {'G', 100, 10, 24 },
                {'P', 200, 7, 37 },
                {'f', 30, 3, 11 },
                {'M', 150, 24, 10 }
            };    
            int forrand;
            int p2 = rand() % 4;
            int enemyhp = enemies[p2].hp;
            printf("\na %c appeared before you!\n", enemies[p2].name);
            bool action = true;
            while(action){
                int choicebat = 0;
                int enemyc = 0;
                char enem[20] = "\0";
                int enemymax = enemies[p2].hp;
                printf("enemy hp: %d/%d\n", enemyhp, enemymax);
                printf("your hp: %d/%d\n", hp, 100);
                printf("what would you like to do?\n1. attack\n2. block\n3. item\n4. run away\n");
                printf("enter a number: ");
                scanf(" %d", &choicebat);
                getchar();
                enemyc = (rand() % 3);
                int enemychc = enemychoice(enemyc);
                if (enemychc == 1){
                    strcpy(enem, "attacked");
                }
                if (enemychc == 2){
                    strcpy(enem, "defended against");
                }
                if (enemychc == 2){
                    if (choicebat == 1){
                        printf("you attacked it and it %s you.", enem);
                        double pdamage = (atk - enemies[p2].def) / 2;
                        enemyhp -= pdamage;
                        printf("\nit takes %.2lf damage\n", pdamage);
                    }
                    if (choicebat == 2){
                        printf("you defended and it %s you.", enem);
                        printf("\nnothing happens\n");
                    }
                    if (choicebat == 3){
                        printf("no item.");
                        printf("\nit %s you.\n", enem);
                    }
                    if (choicebat == 4){
                        int success = (rand() % 3);
                        if (success == 0){
                            printf("\ncannot run away.\n");
                        }
                        else {
                            printf("\nsuccessfully ran away from %s.", enemies[p2].name);
                            battle = false;
                            action = false;
                        }
                    }
                }
                else if(enemychc == 1){
                    if (choicebat == 1){
                        printf("you attacked it and it %s you.\n", enem);
                        double pdamage = atk / 1.2;
                        double edamage = enemies[p2].atk / 1.2;
                        enemyhp -= pdamage;
                        hp -= edamage;
                        printf("you take %.2lf damage\n", edamage);
                        printf("it takes %.2lf damage\n", pdamage);
                    }
                    if (choicebat == 2){
                        double edamage = (enemies[p2].atk) / 2;
                        printf("you defended and it %s you.\n", enem);
                        hp -= edamage;
                        printf("you take %.2lf damage.\n", edamage);
                    }
                    if (choicebat == 3){
                        printf("no item.\n");
                        printf("it %s you.\n", enem);
                        double edamage = enemies[p2].atk / 1.2;
                        hp -= edamage;
                        printf("you take %.2lf damage\n", edamage);
                    }
                    if (choicebat == 4){
                        int success = (rand() % 3);
                        if (success == 0){
                            printf("cannot run away.\n");
                            double edamage = enemies[p2].atk / 1.2;
                            hp -= edamage;
                            printf("you take %.2lf damage\n", edamage);
                        }
                        else {
                            printf("successfully ran away from %s.", enemies[p2].name);
                            battle = false;
                            action = false;
                        }
                    }
                }
                if (hp < 1){
                    printf("youre dead.");
                    playing = false;
                    battle = false;
                    action = false;
                }
                if (enemyhp < 1){
                    printf("you won!");
                    battle = false;
                    action = false;
                }
            }
            battle = false;
        }
        while(shop){
            int choice = -1;
            printf("money: %.2lf", money);
            for (int i = 0; i < num; i++){
                printf("\n %d. %s: ", weapon[i].num, weapon[i].name);
                printf(" %d, price: %d $", weapon[i].atk, weapon[i].price);
            }
            printf("\nwhat would you like to buy?(q to exit) number: ");
            if(scanf(" %d", &choice) == 0){
                printf("would you like to exit?(q): ");
                char ytyt = getch();
                if (ytyt == 'q'){
                    shop = false;
                    continue;
                    printf("\n");
                }
            }
            printf("buy?(y): ");
            char pl = getch();
            if (pl == 'y'){
                if (money >= weapon[choice].price){
                    money -= weapon[choice].price;
                    printf("succesfully bought.");
                    damage = weapon[choice].atk;
                    strcpy(arm, weapon[choice].name);
                }
                else{
                    printf("not enough money.");
                }
            }            
        }            
    }
    getchar();
    getchar();
    return 0;
}