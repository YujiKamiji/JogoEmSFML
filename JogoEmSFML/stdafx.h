#pragma once

#include <stdlib.h>
#include <time.h>
#include <math.h>

#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>

#include <iostream>
using namespace std;

enum idEstado
{
    MENU,           //0
    MENU_OPCOES,    //1    
	FLORESTA_SINGLE,//2
    FLORESTA_MULTI, //3
	CASTELO_SINGLE, //4
    CASTELO_MULTI,  //5
    PAUSE,          //6
    GAMEOVER,       //7   
    VITORIA         //8
};
