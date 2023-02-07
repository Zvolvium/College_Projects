"""
    File Name: prog2MAM.py

    Python Version: 3.11.0

    Author: Mason A. Motschke

    Contact: mason.motschke@und.edu

    Comment:
        Write each of the following programs in C, C++, Python, and Java.
        Write a program that surveys the majors of students in some unnamed class.
        Only majors I’m concerned with are Computer Science, Data Science, and Cyber Security.
        For only the CS majors we want to ask about their minor. 
"""
def getMajorsAndMinors ():  # Returns a Dictionary of Majors with # of Occurances
    minors = {
        'Data' : 0, 'Cyber' : 0, 'Math' : 0, 'Other' : 0
    };
    majors = {
        'CS' : [0, minors], 'Data' : 0, 'Cyber' : 0, 'Other' : 0
    };

    next = input("Enter a Major('Done to quit'): ");
    while (next.lower() != "Done".lower()):
        if (next.lower() == 'CS'.lower()):
            majors['CS'][0] += 1;
            majors['CS'][1] = getMinors(majors['CS'][1]);
        elif (next.lower() == 'Data'.lower()):
            majors['Data'] += 1;
        elif (next.lower() == 'Cyber'.lower()):
            majors['Cyber'] += 1;
        else:
            majors['Other'] += 1;
        next = input("\nEnter a Major('Done to quit'): ");
    return majors;

def getMinors (currMinors):  # Returns Dictionary of Updated Minor(s) Data
    nextMinor = input("Enter your Minor: ");
    if (nextMinor.lower() == 'Data'.lower()):
        currMinors['Data'] += 1;
    elif (nextMinor.lower() == 'Cyber'.lower()):
        currMinors['Cyber'] += 1;
    elif (nextMinor.lower() == 'Math'.lower()):
        currMinors['Math'] += 1;
    else:
        currMinors['Other'] += 1;
    return currMinors;

def getStudentNumber (data):
    keys = data.keys(); num = 0;
    for key in keys:
        if (key == 'CS'):
            num += data[key][0];
        else:
            num += data[key];
    return num;

def printData (data):
    studentNum = getStudentNumber(data);
    keys = data.keys();
    print('\n\n\nNumber of Students Surveyed: {0}'.format(studentNum));
    print("\n\nMajors of Students in the Survey:");
    for key in keys:
        if (key == 'CS'):
            print('{0:10} {1:3} {2:>10}'.format(key, data[key][0], '{:1.2f}'.format((data[key][0] / studentNum) * 100)));
        else:
            print('{0:10} {1:3} {2:>10}'.format(key, data[key], '{:1.2f}'.format((data[key] / studentNum) * 100)));

    print("\n\nMinors of Computer Science Students in Survey:");
    minors = data['CS'][1]; keys = minors.keys();
    studentNum = getStudentNumber(minors);
    for key in keys:
        print('{0:10} {1:3} {2:>10}'.format(key, minors[key], '{:1.2f}'.format((minors[key] / studentNum) * 100)));
    print('\n\n');
    return;

def main ():
    data = getMajorsAndMinors();
    printData(data);
    return;

main();
