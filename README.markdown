###How it all started###
I came across this problem: find the largest palindrome made from the product of two n-digit numbers. Out of curiosity I decided to compare 2 different approaches to the implementations of the solution. 

A simple java solution to the problem which utilized built in java functions was compared to a loosely object oriented c++ program which used no built in functions except the power function from the math library. 

Both programs use the very similar brute force type algorithm to find the solution. 

Asymptotic run-time of both programs was analyzed. The difference was initially startling. To find the largest palindrome for  five digit operands, it took the c++ program 1305.977 seconds where as it took the java program, on the same machine, 38 seconds. 

38 seconds vs 1305.977 seconds means that that java application is 97.09% more efficient. 

I knew that c++ is supposed to be faster and more efficient so… 

###Why does this happen?###

Some research and more testing brought me straight to the following conclusion: the reason was because in the c++ program I had not used the built in functions for string array manipulations, necessary to determine if the product was an operand. Since both methods have to perform the same number of multiplications (in fact the Java program has to do more since I did not include the check to see if the multiplication had already been done before) this is the only other significant difference. 

###What can we take from this little experiment?###

The built in functions are optimum. The function I wrote for array manipulation involved loops which were likely one of the main contributors to the c++ program's deplorable run time. 

So, now we have CONCRETE evidence supporting the notion that you should always take advantage of the built in functions!


###Files###


C++ program: main.cpp FindPalindrome.h 

Java program: FindPalindrome.java
