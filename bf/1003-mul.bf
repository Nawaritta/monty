/ Multiply two digits (n * m) /


# Read the 1st digit n then substract 48 the ASCII value of zero

>   ,------------------------------------------------    |block1



# Read the 2nd digit m

>   ,------------------------------------------------    |block2


 1  0 123 21  0  1 0   12
[< [<+>>>+<<-]<[>+<-]  >>-]	|The block0 is used to hold the content of block1 (n) that we will empty m times in the block3
                                |In the outsider loop we decrease the block2
         			|block3 is carrying the result

# add 48 to convert to the ASCII number and print the product

>    ++++++++++++++++++++++++++++++++++++++++++++++++.
