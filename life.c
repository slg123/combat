#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAXROW 50
#define MAXCOL 90

typedef enum state { 
    DEAD, 
    ALIVE 
} State;

typedef enum boolean {
    FALSE,
    TRUE
} Boolean;


typedef State Grid[MAXROW+2][MAXCOL+2]; // +2 for the gutters

void CopyMap(Grid map, Grid newmap);
void Initialize(Grid map);
int NeighborCount(Grid map, int row, int column);
int CheckForSurvivors(Grid map);
void WriteMap(Grid map);
void initGliderGun(Grid map);
void initFylfot(Grid map);
void initHarvester(Grid map);
void initCheshireCat(Grid map);
void initAcorn(Grid map);


void Error(char *);
void Warning(char *);

int main(void)
{
    int row, col;
    int selection;
    int ndead;
    int nsecPerDay = 86400;
    int a[nsecPerDay];
    

    Grid map;
    Grid newmap;
    Initialize(map);
    system("/usr/bin/clear");

    printf("press: \n"
            "(1) for glider gun\n"
            "(2) for harvester\n"
            "(3) for cheshire cat\n"
            "(4) for acorn\n"
            " => ");

    scanf("%d", &selection);

    switch( selection ) {
        case 1:
            initGliderGun(map);
        case 2:
            initHarvester(map);
        case 3:
            initCheshireCat(map);
        case 4:
            initAcorn(map);
        break;
    }

    WriteMap(map);
  
    int generations = 0;

    while (generations < nsecPerDay) {    // number of seconds in 24 hours. this won't hold your interest that long.

        WriteMap(map);

        for (row = 1; row <= MAXROW; row++) 

            for (col = 1; col <= MAXCOL; col++) 
 
                switch(NeighborCount(map, row, col)) {

                case 0:
                case 1:
                    newmap[row][col] = DEAD;
                    ndead = CheckForSurvivors(map);
                    if (ndead == (MAXROW * MAXCOL)) {
                        printf("all cells dead. exiting.\n"); 
                        exit(1);
                    }
                    break;
                case 2:
                    newmap[row][col] = map[row][col];
                    ndead = CheckForSurvivors(map);
                    if (ndead == (MAXROW * MAXCOL)) {
                        printf("all cells dead. exiting.\n"); 
                        exit(1);
                    }
                    break;
                case 3:
                    newmap[row][col] = ALIVE;
                    ndead = CheckForSurvivors(map);
                    if (ndead == (MAXROW * MAXCOL)) {
                        printf("all cells dead. exiting.\n"); 
                        exit(1);
                    }
                    break;
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                    newmap[row][col] = DEAD;
                    ndead = CheckForSurvivors(map);
                    if (ndead == (MAXROW * MAXCOL)) {
                        printf("all cells dead. exiting.\n"); 
                        exit(1);
                    }
                    break;
                }

            WriteMap(map);
            a[generations] = CheckForSurvivors(map); 

            if (a[generations] == a[generations-4]) {
                if (selection == 1 || selection == 5) {
                    ;
                } else {
                    printf("grid is stable. exiting.\n"); 
                    exit(1);
                }
            }
          
            CopyMap(map, newmap);
            sleep(1);
            generations++;
    }
        
}

void Error(char *s)
{
    fprintf(stderr, "%s\n", s);
    exit(1);
}

int NeighborCount(Grid map, int row, int col)
{
    int i;
    int j;

    int count = 0;

    for (i = row - 1; i <= row + 1; i++) 
        for (j = col - 1; j <= col + 1; j++) 
            if (map[i][j] == ALIVE) 
                count++;
    if (map[row][col] == ALIVE) 
        count--;
    return count;
}

void Initialize(Grid map)
{
    int row, col;

    system("/usr/bin/clear");
    printf("This program is a simulation of Conway's game of Life.\n"
           "The grid has a size of %d rows and %d columns.\n", MAXROW, MAXCOL); 
    sleep(3);

    for (row = 0; row <= MAXROW+1; row++) {
        for (col = 0; col <= MAXCOL+1; col++) {
            map[row][col] = DEAD;
        }
    }

}

void WriteMap(Grid map)
{
    int row, col;
    putchar('\n');
    putchar('\n');
    for (row = 1; row <= MAXROW; row++) {
        for (col = 1; col <= MAXCOL; col++) 
            if (map[row][col] == ALIVE) 
                putchar('*');
            else 
                putchar(' ');
        putchar('\n');
    }
}

int CheckForSurvivors(Grid map)
{
    int row, col;
    int count;
    for (row = 1; row <= MAXROW; row++) {
        for (col = 1; col <= MAXCOL; col++)
            if (map[row][col] == DEAD)
                count++;
    }
    return count;

}

void CopyMap(Grid map, Grid newmap)
{
    int row, col;
    for (row = 0; row <= MAXROW+1; row++) 
        for (col = 0; col <= MAXCOL+1; col++) 
            map[row][col] = newmap[row][col];
}

void initGliderGun(Grid map)
{
    map[7][42] = ALIVE;
    map[7][43] = ALIVE;
    map[6][43] = ALIVE;
    map[5][52] = ALIVE;
    map[6][52] = ALIVE;
    map[7][52] = ALIVE;
    map[4][53] = ALIVE;
    map[8][53] = ALIVE;
    map[3][54] = ALIVE;
    map[9][54] = ALIVE;
    map[3][55] = ALIVE;
    map[9][55] = ALIVE;
    map[6][65] = ALIVE;
    map[10][65] = ALIVE;
    map[5][66] = ALIVE;
    map[6][66] = ALIVE;
    map[10][66] = ALIVE;
    map[11][66] = ALIVE;
    map[7][68] = ALIVE;
    map[8][68] = ALIVE;
    map[9][68] = ALIVE;
    map[7][69] = ALIVE;
    map[8][69] = ALIVE;
    map[9][69] = ALIVE;
    map[8][70] = ALIVE;
    map[9][76] = ALIVE;
    map[8][77] = ALIVE;
    map[9][77] = ALIVE;
}

void initHarvester(Grid map)
{
    map[8][50] = ALIVE;
    map[9][49] = ALIVE;
    map[10][48] = ALIVE;
    map[11][47] = ALIVE;
    map[12][46] = ALIVE;
    map[13][45] = ALIVE;
    map[14][44] = ALIVE;
    map[15][43] = ALIVE;
    map[16][42] = ALIVE;
    map[17][41] = ALIVE;
    map[18][40] = ALIVE;
    map[19][39] = ALIVE;
    map[20][38] = ALIVE;
    map[21][37] = ALIVE;
    map[22][36] = ALIVE;
    map[23][35] = ALIVE;
    map[24][34] = ALIVE;
    map[25][33] = ALIVE;
    map[26][32] = ALIVE;
    map[27][31] = ALIVE;
    map[28][30] = ALIVE;
    map[29][29] = ALIVE;
    map[30][28] = ALIVE;
    map[31][27] = ALIVE;
    map[32][26] = ALIVE;
    map[33][25] = ALIVE;
    map[33][26] = ALIVE;
    map[33][23] = ALIVE;
    map[32][23] = ALIVE;
    map[32][24] = ALIVE;
    map[32][25] = ALIVE;
    map[32][26] = ALIVE;
    map[31][23] = ALIVE;
    map[31][24] = ALIVE;
    map[31][25] = ALIVE;
    map[31][26] = ALIVE;
}

void initCheshireCat(Grid map)
{
    map[10][50] = ALIVE;
    map[10][53] = ALIVE;
    map[11][50] = ALIVE;
    map[11][51] = ALIVE;
    map[11][52] = ALIVE;
    map[11][53] = ALIVE;
    map[12][49] = ALIVE;
    map[12][54] = ALIVE;
    map[13][49] = ALIVE;
    map[13][51] = ALIVE;
    map[13][52] = ALIVE;
    map[13][54] = ALIVE;
    map[14][49] = ALIVE;
    map[14][54] = ALIVE;
    map[15][50] = ALIVE;
    map[15][51] = ALIVE;
    map[15][52] = ALIVE;
    map[15][53] = ALIVE;
} 

void initAcorn(Grid map)
{
    map[20][40] = ALIVE;
    map[21][42] = ALIVE;
    map[22][39] = ALIVE;
    map[22][40] = ALIVE;
    map[22][43] = ALIVE;
    map[22][44] = ALIVE;
    map[22][45] = ALIVE;

}

