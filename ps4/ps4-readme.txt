/**********************************************************************
 *  readme template                                                   
 *  DNA Sequence Alignment
 **********************************************************************/

Name: Justin Nguyen
Login: 


Hours to complete assignment (optional): 20



/**********************************************************************
 *  Explain what you did to find the alignment itself.
 **********************************************************************/
I made a while loop to check if i and j equaled to the length of string1 and string2 respectively. I then checked if penalty returned 0 and 1 and if the character equaled each other or not and from there went one character at a time in each string to see if it would return a 0, 1, or 2. 


/**********************************************************************
 * Does your code work correctly with the endgaps7.txt test file? 
 * 
 * This example should require you to insert a gap at the beginning
 * of the Y string and the end of the X string.
 **********************************************************************/
Input: ./ED < endgaps7.txt

Expected output: Edit distance: 4
- a 2
t t 0
a a 0
t t 0
t t 0
a a 0
t t 0
execution time is: 0.00043 seconds 


What happened: It only inserted a gap in the beginning but not the end.



/**********************************************************************
 *  How much main memory does your computer have? Typical answers
 *  are 2 GB to 16 GB.
 **********************************************************************/

4GB

/**********************************************************************
 *  For this question assume M=N. Look at your code and determine
 *  approximately how much memory it uses in bytes, as a function of 
 *  N. Give an answer of the form a * N^b for some constants a 
 *  and b, where b is an integer. Note chars are 2 bytes long, and 
 *  ints are 4 bytes long.
 *
 *  Provide a brief explanation.
 *
 *  What is the largest N that your program can handle if it is
 *  limited to 8GB (billion bytes) of memory?
 **********************************************************************/
a =
b = 
largest N =

/**********************************************************************
 *  Were you able to run Valgrind's massif tool to verify that your
 *  implementation uses the expected amount of memory?
 *
 *  Answer yes, no, I didn't try, I tried and failed, or I used a 
 *  different tool.
 *
 *  If yes, paste in the ms_print top chart of memory use over time,
 *  and also indicate which file your code was solving.
 * 
 *  Explain if necessary.
/**********************************************************************



/**********************************************************************
 *  For each data file, fill in the edit distance computed by your
 *  program and the amount of time it takes to compute it.
 *
 *  If you get segmentation fault when allocating memory for the last
 *  two test cases (N=20000 and N=28284), note this, and skip filling
 *  out the last rows of the table.
 **********************************************************************/

data file           distance       time (seconds)     memory (MB)
------------------------------------------------------------------
ecoli2500.txt        118               0.246305          25.0979
ecoli5000.txt        160               1.05916            100.212
ecoli7000.txt        194               2.1403              196.288
ecoli10000.txt      223               4.4952              400.445
ecoli20000.txt      3125             52.5743           1600.83
ecoli28284.txt      doesn't work

Fill out the data here first, then go to the assignment web page for
instructions on sharing your data on iSENSE.

/*************************************************************************
 *  Here are sample outputs from a run on a different machine for 
 *  comparison.
 ************************************************************************/

data file           distance       time (seconds)
-------------------------------------------------
ecoli2500.txt          118             0.171
ecoli5000.txt          160             0.529
ecoli7000.txt          194             0.990
ecoli10000.txt         223             1.972
ecoli20000.txt         3135            7.730

/**********************************************************************
 *  Enter your data onto iSENSE per the directions on the course web
 *  site. Then, paste a URL to your data set here.
 *
 *  YOU WILL ONLY RECEIVE CREDIT FOR YOUR iSENSE WORK IF YOU PROVIDE
 *  THE URL HERE.
 *
 *  e.g.: http://isenseproject.org/projects/871/data_sets/7893
 ************************************************************************/
http://isenseproject.org/projects/871/data_sets/8049


/**********************************************************************
 *  For this question assume M=N (which is true for the sample files 
 *  above). By applying the doubling method to the data points that you
 *  obtained, estimate the running time of your program in seconds as a 
 *  polynomial function a * N^b of N, where b is an integer.
 *  (If your data seems not to work, describe what went wrong and use 
 *  the sample data instead.)
 *
 *  Provide a brief justification/explanation of how you applied the
 *  doubling method.
 * 
 *  What is the largest N your program can handle if it is limited to 1
 *  day of computation? Assume you have as much main memory as you need.
 **********************************************************************/
a = 
b = 
largest N = 

/**********************************************************************
 *  List whatever help (if any) you received from the course TAs,
 *  instructor, classmates, or anyone else.
 **********************************************************************/
Asked Professor Grinberg on how the algorithm worked.


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/



/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           