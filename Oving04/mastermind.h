#pragma once
#include "std_lib_facilities.h"
#include "masterVisual.h"

void playMastermind();

int checkCharactersAndPosition(string code, string guess);

int checkCharacters(string code, string guess, char min, char max);

