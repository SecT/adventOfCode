

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
    
    if data[0] != 1686 or data[1] != 1337 or data[-1] != 1862:
        print("-"+data[0]+"-")
        print("-"+data[1]+"-")
        print("-"+data[-1]+"-")
        return False

    return True

def process(input):

    a = 0
    b = 0

    wantedTotal = 2020

    for i in input[1:]:
        for j in input:
            if i+j == wantedTotal:
                return i,j
                
    return a,b

######################
if __name__ == '__main__':
    print("Task")
    
    data = readInputFile("input.txt")
    data = stripAllElementsInList(data)
    data = convertAllStringsInListToInt(data)

    #test if input reading is correct
    if not testReadInput(data):
        print("Incorrect input!!")
    else:
        a,b = process(data)
        print("Result a=%d,b=%d  Product: %d" % (a,b, a*b))


    print("Task End")