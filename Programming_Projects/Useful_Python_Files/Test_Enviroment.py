#from sys import exit as Exit;
#from PersonalUtils import AddCommas;
#from Math_Help import Factorial;

def Main():
  ''' AddCommas Test <----------------------------------------------------------------------------AddCommas(); '''  ''' <--Comment out
  test = []; cnt = [];
  for x in range(0, 100 + 1):
    z = (10**x); cnt.append(x);
    test.append(z);

    i = 0; print("\n------------------------------Test #1------------------------------------");
    for z in test:
      z = AddCommas(z);
      print("{0} {1}".format(z, i)); i += 1;

    test = []; cnt = [];
    for x in range(0, 100 + 1):
      z = (10.0**x); cnt.append(x);
      test.append(z);

    i = 0; print("\n------------------------------Test #2------------------------------------");
    for z in test:
      z = AddCommas(z);
      print("{0} {1}".format(z, i)); i += 1;

    AddCommas("Let's Go Mate!!!"); # --------------------------- String Test ------------------------------------

  #Comment out--> '''
  '''
  # ------------------------------- Factorial Test -------------------------------
  x = 0; num = 0; val = 3000;
  while (x <= val):
    num = Factorial(x); num = AddCommas(num);
    print("x-value: {0}; Factorial: {1}".format(x, num)); print(); x += 1;
    if (x > val):
      break;
  '''
  return;

Main();