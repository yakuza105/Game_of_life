#include<iostream>
#include<cstdlib>
#include <windows.h>
using namespace std;

const int gridSize = 100;

void printGrid(bool gridOne[gridSize+1][gridSize+1]);
void determineState(bool gridOne[gridSize+1][gridSize+1]);

int main(){
	
   
    bool gridOne[gridSize+1][gridSize+1] = {};
    int x,y,n;
    char start;
  
    cin >> n;
    for(int i=0;i<n;i++)
    {
       x = ( std::rand() % gridSize+1 ) + 0;
		   y=  ( std::rand() % gridSize+1 ) + 0;        
        gridOne[x][y] = true;
        
    }

    cout << " Start ?(y/n)" << endl;
    printGrid(gridOne);
    cin >> start;

    if(start == 'y' || 'Y')
    {
        while (true)
        {
            printGrid(gridOne);
            determineState(gridOne);
            Sleep(100);
            system("CLS");
        }
    }
    else
    {
        return 0;
    }

}

void printGrid(bool gridOne[gridSize+1][gridSize+1]){
    for(int a = 1; a < gridSize; a++)
        {
        for(int b = 1; b < gridSize; b++)
        {
            if(gridOne[a][b] == true)
            {
                cout << "o";
            }
            else
            {
                cout << ".";
            }
            if(b == gridSize-1)
            {
                cout << endl;
            }
        }
    }
}

void compareGrid (bool gridOne[gridSize+1][gridSize+1], bool gridTwo[gridSize+1][gridSize+1]){
    for(int a =0; a < gridSize; a++)
    {
        for(int b = 0; b < gridSize; b++)
        {
                gridTwo[a][b] = gridOne[a][b];
        }
    }
}

void determineState(bool gridOne[gridSize+1][gridSize+1]){
    bool gridTwo[gridSize+1][gridSize+1] = {};
    compareGrid(gridOne, gridTwo);

    for(int a = 1; a < gridSize; a++)
    {
        for(int b = 1; b < gridSize; b++)
        {
            int alive = 0;
            for(int c = -1; c < 2; c++)
            {
                for(int d = -1; d < 2; d++)
                {
                    if(!(c == 0 && d == 0))
                    {
                        if(gridTwo[a+c][b+d])
				{
					++alive;
				}
                    }
                }
            }
            if(alive < 2)
            {
                gridOne[a][b] = false;
            }
            else if(alive == 3)
            {
                gridOne[a][b] = true;
            }
            else if(alive > 3)
            {
                gridOne[a][b] = false;
            }
        }
    }
}