/*==============================================================================
 | Filename: main.c                                                      
 | Programmer: Lou Na                            
 | Game of Battleship                    
 | Date: Dec 17, 2019                                                
 +------------------------------------------------------------------------------                                                                       
 | Description: This program simulates the game of Battleship. The game will be 
 |              completely text-based. Players' fleets consist of 4 ships. Each battle ship 
 |              has different number of cells that expands on the game board. The maximum 
 |              number of cell is 4. The Carrier has 4 cells, the Cruiser has 3 cells, the Submarine  
 |              has 2 cells,  the Destroyer has 1 cells.                               
 ==============================================================================*/

#include "battleship.h"
#include "stdlib.h"

int main ()
{
	/**
	 * The game board implemented as a 2-dimensional array.  
	 * The dime of 2-dimensional array is 10 X 10. 
	 */
	Stats players = {0, 0, 0, 0.0};

	Cell playerGameBoard[ROWS][COLS];       /* Player  game board */

	Coordinate target;             /* x, y value of a target */
	Coordinate targetTemp;         /* x, y value that holds a temporary value*/
	Coordinate targetOrigin;       /* x, y value of the original target */
	Coordinate targetAI;           /* x, y value of the targets using AI technique */

	WaterCraft ship[NUM_OF_SHIPS] = {{'c', 4, "Carrier"}, 
	                                                   {'r',  3, "Cruiser"}, 
	                                                   {'s', 2, "Submarine"}, 
	                                                   {'d', 1, "Destroyer"}};

	Boolean    huntMode       = TRUE;                     /* mode of randomly selecting a target */
	Boolean    targetMode     = FALSE;                    /* mode when there is a hit */
	Boolean    flipper        = TRUE;	                  /* flips values of boolean */
	Boolean    cardinals[4]   = {TRUE, TRUE, TRUE, TRUE}; /* represents the 4 cardinals, N, S, W, E */
	Boolean    hasAShipSunked = FALSE;                    /* if a ship has sank */


	short sunkShip [NUM_OF_SHIPS] = {4, 3, 2, 1};  /* tracks parts of the ship destroyed */

	short shot    = 0;             /* holds temp value if ship has been shot */
	int   option  = 0;             /* option for player to place ship manually or randomly */
	int   north   = 0,             /* holds change of value when going north */
		  south   = 0,             /* holds change of value when going south */
		  east    = 0,             /* holds change of value when going east */
		  west    = 0;             /* holds change of value when going west */
	int   i       = 0,             
		  counter = 1;             /* i and counter are used as counters */

	char  shipSymbol = '\0';       /* temporary value to save character symbol of the ship */

	int exitFlag = -1;

       char k = '\0';

	srand ((unsigned int) time (NULL));

	/**
	 * Print welcome screen
	 */
	welcomeScreen ();
	systemMessage ("                            Hit <ENTER> to continue!\n");
	system ("clear");

	/**
	 * Player's game board should be initialized to all '~' indicating
	 * no ships have been placed on either board.
	 */
	initializeGameBoard (playerGameBoard);

	/**
	 * players' fleets consist of 4 ships.
	 * Each ship may be differentiated by its "size" 
	 *      The Carrier has 4 cells, 
	 *      Cruiser has 3 cells, 
	 *      Submarine has 2 cells, and 
	 *      the Destroyer has 1 cell. 
	 */


	/**
	 * Note that ships cannot be placed diagonally on the board, they can 
	 * only be placed vertically or horizontally. You program must check to 
	 * see if the user tries to place a ship outside the boundaries of the 
	 * board or on top of a ship that has already been placed. Each cell on 
	 * the board that contains part of the ship must be indicated by 'c' for 
	 * Carrier,  'r' for Cruiser, 's' for Submarine, or 'd' for Destroyer.
	 */

	randomlyPlaceShipsOnGameBoard (playerGameBoard, ship);
	printf ("> Player board has been generated.\n");


	while (TRUE) 
	{
		/* Print player's game board*/
		printf ("> Player's Board:\n");
		printGameBoard (playerGameBoard, TRUE);
		printf ("> YOUR TURN TO FIRE\n");

		/* Prompts user to enter target */
		do {
			target = getTarget (); 
			shot = checkShot (playerGameBoard, target);
					
			/* prompts user that input is invalid or either a hit or miss cell */
			if (shot == -1) 
				printf ("> Try inputting another target!\n");

		} while (shot == -1);

		/* saves the character of the targeted cell */
	       shipSymbol = playerGameBoard[target.row][target.column].symbol;
	
		/**
		 * Prompts player if it's a hit or miss 
		 */
		if (shot == 1) { /* HIT */
                    int2char(target.row, &k);
			
			printf ("> %c, %d is a hit!\n", k, target.column);


			/* Keeps track so number of hits for stats */
			players.numHits++;

			/* Checks if the ship has sank */
		      hasAShipSunked = checkSunkShip (sunkShip, shipSymbol);
		} else {        /* MISS */
                    int2char(target.row, &k);

			printf ("> %c, %d is a miss!\n", k, target.column);		

			players.numMisses++;
		}
		
		updateGameBoard (playerGameBoard, target);

             #if 0
		/* Determins if there is a winner based on number of hits */
		if (isWinner (players, player)) {
			printf ("\n> Player %d wins!\n", player + 1);

			/* Write to battleship.log */
			//fprintf (outStream, "\n>>>>> Player %d wins! <<<<<\n", player + 1);
			break;
		}
		#endif
            
              getchar();
		char cmd = '\0';

		printf("> Press Y to stop fire and check result, press other to continue fire !\n");
		cmd = getchar();

		if(cmd == 'Y') break;
		
		system ("clear");
	}


	int k1 =0;

	int sunkedNm = 0;

	int hitedNm = 0;

	for(k1=0; k1<4; k1++)
	{
            if(sunkShip[k1] == 0)
            {
                 sunkedNm++;
	          continue;
            }
	     if(sunkShip[k1] != (4-k1))
	     {
	           hitedNm++;
	     }
	}

	printf("the number of sunked ship is %d\n", sunkedNm);

	printf("the number of hited but not sunked ship is %d\n", hitedNm);

	return 0;
}
