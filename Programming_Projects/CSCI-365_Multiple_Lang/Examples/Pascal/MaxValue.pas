{ Hello World in Pascal }
PROGRAM MaxValue;

TYPE
   ArrayType = ARRAY[1..5] OF INTEGER;

FUNCTION max ( theArray : ArrayType) : INTEGER;
VAR
   value : INTEGER;
   x : INTEGER;
BEGIN
   value := theArray[1];
   FOR x := 1 to 5 DO
      IF theArray[x] > value THEN
         value := theArray[x];
   max := value;
END;

{ main program }
VAR
   myArray : ArrayType;
   answer : INTEGER;
BEGIN
   myArray[1] := 10000;
   myArray[2] := 100;
   myArray[3] := 1;
   myArray[4] := 5;
   myArray[5] := 1000;
   answer := max (myArray);
   WriteLn ('The max value is ', answer);
END.
