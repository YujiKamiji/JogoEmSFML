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
    FLORESTA,       //2
    CASTELO,        //3
    PAUSE,          //4
    GAMEOVER,       //5    
    VITORIA         //6    
};
