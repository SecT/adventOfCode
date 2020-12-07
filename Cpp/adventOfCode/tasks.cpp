#include "tasks.h"

///////////////////////////////////////TASK 2020 01////////////////////////////////////////////////////////

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


///////////////////////////////////////TASK 2020 02////////////////////////////////////////////////////////

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

bool testTask_2020_02_B(int result)
{
    return result == 428;
}

int processTask_2020_02_A(std::vector<std::string> inputData)
{
    int result = 0;

    int invalidPasswordCount = 0;

    for (std::vector<string>::iterator i = inputData.begin(); i != inputData.end(); ++i)
    {
        string row = *i;

        task2020_02_record record = convertRowToRecord(row);

        char letterToCount;
        letterToCount = record.letter.c_str()[0];

        int letterCount = std::count(record.password.begin(), record.password.end(), letterToCount);

        if ( letterCount < record.a || letterCount > record.b)
        {
            invalidPasswordCount++;

            //cout<<"Invalid! row:"<<row<<" a:"<<record.a<<" b:"<<record.b<<" letter:"<<record.letter<<" pass:"<<record.password<<"^^"<<endl;
        }
    }
    cout<<"Size:"<<inputData.size()<<endl;
    return inputData.size() - invalidPasswordCount;
}

int processTask_2020_02_B(std::vector<std::string> inputData)
{
    int result = 0;

    int invalidPasswordCount = 0;

    for (std::vector<string>::iterator i = inputData.begin(); i != inputData.end(); ++i)
    {
        string row = *i;

        task2020_02_record record = convertRowToRecord(row);

        if(!( (record.password[record.a-1] == record.letter[0]) ^ (record.password[record.b-1] == record.letter[0])))
        {
            invalidPasswordCount++;
        }

    }
    cout<<"Size:"<<inputData.size()<<endl;
    return inputData.size() - invalidPasswordCount;
}


void splitString(string input, std::vector<string>& output, char delim)
{
    std::stringstream ss(input);
    std::string token;
    while (std::getline(ss, token, delim)) {
        output.push_back(token);
    }
}

string leftTrimWhitespace(string input)
{
    string output = input.substr(input.find_first_not_of(" "), string::npos);

    return output;
}

string rightTrimWhitespace(string input)
{
    string  output = input.substr(0,input.find_last_of(" "));

    return output;
}

string trimWhitespace(string input)
{
    string output = leftTrimWhitespace(input);
    output = rightTrimWhitespace(output);

    return output;
}

bool test_trimWhitespace()
{
    bool result = false;

    string output = trimWhitespace("abc ");
    string output1 = trimWhitespace(" abc");

    result = (output == "abc") && (output1 == "abc");

    if(!result)
    {
        cout<<"test_trimWhitespace failed. output:"<<output<<"^^ output1:"<<output1<<"^^"<<endl;
    }

    return result;
}

bool test_splitString()
{
    std::vector<string> result;
    splitString("abc:def", result, ':');

    std::vector<string> result0;
    splitString("abc def", result0, ' ');

    std::vector<string> result1;
    splitString("abc-def", result1, '-');

    return (result[0] == "abc" && result[1] == "def") && (result0[0] == "abc" && result0[1] == "def") && (result1[0] == "abc" && result1[1] == "def");
}

task2020_02_record convertRowToRecord(string row)
{
    task2020_02_record record;

    std::vector<string> tokens;
    splitString(row, tokens, ':');

    record.password = trimWhitespace(tokens[1]);


    string modifiedRow;
    int pos = row.find(":");
    modifiedRow = row.substr(0,pos);


    std::vector<string> policyTokens;
    splitString(modifiedRow, policyTokens, ' ');

    record.letter = policyTokens[1];


    std::vector<string> rangeTokens;
    splitString(modifiedRow, rangeTokens, '-');

    record.a = std::stoi(rangeTokens[0]);
    record.b = std::stoi(rangeTokens[1]);

    return record;
}

bool test_convertRowToRecord()
{
    task2020_02_record record = convertRowToRecord("4-7 z: zzzfzlzzz");

    bool result = ( record.a == 4 && record.b == 7 && record.letter == "z" && record.password == "zzzfzlzzz");

    if(!result)
    {
        cout<<"test_convertRowToRecord  record.a:"<<record.a<<" record.b:"<<record.b<<" record.letter:"<<record.letter<<" record.password:"<<record.password<<"^^"<<endl;
    }

    return result;
}