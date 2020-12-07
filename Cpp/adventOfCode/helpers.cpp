#include "helpers.h"
#include <sstream>

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