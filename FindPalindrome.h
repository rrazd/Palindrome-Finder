/*
 *  FindPalindrome.h
 */

//Problem:
//A palindromic number reads the same both ways. The largest palindrome made from
//the product of two 2-digit numbers is 9009 = 91 × 99.
//Find the largest palindrome made from the product of two 3-digit numbers.


#include <math.h>

class FindPalindrome {

	private:
		
		//CLASS member vars

		//multiplicand 1
		int number_one; 
		//multiplicand 2
		int number_two;
		//holds current product
		int current;
		//copy of current product copy so as the current var values is not manipulated as its original will be needed
		int copy; 	
		//holds most recently discovered palindrome
		int palindrome; 
		//holds greatest palindrome discovered 
		int greatest;
	    
		int upper_limit;
	
	
	public:
	
	    //Constructor
		FindPalindrome(int digits_requiered);
		
		//Accessors
        int Greatest_Palindrome_Found();

		//Mutators
		void Product_Generator();
		void Determine_if_Palindrome();  

};



FindPalindrome::FindPalindrome(int digits_requiered){
	
	
	//both number one and number two are set to their minimum possible values
	//for palindrome of requiered digits
	upper_limit = pow(10, digits_requiered) - 1;
	number_one = pow(10, digits_requiered -1);
	number_two = number_one;
	
	 current = 0;
	 copy = 0; 	
	 palindrome = 0;
	 greatest = 0;

}



int FindPalindrome::Greatest_Palindrome_Found(){

	return greatest;
}




void FindPalindrome::Product_Generator(){
	
 	int original_number_two = number_two;
 		

	//While loop: for 10 * (varying) multiplications ie/ [10 * 10 ... 10 * 99]
	//this always runs but only once at the start
		
	 while (number_two <= upper_limit) {		
			
			//test initial numbers to see if they generate palindrome
			Determine_if_Palindrome();
			
			number_two = number_two + 1;
 
		}
	 
	
	//we have reached the 10 * 100 case if we are assuming 2 digits, which caused us to skip out 
	//of the if block
	
	
	//While loop: for (11 to 99) * (10 to 99) multiplications without repeating the multiplications already
	//done in the if clause ie/ [11*11, 11*12.... 55*56, 55*57 .... 99*99]

 	while (number_one <= upper_limit) {
		
		number_one = number_one + 1;
		number_two = original_number_two;
		
		while (number_two <= upper_limit) {
		
			number_two = number_two + 1;
			
			if (number_two >= number_one) {
				
				Determine_if_Palindrome();
			}
		}
	}	
}




void FindPalindrome:: Determine_if_Palindrome(){
	//FUNCTION vars

	//used in determining length of array and storing product into array
	int array_length = 0;
	//copy of array length so that original length value is still available
	int array_length_cpy = 0;	
	//vars for checking for palindrome properties
	int head = 0;
	int tail = 0;
	int retrieve_one = 0;
	int retrieve_two = 0;




	current = number_one * number_two;
	copy = current;



	//get length of number and create array to hold number
	while (copy != 0) {
		copy /= 10;
		++array_length;
	}

	int store[array_length];

	//restore to products value for extraction manipulations
	copy = current;


	array_length_cpy = array_length;
	//extract digits from number and poopulate array
	for (int i = array_length_cpy; i>0; --i) {
		store[i-1] = copy%10;
		copy/=10;
		--array_length_cpy;
	}


	//Compare last and first digits then move "inwards" comparing the digits
	tail = array_length -1;

	retrieve_one = store[head];
	retrieve_two = store[tail];

	if (retrieve_one == retrieve_two) {
		for (int i = (array_length/2); i > 0; --i) {
			tail = tail -1;
			head = head + 1;
			retrieve_one = store[head];
			retrieve_two = store[tail];

			if (retrieve_one != retrieve_two) {
				return;
			}
		}
		
		palindrome = current; //it is a palindrome
		
		//test for if it is the biggest one found yet
		if (current > greatest) {
			greatest = current;
			
		/*	
			//output of all palindromic products for user info
			
			std::cout << "    " << number_one <<"\t\t\t";
			std::cout  << "   "<<number_two<<"\t\t\t";
			std::cout << "  "<<current<<"\n";
		 
		*/
			
		
		}
	}
	  
}


