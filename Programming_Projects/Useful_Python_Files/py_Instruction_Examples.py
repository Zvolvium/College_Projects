
def Syntax():
  '''
  In Python there are no '{}' or ';' for line / function ending,
    - All cases covered by ':' colon for the following:
      - functions, 'for' and 'while' loops, classes, etc...

  Since there are no line-enders, indentation is KING instead of '{}' and ';'
    - Warning:
      - When coding in python use tabs or spaces NOT both, 
      - If used together causes compiler to get confused, as well as unwanted / unknown results.
    
    Note: semi-colons ';' can still be used for line ends but are not required (won't raise errors / warnings if used)
      EX:
        '
          x = 1;
        '
    Note 2: ';' can also be used for "code stacking" on one line (won't raise errors / warnings if used)
      EX:
        '
          x = 1; y = 5; z = 255;
        '
      - Warning:
        - When "code stacking" python doesn't like operators like 'for' loops to be stacked,
        - assume rule applies to other loops / operators as well.
  Comments:
    - Python has 2 ways to put comments in your code
       (1) Using a hashtag '#'
         - Single line comment CANNOT be used for multiple lines
       (2) Using triple single quotes
         - Examples of this is seen in this document
  '''

def Variables():
  '''
  Python is nice with variables in many ways
    - No need to declare before defining except with lists or dictionaries, MUST DECLARE BEFORE USE.
    - Variables will be auto-cast to most appropriate class
      - EX:
        '
          x = 1;       # int
          y = 1.5;     # float
          z = "1.525"; # str - no difference in use of,
          a = '1.525'; # str - single or double quotes!!
        '
  Note: User can also manually cast to desired class using appropriate operators
    - int(varName), float(varName), str(varName);
  
  Note 2: Can reassign variables from int, float, str to lists or dicts if wanted (deletes values already in place)
    ' EX:
      x = 1; y = 2; z = 3;
      x = []; y = []; z = []; # List Declaration
      x = 10; y = 20; z = 30; print(x, y, z);
    '
  '''

def ListsandDictionaries():
  '''
  Lists:
    Lists in Python are unique since they allow more than one data type at once (ie ints, floats, strings, bools, etc...),
    Lists have indexing starting at 0 and ending at n - 1; where n is the size of the list,
      EX:
        list1 = [1, 2, 3, 4, 5, 5]; # -----------------------------> Duplicate items are allowed <-----------------------------
        # List has size = 5, but indexing only from 0-4
        # Since 'list[0] = 1' and 'list[4] = 5'

    To define a list the use of square brackets is nessesary '[' and ']'
      EX:
      '
        list1 = []; # Defines an empty list w/ name 'list1'
      '

    Data type EX:
      '
        list1 = ["string", 5, 3.1415, True]; # Defines a non-empty list w/ multiple data types
      '

    There are many methods within the List data structure that are quite useful,
    Here are a few commonly known ones:
      append(item) - adds 'item' to end of the list
      insert(index, item) - adds 'item' before a given 'index'
      pop(index) - removes 'item' at desired 'index' (set default is value at end of list)
      remove(item) - removes the first occurance of said 'item'

  Dictionaries:
    Dictionaries are very simular to lists except that they have no default indexing,
    You define the indexing instead,

    To define a dictionary the use of curly brackets is nessesary '{' and '}'
      EX:
      '
        dict1 = {}; # Defines an empty dictionary w/ name 'dict1'
      '
    Dictionaries store data in 'key:value' pairs, and duplicates are not allowed,
    Any data types can be used just like lists
      EX:
      '
        # Format: key = "name"; value = "Age"
        dict1 = {
          "Tom": 55, "Jean": 100, "Phil": 2
        };

        # The above dictionary also can be seem as:
        dict1 = { "Tom": 55, "Jean": 100, "Phil": 2 };
      '
    You can add to an existing dictionary by just defining the new key and value pair
      EX:
      '
        Existing Dict: dict1 = { "Tom": 55, "Jean": 100, "Phil": 2 };

        # New pair: "Montgomery": 500
        dict1["Montgomery"] = 500;        # Adds to dictionary

        Appended Dict: dict1 = { "Tom": 55, "Jean": 100, "Phil": 2, "Montgomery": 500 };
      '
    Common Methods:
      items() - returns a set of all 'items' in dict
      keys() - returns a set of all 'keys' in dict
      values() - returns a set of all 'values' in dict
  '''

def Loops():
  '''
  'in' operator is very useful, used in most loops in some way

  ' For loop EX:
    for varName in Object:
      # Do something 
    # After loop
  '
  ' While loop EX:
    while ( x in Object):
      # Do something in loop
    # After loop
  '
  'range' operator
    - Used mainly for 'for' loops as a way of indexing / iteration
    - Has 3 possible inputs: 1) start, 2) stop, 3) 'Guess last one'
    ' Range EX:
      for x in range(startVal, endVal, increment):
        # Do something
      # After loop
    '

  '''

def Print_ex():
  '''
  # All 3 versions print the same string
  
  x = 10; y = 28;
  
  print(); # print statements have an implied '\n' newline char at end of input.

  print("--- The mighty koala lives", x, "years in Sandiego Zoo with his", y, "siblings.\n");

  print("--- The mighty koala lives " + str(x) + " years in Sandiego Zoo with his " + str(y) + " siblings.\n");

  print("--- The mighty koala lives {0} years in Sandiego Zoo with his {1} siblings.\n".format(x, y));

  '''

#Print_ex();