Operation:

Run the program in any C++ compiler. The complier used to run and create this program is gcc.

OR

Use the executable provided to run the program.
*The executable was only tested on macOS*

Included with my submission is test data to test the program with. I have included warn.txt (a file randomly selected from the Pygame package. I also created a testData.txt that contains 1 MB worth of random symbols.

On startup:

You will be prompted to select one of four options Encode a File, Decode a File, Encode and Decode a File, Print Frequency Table For File. There is a 5th option utilizing testData.txt.

-    Encode a File:
o    Enter the file name you would like to compress -> Enter the file name you would like to output the compressed contents to.

Console Snippet:

Please enter option 1-3
1. Encode a File
2. Decode a File
3. Encode and Decode a File
4. Print Frequency Table For File
1
Enter the original file name: testData.txt
Inputted File Size 1000000
Enter the name of the encoded output file: testData.huf
File Encoded! See results in testData.huf

-    Decode a File:
o    Enter the original file to create Huffman Table -> Enter the file name you would like to decompress -> Enter the file name you would like to output the decompressed contents to.

Console Snippet:

Please enter option 1-3
1. Encode a File
2. Decode a File
3. Encode and Decode a File
4. Print Frequency Table For File
2
Enter the original file name: testData.txt
Inputted File Size 1000000
Enter the name of the encoded file: testData.huf
Enter the name of the decode ouput file: testData2.txt
Decoded File Size 1000000
File Decoded! See results in testData2.txt

-    Encode and Decode:
o    Enter the file name you would like to compress -> Enter the file name you would like to output the compressed contents to -> Enter the file name you would like to output the decompressed contents to.

Console Snippet:

Please enter option 1-3
1. Encode a File
2. Decode a File
3. Encode and Decode a File
4. Print Frequency Table For File
3
Enter the file name you would like to compress: testData.txt
Inputted File Size 1000000
Enter the name of the encoded output file: testData.huf
File Encoded!
Enter the name of the decoded output file: testData2.txt
Decoded File Size 1000000
File Decoded!

-    Print Frequency Table from File:
o    Enter the file name that you would like to see the stats of.

Console Snippet:

Please enter option 1-3
1. Encode a File
2. Decode a File
3. Encode and Decode a File
4. Print Frequency Table For File
4
Enter the file name you would like to compress: testData.txt
Inputted File Size 1000000
!: 11006
#: 11015
%: 11062
&: 11118
': 11032
(: 10870
): 11130
*: 11063
+: 10810
-: 11157
.: 11135
/: 10979
0: 10972
1: 11099
2: 10807
3: 10953
4: 10994
5: 11028
6: 10844
7: 11098
8: 11015
9: 11023
;: 11042
<: 10998
=: 11282
>: 11005
?: 11095
@: 10906
A: 11032
B: 10962
C: 10865
D: 11026
E: 10885
F: 10807
G: 11010
H: 11041
I: 10997
J: 10742
K: 10870
L: 10815
M: 10999
N: 10975
O: 10907
P: 11249
Q: 10841
R: 10897
S: 11075
T: 10905
U: 11117
V: 11142
W: 11018
X: 11013
Y: 11008
Z: 10804
[: 21973
\: 11101
]: 11093
^: 10923
_: 10938
`: 11080
a: 11054
b: 10957
c: 10999
d: 10885
e: 10903
f: 11059
g: 11127
h: 10906
i: 11114
j: 11041
k: 10957
l: 11080
m: 11028
n: 10877
o: 10964
p: 10941
q: 11073
r: 10949
s: 11043
t: 10984
u: 10982
v: 10787
w: 10890
x: 10992
y: 10943
z: 10832
{: 11098
|: 11101
}: 10900
~: 10886

