//Problem:
//A palindromic number reads the same both ways. The largest palindrome made from
//the product of two 2-digit numbers is 9009 = 91 × 99.
//Find the largest palindrome made from the product of two 3-digit numbers.
#include <sys/time.h>
#include <iostream>
#include "FindPalindrome.h"

using namespace std;


int main () { 
 
	int digits_specified = 0;
	
	cout << "\n\n(_}{_}{_}{_}{_}{_}{_}{_}{_}{_}{_}{_}{_}{_}{_}{_}{_}{_}{_}{_}{_}{_}{_}{_}{_}{_}{_}{_}{_}{_}{_}{_)\n\n"; 

	cout << "Please enter the number of digits for which largest palindromic product will be given: ";
	cin>>digits_specified;
	cout << "\n";
	
	//For testing purposes to print out all palindromes generated
	/*
	std::cout << "Operand 1" <<"\t\t";
	std::cout << "Operand 2" <<"\t\t";
	std::cout << "Product" <<"\t\t\n\n";
	*/
	
	FindPalindrome trial1(digits_specified);

	//find palindrome and record the time it took to do this
	struct timeval start, end;
    long mtime, seconds, useconds;
    
    gettimeofday(&start, NULL);
	//start actual calculation for palindrome
	trial1.Product_Generator();
	gettimeofday(&end, NULL);
    
	seconds  = end.tv_sec  - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + useconds/1000.0) + 0.5;
	cout << "\n";
    printf("Elapsed time: %ld milliseconds\n", mtime);
 	cout << "\n";
	cout<<endl<< "Largest palimdromic number: "<< trial1.Greatest_Palindrome_Found()<<endl; 

	cout << "\n\n(_}{_}{_}{_}{_}{_}{_}{_}{_}{_}{_}{_}{_}{_}{_}{_}{_}{_}{_}{_}{_}{_}{_}{_}{_}{_}{_}{_}{_}{_}{_}{_)\n\n"; 

	cout << "\n";
    return 0;
}