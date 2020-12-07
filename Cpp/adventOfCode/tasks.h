#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;



///////////////////////////////////////TASK 2020 01////////////////////////////////////////////////////////
bool testReadingFileForTask_2020_01(std::vector<string>& inputData);
bool testTask_2020_01_A(int result);
bool testTask_2020_01_B(int result);
int processTask_2020_01_A(std::vector<std::string> inputData);
int processTask_2020_01_B(std::vector<std::string> inputData);

///////////////////////////////////////TASK 2020 02////////////////////////////////////////////////////////
bool testReadingFileForTask_2020_02(std::vector<string>& inputData);
bool testTask_2020_02_A(int result);
bool testTask_2020_02_B(int result);
int processTask_2020_02_A(std::vector<string> inputData);
int processTask_2020_02_B(std::vector<string> inputData);

struct task2020_02_record
{
    int a;
    int b;
    string letter;
    string password;
};

task2020_02_record convertRowToRecord(string row);
bool test_convertRowToRecord();

///////////////////////////////////////TASK 2020 03////////////////////////////////////////////////////////
bool testReadingFileForTask_2020_03(std::vector<string>& inputData);
bool testTask_2020_03_A(int result);
bool testTask_2020_03_B(int result);
int processTask_2020_03_A(std::vector<string> inputData);
int processTask_2020_03_B(std::vector<string> inputData);
