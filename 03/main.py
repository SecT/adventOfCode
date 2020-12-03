

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


def testReadInput(readInput):
    
    if data[0] != ".............#...#....#.....##." or data[1] != ".#...##.........#.#.........#.#" or data[-1] != ".#...##..##.#.........#.##...#.":
        print("-"+data[0]+"-")
        print("-"+data[1]+"-")
        print("-"+data[-1]+"-")
        return False

    return True

def countTressForStartingPosAndVector(input, startX, startY, divX, divY):

    currX = startX
    currY = startY
    
    rowLength = len(input[0])
    colLength = len(input)
    
    count = 0
    
    currentRow = 0
    
    while currY < colLength:
        row = input[currY]
        if row[currX % rowLength] == '#':
            count = count + 1
        
        currX = currX + divX
        currY = currY + divY
        
        
    return count

def processA(input):

    return countTressForStartingPosAndVector(input, 0,0,  3, 1)

def processB(input):

    count = [0]*5

    count[0] = countTressForStartingPosAndVector(input, 0,0, 1,1)
    count[1] = countTressForStartingPosAndVector(input, 0,0, 3,1)
    count[2] = countTressForStartingPosAndVector(input, 0,0, 5,1)
    count[3] = countTressForStartingPosAndVector(input, 0,0, 7,1)
    count[4] = countTressForStartingPosAndVector(input, 0,0, 1,2)

    output = 1
    for i in count:
        output = i * output

    return output

def testProcessA(input):
    if processA(input) != 167:
        return False
    return True

def testExampleInput(input):

    if processB(input) != 336:
        print(processB(input))
        return False
    return True

######################
if __name__ == '__main__':
    print("Task")
    
    data = readInputFile("input.txt")
    data = stripAllElementsInList(data)

    testData = readInputFile("inputTest.txt")
    testData = stripAllElementsInList(testData)
               
    #test if input reading is correct
    if not testReadInput(data):
        print("Incorrect input!!")
    #elif not testConvertPolicyIntoRangeAndLetterFromInputList(data):
    #    print("Tests failed!!")
    else:
        #data = splitRowsIntoPolicyAndPassword(data)

        a = processA(data)
        print("Result A count=%d" % a)

        if not testProcessA(data):
            print("Incorrect value from task A!!")

        print("Test example data")
        if not testExampleInput(testData):
            print("Incorrect value for example data!!")
        print("End test example data")

        a = processB(data)
        print("Result B count=%d" % a)



    print("Task End")