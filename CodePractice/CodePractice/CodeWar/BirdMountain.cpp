#include "BirdMountain.h"

#include <iostream>

int BirdMountain::peak_height(std::vector<std::string>& mountain)
{
    // Graph depth first, row
    // If space, or inferior height as a neighbour, transform ^ into current height
    // Outside of bound are considered space;
    // If ^ were skipped, increment the height until all ^ are changed into a height value

    int CurrentHeight = 0;
    bool IncrementHeight = true;
    
    while (IncrementHeight)
    {
        IncrementHeight = false;
        bool FirstIncrement = true;
        
        for (int row=0; row<mountain.size(); row++)
        {
            for (int col=0; col<mountain[row].length(); col++)
            {
                //skip spaces or lower index
                if (mountain[row][col] == ' ' || mountain[row][col] != '^')
                {
                    continue;
                }

                if (FirstIncrement)
                {
                    CurrentHeight++;
                    FirstIncrement = false;
                }
                
                // inexistant row cell are considered space
                if (row-1 < 0 || row+1 == mountain.size() || col-1 < 0 || col+1 == mountain[row].length())
                {
                    mountain[row][col] = CurrentHeight + '0';
                    continue;
                }

                // if there is a neighbour that is a space or a lower index, identify as current height
                if (
                    mountain[row-1][col] == ' ' ||
                    mountain[row+1][col] == ' ' ||
                    mountain[row][col-1] == ' ' ||
                    mountain[row][col+1] == ' ' ||
                    mountain[row-1][col] == (CurrentHeight-1) + '0' ||
                    mountain[row+1][col] == (CurrentHeight-1) + '0' ||
                    mountain[row][col-1] == (CurrentHeight-1) + '0' ||
                    mountain[row][col+1] == (CurrentHeight-1) + '0' 
                    )
                {
                    mountain[row][col] = CurrentHeight + '0';
                }
            
                //if the value is still a mountain at the end, revisit later to know it height
                if (mountain[row][col] == '^')
                {
                    IncrementHeight = true;
                }
            }
        }
    }
    
    return CurrentHeight;
}

void BirdMountain::Execute()
{
    std::vector<std::string> mountain = {
        "^^^^^^        ",
        " ^^^^^^^^     ",
        "  ^^^^^^^     ",
        "  ^^^^^       ",
        "  ^^^^^^^^^^^ ",
        "  ^^^^^^      ",
        "  ^^^^        "
    };
    
    std::cout<< peak_height(mountain) << std::endl;
}
