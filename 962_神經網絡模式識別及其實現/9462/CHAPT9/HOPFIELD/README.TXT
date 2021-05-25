This code in this directory implements the binary hopfield network.
Source code may be found in HOPNET.CPP.  A sample training file is
H7x8N4.trn.  Sample test pattern files are: H7x8D4.TST, H5x8D7.TST,
H5x8D7.TST and H5x8D9.TST,  Output of the program goes to both the
screen and a file, ARCHIVE.LST.

USAGE:

  To  run the program for a single test pattern type the following on
  the command line:


                     +---------Test pattern file name
                     |         (specify "RANDOM" for random test pattern)
                     |
  HOPNET TrainFile TestFile  <enter>
           |
           +----------------Training set file name 
                        

  for example:
  To run the HOPNET with the sample training set and the test pattern 
  file  H7X8D4.TST type the following at the command line:
                HOPNET H7X8N4.TRN H7X8D4.TST <enter>



  Network results are displayed on the screen and stored to archive.lst


To compile:
   ICC HOPNET.CPP <enter>

PIXEL MAPS:
The following figures represent the digits in the sample training set.
   X = Pixel ON
   . = Pixel OFF

XX..XX.   XXXXXX.   XXXXXXX   ...XX..   
XX..XX.   XXXXXX.   XXXXXXX   .XX..XX   
XX..XX.   XX.....   .....XX   .XX...X   
XX..XX.   XX.....   .....XX   .XX..XX   
XXXXXX.   .XXXX..   .....XX   ..XXXXX   
XXXXXX.   .....XX   ....XX.   .....XX   
....XX.   .....XX   ....XX.   .....XX   
....XX.   XXXXX..   ....XX.   .....XX   

 DIGIT 4   DIGIT 5   DIGIT 7   DIGIT 9

NET SIZE:
  The net sized used was 7 by 8.  The theoretical lower bound limit
  (from P=.15N) for P = 4 decisons is  N = 27 neurons.   The networks
  I tried in this lower range did not perform very well,Perhaps
  because of the lack of orthogonality among patterns reuired to
  represent the 7,9,4, and 5 digit pixel maps.  The  7x8 network did
  converge properly when trained as above.
  

