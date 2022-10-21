# Mason Motschke - CSCI_365 - mason.motschke@und.edu
# Program 4 - Part 1

import re;
import sys;

def scanner(file):
  finalList = [];
  opCodes = {
             "<print>" : "^print",
             "<lparen>" : "^ *[(]",
             "<var>" : "^var",
             "<id>" : "^ *[a-zA-Z]+[a-zA-Z]*[0-9]*",
             "<number>" : "^ *[0-9]+\.?[0-9]*",
             "<rparen>" : "^ *[)]",
             "<assign>" : "^ *[=]",
             "<add_op>" : "^ *[+-]",
             "<mult_op>" : "^ *[*/]",
             "<error>" : "^ *[^ ()=+*/0-9a-zA-z-]"
            };
  keys = list(opCodes.keys()); #print("\nopCode Keys: {0}\n".format(keys));
  values = list(opCodes.values()); #print("opCode Values: {0}\n".format(values));

  start = 0; i = 0; cnt = 0; array = [];
  for line in file:
    i = 0; line = line.strip();
    while (i < len(values)):
      regMatch = re.search(values[i], line);
      #print("Line: {0} {2}; Match: {1};\n i: {s}; REGEX: {r}".format(line, regMatch, len(line), s = i, r = keys[i]));
      if (regMatch != None):
        start = regMatch.start(); end = regMatch.end();
        if (keys[i] == "<error>"):
          print("{error} , {txt}".format(error = keys[i], txt = line[start:end])); return finalList;
        finalList.append(keys[i]); finalList.append(',');
        for x in range(start, end): array.append(line[x]);
        #finalList.append(line[start:end]);
        array = ''.join(array); array = array.strip(); finalList.append(array);
        match = None; array = [];
        line = re.sub('.', ' ', line, end); # Below lines tells it where to start looking in very basic form ---\/
        if (keys[i] == "<print>"): i = 0;
        elif (keys[i] == "<var>"): i = 2;
        elif (keys[i] == "<id>"): i = 4;
        elif (keys[i] == "<assign>"): i = 0;
        elif (keys[i] == "<add_op>"): i = 1;
        elif (keys[i] == "<mult_op>"): i = 1;
        elif (keys[i] == "<lparen>"): i = 2;
        elif (keys[i] == "<rparen>"): i = 5;
        else: i = 0; # -----------------------------------------------------------------------------------------/\
      i += 1;
    #print(finalList);
  
  return finalList;

def Main():
  # Get command line args
  args = sys.argv; argLen = len(args);
  if (argLen < 2): exit("\n -- Error: Command Line Argument NOT Found!!\n");
  # Open file at specified name
  fileName = args[1];
  try: openFile = open(fileName, 'r');
  except FileNotFoundError: exit("\n -- Error: File '{0}' NOT Found??\n".format(fileName));

  tokens = scanner(openFile);

  print(); #print("Length of tokens: {0}\n".format(len(tokens)));
  try:
    for x in range(0, len(tokens)):
      if (tokens[x] == ','):
        print("{id} {comma} {lex}".format(id = tokens[x - 1], comma = tokens[x], lex = tokens[x + 1]));
  except IndexError:
    pass;

  openFile.close();
  return;

Main();
