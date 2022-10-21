1 REM Mason Motschke - CSCI 365 - Program 1 in bwbasic
2 REM Part 1 and Part 2 - mason.motschke@und.edu
3 REM Choose the Part that you want to do ------------------\/
10 PRINT "Part 1 or Part 2?"
20 INPUT "Enter Choice (EX: 1): ", user
30 IF user = 1 THEN GOTO 40
31 IF user = 2 THEN GOTO 210
32 GOTO 1000
33 REM End of Part Choosing --------------------------------/\
34 REM Part 1 -----------------------------\/
40 PRINT
41 PRINT "Part 1: "
42 PRINT
43 INPUT "Enter a percent (EX: 50)(Enter negative to quit): ", percent
44 IF percent < 0 THEN GOTO 1000
45 IF percent > 100 THEN GOTO 200
46 IF percent >= 0 AND percent <= 100 THEN GOTO 50
50 IF percent >= 90 THEN GOTO 60
51 IF percent < 90 AND percent >= 80 THEN GOTO 70
52 IF percent < 80 AND percent >= 70 THEN GOTO 80
53 IF percent < 70 AND percent >= 60 THEN GOTO 90
54 IF percent < 60 AND percent >= 0 THEN GOTO 95
60 PRINT "You got an A"
61 GOTO 100
70 PRINT "You got an B"
71 GOTO 100
80 PRINT "You got an C"
81 GOTO 100
90 PRINT "You got an D"
91 GOTO 100
95 PRINT "You got an F"
96 GOTO 100
100 GOTO 42
200 PRINT "Value of percent is too high!!"
201 GOTO 100
202 REM Part 1 End -----------------------/\
203 REM Part 2 -----------------------------------\/
210 PRINT
211 PRINT "Part 2: "
212 PRINT
213 i = 1 REM Start of FOR Loop <----
219 IF i > 100 THEN GOTO 1000
220 IF i MOD 3 = 0 AND i MOD 5 = 0 THEN GOTO 230
221 IF i MOD 3 = 0 THEN GOTO 240
222 IF i MOD 5 = 0 THEN GOTO 250
223 PRINT i
224 i = i + 1
225 GOTO 219 REM End of FOR Loop <----$
230 PRINT "FIZZBUZZ"
231 GOTO 224
240 PRINT "FIZZ"
241 GOTO 224
250 PRINT "BUZZ"
251 GOTO 224
252 REM Part 2 End -------------------------------/\
1000 PRINT "Exiting Program"
1001 SYSTEM
