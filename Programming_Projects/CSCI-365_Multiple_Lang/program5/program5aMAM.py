import sys;

class errorTok (Exception):
  # If an error Tok is found 
  def __init__(self):
    self.message = "\n -- Error: '<error>' Token Found!!!";
    print(self.message);

class wrongToken (Exception):
  def __init__(self):
    self.message = "\n -- Error: Expected Token Not Found!!!";
    print(self.message);

def main():
  # Get input file name
  args = sys.argv; argLen = len(args);
  argLen = 2;
  if (argLen < 2): exit("\n -- Error: Command Line Argument NOT Found!!\n");

  fileName = args[1];
  try: openFile = open(fileName, 'r');
  except FileNotFoundError: exit("\n -- Error: File '{0}' NOT Found??\n".format(fileName));

  fileStack = []; tokStack = []; lexStack = [];
  try:
    for line in openFile:
      line = line.split(',');
      for i in range(0, 2):
        line[i] = line[i].strip();
        fileStack.append(line[i]);
  except IndexError:
    openFile.close(); exit("\n -- Error: Problem with Input File Lines\n");
  openFile.close();

  for i in range(0, len(fileStack)):
    if (i % 2 == 0):
      tokStack.append(fileStack[i]);
    elif (i % 2 == 1):
      lexStack.append(fileStack[i]);
  fileStack = [];

  operatorStack = []; valueStack = []; tokLength = len(tokStack); variables = {}; errorFlag = 0;
  #print("\nTok Stack: {0}".format(tokStack));
  #print("Lex Stack: {0}\n".format(lexStack));
  for i in range(0, tokLength):
    if (errorFlag): break;
    if (tokStack == []):
      print(" -- Processing Finished"); break;
    elif (tokStack[0] == '<error>'):
      print("\n -- Error: Token '{tok}' Found!!!\n -- Halting Process...\n".format(tok = tokStack[0])); errorFlag = 1;
    elif ((tokStack[0] == '<var>') and (tokStack[1] == '<id>') and (tokStack[2] == '<semi>')):
      # Do Variable Declare
      #variables[lexStack[1]] = ''; # Saves Variables to Structure for Later Use
      keys = list(variables.keys()); LexId = lexStack[1];
      if (LexId in keys): pass;
      else: variables[LexId] = 0;
      for j in range(0, 3):
        tokStack.pop(0); lexStack.pop(0);
    elif ((tokStack[0] == '<print>') and (tokStack[1] == '<id>') and (tokStack[2] == '<semi>')):
      # Do Print 1
      keys = list(variables.keys()); LexId = lexStack[1];
      if (LexId in keys):
        print("{id} : {value}".format(id = LexId, value = variables[LexId]));
      else:
        print("\n -- Error: Undefined Variable '{tok}' in Print Statement\n -- Halting Process...\n".format(tok = LexId)); errorFlag = 1;
      for j in range(0, 3):
        tokStack.pop(0); lexStack.pop(0);
    elif ((tokStack[0] == '<print>') and (tokStack[1] == '<number>') and (tokStack[2] == '<semi>')):
      # Do Print 2
      print("{num}".format(num = lexStack[1]));
      for j in range(0, 3):
        tokStack.pop(0); lexStack.pop(0);
    elif ((tokStack[0] == '<id>') and (tokStack[1] == '<assign>')):
      try:
        semiIndex = tokStack.index('<semi>');
        # Check for Error tokens '<error>' between 'id' and '<semi>'
        for j in range(0, semiIndex):
          if (tokStack[j] == '<error>'): errorFlag = 1;
        if (errorFlag): raise errorTok;

        keys = list(variables.keys()); LexId = lexStack[0];
        if (LexId in keys): pass;
        else: variables[LexId] = 0;
        
        # Do Expression -----------------------------------\/
        # Fill operator and value stacks
        precedence = {
          '*':5, '/':5,'-':3,'+':3
        };
        expressionLex = []; expressionTok = [];
        for j in range(2, semiIndex):
          expressionLex.append(lexStack[j]); expressionTok.append(tokStack[j]);
        #print('Hell', expressionLex, expressionTok, variables);
        size = len(expressionTok);
        for j in range(0, size):
          #valueStack = [];
          if ((expressionTok[j] == '<id>') or (expressionTok[j] == '<number>')):
            valueStack.append(expressionLex[j]);
          if ((expressionTok[j] == '<add_op>') or (expressionTok[j] == '<mult_op>')):
            #print(precedence[expressionLex[j]]);
            if (operatorStack == []):
              operatorStack.append(expressionLex[j]);
            elif (precedence[expressionLex[j]] > precedence[operatorStack[0]]):
              operatorStack.append(expressionLex[j]);
            elif (precedence[expressionLex[j]] <= precedence[operatorStack[0]]):
              # Process Stacks
              print(operatorStack, valueStack);
              while ((precedence[expressionLex[j]] < precedence[operatorStack[0]]) or (operatorStack == [])):
                if (variables[valueStack[0]] == 0 or variables[valueStack[1]] == 0):
                  errorFlag = 1; raise ValueError;
                if (operatorStack[0] == '+'):
                  valueStack.insert(2, int(valueStack[0]) + int(valueStack[1]));
                elif (operatorStack[0] == '-'):
                  valueStack.insert(2, int(valueStack[0]) - int(valueStack[1]));
                elif (operatorStack[0] == '*'):
                  valueStack.insert(2, int(valueStack[0]) * int(valueStack[1]));
                elif (operatorStack[0] == '/'):
                  valueStack.insert(2, int(valueStack[0]) / int(valueStack[1]));
                valueStack.pop(0); valueStack.pop(1); operatorStack.pop(0);
            else: errorFlag = 1; raise wrongToken;
          pass;
        # Expression End ----------------------------------/\
        #print(valueStack[0]);
        variables[LexId] = int(valueStack[0]);
        for j in range(0, semiIndex + 1):
          tokStack.pop(0); lexStack.pop(0);
        #print(" - Assign Statement");
      finally:
        pass;
    else:
      print("\n -- Error: Invalid Token '{tok}' Found!!!\n -- Halting Process...\n".format(tok = tokStack[0])); errorFlag = 1;

  if (errorFlag):
    #print(" -- Halting Process...\n");
    print("\nTok Stack: {0}".format(tokStack));
    print("Lex Stack: {0}".format(lexStack));
    print("Current Variables: {0}".format(variables));
    exit();
  
  #print("\nTok Stack: {0}".format(tokStack));
  #print("Lex Stack: {0}".format(lexStack));
  print("Current Variables: {0}".format(variables));
  #print("Operator Stack: {0}".format(operatorStack));
  #print("Value Stack: {0}".format(valueStack));

  return;

main();