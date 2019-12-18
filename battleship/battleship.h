/*==============================================================================
 | Filename: battleship.h                                                    
 | Programmer: Lou Na                                                           
 | Game of Battleship                    
 | Date: Dec 17, 2019                                                 
 +------------------------------------------------------------------------------                                                                       
 | Description: The file contains all of the function prototypee, structs, 
 |              enumerated types, constanct macros and standard libraries,
 |              required to run the game of Battleship.
 ==============================================================================*/

#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

/* CONSTANT MACROS */

#define ROWS 10
#define COLS 10

#define NUM_OF_SHIPS  4

#define HORIZONTAL    0
#define VERTICAL      1

#define WATER         '~'
#define HIT           '*'
#define MISS          'm'

#define CARRIER       'c'
#define CRUISER       'r'
#define SUBMARINE     's'
#define DESTROYER     'd'

#define NORTH 0
#define SOUTH 1
#define WEST  2
#define EAST  3

/* ENUMERATED TYPES */

typedef enum {
	FALSE, TRUE
} Boolean;

typedef enum {
	CARRIER_L    = 4, 
	CRUISER_L    = 3, 
	SUBMARINE_L  = 2,
	DESTROYER_L  = 1
} ShipType;

/* STRUCT TYPES */

typedef struct watercraft {
	char   symbol;
	short  length;
	char   *name;
} WaterCraft;

typedef struct stats {
	int        numHits;
	int        numMisses;
	int        totalShots;
	double     hitMissRatio;
} Stats;

typedef struct coordinate {
	int        row;
	int        column;
} Coordinate;

typedef struct cell {
	char       symbol; 
	Coordinate position;
} Cell;

/* FUNCTION PROTOTYPES */

void         welcomeScreen                  (void);
void         initializeGameBoard            (Cell gameBoard[][COLS]);
void         printGameBoard                 (Cell gameBoard [][COLS], Boolean showPegs);
void         putShipOnGameBoard             (Cell gameBoard[][COLS], WaterCraft ship, Coordinate position, int direction);
void         manuallyPlaceShipsOnGameBoard  (Cell gameBoard[][COLS], WaterCraft ship[]);
void         randomlyPlaceShipsOnGameBoard  (Cell gameBoard[][COLS], WaterCraft ship[]);
void         updateGameBoard                (Cell gameBoard[][COLS], Coordinate target);
void         checkBoundsOfCardinal          (Boolean cardinals[], int bound, int direction);
void         systemMessage                  (char *message);

Boolean      checkSunkShip                  (short sunkShip[NUM_OF_SHIPS], char shipSymbol);
Boolean      isValidLocation                (Cell gameBoard[][COLS], Coordinate position, int direction, int length);
Boolean      convertStringtoPosition        (Coordinate position[], char *stringPosition, int length);

Coordinate   generatePosition               (int direction, int length);
Coordinate   getTarget                      (void);

short        checkShot                      (Cell gameBoard[][COLS], Coordinate target);
int          getRandomNumber                (int lowest, int highest);

#endif
