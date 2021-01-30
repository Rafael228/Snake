#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>
#include<time.h>

void finalizacao( int pts ){
    system("cls");
    gotoxy(22,7);
    printf("VOCE FEZ %d PONTOS", pts);
    gotoxy(24, 10);
    printf("VOCE PERDEU!!");
    gotoxy(15,13);
    printf("APERTE QUALQUER TECLA PARA SAIR\n\n\n\n\n\n\n\n\n");
    getch();
    exit(0);
}

void gotoxy( int x, int y ){
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x,y});
}

int main(){
    char m[24][50];
    char auxmenu;
    int x,y,i,j,randx,randy,tam,startgame,localizacaoaux[2],dir,comidaemcampo,comidacont,comidacont2,ad,pts;
    startgame = 1;
    tam = 5;
    x = 6;
    y = 12;
    int tamcont, menucont, menudec, speed;
    char direcao, direcaoaux;
    direcao = 'd';
    direcaoaux = 'd';
    comidaemcampo = 0;
    comidacont = 0;
    comidacont2 = 0;
    ad = 5;
    pts = 0;
    menucont = 10;
    speed = 100;

    srand(time(NULL));
    system("cls");
    int menu[2];
    gotoxy(20,10);
    printf("NEW GAME");
    gotoxy(20,11);
    printf("EXIT");
    gotoxy(18, 10);
    printf(">");
    for( ; ; ){
        gotoxy(1,1);
        auxmenu = getch();
        if( auxmenu == 'w'){
            if( menucont == 10 ){
                gotoxy(18, 10);
                printf(" ");
                gotoxy(18,11);
                printf(">");
                menucont++;
                menudec = 0;
            }
            else{
                gotoxy(18, 10);
                printf(">");
                gotoxy(18,11);
                printf(" ");
                menucont--;
                menudec = 1;
            }
        }
        if( auxmenu == 's' ){
            if( menucont == 11 ){
                gotoxy(18, 10);
                printf(">");
                gotoxy(18,11);
                printf(" ");
                menucont--;
                menudec = 0;
            }
            else{
                gotoxy(18, 10);
                printf(" ");
                gotoxy(18,11);
                printf(">");
                menucont++;
                menudec = 1;
            }
        }
        if( auxmenu == 13 ){
            if( menudec == 0 ){
                system("cls");
                break;
            }
            else{
                exit(0);
            }
        }
    }

    // LOCALIZAR A COBRINHA
    int localvetorx[1000][1];
    int localvetory[1000][1];
    localvetorx[0][0] = 6;
    localvetorx[1][0] = 5;
    localvetorx[2][0] = 4;
    localvetorx[3][0] = 3;
    localvetorx[4][0] = 2;
    localvetory[0][0] = 12;
    localvetory[1][0] = 12;
    localvetory[2][0] = 12;
    localvetory[3][0] = 12;
    localvetory[4][0] = 12;
    for( i = 5; i < 1000; i++){
        localvetorx[i][0] = 999999;
        localvetory[i][0] = 999999;
    }
    // LOCALIZAR A COBRINHA

    for( i = 0; i<24; i++ ){
        for( j = 0; j < 50; j++ ){
            m[i][j] = ' ';
        }
    }
    for( i = 0; i<50; i++ ){
        m[0][i]='x';
        m[23][i]='x';
    }
    for( i = 0; i<24; i++ ){
        m[i][0]='|';
        m[i][48]='|';
    }
    for( i = 0; i<24; i++ ){
        for( j = 0; j < 49; j++ ){
            printf("%c", m[i][j]);
        }
        printf("\n");
    }
    // PRIMEIRO PRINTF DA COBRINHA
    gotoxy(6,12);
    printf("%c", '0');
    gotoxy(5,12);
    printf("%c", '0');
    gotoxy(4,12);
    printf("%c", '0');
    gotoxy(3,12);
    printf("%c", '0');
    gotoxy(2,12);
    printf("%c", '0');
    // PRIMEIRO PRINTF DA COBRINHA

    gotoxy(6,12);
    for( ; ; ){
        tam = ad;
         if( x == randx && y == randy && startgame > 1 ){
            comidaemcampo = 0;
            localvetorx[tam][0] = localizacaoaux[0];
            localvetory[tam][0] = localizacaoaux[1];
            gotoxy(localvetorx[tam-1][0], localvetory[tam-1][0]);
            printf("0");
            ad++;
            pts++;
            speed--;
        }
        // COMIDA RANDOMICA
        if( comidaemcampo == 0 ){
            for( ; ; ){
                randx = rand()%48;
                randy = rand()%23;
                if( randx == 0 ){
                    randx++;
                }
                if(randx == 48 ){
                    randx--;
                }
                if(randy == 0 ){
                    randy++;
                }
                if(randy == 23 ){
                    randy--;
                }
                for( tamcont = tam - 1 ; tamcont > -1 ; tamcont-- ){
                    if( localvetorx[tamcont][0] != randx && localvetory[tamcont][0] != randy ){
                        comidacont++;
                    }
                    if( comidacont++ == tam ){
                        comidacont2++;
                    }
                }
                if( comidacont2 == 1 ){
                    gotoxy(randx, randy);
                    printf("D");
                    comidaemcampo++;
                    comidacont2 = 0;
                    comidacont = 0;
                    break;
                }
                comidacont2 = 0;
                comidacont = 0;
            }
        }
        // COMIDA RANDOMICA
        if( kbhit()){
            direcao = getch();
            if(direcao == 'w' && direcaoaux != 's' && direcaoaux != 'w'){
                dir = 0;
                direcaoaux = direcao;
                startgame++;
            }
            if(direcao == 's' && direcaoaux != 'w' && direcaoaux != 's'){
                dir = 1;
                direcaoaux = direcao;
                startgame++;
            }
            if(direcao == 'd' && direcaoaux != 'a' && direcaoaux != 'd'){
                dir = 2;
                direcaoaux = direcao;
                startgame++;
            }
            if(direcao == 'a' && direcaoaux != 'd' && direcaoaux != 'a'){
                dir = 3;
                direcaoaux = direcao;
                startgame++;
            }
        }
        if( ( startgame == 1 ) ){
            x++;
            gotoxy(x,y);
            printf("%c", '0');
            x = x - 5;
            gotoxy(x,y);
            printf(" ");
            x = x + 5;
            gotoxy(x,y);
        }
        if( dir == 0 || dir == 1 || dir == 2 || dir == 3 ){
            localizacaoaux[0] = localvetorx[tam-1][0];
            localizacaoaux[1] = localvetory[tam-1][0];
            gotoxy(localizacaoaux[0], localizacaoaux[1]);
            printf(" ");
            gotoxy(x,y);
        }
        if( dir == 0 ){
            y--;
            for( tamcont = tam - 1; tamcont > 2; tamcont-- ){
                if( localvetorx[tamcont][0] == x && localvetory[tamcont][0] == y ){
                    finalizacao(pts);
                }
            }
            gotoxy(x,y);
            printf("0");
        }
        if( dir == 1 ){
            y++;
            for( tamcont = tam - 1; tamcont > 2; tamcont-- ){
                if( localvetorx[tamcont][0] == x && localvetory[tamcont][0] == y ){
                    finalizacao(pts);
                }
            }
            gotoxy(x,y);
            printf("0");
        }
        if( dir == 2 ){
            x++;
            for( tamcont = tam - 1; tamcont > 2; tamcont-- ){
                if( localvetorx[tamcont][0] == x && localvetory[tamcont][0] == y ){
                    finalizacao(pts);
                }
            }
            gotoxy(x,y);
            printf("0");
        }
        if( dir == 3 ){
            x--;
            for( tamcont = tam - 1; tamcont > 2; tamcont-- ){
                if( localvetorx[tamcont][0] == x && localvetory[tamcont][0] == y ){
                    finalizacao(pts);
                }
            }
            gotoxy(x,y);
            printf("0");
        }
        for( tamcont = tam - 1; tamcont > 0; tamcont-- ){
            localvetorx[tamcont][0] = localvetorx[tamcont-1][0];
            localvetory[tamcont][0] = localvetory[tamcont-1][0];
        }
        localvetorx[0][0] = x;
        localvetory[0][0] = y;
        Sleep(speed);
        gotoxy(35, 26);
        printf("PONTUACAO: %d", pts);
        gotoxy(x,y);
        if( y == 0 || y == 23 || x == 0 || x == 48 ){
           finalizacao( pts );
        }
    }

}
