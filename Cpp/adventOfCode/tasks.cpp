#include "tasks.h"
#include "helpers.h"

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


///////////////////////////////////////TASK 2020 03////////////////////////////////////////////////////////
bool testReadingFileForTask_2020_03(std::vector<string>& inputData)
{
    if(inputData[0] != ".............#...#....#.....##." || inputData[1] != ".#...##.........#.#.........#.#" || inputData[inputData.size()-1] != ".#...##..##.#.........#.##...#.")
    {
        return false;
    }

    return true;
}

bool testTask_2020_03_A(int result)
{
    return result == 167;
}

bool testTask_2020_03_B(int result)
{
    return result == 736527114;
}

int calculateTreesOnPath(std::vector<std::string> inputData, int startX, int startY, int dX, int dY)
{
    int treeCount = 0;

    unsigned int currentRow = 0;
    unsigned int currentCol = 0;

    while(currentRow < inputData.size())
    {
        if(inputData[currentRow][currentCol] == '#')
        {
            treeCount+=1;
        }

        currentCol = (currentCol + dX) % inputData[currentRow].length();
        currentRow+=dY;
    }

    return treeCount;
}

int processTask_2020_03_A(std::vector<std::string> inputData)
{
    int result = 0;

    result = calculateTreesOnPath(inputData, 0,0, 3,1);

    return result;
}

int processTask_2020_03_B(std::vector<std::string> inputData)
{
    int result = 0;

    result = calculateTreesOnPath(inputData, 0,0,  1,1);
    result *= calculateTreesOnPath(inputData, 0,0, 3,1);
    result *= calculateTreesOnPath(inputData, 0,0, 5,1);
    result *= calculateTreesOnPath(inputData, 0,0, 7,1);
    result *= calculateTreesOnPath(inputData, 0,0, 1,2);


    return result;
}

///////////////////////////////////////TASK 2020 04////////////////////////////////////////////////////////
bool testReadingFileForTask_2020_04(std::vector<string>& inputData)
{
    if(inputData[0] != "byr:1971" || inputData[1] != "ecl:hzl pid:112040163" || inputData[2] != "eyr:2023 iyr:2019" || inputData[3] != "hcl:#b6652a hgt:167cm" 
        || inputData[4] != ""
        || inputData[5] != "pid:108667812 eyr:2023 hcl:#623a2f hgt:171cm iyr:2018 ecl:amb byr:1993"
        || inputData[6] != ""
        || inputData[7] != "hcl:#cfa07d iyr:2014 ecl:blu eyr:2023 cid:304 hgt:70in byr:1961"
        || inputData[8] != ""
        || inputData[inputData.size()-1] != "iyr:2017 ecl:blu byr:1942 hcl:#733820 eyr:2023 hgt:151cm pid:289923625")
    {
        return false;
    }

    return true;
}

bool testTask_2020_04_A(int result)
{
    return result == 192;
}

bool testTask_2020_04_A_example(int result)
{
    return result == 2;
}

bool testTask_2020_04_B(int result)
{
    return result == 101;
}

bool testTask_2020_04_B_example_valid(int result)
{
    return result == 4;
}

bool testTask_2020_04_B_example_invalid(int result)
{
    return result == 0;
}


void getListOfPassports(std::vector<std::string>& inputData, std::vector<task2020_04_passport>& passports)
{

    bool readingPassport = false;

    task2020_04_passport currentPassport;

    for(std::vector<std::string>::iterator line = inputData.begin(); line != inputData.end(); line++)
    {
        if(*line != "")
        {
            if(!readingPassport)
            {
                readingPassport = true;
            }

            if(readingPassport)
            {
                currentPassport.content = currentPassport.content + (*line) + " ";
            }

            if(line+1 == inputData.end() && readingPassport)
            {
                //last line in file
                currentPassport.content = trimWhitespace( currentPassport.content);
                passports.push_back(currentPassport);
            }

            continue;
        }

        if(*line == "")
        {
            if(readingPassport)
            {
                currentPassport.content = trimWhitespace( currentPassport.content);
                passports.push_back(currentPassport);
                readingPassport = false;
                currentPassport.content = "";
                continue;
            }
        }

    }

}

bool test_getListOfPassports()
{
    std::vector<std::string> inputData;

    inputData.push_back("byr:1971");
    inputData.push_back("ecl:hzl pid:112040163");
    inputData.push_back("eyr:2023 iyr:2019");
    inputData.push_back("hcl:#b6652a hgt:167cm");
    inputData.push_back("");
    inputData.push_back("pid:108667812 eyr:2023 hcl:#623a2f hgt:171cm iyr:2018 ecl:amb byr:1993");
    inputData.push_back("");

    std::vector<task2020_04_passport> passports;

    getListOfPassports(inputData, passports);

    if(passports[0].content != "byr:1971 ecl:hzl pid:112040163 eyr:2023 iyr:2019 hcl:#b6652a hgt:167cm")
    {
        cout<<"test_getListOfPassports failed! Content: "<<passports[0].content<<"^^"<<endl;
        return false;
    }

    if(passports[1].content != "pid:108667812 eyr:2023 hcl:#623a2f hgt:171cm iyr:2018 ecl:amb byr:1993")
    {
        cout<<"test_getListOfPassports failed! Content: "<<passports[1].content<<"^^"<<endl;
        return false;
    }

    return true;
}

void fillOutFields(task2020_04_passport& passport)
{
    string text = passport.content;
    std::vector<string> pairsAsStrings;
    splitString(text, pairsAsStrings, ' ');

    for(std::vector<string>::iterator i = pairsAsStrings.begin(); i != pairsAsStrings.end(); i++)
    {
        std::vector<string> keyVal;

        splitString((*i), keyVal, ':');

        passport.fields.push_back(std::make_pair(keyVal[0], keyVal[1]));

        if(keyVal[0] == "byr") {passport.byr = keyVal[1]; continue; }
        if(keyVal[0] == "iyr") {passport.iyr = keyVal[1]; continue; }
        if(keyVal[0] == "eyr") {passport.eyr = keyVal[1]; continue; }
        if(keyVal[0] == "hgt") 
        {
            passport.hgt = keyVal[1];
            //passport.hgtUnit = keyVal[1].substr(keyVal[1].length()-2, keyVal[1].length()-1);

            //string heightValAsStr = keyVal[1].substr(0, keyVal[1].length()-2);

            //passport.hgtVal = std::stoi(heightValAsStr);
        }
        if(keyVal[0] == "hcl") passport.hcl = keyVal[1];
        if(keyVal[0] == "ecl") passport.ecl = keyVal[1];
        if(keyVal[0] == "pid") passport.pid = keyVal[1];

    }
}

bool test_fillOutFields()
{
    task2020_04_passport passport;
    passport.content = "byr:1971 pid:112040163 hcl:#b6652a hgt:167cm";

    fillOutFields(passport);

    if(passport.fields.size() == 4 && passport.fields[0].first == "byr" && passport.fields[0].second == "1971" && passport.fields[1].first == "pid" && passport.fields[1].second == "112040163"
        && passport.fields[2].first == "hcl" && passport.fields[2].second == "#b6652a"
        )
    {
        return true;
    }

    return false;
}

int processTask_2020_04_A(std::vector<std::string>& inputData, std::vector<task2020_04_passport>& validPassports)
{
    int result = 0;


    std::vector<task2020_04_passport> passports;
    getListOfPassports(inputData, passports);

    for(std::vector<task2020_04_passport>::iterator passport = passports.begin(); passport != passports.end(); passport++)
    {
        fillOutFields(*passport);
    }

    for(std::vector<task2020_04_passport>::iterator passport = passports.begin(); passport != passports.end(); passport++)
    {
        if((*passport).fields.size() == 8)
        {
            result++;
                validPassports.push_back(*passport);

            continue;
        }

        if((*passport).fields.size() == 7)
        {
            bool cidFound = false;

            for(auto field = (*passport).fields.begin(); field != (*passport).fields.end(); field++ )
            {
                if((*field).first == "cid") 
                {
                    cidFound = true;
                    break;
                }
            }

            if( !cidFound )
            {
                result++;
                validPassports.push_back(*passport);
            }
        }

    }

    return result;
}

bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

bool validatePassport(task2020_04_passport& passport)
{
    try{
        if(std::stoi(passport.byr) < 1920 || std::stoi(passport.byr) > 2002) {
            return false;
        }
        if(std::stoi(passport.iyr) < 2010 || std::stoi(passport.iyr) > 2020) 
        {return false;}
        if(std::stoi(passport.eyr) <2020 || std::stoi(passport.eyr) > 2030) {
            return false;
        }

        if(passport.hgt.find("cm") !=std::string::npos )
        {
            int cmPos = passport.hgt.find("cm");
            string hgtVal = passport.hgt.substr(0, cmPos);

            if(std::stoi(hgtVal)<150 || std::stoi(hgtVal) > 193)  
                {
                    return false;
            }
        }
        else if(passport.hgt.find("in") !=std::string::npos)
        {
            int inPos = passport.hgt.find("in");
            string hgtVal = passport.hgt.substr(0, inPos);
            if(std::stoi(hgtVal)<59 || std::stoi(hgtVal) > 76)  
                {
                    return false;
            }
        }
        
        if(passport.hgt.find("cm") == std::string::npos && passport.hgt.find("in") == std::string::npos) 
        {return false;}


        if(passport.hcl.length() != 7) {
            return false;
        }
        else if(passport.hcl[0] != '#') {
            return false;
        }
        else
        {

            for(unsigned int i=1; i< passport.hcl.length(); i++)
            {
                if(passport.hcl[i] <48) {
                    return false;
                } 
                else if( passport.hcl[i] >57 && passport.hcl[i] <97) {

                    return false;
                } 
                else if( passport.hcl[i] >102) {

                    return false;
                }
                else
                {
                }
            }
        }

        if(passport.ecl !=  "amb" && passport.ecl != "blu" && passport.ecl != "brn" && passport.ecl != "gry" && passport.ecl != "grn" && passport.ecl != "hzl" && passport.ecl != "oth")
        {return false;}
        else
        {
        }

        if(passport.pid.length() != 9)
        {return false;} 
        else 
        {
        } 
        if(!is_number(passport.pid))
        {
            return false;
        }

    }
    catch (...)
    {
        return false;
    }

    return true;

}

int processTask_2020_04_B( std::vector<task2020_04_passport>& passports)
{
    int result = 0;

    for(std::vector<task2020_04_passport>::iterator passport = passports.begin(); passport != passports.end(); passport++)
    {
        if(validatePassport(*passport))
        {
            result++;
        }
    }

    return result;
}