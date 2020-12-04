#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::string;

#include "tasks.h"

bool readLinesFromFileToVector(std::vector<string>& inputData, string filePath)
{
    std::ifstream inputFile(filePath.c_str());

    if (!inputFile)
    {
        std::cerr << "Cannot open the File : "<<filePath.c_str()<<std::endl;
        return false;
    }

    std::string row;

    while (std::getline(inputFile, row))
    {
        inputData.push_back(row);
    }

    inputFile.close();
    return true;
}

bool task_2020_01()
{
    std::vector<std::string> inputData;
    string filePath = "input_2020_Task_01.txt";
    if(!readLinesFromFileToVector(inputData, filePath))
    {
        cout<<"Error reading file: "<<filePath<<endl;
        return false;
    }

    if(!testReadingFileForTask_2020_01(inputData))
    {
        cout<<"File reading test failed!"<<endl;
        return false;
    }

    int result_task_2020_01_A = processTask_2020_01_A(inputData);

    if(!testTask_2020_01_A(result_task_2020_01_A))
    {
        cout<<"task 2020 01 A failed!"<<endl;
        return false;
    }

    cout<<"Task 2020 01 A result: "<<result_task_2020_01_A<<endl;    


    int result_task_2020_01_B = processTask_2020_01_B(inputData);

    if(!testTask_2020_01_B(result_task_2020_01_B))
    {
        cout<<"task 2020 01 B failed!"<<endl;
        return false;
    }

    cout<<"Task 2020 01 B result: "<<result_task_2020_01_B<<endl;    

    return true;
}

bool task_2020_02()
{
    return true;
}

int main()
{
    cout<<"Advent of Code"<<endl;

    task_2020_01();

    cout<<"End"<<endl;

    return 0;
}