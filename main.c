#include <stdio.h>
#include <stdlib.h>
struct polynomial
{
    double coefficient ;
    int degree ;
};
void Read (struct polynomial x[] , int n) {
   int j  ;
   for (j = 0 ; j < n ; j++) {
    printf("Enter coefficient of X^%d :" , n-j-1) ;
    scanf("%lf" , &x[j].coefficient) ;
    x[j].degree = (n-j-1) ;
   }
}
void Print(struct polynomial answer[] , int k){
    int q ;
  for (q = 0 ; q < k ; q++) {
        if ( (q) && (answer[q].coefficient >= 0) ) {
             printf(" + ") ;
        }
        printf("%lf" ,answer[q].coefficient);
        if (answer[q].degree) {printf("X");}
        if ( (answer[q].degree !=1) && (answer[q].degree !=0)){
            printf ("^%d" ,answer[q].degree) ;
        }

  }
}
int main()
{
    /*
    please remember  if x / y = z
    therefore  x --> dividend
               y --> divisor
               z --> result
    */
    /*
    please note that if you decide to enter n terms you should start to enter coefficients from x^(n-1) to x^0
    for example if you want to enter three terms
    you should enter the coefficients of all terms form x^2 to x^0
    a(x)^2 + bx + c

    VERY IMPORTANT NOTE
    if your input is something like that : X^4 + 9
    you must enter five terms not two terms :
     coefficient of X^4 : 1
     coefficient of X^3 : 0
     coefficient of X^2 : 0
     coefficient of X^1 : 0
     coefficient of X^0 : 9
    */
static struct polynomial dividand [100] ;
static struct polynomial divisor [100] ;
struct polynomial result [100]  ;
int cnt = 0 , Divisor_Terms ,i ,  Dividend_terms  ;
    printf ("Enter number of terms of dividend  : ") ;
    scanf ("%d" , &Dividend_terms) ;
    Read(dividand , Dividend_terms) ;
    printf ("Enter number of terms of divisor : ") ;
    scanf ("%d" , &Divisor_Terms) ;
    Read(divisor , Divisor_Terms) ;
    printf("The result of division is :\r\n") ;
    while (dividand[cnt].degree >= divisor[0].degree)
    {
        result[cnt].degree = (dividand[cnt].degree - divisor[0].degree) ;
        result[cnt].coefficient = (dividand[cnt].coefficient / divisor[0].coefficient) ;
        for (i = 0 ; i < Divisor_Terms ; i++)
        {
            dividand[i + cnt].coefficient -= result[cnt].coefficient * divisor[i].coefficient ;
        }
        cnt ++ ;
    }
 Print (result , cnt) ;
    if (dividand[cnt].coefficient)
    {
         printf(" + ") ;
        for (i = cnt ; i < Dividend_terms ; i++)
        {
            if ((i!=cnt) &&(dividand[i].coefficient >= 0)) printf(" + ") ;
            if (i == cnt) printf("(") ;
            printf ("%lf" , dividand[i].coefficient) ;
            if (dividand[i].degree)
            {
                printf("X");
            }
            if ( (dividand[i].degree !=1) && (dividand[i].degree !=0))
            {
                printf ("^%d" ,dividand[i].degree) ;
            }
        }
        printf(")/(") ;
        Print(divisor , Divisor_Terms) ;
        puts(")") ;
    }
    return 0;
}
