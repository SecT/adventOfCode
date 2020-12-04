#include "tasks.h"

bool testReadingFileForTask_2020_01(std::vector<string>& inputData)
{
    if(inputData[0] != "1686" || inputData[1] != "1337" || inputData[inputData.size()-1] != "1862")
    {
        return false;
    }

    return true;
}

bool testTask_2020_01_A(int result)
{
    return result == 955584;
}

bool testTask_2020_01_B(int result)
{
    return result == 287503934;
}

int processTask_2020_01_A(std::vector<std::string> inputData)
{
    int result = 0;

    int wantedTotal = 2020;
    
    for (std::vector<string>::iterator i = inputData.begin(); i != inputData.end(); ++i)
    { 
            for (std::vector<string>::iterator j = inputData.begin(); j != inputData.end(); ++j)
            {
                if( std::stoi(*i) + std::stoi(*j) ==  wantedTotal )
                {
                    return std::stoi(*i) * std::stoi(*j);
                }
            }

    }

    return result;
}

int processTask_2020_01_B(std::vector<std::string> inputData)
{
    int result = 0;

    int wantedTotal = 2020;
    
    for (std::vector<string>::iterator i = inputData.begin(); i != inputData.end(); ++i)
    { 
            for (std::vector<string>::iterator j = inputData.begin(); j != inputData.end(); ++j)
            {
                if ( i == j)
                {
                    continue;
                }
                            for (std::vector<string>::iterator k = inputData.begin(); k != inputData.end(); ++k)
            {
                if( std::stoi(*i) + std::stoi(*j) + std::stoi(*k) ==  wantedTotal) 
                {
                    return std::stoi(*i) * std::stoi(*j) * std::stoi(*k);
                }
            }
            }
    }

    return result;
}

bool testReadingFileForTask_2020_02(std::vector<string>& inputData)
{
    if(inputData[0] != "4-7 z: zzzfzlzzz" || inputData[1] != "3-4 l: blllk" || inputData[inputData.size()-1] != "12-20 t: ttttttltttvttttttttt")
    {
        return false;
    }

    return true;
}

bool testTask_2020_02_A(int result)
{
    return result == 396;
}