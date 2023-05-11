#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Player.h"
#include "ConsoleControl.h"
using namespace std;

/*
Description: Functions to paint a cat.
Input: Nothing.
Return: Nothing.
*/
void paintCat();
void paintListCat();
void paintWinnerCat();
void paintLoserCat();

/*
Description: Function to show the selector of the game
Input: The selected value.
Return: The selected value.
*/
void choiceSelector(int& value);

/*
Description: Function to ask and save the name of the player.
Input: Pointer to the Player.
Return: Nothing, only changes the values of the name variable.
*/
void playerName(Player* pointer);

/*
Description: Function to write the points of the game.
Input: Pointer to the Player.
Return: Nothing, only adds to the file the points and the name of the player.
*/
void writePointsFile(Player* pointer);

/*
Description: Function to read and show the top 10.
Input: Nothing.
Return: Nothing, only shows in screen the points and the name of the player.
*/
void readPointsFile();