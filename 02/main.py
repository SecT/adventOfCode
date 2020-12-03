

def readInputFile(filename):
    
    try:
        with open(filename) as f:
            
            fileContent = f.readlines()

    except OSError as e:
        print('Exception: '+ e)

    return fileContent

def stripAllElementsInList(input):
    
    output = []

    for i in input:
        output.append(i.strip())

    return output

def convertAllStringsInListToInt(input):
    output = []

    for i in input:
        output.append(int(i))

    return output  

def testReadInput(readInput):
    
    if data[0] != "4-7 z: zzzfzlzzz" or data[1] != "3-4 l: blllk" or data[-1] != "12-20 t: ttttttltttvttttttttt":
        print("-"+data[0]+"-")
        print("-"+data[1]+"-")
        print("-"+data[-1]+"-")
        return False

    return True

def splitRowsIntoPolicyAndPassword(inputList):
    outputList = []

    for el in inputList:
        modifiedElement = el.split(":")
        
        modifiedElement[0] = modifiedElement[0].strip()
        modifiedElement[1] = modifiedElement[1].strip()

        outputList.append(modifiedElement)

    return outputList

def splitPolicyIntoRangeAndLetter(policy):
    minCount = 0
    maxCount = 0
    symbol = ""

    range, symbol = policy.split(" ")
    minCount, maxCount =  range.split("-")
    
    return [int(minCount), int(maxCount), symbol]

def testConvertPolicyIntoRangeAndLetterFromInputList(input):

    policies = splitRowsIntoPolicyAndPassword(input)
    
    #testCase 1
    minCount, maxCount, symbol = splitPolicyIntoRangeAndLetter(policies[0][0])
    if minCount != 4 or maxCount != 7 or symbol != 'z':
        print("Case 1 Failed")
        return False

    #testCase 2
    minCount, maxCount, symbol = splitPolicyIntoRangeAndLetter(policies[1][0])
    if minCount != 3 or maxCount != 4 or symbol != 'l':
        print("Case 2 Failed")
        return False

    #testCase 3
    minCount, maxCount, symbol = splitPolicyIntoRangeAndLetter(policies[-1][0])
    if minCount != 12 or maxCount != 20 or symbol != 't':
        print("Case 3 Failed")
        return False

    return True

def processA(input):

    invalidPasswordsCount = 0

    for policy, password in input:
        min, max, letter = splitPolicyIntoRangeAndLetter(policy)
        
        letterCount = password.count(letter)

        if letterCount < min or letterCount > max:
            invalidPasswordsCount = invalidPasswordsCount + 1
            #print ("Invalid password: {0} according to policy: {1}-{2} {3}".format(password, min, max, letter))


    return len(input) - invalidPasswordsCount

def processB(input):

    invalidPasswordsCount = 0

    for policy, password in input:
        firstPos, secondPos, letter = splitPolicyIntoRangeAndLetter(policy)

        if (password[firstPos-1] == letter and password[secondPos-1] == letter) or (password[firstPos-1] != letter and password[secondPos-1] != letter):
            invalidPasswordsCount = invalidPasswordsCount + 1

    return len(input) - invalidPasswordsCount


######################
if __name__ == '__main__':
    print("Task")
    
    data = readInputFile("input.txt")
    data = stripAllElementsInList(data)

    #test if input reading is correct
    if not testReadInput(data):
        print("Incorrect input!!")
    elif not testConvertPolicyIntoRangeAndLetterFromInputList(data):
        print("Tests failed!!")
    else:
        data = splitRowsIntoPolicyAndPassword(data)

        a = processA(data)
        print("Result A count=%d" % a)

        a = processB(data)
        print("Result B count=%d" % a)



    print("Task End")