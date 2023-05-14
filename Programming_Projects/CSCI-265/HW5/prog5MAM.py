"""
    File Name: prog4MAM.py

    Python Version: 3.11.0

    Author: Mason A. Motschke

    Contact: mason.motschke@und.edu

    Comment:
        These programs will store a collection of parts and their prices.
        Prices can be updated.
        Parts can be removed from the collection.
        You will need to write several functions/methods which report various information about the collection.
"""

def addPart (parts, part, cost):
    # boolean addPart (HashMap <String, Double> parts, String part, double cost)
    # bool addPart (unordered_map <string, double>& parts, string part, double cost)
    # def addPart (parts, part, cost)
    # 
    # Ensures that the specified part/cost key/value pair is in the data structure.
    # Returns a true value if the pair is a new pair/added to the data structure.
    # Returns a false value if the pair is not new, with the cost being updated.
    keys = list(parts.keys());
    newKey = part.lower();
    
    if (newKey in keys):
        parts[newKey] = float(cost);
        return False;
    else:
        parts[newKey] = float(cost);
        return True;

def averagePrice (parts):
    # double averagePrice (HashMap <String, Double> parts)
    # double averagePrice (unordered_map <string, double> parts)
    # def averagePrice (parts)
    # 
    # Returns the average of all parts in the dictionary.
    # Return -1 if you are unable to determine the average.
    keys = list(parts.keys());
    length = len(keys);
    av = 0;
    
    if (length == 0):
        return -1;
    else:
        try:
            for key in keys:
                av += parts[key];
                
            av = av / length;
            return av;
        except:
            return -1;

def isPart (parts, part):
    # boolean isPart (HashMap <String, Double> parts, String part)
    # bool isPart (unordered_map <string, double> parts, string part)
    # def isPart (parts, part)
    # 
    # Returns a true value if part is a valid part in data structure, otherwise return a false value.
    # The case of the parts should not matter.
    keys = list(parts.keys());
    
    if (part.lower() in keys):
        return True;
    else:
        return False;

def leastExpensivePart (parts):
    # String leastExpensivePart (HashMap <String, Double> parts)
    # string leastExpensivePart (unordered_map <string, double> parts)
    # def leastExpensivePart (parts):
    # 
    # Returns the part name with the least expensive price.
    # You can assume that there will be only one part with the least expensive price.
    keys = list(parts.keys());
    least = None;
    
    for key in keys:
        if ( (least == None) or (parts[key] < parts[least]) ):
            least = key;
    
    return least;

def mostExpensivePart (parts):
    # String mostExpensivePart (HashMap <String, Double> parts)
    # string mostExpensivePart (unordered_map <string, double> parts)
    # def mostExpensivePart (parts):
    # 
    # Returns the part name with the most expensive price.
    # You can assume that there will be only one part with the most expensive price.
    keys = list(parts.keys());
    most = None;
    
    for key in keys:
        if ( (most == None) or (parts[key] > parts[most]) ):
            most = key;
    
    return most;

def partsGreaterThan (parts, upperLimit):
    # ArrayList<String> partsGreaterThan (HashMap <String, Double> parts, double upperLimit)
    # vector<string> partsGreaterThan (unordered_map <string, double> parts, double upperLimit)
    # def partsGreaterThan (parts, upperLimit):
    # 
    # Returns a list/array of the part names with a price greater than or equal to the upperLimit variable.
    # The list should be created in the function.
    keys = list(parts.keys());
    res = [];
    
    for key in keys:
        if (parts[key] >= upperLimit):
            res.append(key);
    
    return res;

def printParts (parts):
    # void printParts (HashMap <String, Double> parts)
    # void printParts (unordered_map <string, double> parts)
    # def printParts (parts)
    # 
    # This function WILL write to the display a table of each part and its price.
    # Include column headers in the output.
    # Make sure the price has two places after the decimal point.
    # Also make sure the columns are neatly aligned,
    #  - with the part column being left justified and the price column being right justified.
    # This function/method should not return a value.
    
    # TODO: Finish
    keys = list(parts.keys());
    print('  Parts | Cost  ');
    print('  ------------  ');
    for key in keys:
        print(f'  {key} | {parts[key]}');
    print('  ------------  ');
    return;

def totalParts (parts):
    # int totalParts (HashMap <String, Double> parts)
    # int totalParts (unordered_map <string, double> parts)
    # def totalParts (parts):
    # 
    # Returns the number of unique parts (int) in the data structure.
    keys = list(parts.keys());
    return len(keys);

def main():
    # Define Dictionary
    parts = {};
    
    # Testing Functions
    addPart(parts, "Hammer", 15);
    addPart(parts, "Sickle", 30);
    addPart(parts, "Jack Hammer", 50);
    
    print(f'Total Parts: {totalParts(parts)}');
    print(f'Average Price: {averagePrice(parts)}');
    print(f'Least Expensive Part: {leastExpensivePart(parts)}');
    print(f'Most Expensive Part: {mostExpensivePart(parts)}');
    print(f'IS Part ~ Hammer: {isPart(parts, "Hammer")}');
    print(f'IS Part ~ Nail: {isPart(parts, "Nail")}');
    print(f'Parts Greater Than 10: {partsGreaterThan(parts, 10)}');
    print(f'Parts Greater Than 20: {partsGreaterThan(parts, 20)}');
    print(f'Parts Greater Than 40: {partsGreaterThan(parts, 40)}');
    
    print();
    printParts(parts);
    return;

if __name__ == '__main__':
    main();
    