-- Mason Motschke - CSCI 365 - Program 2 in Ada
-- Part 1 - mason.motschke@und.edu

with Ada.Text_IO, Ada.Integer_Text_IO, Ada.Float_Text_IO;
use Ada.Text_IO, Ada.Integer_Text_IO;

procedure main is 
  type Arraytype is array (Integer range<>) of Integer;
  arr1 : Arraytype(0 .. 4) := (67, 78, 89, 97, 45);
  arr2 : Arraytype(0 .. 6) := (45, 100, 75, 32, 99, 66, 82);
  arr3 : Arraytype(0 .. 5); -- 6 items; ask user for scores in arr3
  cnt : Integer := 0; avg : Float := 0.00; bool : Boolean := False;
  num : Integer := 1;

  function Count70OrGreater (theArray : ArrayType) return Integer is
  begin
    for i of theArray loop
      if (i >= 70) then
        cnt := cnt + 1;
      end if;
    end loop;
    return cnt;
  end Count70OrGreater;

  procedure UpdateScores (theArray : in out ArrayType) is
  begin
    Put("Array "); Put(Integer'image(num)); Put(": ");
    num := num + 1;
    for i in 0 .. (theArray'Length - 1) loop
      theArray(i) := theArray(i) + 3;
      Put(Integer'image(theArray(i))); Put(" ");
    end loop; New_Line(1);
  end UpdateScores;

  function HasPerfectScore (theArray : ArrayType) return Boolean is
  begin
    for c of theArray loop
      if (c >= 100) then
        return True;
      end if;
    end loop;
  return False;
  end HasPerfectScore;

  function Average (theArray : ArrayType) return Float is
    x, z : Float := 0.00;
  begin
    for i of theArray loop
      x := x + Float(i);
    end loop;
      z := x / Float(theArray'Length); x := 0.00; 
    return z;
  end Average;

begin
  Put_Line("Hello, I'm Alive :)"); New_Line(1);
  -- Initialize Array3 -------------------\/
  Put_Line("--- Populating Array 3 ---");
  for x in 0 .. 5 loop
    Put("Enter a Number: ");
    arr3(x) := Integer'Value(Get_Line); --New_Line(1);
  end loop;
  New_Line(1);
  -- Finish Initializing Array3 ----------/\

  cnt := Count70OrGreater(arr1);
  Put("Array1 Count >= 70:"); Put(Integer'image(cnt)); New_Line(1); cnt := 0;
  cnt := Count70OrGreater(arr2);
  Put("Array2 Count >= 70:"); Put(Integer'image(cnt)); New_Line(1); cnt := 0;
  cnt := Count70OrGreater(arr3);
  Put("Array3 Count >= 70:"); Put(Integer'image(cnt)); New_Line(2); cnt := 0;

  bool := HasPerfectScore(arr1);
  Put("Array1 Perfect Score "); Put(Boolean'image(bool)); New_Line(1); bool := False;
  bool := HasPerfectScore(arr2);
  Put("Array2 Perfect Score "); Put(Boolean'image(bool)); New_Line(1); bool := False;
  bool := HasPerfectScore(arr3);
  Put("Array3 Perfect Score "); Put(Boolean'image(bool)); New_Line(2); bool := False;

  Put_Line("--- Updating Scores ---");
  UpdateScores(arr1);
  UpdateScores(arr2);
  UpdateScores(arr3); New_Line(1);

  bool := HasPerfectScore(arr1);
  Put("Array1 Perfect Score "); Put(Boolean'image(bool)); New_Line(1); bool := False;
  bool := HasPerfectScore(arr2);
  Put("Array2 Perfect Score "); Put(Boolean'image(bool)); New_Line(1); bool := False;
  bool := HasPerfectScore(arr3);
  Put("Array3 Perfect Score "); Put(Boolean'image(bool)); New_Line(2);

  avg := Average(arr1);
  Put("Average of Array1:"); Ada.Float_Text_IO.Put(avg, 10, 5, 0); New_Line(1); avg := 0.00;
  avg := Average(arr2);
  Put("Average of Array2:"); Ada.Float_Text_IO.Put(avg, 10, 5, 0); New_Line(1); avg := 0.00;
  avg := Average(arr3);
  Put("Average of Array3:"); Ada.Float_Text_IO.Put(avg, 10, 5, 0); New_Line(2);

  Put_Line("Goodbye, I'm Dead :(");
end main;
