

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

def processB(input):
    a = 0
    b = 0
    c = 0

    wantedTotal = 2020

    for i in input[1:]:
        for j in input:
            for k in input:
                if i+j+k == wantedTotal:
                    return i,j,k

    return a,b,c

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
        print("Result A a=%d,b=%d  Product: %d" % (a,b, a*b))

        a,b,c = processB(data)
        print("Result B a=%d,b=%d,c=%d  Product: %d" % (a,b,c, a*b*c))


    print("Task End")