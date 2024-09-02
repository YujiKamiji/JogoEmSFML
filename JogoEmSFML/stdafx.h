#pragma once

#include <stdlib.h>
#include <time.h>
#include <math.h>

#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include <list>

#include <functional>
#include <iostream>
#include <fstream>
using namespace std;

enum idEstado
{
    MENU,           //0
    MENU_RANKING,   //1    
	FLORESTA_SINGLE,//2
    FLORESTA_MULTI, //3
	CASTELO_SINGLE, //4
    CASTELO_MULTI,  //5
};
