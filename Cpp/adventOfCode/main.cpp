#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::string;

#include "tasks.h"
#include "helpers.h"

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
    std::vector<std::string> inputData;
    string filePath = "input_2020_Task_02.txt";
    if(!readLinesFromFileToVector(inputData, filePath))
    {
        cout<<"Error reading file: "<<filePath<<endl;
        return false;
    }

    if(!testReadingFileForTask_2020_02(inputData))
    {
        cout<<"File reading test failed!"<<endl;
        return false;
    }

    if(!test_convertRowToRecord())
    {
        cout<<"Task 2 - row conversion to record failed!"<<endl;
        return false;
    }

    int result_A = processTask_2020_02_A(inputData);

    if(!testTask_2020_02_A(result_A))
    {
        cout<<"task 2020 02 A failed! Obtained result:"<<result_A<<endl;
        return false;
    }

    cout<<"Task 2020 02 A result: "<<result_A<<endl;    


    int result_B = processTask_2020_02_B(inputData);

    cout<<"Task 2020 02 B result: "<<result_B<<endl; 

    if(!testTask_2020_02_B(result_B))
    {
        cout<<"task 2020 02 B failed!"<<endl;
        return false;
    }

    return true;
}

bool task_2020_03()
{
    std::vector<std::string> inputData;
    string filePath = "input_2020_Task_03.txt";
    if(!readLinesFromFileToVector(inputData, filePath))
    {
        cout<<"Error reading file: "<<filePath<<endl;
        return false;
    }

    if(!testReadingFileForTask_2020_03(inputData))
    {
        cout<<"File reading test failed!"<<endl;
        return false;
    }

    int result_A = processTask_2020_03_A(inputData);

    if(!testTask_2020_03_A(result_A))
    {
        cout<<"task 2020 03 A failed! Obtained result:"<<result_A<<endl;
        return false;
    }

    cout<<"Task 2020 03 A result: "<<result_A<<endl;    


    int result_B = processTask_2020_03_B(inputData);

    cout<<"Task 2020 03 B result: "<<result_B<<endl; 

    if(!testTask_2020_03_B(result_B))
    {
        cout<<"task 2020 03 B failed!"<<endl;
        return false;
    }

    return true;
}

bool task_2020_04()
{
    std::vector<std::string> inputData;
    string filePath = "input_2020_Task_04.txt";
    if(!readLinesFromFileToVector(inputData, filePath))
    {
        cout<<"Error reading file: "<<filePath<<endl;
        return false;
    }

    std::vector<std::string> exampleInputData;
    string exampleFilePath = "input_2020_Task_04_example.txt";
    if(!readLinesFromFileToVector(exampleInputData, exampleFilePath))
    {
        cout<<"Error reading file: "<<exampleFilePath<<endl;
        return false;
    }

    std::vector<std::string> exampleInputData_valid;
    string exampleFilePath_valid = "input_2020_Task_04_example_B_valid.txt";
    if(!readLinesFromFileToVector(exampleInputData_valid, exampleFilePath_valid))
    {
        cout<<"Error reading file: "<<exampleFilePath_valid<<endl;
        return false;
    }

    std::vector<std::string> exampleInputData_invalid;
    string exampleFilePath_invalid = "input_2020_Task_04_example_B_invalid.txt";
    if(!readLinesFromFileToVector(exampleInputData_invalid, exampleFilePath_invalid))
    {
        cout<<"Error reading file: "<<exampleFilePath_invalid<<endl;
        return false;
    }

    if(!testReadingFileForTask_2020_04(inputData))
    {
        cout<<"File reading test failed!"<<endl;
        return false;
    }

    if(!test_getListOfPassports())
    {
        cout<<"getListOfPassports test failed!"<<endl;
        return false;
    }

    if(!test_fillOutFields())
    {
        cout<<"fillOutFields test failed!"<<endl;
        return false;
    }
    std::vector<task2020_04_passport> validPassportsExample;
    int result_example = processTask_2020_04_A(exampleInputData, validPassportsExample);

    if(!testTask_2020_04_A_example(result_example))
    {
        cout<<"task 2020 04 Example failed! Obtained result:"<<result_example<<endl;
        return false;
    }


    std::vector<task2020_04_passport> validPassports;
    int result_A = processTask_2020_04_A(inputData, validPassports);

    cout<<"Task 2020 04 A result: "<<result_A<<endl;    

    if(!testTask_2020_04_A(result_A))
    {
        cout<<"task 2020 04 A failed! Obtained result:"<<result_A<<endl;
        return false;
    }

    std::vector<task2020_04_passport> validPassportsExample_B;
    int result_example_B =   processTask_2020_04_A(exampleInputData_valid, validPassportsExample_B);

    if(result_example_B != 4)
    {
        cout<<"task 2020 04 Example valid failed! Incorrect passport count. Obtained result:"<<result_example_B<<endl;
        return false;    
    }

    result_example_B = processTask_2020_04_B(validPassportsExample_B);

    if(!testTask_2020_04_B_example_valid(result_example_B))
    {
        cout<<"task 2020 04 Example valid failed! Obtained result:"<<result_example_B<<endl;
        return false;
    }

    //
    std::vector<task2020_04_passport> invalidPassportsExample_B;
    result_example_B =   processTask_2020_04_A(exampleInputData_invalid, invalidPassportsExample_B);

    if(result_example_B != 4)
    {
        cout<<"task 2020 04 Example invalid failed! Incorrect passport count. Obtained result:"<<result_example_B<<endl;
        return false;    
    }

    result_example_B = processTask_2020_04_B(invalidPassportsExample_B);

    if(!testTask_2020_04_B_example_invalid(result_example_B))
    {
        cout<<"task 2020 04 Example invalid failed! Obtained result:"<<result_example_B<<endl;
        return false;
    }


    int result_B = processTask_2020_04_B(validPassports);

    cout<<"Task 2020 04 B result: "<<result_B<<endl; 

    if(!testTask_2020_04_B(result_B))
    {
        cout<<"task 2020 04 B failed!"<<endl;
        return false;
    }

    return true;
}

bool task_2020_05()
{
    std::vector<std::string> inputData;
    string filePath = "input_2020_Task_05.txt";
    if(!readLinesFromFileToVector(inputData, filePath))
    {
        cout<<"Error reading file: "<<filePath<<endl;
        return false;
    }

    if(!testReadingFileForTask_2020_05(inputData))
    {
        cout<<"File reading test failed!"<<endl;
        return false;
    }

        if(!test_calculateCol())
    {
        cout<<"test_calculateCol failed!"<<endl;    
        return false;

    }

    if(!test_calculateRow())
    {
        cout<<"test_calculateRow failed!"<<endl;    
        return false;

    }



    if(!test_calculateSeatIdFromString())
    {
        cout<<"test_calculateSeatIdFromString failed!"<<endl;    
        return false;
    }


    int result_A = processTask_2020_05_A(inputData);

    if(!testTask_2020_05_A(result_A))
    {
        cout<<"task 2020 05 A failed! Obtained result:"<<result_A<<endl;
        return false;
    }

    cout<<"Task 2020 05 A result: "<<result_A<<endl;  


    int result_B = processTask_2020_05_B(inputData);

    if(!testTask_2020_05_B(result_B))
    {
        cout<<"task 2020 05 B failed! Obtained result:"<<result_B<<endl;
        return false;
    }

    cout<<"Task 2020 05 B result: "<<result_B<<endl; 

    return true;
}

bool task_2020_06()
{
        std::vector<std::string> inputData;
    string filePath = "input_2020_Task_06.txt";
    if(!readLinesFromFileToVector(inputData, filePath))
    {
        cout<<"Error reading file: "<<filePath<<endl;
        return false;
    }

        if(!testReadingFileForTask_2020_06(inputData))
    {
        cout<<"File reading test failed!"<<endl;
        return false;
    }

    if(!test_getSumOfPositiveAnswersForGroup())
    {
            cout<<"test_getSumOfPositiveAnswersForGroup failed!"<<endl;    
        return false;
    }

////example
        std::vector<std::string> exampleInputData;
    string exampleFilePath = "input_2020_Task_06_example_A.txt";
    if(!readLinesFromFileToVector(exampleInputData, exampleFilePath))
    {
        cout<<"Error reading file: "<<exampleFilePath<<endl;
        return false;
    }

            int result_example_A = processTask_2020_06_A(exampleInputData);
    if(!testTask_2020_06_A_example(result_example_A))
    {
        cout<<"task 2020 06 example A failed! Obtained result:"<<result_example_A<<endl;
        return false;
    }
///



            int result_A = processTask_2020_06_A(inputData);

    if(!testTask_2020_06_A(result_A))
    {
        cout<<"task 2020 06 A failed! Obtained result:"<<result_A<<endl;
        return false;
    }

    cout<<"Task 2020 05 A result: "<<result_A<<endl;  

            int result_B = processTask_2020_06_B(inputData);

    if(!testTask_2020_06_B(result_B))
    {
        cout<<"task 2020 06 B failed! Obtained result:"<<result_B<<endl;
        return false;
    }

    cout<<"Task 2020 06 B result: "<<result_B<<endl; 

    return true;
}

int main()
{
    cout<<"Advent of Code"<<endl;

    //test general functions
    if(!test_splitString())
    {
        cout<<"split string test failed !"<<endl;
        return 0;
    }


    if(!test_trimWhitespace())
    {
        cout<<"trim whitespace test failed !"<<endl;
        return 0;
    }

    //

    task_2020_01();
    task_2020_02();
    task_2020_03();
    task_2020_04();
    task_2020_05();
    task_2020_06();


    cout<<"End"<<endl;

    return 0;
}