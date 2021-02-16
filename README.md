# magicMirror

To generate different right - rotations of a word, write the word in a circle in clockwise order,
then start reading from any given character in clockwise order till you have covered all the characters.

For example: in word "sample" if we start with "p" we get right rotated word as "plesam".
There are six such of "sample" including itself.

The inputs of the program consists of two strings: word1 and word2 separated by comma.
The function returns 1 if word1 and word2 are right rotations of the same word and -1 if they are not.

Examples:

Input | Output
------------ | -------------
abc, abcd |-1
abc, cba |-1
abc, bca |   1
sample, plesam | 1
magicMirror, cMirrormagi | 1
