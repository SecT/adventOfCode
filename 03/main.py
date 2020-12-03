

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


def processA(input):

    count = 0

    startX = 0
    divX = 3
    currX = startX + divX
    
    rowLength = len(input[0])
    
    for row in input[1:]:
        if row[currX % rowLength] == '#':
            count = count + 1
        
        currX = currX + divX

    return count

def processB(input):

    count = 0

    return count


######################
if __name__ == '__main__':
    print("Task")
    
    data = readInputFile("input.txt")
    data = stripAllElementsInList(data)

    #test if input reading is correct
    if not testReadInput(data):
        print("Incorrect input!!")
    #elif not testConvertPolicyIntoRangeAndLetterFromInputList(data):
    #    print("Tests failed!!")
    else:
        #data = splitRowsIntoPolicyAndPassword(data)

        a = processA(data)
        print("Result A count=%d" % a)

        a = processB(data)
        print("Result B count=%d" % a)



    print("Task End")