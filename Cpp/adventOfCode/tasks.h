#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <utility>
#include <cctype>

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

///////////////////////////////////////TASK 2020 04////////////////////////////////////////////////////////
bool testReadingFileForTask_2020_04(std::vector<string>& inputData);
bool testTask_2020_04_A(int result);
bool testTask_2020_04_B(int result);
bool testTask_2020_04_A_example(int result);
bool testTask_2020_04_B_example_valid(int result);
bool testTask_2020_04_B_example_invalid(int result);



struct task2020_04_passport
{
    string content;
    std::vector<std::pair<string,string>> fields;
    string byr, iyr, eyr, hgt; 
    string  hcl, ecl, pid;
};
bool test_getListOfPassports();
bool test_fillOutFields();

int processTask_2020_04_A(std::vector<std::string>& inputData, std::vector<task2020_04_passport>& validPassports);

int processTask_2020_04_B( std::vector<task2020_04_passport>& validPassports);