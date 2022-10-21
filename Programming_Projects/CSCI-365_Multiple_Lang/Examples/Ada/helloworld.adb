with Ada.Text_IO; use Ada.Text_IO;

procedure helloworld is

   procedure PrintHelloWorld is
   begin
      Put_Line ("Hello World");
   end PrintHelloWorld;

begin
   Put_Line ("Hello World");
   PrintHelloWorld;
end helloworld;

