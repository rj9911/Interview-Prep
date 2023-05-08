class Solution {
public:
    double myPow(double x, long n) {
      if(n==0) return 1; // Base case For recursion
      if(n==-1) return 1/x; // Base case for the question
    
      double temp = myPow(x,n/2); // Divide And Conquer
      if(n%2==0) return temp*temp; // if n is even no.
        
      // Math  
      if(n>0) return temp*temp*x; // if n is odd and +ve no
      return temp*temp*(1/x); // if n is odd as well as -ve no.
    }
};