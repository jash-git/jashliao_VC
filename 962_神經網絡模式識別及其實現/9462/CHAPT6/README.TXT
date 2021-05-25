The programs in this directory illustrate geometric feature detection 
as discussed in chapter6. The features detected are intersections,
end points and loops.  As a preliminary step in the feature detection
process, thinning(see chapter 3) is performed.  The two programs found
in this directory are:
  1) showdata
  2) feature

Sample data can be found in: chrdata.bm
Sample output data can be found in: chrdata.0,  chrdata.1,...,chrdata.9.


SHOWDATA:

The showdata program read character data in the format of a ".BM" file, 
converts it to a matrix representation and outputs the image in text mode
to the screen.  Characters are on a 16x 24 pixel grid.
 
".BM" consist of an arbitrary number of records where each record 
consists of:
   byte 0x00: always 0x00
   byte 0x01: ascii code of the character
   bytes 0x02-0x31: data in 1 bit-per-pixel format. (i.e. Thus it takes
                    2 bytes to represent a row of the character matrix.)

FEATURES:
Accepts a ".BM" file as input and creates: 1) a thinned version  of the
target character and 2) a version of the character consisting only of 
pixels that are loop members.  The original, thinned and loop member 
versions are all displayed.  Coordinates for intersections and endpoints 
are calculated and displayed.  Loop mass and the coordinates of the loop
center of mass are calculated and displayed as [mass,(x,y)].

TO Compile:
      icc showdata.cpp <enter>

Usage:
      showdata SourceFile <enter>

         where SourceFile is the name of a ".BM" format file
               (both name and extention are required)


FEATURES:


To compile:
      icc features.cpp <enter>

Usage
      features SourceFileName <enter>
         x
         where SourceFilename is the name of a ".BM" format file.
               (ONLY the file name should appear on the command line
                as the program will fill in the .BM extention.

         Output from the program will go to both the screen and to
         files SourceFilename.1, SourceFilename.2, SourceFilename,...

