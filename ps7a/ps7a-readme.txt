/**********************************************************************
 *  readme.txt template                                                   
 *  Kronos PS7a startup
 **********************************************************************/

Name: Justin Nguyen


Hours to complete assignment (optional): 10


/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
Successful because I was able to print to report files, the starting boot time, boot time and ending boot time.


/**********************************************************************
 *  Copy here all regex's you created for parsing the file, 
 *  and explain individually what each ones does.
 **********************************************************************/
 "([0-9]+)-([0-9]+)-([0-9]+) ([0-9]+):([0-9]+):([0-9]+): \\(log.c.166\\) server started.*"

 The ([0-9]+) checks for numbers between 0 and 9. The "+" checks for more than one number. The "-" checks for the "-" character. The ":" and " " does the same. The "\\(log.c.166\\) server started.*" looks for that exact sentence without the "(log.c.166)". The "\\" are there for the "(" and ")". The sentense is also the code for boot starting.

 "([0-9]+)-([0-9]+)-([0-9]+) ([0-9]+):([0-9]+):([0-9]+).([0-9]+):INFO:oejs.AbstractConnector:Started SelectChannelConnector@0.0.0.0:9080.*" 

 ([0-9]+) -> checks for numbers from 0-9 and the + means it is checking for more than one number.

 "-" -> checks for "-" similar to the case ":" and " ".

 ":INFO:oejs.AbstractConnector:Started SelectChannelConnector@0.0.0.0:9080.*" -> looks for the sentence which is the code for completing a boot.


/**********************************************************************
 *  Describe your overall approach for solving the problem.
 *  100-200 words.
 **********************************************************************/
I first created a regex for the start code and the regex for the end code. After, I used istream and ostream to open the file (from the argument) and create a report file. I used regex_match to check if the new line matched with the regex start code or end code. If it did start with either, it will use the start code precedure or the end code procedure. Also, depending on if the system is currently booting, complete booting, or incomplete booting(in this case, neither were found), it will print the date, time and status of the system to the report file.


/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/
Only got help from Grinberg's class


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
N/A


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
N/A
