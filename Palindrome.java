class Palindrome{
    public static void main(String[] args)
    {
        
        
        //hardcoded for testing
        int digits = 5;
        
        
        int upper_limit = 0;
        int lower_limit = 0;
        int greatest = 0;
        
        
        upper_limit = (int)(Math.pow(10.0,  (double)(digits)) - 1);
        lower_limit = (int)(Math.pow(10.0,  (double)(digits -1)));
        
        
        for (int number_one = upper_limit; number_one>=lower_limit; number_one--){
            for(int number_two = upper_limit; number_two>=lower_limit; number_two--){
                int current = number_one * number_two;
                if(greatest < current){
                    if(isPalindrome(current)){
                        greatest = current;
                    }
                }
            }
        }
        
        System.out.println(greatest);
    }
    private static boolean isPalindrome(int number){
        String numberToTest = Integer.toString(number);
        boolean isPalindrome = true;
        int strLength = numberToTest.length();
        int loopLength = strLength/2;
        for (int i=0 ; i<loopLength ; i++){
            if(numberToTest.charAt(i) != numberToTest.charAt(strLength-i-1)){
                 
                isPalindrome = false;  
            }
            
        }
        return isPalindrome;
    }
    
}

