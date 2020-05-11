#
# Pack and check a new distribution of yabasic
#

use IPC::Open3;
use File::Copy;

# Variables, that can be configured
$homepagedir="E:\\Html\\Homepage";
$downloaddir=$homepagedir."\\download";
$projectdir="E:\\Projekte\\Yabasic";
$sourcedir=$projectdir."\\Yabasic";
$yabexedir=$sourcedir."\\Release";
$setupsrcdir=$projectdir."\\Setup";
$setupexedir=$setupsrcdir."\\Release";
$zipdir="C:\\Kits\\Zip-Unzip\\Zip";
$unzipdir="C:\\Kits\\Zip-Unzip\\Unzip";

# files to copy from floppy
%fromlist=("yab.tar.Z"=>$downloaddir,
	   "yabasic.rpm"=>$downloaddir,
	   "yabasic.c"=>$sourcedir,
	   "yabasic.h"=>$sourcedir,
	   "bison.c"=>$sourcedir,
	   "bison.h"=>$sourcedir,
	   "flex.c"=>$sourcedir,
	   "bison.txt"=>$sourcedir,
	   "flex.txt"=>$sourcedir);

# files to copy to floppy
%tolist=("yabasic.c"=>$sourcedir,
	 "yabasic.h"=>$sourcedir,
	 "yabasic.htm"=>$homepagedir);

# source or html files with version information
%verdir=("yabasic.htm"=>$homepagedir,
	 "basic.htm"=>$homepagedir,
	 "yabasic.c"=>$sourcedir,
	 "yabasic.exe"=>$yabexedir);
%vermatch=("yabasic.htm"=>"Current Version:\\s*(\\d)\\.(\\d{1,2})",
	   "basic.htm"=>"<b>\\s*(\\d)\\.(\\d{1,2})</b>",
	   "yabasic.c"=>"\\s*#define\\s+BASIC_VERSION\\s+\"(\\d)\\.(\\d{1,2})\"",
	   "yabasic.exe"=>"yabasic\\s+(\\d)\\.(\\d{1,2})");

# files of binary distribution
@binfiles=("$yabexedir\\yabasic.exe",
	   "$setupexedir\\setup.exe",
	   "Dist\\Copying.txt",
	   "Dist\\Readme.txt",
	   "Yabver.txt",
	   "$projectdir\\yabico.ico",
	   "Dist\\animals.yab",
	   "$homepagedir\\yabasic.htm",
	   "Dist\\yabdemo.yab");

# files of source distribution
@srcfiles=("$setupsrcdir\\yabinst.rc",
	   "$setupsrcdir\\yabinst.c",
	   "$setupsrcdir\\setup.dsp",
	   "$setupsrcdir\\resource.h",
	   "$projectdir\\yabico.ico",
	   "$sourcedir\\yabflex.txt",
	   "$sourcedir\\yabbison.txt",
	   "$sourcedir\\yabasic.h",
	   "$sourcedir\\yabasic.dsp",
	   "$sourcedir\\yabasic.c",
	   "$sourcedir\\flex.c",
	   "$sourcedir\\bison.c",
	   "$sourcedir\\bison.h",
	   "source\\copying.txt",
	   "source\\readme.txt",
	   "pack.pl");

# Autoflush stdout
$|=1;

# Check date of files
print "\nCopying Files:\n";
for $file (keys(%fromlist)) {
    $fromfile="A:\\$file";
    $fromtime=(stat($fromfile))[9];
    $tofile="$fromlist{$file}\\$file";
    $totime=(stat($tofile))[9];
    if ($fromtime>$totime+120) {
	$copied++;
	if (!copy($fromfile,$tofile)) {
	    print " error !\n";
	    print "Couldn't copy $fromfile to $tofile\n";
	    <stdin>;
	    exit;
	}
	print "  $tofile\n";
    }
}
if (!$copied) {
    print "done.\nAll files are up to date.\n";
}
else {
    print "done.\n";
    print "\nCopied some files, better recompile.\n";
    <stdin>;exit;
}

# check versions
print "\nChecking versions:\n";
for $file (keys(%verdir)) {
    $fullname="$verdir{$file}\\$file";
    if (!open(YAB,$fullname)) {print "\nCouldn't open $fullname\n";<stdin>;exit;}
    $found=0;
    binmode(YAB);
    while(<YAB>) {
	if (/$vermatch{$file}/) {
	    $version{"$1.$2"}++;
	    $found=1;
	    $ver="$1.$2";
	    print "  $1.$2 ($file)\n";
	    last;
	}
    }
    if (!$found) {
	print "\nCouldn't get Version from $fullname\n";<stdin>;exit;
    }
    close(YAB);
}

each(%version);
if (each(%version)) {
    print "They don't match, better bring them in line !\n";
    <stdin>;
    exit;
}
print "They match.\n";
open(YAB,"> Yabver.txt") || die "Couldn't open Yabver.txt\n";
print YAB $ver,"\n";
close(YAB);
    
print "\nPacking binaries:\n";
system("$zipdir\\zip YabBin.zip -j -D ".join(" ",@binfiles)." >j.out");
system("copy /b /Y $unzipdir\\unzipsfx.exe+YabBin.zip yabbin.exe >j.out");
system("$zipdir\\zip -A yabbin.exe >j.out");
system("move /Y yabbin.exe $downloaddir >j.out");
print "done.\n";

print "\nPacking sources:\n";
system("$zipdir\\zip YabSrc.zip -j -D ".join(" ",@srcfiles)." >j.out");
system("copy /b /Y $unzipdir\\unzipsfx.exe+YabSrc.zip yabsrc.exe >j.out");
system("$zipdir\\zip -A yabsrc.exe >j.out");
system("move /Y yabsrc.exe $downloaddir >j.out");
print "done.\n";

print "\nCopying files to floppy\n";
for $file (keys(%tolist)) {
    $tofile="A:\\$file";
    $totime=(stat($tofile))[9];
    $fromfile="$tolist{$file}\\$file";
    $fromtime=(stat($fromfile))[9];
    if ($fromtime>$totime+120) {
	if (!copy($fromfile,$tofile)) {
	    print "\nerror !\n";
	    print "Couldn't copy $fromfile to $tofile\n";
	    <stdin>;
	    exit;
	}
	print "  $file\n";
    }
}
print "done.\n";
print "\nProgram done, press <RETURN>.\n";
<stdin>;
