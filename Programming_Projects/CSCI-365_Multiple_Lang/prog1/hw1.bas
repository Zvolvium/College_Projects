1 REM Mason Motschke - CSCI365 - HW1 in bwbasic - mason.motschke@und.edu
2 GOTO 900
3 PRINT
4 GOTO 100
5 PRINT
6 GOSUB 200
7 PRINT "Exiting Program"
8 SYSTEM
100 PRINT "Part 1:"
101 PRINT
110 INPUT "Enter a Percent (EX: 50)(Enter negative to quit): ", percent
120 IF percent < 0 THEN
130   GOTO 7
140 ELSEIF percent > 100 THEN
141   PRINT "Value of percent is too high!!"
142   GOTO 7
150 ELSE
152   IF percent >= 90 THEN
153     PRINT "You got an A"
154   ELSEIF percent >= 80 THEN
155     PRINT "You got an B"
156   ELSEIF percent >= 70 THEN
157     PRINT "You got an C"
158   ELSEIF percent >= 60 THEN
159     PRINT "You got an D"
160   ELSEIF percent >= 0 THEN
161     PRINT "You got an F"
162   END IF
163 END IF
165 GOTO 101
200 PRINT "Part 2:"
201 PRINT
202 FOR i = 1 TO 100 STEP 1
210   IF i MOD 3 = 0 AND i MOD 5 = 0 THEN
211     PRINT "FIZZBUZZ"
212   ELSEIF i MOD 3 = 0 THEN
213     PRINT "Fizz"
214   ELSEIF i MOD 5 = 0 THEN
215     PRINT "Buzz"
216   ELSE
217     PRINT i
220   END IF
220 NEXT
500 RETURN
899 REM Choose the Part that you want to do ------------\/
900 PRINT "Part 1 or Part 2?"
901 INPUT "Enter number (EX: 1): ", A
902 IF A = 1 THEN
903   GOTO 3
904 ELSEIF A = 2 THEN
905   GOTO 5
906 ELSE
907   GOTO 7
908 END IF
