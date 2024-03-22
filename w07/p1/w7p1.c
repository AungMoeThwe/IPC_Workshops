/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P1)
Full Name  : Aung Moe Thwe
Student ID#: 148396237
Email      : amthwe@myseneca.ca
Section    : ZBB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#define MAXPATH 70
#define MINPATH 10
#define VALUE_MULTIPLE 5
#define MINLIFE 1
#define MAXLIFE 10


#include <stdio.h>
struct PlayerInfo // to define player information 
{
    int lives;
    char representation;
    int treasure_counter;
    int history[MAXPATH];
};
struct GameInfo // to define game configuration 
{
    int moves;
    int path;
    int bombs[MAXPATH];
    int treasure[MAXPATH];

};
int main(void)
{
    int i;
    struct PlayerInfo player = { 0,'0',0,{0} }; // setting safe state to history of players and player info to re-initialise
    struct GameInfo config = { 0,0,{0},{0} }; // setting safe state to gameinfo to re-initialise


    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");


    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.representation);

    do // validating player lives 
    {
        printf("Set the number of lives: ");
        scanf("%d", &player.lives);
        if (player.lives<MINLIFE || player.lives >MAXLIFE)
        {
            printf("     Must be between 1 and 10!\n");
        }
    } while (player.lives<MINLIFE || player.lives >MAXLIFE);

    printf("Player configuration set-up is complete\n");

    printf("\nGAME Configuration\n");
    printf("------------------\n");

    do // validating path and making sure that its a multiple of 5
    {
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &config.path);

        if ((config.path < MINPATH || config.path > MAXPATH) || (config.path % VALUE_MULTIPLE != 0))
        {
            printf("     Must be a multiple of 5 and between 10-70!!!\n");
        }
    } while ((config.path < MINPATH || config.path > MAXPATH) || (config.path % VALUE_MULTIPLE != 0));

    do // validating moves for the player
    {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &config.moves);

        if (config.moves < player.lives || config.moves > ((int)(config.path * 0.75)))
        {
            printf("    Value must be between %d and %d\n", player.lives, ((int)(config.path * 0.75)));
        }
    } while (config.moves < player.lives || config.moves > ((int)(config.path * 0.75)));

    printf("\nBOMB Placement");
    printf("\n--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");

    for (i = 0; i < config.path / VALUE_MULTIPLE; i++) // iteration for position placemnet. bombs
    {
        printf("   Positions [%2d-%2d]: ", ((i * 5) + 1), ((i * 5) + 5));
        scanf("%d %d %d %d %d", &config.bombs[i * 5], &config.bombs[((i * 5) + 1)], &config.bombs[((i * 5) + 2)], &config.bombs[((i * 5) + 3)], &config.bombs[((i * 5) + 4)]);
    }
    printf("BOMB placement set\n");

    printf("\nTREASURE Placement");
    printf("\n------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");

    for (i = 0; i < config.path / VALUE_MULTIPLE; i++) // iteration for position placemnet. Treasure
    {
        printf("   Positions [%2d-%2d]: ", ((i * 5) + 1), ((i * 5) + 5));
        scanf("%d %d %d %d %d", &config.treasure[i * 5], &config.treasure[((i * 5) + 1)], &config.treasure[((i * 5) + 2)], &config.treasure[((i * 5) + 3)], &config.treasure[((i * 5) + 4)]);
    }
    printf("TREASURE placement set\n");

    printf("\nGAME configuration set-up is complete...\n\n");

    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");

    printf("Player:\n"); // player summary
    printf("   Symbol     : %c\n", player.representation);
    printf("   Lives      : %d\n", player.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");

    printf("Game:\n"); // game summary
    printf("   Path Length: %d", config.path);

    printf("\n   Bombs      : ");
    for (i = 0; i < config.path; i++) // iterating through the array for bomb placement
    {
        printf("%d", config.bombs[i]);
    }

    printf("\n   Treasure   : ");
    for (i = 0; i < config.path; i++) // iterating through the array for treasure placement
    {
        printf("%d", config.treasure[i]);
    }

    printf("\n\n");
    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");


    return 0;
}
