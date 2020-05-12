	TITLE	C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\tif_dirinfo.c
	.386P
include listing.inc
if @Version gt 510
.model FLAT
else
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
_DATA	SEGMENT DWORD USE32 PUBLIC 'DATA'
_DATA	ENDS
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
_BSS	SEGMENT DWORD USE32 PUBLIC 'BSS'
_BSS	ENDS
$$SYMBOLS	SEGMENT BYTE USE32 'DEBSYM'
$$SYMBOLS	ENDS
$$TYPES	SEGMENT BYTE USE32 'DEBTYP'
$$TYPES	ENDS
_TLS	SEGMENT DWORD USE32 PUBLIC 'TLS'
_TLS	ENDS
FLAT	GROUP _DATA, CONST, _BSS
	ASSUME	CS: FLAT, DS: FLAT, SS: FLAT
endif
PUBLIC	_tiffDataWidth
_BSS	SEGMENT
_?last@?1??_TIFFFindFieldInfo@@9@9 DD 01H DUP (?)
_BSS	ENDS
CONST	SEGMENT
_tiffFieldInfo DD 0feH
	DW	01H
	DW	01H
	DD	04H
	DW	05H
	DB	01H
	DB	00H
	DD	FLAT:$SG65783
	DD	0feH
	DW	01H
	DW	01H
	DD	03H
	DW	05H
	DB	01H
	DB	00H
	DD	FLAT:$SG65784
	DD	0ffH
	DW	01H
	DW	01H
	DD	03H
	DW	05H
	DB	01H
	DB	00H
	DD	FLAT:$SG65785
	DD	0100H
	DW	01H
	DW	01H
	DD	04H
	DW	01H
	DB	00H
	DB	00H
	DD	FLAT:$SG65786
	DD	0100H
	DW	01H
	DW	01H
	DD	03H
	DW	01H
	DB	00H
	DB	00H
	DD	FLAT:$SG65787
	DD	0101H
	DW	01H
	DW	01H
	DD	04H
	DW	01H
	DB	01H
	DB	00H
	DD	FLAT:$SG65788
	DD	0101H
	DW	01H
	DW	01H
	DD	03H
	DW	01H
	DB	01H
	DB	00H
	DD	FLAT:$SG65789
	DD	0102H
	DW	0ffffH
	DW	0ffffH
	DD	03H
	DW	06H
	DB	00H
	DB	00H
	DD	FLAT:$SG65790
	DD	0103H
	DW	0ffffH
	DW	01H
	DD	03H
	DW	07H
	DB	00H
	DB	00H
	DD	FLAT:$SG65791
	DD	0106H
	DW	01H
	DW	01H
	DD	03H
	DW	08H
	DB	00H
	DB	00H
	DD	FLAT:$SG65792
	DD	0107H
	DW	01H
	DW	01H
	DD	03H
	DW	09H
	DB	01H
	DB	00H
	DD	FLAT:$SG65793
	DD	0108H
	DW	01H
	DW	01H
	DD	03H
	DW	00H
	DB	01H
	DB	00H
	DD	FLAT:$SG65794
	DD	0109H
	DW	01H
	DW	01H
	DD	03H
	DW	00H
	DB	01H
	DB	00H
	DD	FLAT:$SG65795
	DD	010aH
	DW	01H
	DW	01H
	DD	03H
	DW	0aH
	DB	00H
	DB	00H
	DD	FLAT:$SG65796
	DD	010dH
	DW	0ffffH
	DW	0ffffH
	DD	02H
	DW	0bH
	DB	01H
	DB	00H
	DD	FLAT:$SG65797
	DD	010eH
	DW	0ffffH
	DW	0ffffH
	DD	02H
	DW	0cH
	DB	01H
	DB	00H
	DD	FLAT:$SG65798
	DD	010fH
	DW	0ffffH
	DW	0ffffH
	DD	02H
	DW	0dH
	DB	01H
	DB	00H
	DD	FLAT:$SG65799
	DD	0110H
	DW	0ffffH
	DW	0ffffH
	DD	02H
	DW	0eH
	DB	01H
	DB	00H
	DD	FLAT:$SG65800
	DD	0111H
	DW	0ffffH
	DW	0ffffH
	DD	04H
	DW	019H
	DB	00H
	DB	00H
	DD	FLAT:$SG65801
	DD	0111H
	DW	0ffffH
	DW	0ffffH
	DD	03H
	DW	019H
	DB	00H
	DB	00H
	DD	FLAT:$SG65802
	DD	0112H
	DW	01H
	DW	01H
	DD	03H
	DW	0fH
	DB	00H
	DB	00H
	DD	FLAT:$SG65803
	DD	0115H
	DW	01H
	DW	01H
	DD	03H
	DW	010H
	DB	00H
	DB	00H
	DD	FLAT:$SG65804
	DD	0116H
	DW	01H
	DW	01H
	DD	04H
	DW	011H
	DB	00H
	DB	00H
	DD	FLAT:$SG65805
	DD	0116H
	DW	01H
	DW	01H
	DD	03H
	DW	011H
	DB	00H
	DB	00H
	DD	FLAT:$SG65806
	DD	0117H
	DW	0ffffH
	DW	0ffffH
	DD	04H
	DW	018H
	DB	00H
	DB	00H
	DD	FLAT:$SG65807
	DD	0117H
	DW	0ffffH
	DW	0ffffH
	DD	03H
	DW	018H
	DB	00H
	DB	00H
	DD	FLAT:$SG65808
	DD	0118H
	DW	0fffeH
	DW	0ffffH
	DD	03H
	DW	012H
	DB	01H
	DB	00H
	DD	FLAT:$SG65809
	DD	0119H
	DW	0fffeH
	DW	0ffffH
	DD	03H
	DW	013H
	DB	01H
	DB	00H
	DD	FLAT:$SG65810
	DD	011aH
	DW	01H
	DW	01H
	DD	05H
	DW	03H
	DB	00H
	DB	00H
	DD	FLAT:$SG65811
	DD	011bH
	DW	01H
	DW	01H
	DD	05H
	DW	03H
	DB	00H
	DB	00H
	DD	FLAT:$SG65812
	DD	011cH
	DW	01H
	DW	01H
	DD	03H
	DW	014H
	DB	00H
	DB	00H
	DD	FLAT:$SG65813
	DD	011dH
	DW	0ffffH
	DW	0ffffH
	DD	02H
	DW	015H
	DB	01H
	DB	00H
	DD	FLAT:$SG65814
	DD	011eH
	DW	01H
	DW	01H
	DD	05H
	DW	04H
	DB	01H
	DB	00H
	DD	FLAT:$SG65815
	DD	011fH
	DW	01H
	DW	01H
	DD	05H
	DW	04H
	DB	01H
	DB	00H
	DD	FLAT:$SG65816
	DD	0120H
	DW	0ffffH
	DW	0ffffH
	DD	04H
	DW	00H
	DB	00H
	DB	00H
	DD	FLAT:$SG65817
	DD	0121H
	DW	0ffffH
	DW	0ffffH
	DD	04H
	DW	00H
	DB	00H
	DB	00H
	DD	FLAT:$SG65818
	DD	0122H
	DW	01H
	DW	01H
	DD	03H
	DW	00H
	DB	01H
	DB	00H
	DD	FLAT:$SG65819
	DD	0123H
	DW	0ffffH
	DW	0ffffH
	DD	03H
	DW	00H
	DB	01H
	DB	00H
	DD	FLAT:$SG65820
	DD	0128H
	DW	01H
	DW	01H
	DD	03H
	DW	016H
	DB	00H
	DB	00H
	DD	FLAT:$SG65821
	DD	0129H
	DW	02H
	DW	02H
	DD	03H
	DW	017H
	DB	01H
	DB	00H
	DD	FLAT:$SG65822
	DD	012cH
	DW	01H
	DW	01H
	DD	03H
	DW	00H
	DB	01H
	DB	00H
	DD	FLAT:$SG65823
	DD	012dH
	DW	0ffffH
	DW	0ffffH
	DD	03H
	DW	02cH
	DB	01H
	DB	00H
	DD	FLAT:$SG65824
	DD	0131H
	DW	0ffffH
	DW	0ffffH
	DD	02H
	DW	01eH
	DB	01H
	DB	00H
	DD	FLAT:$SG65825
	DD	0132H
	DW	014H
	DW	014H
	DD	02H
	DW	01cH
	DB	01H
	DB	00H
	DD	FLAT:$SG65826
	DD	013bH
	DW	0ffffH
	DW	0ffffH
	DD	02H
	DW	01bH
	DB	01H
	DB	00H
	DD	FLAT:$SG65827
	DD	013cH
	DW	0ffffH
	DW	0ffffH
	DD	02H
	DW	01dH
	DB	01H
	DB	00H
	DD	FLAT:$SG65828
	DD	013eH
	DW	02H
	DW	02H
	DD	05H
	DW	02aH
	DB	01H
	DB	00H
	DD	FLAT:$SG65829
	DD	013fH
	DW	06H
	DW	06H
	DD	05H
	DW	02bH
	DB	01H
	DB	00H
	DD	FLAT:$SG65830
	DD	0140H
	DW	0ffffH
	DW	0ffffH
	DD	03H
	DW	01aH
	DB	01H
	DB	00H
	DD	FLAT:$SG65831
	DD	0141H
	DW	02H
	DW	02H
	DD	03H
	DW	025H
	DB	01H
	DB	00H
	DD	FLAT:$SG65832
	DD	0142H
	DW	01H
	DW	01H
	DD	04H
	DW	02H
	DB	00H
	DB	00H
	DD	FLAT:$SG65833
	DD	0142H
	DW	01H
	DW	01H
	DD	03H
	DW	02H
	DB	00H
	DB	00H
	DD	FLAT:$SG65834
	DD	0143H
	DW	01H
	DW	01H
	DD	04H
	DW	02H
	DB	00H
	DB	00H
	DD	FLAT:$SG65835
	DD	0143H
	DW	01H
	DW	01H
	DD	03H
	DW	02H
	DB	00H
	DB	00H
	DD	FLAT:$SG65836
	DD	0144H
	DW	0ffffH
	DW	01H
	DD	04H
	DW	019H
	DB	00H
	DB	00H
	DD	FLAT:$SG65837
	DD	0145H
	DW	0ffffH
	DW	01H
	DD	04H
	DW	018H
	DB	00H
	DB	00H
	DD	FLAT:$SG65838
	DD	0145H
	DW	0ffffH
	DW	01H
	DD	03H
	DW	018H
	DB	00H
	DB	00H
	DD	FLAT:$SG65839
	DD	014aH
	DW	0ffffH
	DW	0ffffH
	DD	04H
	DW	031H
	DB	01H
	DB	01H
	DD	FLAT:$SG65840
	DD	014cH
	DW	01H
	DW	01H
	DD	03H
	DW	02dH
	DB	00H
	DB	00H
	DD	FLAT:$SG65841
	DD	014dH
	DW	0ffffH
	DW	0ffffH
	DD	02H
	DW	02eH
	DB	01H
	DB	01H
	DD	FLAT:$SG65842
	DD	014eH
	DW	01H
	DW	01H
	DD	03H
	DW	032H
	DB	01H
	DB	00H
	DD	FLAT:$SG65843
	DD	0150H
	DW	02H
	DW	02H
	DD	03H
	DW	02fH
	DB	00H
	DB	00H
	DD	FLAT:$SG65844
	DD	0150H
	DW	02H
	DW	02H
	DD	01H
	DW	02fH
	DB	00H
	DB	00H
	DD	FLAT:$SG65845
	DD	0151H
	DW	0ffffH
	DW	0ffffH
	DD	02H
	DW	030H
	DB	01H
	DB	00H
	DD	FLAT:$SG65846
	DD	0152H
	DW	0ffffH
	DW	0ffffH
	DD	03H
	DW	01fH
	DB	00H
	DB	00H
	DD	FLAT:$SG65847
	DD	0152H
	DW	0ffffH
	DW	0ffffH
	DD	01H
	DW	01fH
	DB	00H
	DB	00H
	DD	FLAT:$SG65848
	DD	0153H
	DW	0ffffH
	DW	0ffffH
	DD	03H
	DW	020H
	DB	00H
	DB	00H
	DD	FLAT:$SG65849
	DD	0154H
	DW	0fffeH
	DW	0ffffH
	DD	00H
	DW	021H
	DB	01H
	DB	00H
	DD	FLAT:$SG65850
	DD	0155H
	DW	0fffeH
	DW	0ffffH
	DD	00H
	DW	022H
	DB	01H
	DB	00H
	DD	FLAT:$SG65851
	DD	0211H
	DW	03H
	DW	03H
	DD	05H
	DW	026H
	DB	00H
	DB	00H
	DD	FLAT:$SG65852
	DD	0212H
	DW	02H
	DW	02H
	DD	03H
	DW	027H
	DB	00H
	DB	00H
	DD	FLAT:$SG65853
	DD	0213H
	DW	01H
	DW	01H
	DD	03H
	DW	028H
	DB	00H
	DB	00H
	DD	FLAT:$SG65854
	DD	0214H
	DW	06H
	DW	06H
	DD	05H
	DW	029H
	DB	01H
	DB	00H
	DD	FLAT:$SG65855
	DD	0214H
	DW	06H
	DW	06H
	DD	04H
	DW	029H
	DB	01H
	DB	00H
	DD	FLAT:$SG65856
	DD	080e3H
	DW	01H
	DW	01H
	DD	03H
	DW	01fH
	DB	00H
	DB	00H
	DD	FLAT:$SG65857
	DD	080e4H
	DW	0fffeH
	DW	0ffffH
	DD	03H
	DW	020H
	DB	00H
	DB	00H
	DD	FLAT:$SG65858
	DD	080e5H
	DW	01H
	DW	01H
	DD	04H
	DW	023H
	DB	00H
	DB	00H
	DD	FLAT:$SG65859
	DD	080e5H
	DW	01H
	DW	01H
	DD	03H
	DW	023H
	DB	00H
	DB	00H
	DD	FLAT:$SG65860
	DD	080e6H
	DW	01H
	DW	01H
	DD	04H
	DW	024H
	DB	00H
	DB	00H
	DD	FLAT:$SG65861
	DD	080e6H
	DW	01H
	DW	01H
	DD	03H
	DW	024H
	DB	00H
	DB	00H
	DD	FLAT:$SG65862
	DD	08214H
	DW	01H
	DW	01H
	DD	04H
	DW	037H
	DB	01H
	DB	00H
	DD	FLAT:$SG65863
	DD	08215H
	DW	01H
	DW	01H
	DD	04H
	DW	038H
	DB	01H
	DB	00H
	DD	FLAT:$SG65864
	DD	08216H
	DW	0ffffH
	DW	0ffffH
	DD	02H
	DW	039H
	DB	01H
	DB	00H
	DD	FLAT:$SG65865
	DD	08217H
	DW	0ffffH
	DW	0ffffH
	DD	02H
	DW	03aH
	DB	01H
	DB	00H
	DD	FLAT:$SG65866
	DD	08218H
	DW	01H
	DW	01H
	DD	0bH
	DW	03bH
	DB	01H
	DB	00H
	DD	FLAT:$SG65867
	DD	08219H
	DW	010H
	DW	010H
	DD	0bH
	DW	03cH
	DB	01H
	DB	00H
	DD	FLAT:$SG65868
	DD	0821aH
	DW	010H
	DW	010H
	DD	0bH
	DW	03dH
	DB	01H
	DB	00H
	DD	FLAT:$SG65869
	DD	08298H
	DW	0ffffH
	DW	0ffffH
	DD	02H
	DW	03eH
	DB	01H
	DB	00H
	DD	FLAT:$SG65870
	DD	083bbH
	DW	0ffffH
	DW	0ffffH
	DD	04H
	DW	035H
	DB	00H
	DB	01H
	DD	FLAT:$SG65871
	DD	08649H
	DW	0ffffH
	DW	0fffdH
	DD	01H
	DW	034H
	DB	00H
	DB	01H
	DD	FLAT:$SG65872
	DD	08773H
	DW	0ffffH
	DW	0fffdH
	DD	07H
	DW	033H
	DB	00H
	DB	01H
	DD	FLAT:$SG65873
	DD	0923fH
	DW	01H
	DW	01H
	DD	0cH
	DW	036H
	DB	00H
	DB	00H
	DD	FLAT:$SG65874
_tiffDataWidth DD 01H
	DD	01H
	DD	01H
	DD	02H
	DD	04H
	DD	08H
	DD	01H
	DD	01H
	DD	02H
	DD	04H
	DD	08H
	DD	04H
	DD	08H
CONST	ENDS
_DATA	SEGMENT
$SG65783 DB	'SubfileType', 00H
$SG65784 DB	'SubfileType', 00H
$SG65785 DB	'OldSubfileType', 00H
	ORG $+1
$SG65786 DB	'ImageWidth', 00H
	ORG $+1
$SG65787 DB	'ImageWidth', 00H
	ORG $+1
$SG65788 DB	'ImageLength', 00H
$SG65789 DB	'ImageLength', 00H
$SG65790 DB	'BitsPerSample', 00H
	ORG $+2
$SG65791 DB	'Compression', 00H
$SG65792 DB	'PhotometricInterpretation', 00H
	ORG $+2
$SG65793 DB	'Threshholding', 00H
	ORG $+2
$SG65794 DB	'CellWidth', 00H
	ORG $+2
$SG65795 DB	'CellLength', 00H
	ORG $+1
$SG65796 DB	'FillOrder', 00H
	ORG $+2
$SG65797 DB	'DocumentName', 00H
	ORG $+3
$SG65798 DB	'ImageDescription', 00H
	ORG $+3
$SG65799 DB	'Make', 00H
	ORG $+3
$SG65800 DB	'Model', 00H
	ORG $+2
$SG65801 DB	'StripOffsets', 00H
	ORG $+3
$SG65802 DB	'StripOffsets', 00H
	ORG $+3
$SG65803 DB	'Orientation', 00H
$SG65804 DB	'SamplesPerPixel', 00H
$SG65805 DB	'RowsPerStrip', 00H
	ORG $+3
$SG65806 DB	'RowsPerStrip', 00H
	ORG $+3
$SG65807 DB	'StripByteCounts', 00H
$SG65808 DB	'StripByteCounts', 00H
$SG65809 DB	'MinSampleValue', 00H
	ORG $+1
$SG65810 DB	'MaxSampleValue', 00H
	ORG $+1
$SG65811 DB	'XResolution', 00H
$SG65812 DB	'YResolution', 00H
$SG65813 DB	'PlanarConfiguration', 00H
$SG65814 DB	'PageName', 00H
	ORG $+3
$SG65815 DB	'XPosition', 00H
	ORG $+2
$SG65816 DB	'YPosition', 00H
	ORG $+2
$SG65817 DB	'FreeOffsets', 00H
$SG65818 DB	'FreeByteCounts', 00H
	ORG $+1
$SG65819 DB	'GrayResponseUnit', 00H
	ORG $+3
$SG65820 DB	'GrayResponseCurve', 00H
	ORG $+2
$SG65821 DB	'ResolutionUnit', 00H
	ORG $+1
$SG65822 DB	'PageNumber', 00H
	ORG $+1
$SG65823 DB	'ColorResponseUnit', 00H
	ORG $+2
$SG65824 DB	'TransferFunction', 00H
	ORG $+3
$SG65825 DB	'Software', 00H
	ORG $+3
$SG65826 DB	'DateTime', 00H
	ORG $+3
$SG65827 DB	'Artist', 00H
	ORG $+1
$SG65828 DB	'HostComputer', 00H
	ORG $+3
$SG65829 DB	'WhitePoint', 00H
	ORG $+1
$SG65830 DB	'PrimaryChromaticities', 00H
	ORG $+2
$SG65831 DB	'ColorMap', 00H
	ORG $+3
$SG65832 DB	'HalftoneHints', 00H
	ORG $+2
$SG65833 DB	'TileWidth', 00H
	ORG $+2
$SG65834 DB	'TileWidth', 00H
	ORG $+2
$SG65835 DB	'TileLength', 00H
	ORG $+1
$SG65836 DB	'TileLength', 00H
	ORG $+1
$SG65837 DB	'TileOffsets', 00H
$SG65838 DB	'TileByteCounts', 00H
	ORG $+1
$SG65839 DB	'TileByteCounts', 00H
	ORG $+1
$SG65840 DB	'SubIFD', 00H
	ORG $+1
$SG65841 DB	'InkSet', 00H
	ORG $+1
$SG65842 DB	'InkNames', 00H
	ORG $+3
$SG65843 DB	'NumberOfInks', 00H
	ORG $+3
$SG65844 DB	'DotRange', 00H
	ORG $+3
$SG65845 DB	'DotRange', 00H
	ORG $+3
$SG65846 DB	'TargetPrinter', 00H
	ORG $+2
$SG65847 DB	'ExtraSamples', 00H
	ORG $+3
$SG65848 DB	'ExtraSamples', 00H
	ORG $+3
$SG65849 DB	'SampleFormat', 00H
	ORG $+3
$SG65850 DB	'SMinSampleValue', 00H
$SG65851 DB	'SMaxSampleValue', 00H
$SG65852 DB	'YCbCrCoefficients', 00H
	ORG $+2
$SG65853 DB	'YCbCrSubsampling', 00H
	ORG $+3
$SG65854 DB	'YCbCrPositioning', 00H
	ORG $+3
$SG65855 DB	'ReferenceBlackWhite', 00H
$SG65856 DB	'ReferenceBlackWhite', 00H
$SG65857 DB	'Matteing', 00H
	ORG $+3
$SG65858 DB	'DataType', 00H
	ORG $+3
$SG65859 DB	'ImageDepth', 00H
	ORG $+1
$SG65860 DB	'ImageDepth', 00H
	ORG $+1
$SG65861 DB	'TileDepth', 00H
	ORG $+2
$SG65862 DB	'TileDepth', 00H
	ORG $+2
$SG65863 DB	'ImageFullWidth', 00H
	ORG $+1
$SG65864 DB	'ImageFullLength', 00H
$SG65865 DB	'TextureFormat', 00H
	ORG $+2
$SG65866 DB	'TextureWrapModes', 00H
	ORG $+3
$SG65867 DB	'FieldOfViewCotan', 00H
	ORG $+3
$SG65868 DB	'MatrixWorldToScreen', 00H
$SG65869 DB	'MatrixWorldToCamera', 00H
$SG65870 DB	'Copyright', 00H
	ORG $+2
$SG65871 DB	'RichTIFFIPTC', 00H
	ORG $+3
$SG65872 DB	'Photoshop', 00H
	ORG $+2
$SG65873 DB	'ICC Profile', 00H
$SG65874 DB	'StoNits', 00H
_DATA	ENDS
PUBLIC	__TIFFSetupFieldInfo
PUBLIC	__TIFFMergeFieldInfo
EXTRN	__TIFFfree:NEAR
_TEXT	SEGMENT
_tif$ = 8
__TIFFSetupFieldInfo PROC NEAR

; 270  : {

	push	ebp
	mov	ebp, esp

; 271  : 	if (tif->tif_fieldinfo) {

	mov	eax, DWORD PTR _tif$[ebp]
	cmp	DWORD PTR [eax+532], 0
	je	SHORT $L65880

; 272  : 		_TIFFfree(tif->tif_fieldinfo);

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+532]
	push	edx
	call	__TIFFfree
	add	esp, 4

; 273  : 		tif->tif_nfields = 0;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+536], 0
$L65880:

; 275  : 	_TIFFMergeFieldInfo(tif, tiffFieldInfo, N(tiffFieldInfo));

	push	92					; 0000005cH
	push	OFFSET FLAT:_tiffFieldInfo
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	__TIFFMergeFieldInfo
	add	esp, 12					; 0000000cH

; 276  : }

	pop	ebp
	ret	0
__TIFFSetupFieldInfo ENDP
_TEXT	ENDS
EXTRN	__TIFFmalloc:NEAR
EXTRN	__TIFFrealloc:NEAR
EXTRN	_qsort:NEAR
_TEXT	SEGMENT
_tif$ = 8
_info$ = 12
_n$ = 16
_tp$ = -4
_i$ = -8
__TIFFMergeFieldInfo PROC NEAR

; 292  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 293  : 	TIFFFieldInfo** tp;
; 294  : 	int i;
; 295  : 
; 296  : 	if (tif->tif_nfields > 0) {

	mov	eax, DWORD PTR _tif$[ebp]
	cmp	DWORD PTR [eax+536], 0
	jle	SHORT $L65902

; 297  : 		tif->tif_fieldinfo = (TIFFFieldInfo**)
; 298  : 		    _TIFFrealloc(tif->tif_fieldinfo,
; 299  : 			(tif->tif_nfields+n) * sizeof (TIFFFieldInfo*));

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+536]
	add	edx, DWORD PTR _n$[ebp]
	shl	edx, 2
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+532]
	push	ecx
	call	__TIFFrealloc
	add	esp, 8
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+532], eax

; 300  : 	} else {

	jmp	SHORT $L65905
$L65902:

; 301  : 		tif->tif_fieldinfo = (TIFFFieldInfo**)
; 302  : 		    _TIFFmalloc(n * sizeof (TIFFFieldInfo*));

	mov	eax, DWORD PTR _n$[ebp]
	shl	eax, 2
	push	eax
	call	__TIFFmalloc
	add	esp, 4
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+532], eax
$L65905:

; 304  : 	tp = &tif->tif_fieldinfo[tif->tif_nfields];

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+536]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+532]
	lea	eax, DWORD PTR [edx+eax*4]
	mov	DWORD PTR _tp$[ebp], eax

; 305  : 	for (i = 0; i < n; i++)

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L65908
$L65909:
	mov	ecx, DWORD PTR _i$[ebp]
	add	ecx, 1
	mov	DWORD PTR _i$[ebp], ecx
$L65908:
	mov	edx, DWORD PTR _i$[ebp]
	cmp	edx, DWORD PTR _n$[ebp]
	jge	SHORT $L65910

; 306  : 		tp[i] = (TIFFFieldInfo*) &info[i];	/* XXX */

	mov	eax, DWORD PTR _i$[ebp]
	imul	eax, 20					; 00000014H
	mov	ecx, DWORD PTR _info$[ebp]
	add	ecx, eax
	mov	edx, DWORD PTR _i$[ebp]
	mov	eax, DWORD PTR _tp$[ebp]
	mov	DWORD PTR [eax+edx*4], ecx
	jmp	SHORT $L65909
$L65910:

; 307  : 	/*
; 308  : 	 * NB: the core tags are presumed sorted correctly.
; 309  : 	 */
; 310  : 	if (tif->tif_nfields > 0)

	mov	ecx, DWORD PTR _tif$[ebp]
	cmp	DWORD PTR [ecx+536], 0
	jle	SHORT $L65912

; 311  : 		qsort(tif->tif_fieldinfo, (size_t) (tif->tif_nfields += n),
; 312  : 		    sizeof (TIFFFieldInfo*), tagCompare);

	push	OFFSET FLAT:_tagCompare
	push	4
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+536]
	add	eax, DWORD PTR _n$[ebp]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+536], eax
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+536]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+532]
	push	edx
	call	_qsort
	add	esp, 16					; 00000010H

; 313  : 	else

	jmp	SHORT $L65915
$L65912:

; 314  : 		tif->tif_nfields += n;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+536]
	add	ecx, DWORD PTR _n$[ebp]
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+536], ecx
$L65915:

; 315  : }

	mov	esp, ebp
	pop	ebp
	ret	0
__TIFFMergeFieldInfo ENDP
_a$ = 8
_b$ = 12
_ta$ = -4
_tb$ = -8
_tagCompare PROC NEAR

; 280  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 281  : 	const TIFFFieldInfo* ta = *(const TIFFFieldInfo**) a;

	mov	eax, DWORD PTR _a$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR _ta$[ebp], ecx

; 282  : 	const TIFFFieldInfo* tb = *(const TIFFFieldInfo**) b;

	mov	edx, DWORD PTR _b$[ebp]
	mov	eax, DWORD PTR [edx]
	mov	DWORD PTR _tb$[ebp], eax

; 283  : 	/* NB: be careful of return values for 16-bit platforms */
; 284  : 	if (ta->field_tag != tb->field_tag)

	mov	ecx, DWORD PTR _ta$[ebp]
	mov	edx, DWORD PTR _tb$[ebp]
	mov	eax, DWORD PTR [ecx]
	cmp	eax, DWORD PTR [edx]
	je	SHORT $L65891

; 285  : 		return (ta->field_tag < tb->field_tag ? -1 : 1);

	mov	ecx, DWORD PTR _ta$[ebp]
	mov	edx, DWORD PTR _tb$[ebp]
	mov	eax, DWORD PTR [ecx]
	cmp	eax, DWORD PTR [edx]
	sbb	eax, eax
	and	al, -2					; fffffffeH
	add	eax, 1
	jmp	SHORT $L65892
$L65891:

; 286  : 	else
; 287  : 		return (tb->field_type < ta->field_type ? -1 : 1);

	mov	ecx, DWORD PTR _tb$[ebp]
	mov	edx, DWORD PTR _ta$[ebp]
	mov	eax, DWORD PTR [ecx+8]
	xor	ecx, ecx
	cmp	eax, DWORD PTR [edx+8]
	setge	cl
	dec	ecx
	and	ecx, -2					; fffffffeH
	add	ecx, 1
	mov	eax, ecx
$L65892:

; 288  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_tagCompare ENDP
_TEXT	ENDS
PUBLIC	__TIFFPrintFieldInfo
EXTRN	_fprintf:NEAR
_DATA	SEGMENT
$SG65922 DB	'%s: ', 0aH, 00H
	ORG $+2
$SG65928 DB	'TRUE', 00H
	ORG $+3
$SG65929 DB	'FALSE', 00H
	ORG $+2
$SG65930 DB	'TRUE', 00H
	ORG $+3
$SG65931 DB	'FALSE', 00H
	ORG $+2
$SG65932 DB	'field[%2d] %5lu, %2d, %2d, %d, %2d, %5s, %5s, %s', 0aH, 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_fd$ = 12
_i$ = -4
_fip$65926 = -8
__TIFFPrintFieldInfo PROC NEAR

; 319  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 16					; 00000010H

; 320  : 	int i;
; 321  : 
; 322  : 	fprintf(fd, "%s: \n", tif->tif_name);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	push	OFFSET FLAT:$SG65922
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 12					; 0000000cH

; 323  : 	for (i = 0; i < tif->tif_nfields; i++) {

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L65923
$L65924:
	mov	eax, DWORD PTR _i$[ebp]
	add	eax, 1
	mov	DWORD PTR _i$[ebp], eax
$L65923:
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR _i$[ebp]
	cmp	edx, DWORD PTR [ecx+536]
	jge	$L65925

; 324  : 		const TIFFFieldInfo* fip = tif->tif_fieldinfo[i];

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+532]
	mov	edx, DWORD PTR _i$[ebp]
	mov	eax, DWORD PTR [ecx+edx*4]
	mov	DWORD PTR _fip$65926[ebp], eax

; 325  : 		fprintf(fd, "field[%2d] %5lu, %2d, %2d, %d, %2d, %5s, %5s, %s\n"
; 326  : 			, i
; 327  : 			, (unsigned long) fip->field_tag
; 328  : 			, fip->field_readcount, fip->field_writecount
; 329  : 			, fip->field_type
; 330  : 			, fip->field_bit
; 331  : 			, fip->field_oktochange ? "TRUE" : "FALSE"
; 332  : 			, fip->field_passcount ? "TRUE" : "FALSE"
; 333  : 			, fip->field_name
; 334  : 		);

	mov	ecx, DWORD PTR _fip$65926[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+15]
	test	edx, edx
	je	SHORT $L65996
	mov	DWORD PTR -12+[ebp], OFFSET FLAT:$SG65928
	jmp	SHORT $L65997
$L65996:
	mov	DWORD PTR -12+[ebp], OFFSET FLAT:$SG65929
$L65997:
	mov	eax, DWORD PTR _fip$65926[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+14]
	test	ecx, ecx
	je	SHORT $L65998
	mov	DWORD PTR -16+[ebp], OFFSET FLAT:$SG65930
	jmp	SHORT $L65999
$L65998:
	mov	DWORD PTR -16+[ebp], OFFSET FLAT:$SG65931
$L65999:
	mov	edx, DWORD PTR _fip$65926[ebp]
	mov	eax, DWORD PTR [edx+16]
	push	eax
	mov	ecx, DWORD PTR -12+[ebp]
	push	ecx
	mov	edx, DWORD PTR -16+[ebp]
	push	edx
	mov	eax, DWORD PTR _fip$65926[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+12]
	push	ecx
	mov	edx, DWORD PTR _fip$65926[ebp]
	mov	eax, DWORD PTR [edx+8]
	push	eax
	mov	ecx, DWORD PTR _fip$65926[ebp]
	movsx	edx, WORD PTR [ecx+6]
	push	edx
	mov	eax, DWORD PTR _fip$65926[ebp]
	movsx	ecx, WORD PTR [eax+4]
	push	ecx
	mov	edx, DWORD PTR _fip$65926[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	mov	ecx, DWORD PTR _i$[ebp]
	push	ecx
	push	OFFSET FLAT:$SG65932
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 44					; 0000002cH

; 335  : 	}

	jmp	$L65924
$L65925:

; 336  : }

	mov	esp, ebp
	pop	ebp
	ret	0
__TIFFPrintFieldInfo ENDP
_TEXT	ENDS
PUBLIC	__TIFFSampleToTagType
_TEXT	SEGMENT
_tif$ = 8
_bps$ = -4
__TIFFSampleToTagType PROC NEAR

; 359  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 16					; 00000010H

; 360  : 	int bps = (int) TIFFhowmany(tif->tif_dir.td_bitspersample, 8);

	mov	eax, DWORD PTR _tif$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+64]
	add	ecx, 7
	shr	ecx, 3
	mov	DWORD PTR _bps$[ebp], ecx

; 361  : 
; 362  : 	switch (tif->tif_dir.td_sampleformat) {

	mov	edx, DWORD PTR _tif$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+66]
	mov	DWORD PTR -8+[ebp], eax
	mov	ecx, DWORD PTR -8+[ebp]
	sub	ecx, 1
	mov	DWORD PTR -8+[ebp], ecx
	cmp	DWORD PTR -8+[ebp], 3
	ja	SHORT $L65942
	mov	edx, DWORD PTR -8+[ebp]
	jmp	DWORD PTR $L66005[edx*4]
$L65945:

; 363  : 	case SAMPLEFORMAT_IEEEFP:
; 364  : 		return (bps == 4 ? TIFF_FLOAT : TIFF_DOUBLE);

	xor	eax, eax
	cmp	DWORD PTR _bps$[ebp], 4
	setne	al
	add	eax, 11					; 0000000bH
	jmp	SHORT $L65935
$L65946:

; 365  : 	case SAMPLEFORMAT_INT:
; 366  : 		return (bps <= 1 ? TIFF_SBYTE :
; 367  : 		    bps <= 2 ? TIFF_SSHORT : TIFF_SLONG);

	cmp	DWORD PTR _bps$[ebp], 1
	jg	SHORT $L66001
	mov	DWORD PTR -12+[ebp], 6
	jmp	SHORT $L66002
$L66001:
	xor	eax, eax
	cmp	DWORD PTR _bps$[ebp], 2
	setg	al
	add	eax, 8
	mov	DWORD PTR -12+[ebp], eax
$L66002:
	mov	eax, DWORD PTR -12+[ebp]
	jmp	SHORT $L65935
$L65947:

; 368  : 	case SAMPLEFORMAT_UINT:
; 369  : 		return (bps <= 1 ? TIFF_BYTE :
; 370  : 		    bps <= 2 ? TIFF_SHORT : TIFF_LONG);

	cmp	DWORD PTR _bps$[ebp], 1
	jg	SHORT $L66003
	mov	DWORD PTR -16+[ebp], 1
	jmp	SHORT $L66004
$L66003:
	xor	ecx, ecx
	cmp	DWORD PTR _bps$[ebp], 2
	setg	cl
	add	ecx, 3
	mov	DWORD PTR -16+[ebp], ecx
$L66004:
	mov	eax, DWORD PTR -16+[ebp]
	jmp	SHORT $L65935
$L65948:

; 371  : 	case SAMPLEFORMAT_VOID:
; 372  : 		return (TIFF_UNDEFINED);

	mov	eax, 7
	jmp	SHORT $L65935
$L65942:

; 374  : 	/*NOTREACHED*/
; 375  : 	return (TIFF_UNDEFINED);

	mov	eax, 7
$L65935:

; 376  : }

	mov	esp, ebp
	pop	ebp
	ret	0
$L66005:
	DD	$L65947
	DD	$L65946
	DD	$L65945
	DD	$L65948
__TIFFSampleToTagType ENDP
_TEXT	ENDS
PUBLIC	__TIFFFindFieldInfo
_TEXT	SEGMENT
_tif$ = 8
_tag$ = 12
_dt$ = 16
_i$ = -4
_n$ = -8
_fip$65966 = -12
__TIFFFindFieldInfo PROC NEAR

; 380  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 12					; 0000000cH

; 381  : 	static const TIFFFieldInfo *last = NULL;
; 382  : 	int i, n;
; 383  : 
; 384  : 	if (last && last->field_tag == tag &&
; 385  : 	    (dt == TIFF_ANY || dt == last->field_type))

	cmp	DWORD PTR _?last@?1??_TIFFFindFieldInfo@@9@9, 0
	je	SHORT $L65961
	mov	eax, DWORD PTR _?last@?1??_TIFFFindFieldInfo@@9@9
	mov	ecx, DWORD PTR [eax]
	cmp	ecx, DWORD PTR _tag$[ebp]
	jne	SHORT $L65961
	cmp	DWORD PTR _dt$[ebp], 0
	je	SHORT $L65962
	mov	edx, DWORD PTR _?last@?1??_TIFFFindFieldInfo@@9@9
	mov	eax, DWORD PTR _dt$[ebp]
	cmp	eax, DWORD PTR [edx+8]
	jne	SHORT $L65961
$L65962:

; 386  : 		return (last);

	mov	eax, DWORD PTR _?last@?1??_TIFFFindFieldInfo@@9@9
	jmp	SHORT $L65955
$L65961:

; 387  : 	/* NB: if table gets big, use sorted search (e.g. binary search) */
; 388  : 	for (i = 0, n = tif->tif_nfields; i < n; i++) {

	mov	DWORD PTR _i$[ebp], 0
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+536]
	mov	DWORD PTR _n$[ebp], edx
	jmp	SHORT $L65963
$L65964:
	mov	eax, DWORD PTR _i$[ebp]
	add	eax, 1
	mov	DWORD PTR _i$[ebp], eax
$L65963:
	mov	ecx, DWORD PTR _i$[ebp]
	cmp	ecx, DWORD PTR _n$[ebp]
	jge	SHORT $L65965

; 389  : 		const TIFFFieldInfo* fip = tif->tif_fieldinfo[i];

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+532]
	mov	ecx, DWORD PTR _i$[ebp]
	mov	edx, DWORD PTR [eax+ecx*4]
	mov	DWORD PTR _fip$65966[ebp], edx

; 390  : 		if (fip->field_tag == tag &&
; 391  : 		    (dt == TIFF_ANY || fip->field_type == dt))

	mov	eax, DWORD PTR _fip$65966[ebp]
	mov	ecx, DWORD PTR [eax]
	cmp	ecx, DWORD PTR _tag$[ebp]
	jne	SHORT $L65967
	cmp	DWORD PTR _dt$[ebp], 0
	je	SHORT $L65968
	mov	edx, DWORD PTR _fip$65966[ebp]
	mov	eax, DWORD PTR [edx+8]
	cmp	eax, DWORD PTR _dt$[ebp]
	jne	SHORT $L65967
$L65968:

; 392  : 			return (last = fip);

	mov	ecx, DWORD PTR _fip$65966[ebp]
	mov	DWORD PTR _?last@?1??_TIFFFindFieldInfo@@9@9, ecx
	mov	eax, DWORD PTR _?last@?1??_TIFFFindFieldInfo@@9@9
	jmp	SHORT $L65955
$L65967:

; 393  : 	}

	jmp	SHORT $L65964
$L65965:

; 394  : 	return ((const TIFFFieldInfo *)0);

	xor	eax, eax
$L65955:

; 395  : }

	mov	esp, ebp
	pop	ebp
	ret	0
__TIFFFindFieldInfo ENDP
_TEXT	ENDS
PUBLIC	__TIFFFieldWithTag
EXTRN	__assert:NEAR
EXTRN	_TIFFError:NEAR
_DATA	SEGMENT
	ORG $+2
$SG65984 DB	'Internal error, unknown tag 0x%x', 00H
	ORG $+3
$SG65985 DB	'TIFFFieldWithTag', 00H
	ORG $+3
$SG65988 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_dirinfo.c', 00H
$SG65989 DB	'fip != NULL', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_tag$ = 12
_fip$ = -4
__TIFFFieldWithTag PROC NEAR

; 402  : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 403  : 	const TIFFFieldInfo* fip = _TIFFFindFieldInfo(tif, tag, TIFF_ANY);

	push	0
	mov	eax, DWORD PTR _tag$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	__TIFFFindFieldInfo
	add	esp, 12					; 0000000cH
	mov	DWORD PTR _fip$[ebp], eax

; 404  : 	if (!fip) {

	cmp	DWORD PTR _fip$[ebp], 0
	jne	SHORT $L66008

; 405  : 		TIFFError("TIFFFieldWithTag",
; 406  : 		    "Internal error, unknown tag 0x%x", (u_int) tag);

	mov	edx, DWORD PTR _tag$[ebp]
	push	edx
	push	OFFSET FLAT:$SG65984
	push	OFFSET FLAT:$SG65985
	call	_TIFFError
	add	esp, 12					; 0000000cH

; 407  : 		assert(fip != NULL);

	cmp	DWORD PTR _fip$[ebp], 0
	jne	SHORT $L66008
	push	407					; 00000197H
	push	OFFSET FLAT:$SG65988
	push	OFFSET FLAT:$SG65989
	call	__assert
	add	esp, 12					; 0000000cH
$L66008:

; 410  : 	return (fip);

	mov	eax, DWORD PTR _fip$[ebp]

; 411  : }

	mov	esp, ebp
	pop	ebp
	ret	0
__TIFFFieldWithTag ENDP
_TEXT	ENDS
END
