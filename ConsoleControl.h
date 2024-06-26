#pragma once

#define KB_UP 72 
#define KB_UP2 87 
#define KB_UP3 119
#define KB_DOWN 80 
#define KB_DOWN2 83 
#define KB_DOWN3 115
#define KB_LEFT 75 
#define KB_LEFT2 65 
#define KB_LEFT3 97
#define KB_RIGHT 77
#define KB_RIGHT2 68
#define KB_RIGHT3 100
#define KB_SPACE 32
#define KB_ESCAPE 27

enum ConsoleColor { 
	BLACK, DARKBLUE, DARKGREEN, DARKCYAN, DARKRED, DARKMAGENTA, DARKYELLOW, LIGHTGREY,
	DARKGREY, BLUE, GREEN, CYAN, RED, MAGENTA, YELLOW, WHITE
};

void ConsoleSetColor(ConsoleColor ForeColor, ConsoleColor BackColor);
void ConsoleXY(short int x, short int y);
void ConsoleClear();
void ConsoleClearCharacter(char character, ConsoleColor ForeColor, ConsoleColor BackColor);

void ConsoleWait(unsigned long milisecons);

int ConsoleInKey();