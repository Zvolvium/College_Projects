{ Mason Motschke - CSCI_365 - prog3 - mason.motschke@und.edu - Part 1}
PROGRAM prog3;
TYPE
    StrArrayType = ARRAY[1..20] OF STRING;

FUNCTION isInList (list:StrArrayType; size:INTEGER; itemToFind:STRING):BOOLEAN;
VAR
  i : Integer;
BEGIN { isInList Function }
  isInList := False;
  FOR i := 1 to size DO
    IF list[i] = itemToFind THEN
      begin
        isInList := True;
      end;
END;

PROCEDURE addItem (VAR list:StrArrayType; VAR size:INTEGER; itemToAdd:STRING);
VAR
  bool : Boolean = False;
BEGIN { addItem Function } { I can't remove the below writeln; it breaks and be's angree; I don't understand ;( }
  bool := isInList(list, size, itemToAdd); {WriteLn('Needed to Run Correctly????');}
  IF bool = False THEN
    begin
      size := size + 1;
      list[size] := itemToAdd;
    end;
END;

FUNCTION removeItem (VAR list:StrArrayType; VAR size:INTEGER; itemToRemove:STRING):BOOLEAN;
Var 
  i, j : Integer; temp : String; flag : Boolean = False;
BEGIN { removeItem Function }
  for j := 1 to size * size do
    for i := 1 to size - 1 do
      if list[i] = itemToRemove then
        begin
          flag := True; temp := list[i]; list[i] := list[i + 1]; list[i + 1] := temp;
        end;
  if flag = True Then size := size - 1;
  removeItem := flag;
END;

FUNCTION count (list:StrArrayType; size:INTEGER):INTEGER;
VAR
  i : Integer = 0; value : Integer = 0;
BEGIN { count Function }
  FOR i := 1 to 20 DO
    IF list[i] <> '' THEN
      value := value + 1;
  count := value;
END;

PROCEDURE sort (VAR list:StrArrayType; size:INTEGER);
VAR
  i, x : Integer; temp : String;
BEGIN { sort Function }
  FOR x := 1 to size * size * 2 DO
    FOR i := 1 to size - 1 DO
      IF list[i] > list[i + 1] THEN
        begin
          temp := list[i]; list[i] := list[i + 1]; list[i + 1] := temp;
        end;
END;

PROCEDURE swap (VAR a, b : STRING );
VAR
  temp : STRING;
BEGIN { swap Function }
  temp := a;
  a := b;
  b := temp;
END;

PROCEDURE printList (list:StrArrayType; size:INTEGER);
VAR
  i : Integer;
BEGIN { printList Function }
  WriteLn('--- Printing List ---');
  FOR i := 1 to size DO
    WriteLn(list[i]);
  WriteLn('--- Printing END ---');
END;

VAR
  myArray : StrArrayType;
  size : Integer; x : Integer; cnt : Integer; bool : Boolean; str : String;
BEGIN { Main Program }
  size := 0;
  FOR x := 1 to 20 DO
    myArray[x] := '';

  printList(myArray, size); WriteLn();
  addItem(myArray, size, 'Hi,'); addItem(myArray, size, 'I');
  addItem(myArray, size, 'Phil.'); addItem(myArray, size, 'am');
  addItem(myArray, size, 'why'); addItem(myArray, size, 'am');
  addItem(myArray, size, 'How'); addItem(myArray, size, 'Samison');
  addItem(myArray, size, 'Love'); addItem(myArray, size, 'Hate');
  addItem(myArray, size, 'boy'); addItem(myArray, size, 'girl');

  cnt := count(myArray, size);
  WriteLn('Array Size Currently: ', size); WriteLn('Array Size using count Function: ', cnt); WriteLn();

  WriteLn('Array Before Swap:'); printList(myArray, size); WriteLn();
  WriteLn('Strings Swaped: ', myArray[3], ' and ', myArray[4]); WriteLn();
  WriteLn('Array After Swap:'); swap(myArray[3], myArray[4]); printList(myArray, size); WriteLn();

  WriteLn('Array Before Sort:'); printList(myArray, size); WriteLn();
  WriteLn('Array After Sort:'); sort(myArray, size); printList(myArray, size); WriteLn();

  WriteLn('Array Before Remove:'); printList(myArray, size); WriteLn();

  str := 'Hi,'; bool := removeItem(myArray, size, str);
  if bool = False then WriteLn('Item was not deleted: ', str)
  Else begin WriteLn('Item was deleted: ', str); end;

  str := 'Hate'; bool := removeItem(myArray, size, str);
  if bool = False then WriteLn('Item was not deleted: ', str)
  Else begin WriteLn('Item was deleted: ', str); end;

  str := 'Yellow'; bool := removeItem(myArray, size, str);
  if bool = False then WriteLn('Item was not deleted: ', str)
  Else begin WriteLn('Item was deleted: ', str); end;

  str := 'girl'; bool := removeItem(myArray, size, str);
  if bool = False then WriteLn('Item was not deleted: ', str)
  Else begin WriteLn('Item was deleted: ', str); end;

  str := 'boy'; bool := removeItem(myArray, size, str);
  if bool = False then WriteLn('Item was not deleted: ', str)
  Else begin WriteLn('Item was deleted: ', str); end;

  str := 'Philidelphia'; bool := removeItem(myArray, size, str);
  if bool = False then WriteLn('Item was not deleted: ', str)
  Else begin WriteLn('Item was deleted: ', str); end; WriteLn();
  
  WriteLn('Array After Remove:'); printList(myArray, size); WriteLn();
END.
