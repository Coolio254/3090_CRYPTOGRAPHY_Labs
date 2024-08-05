#include<iostream>
#include<math.h>
#include<cstdlib>
 
using namespace std;
 

int Greatest_Common_Divisor(int a, int b)
{
    int temporary;
    while(1)
    {
        temporary = a%b;
        if(temporary==0)
        return b;
        a = b;
        b = temporary;
    }
}
 
int main()
{
	
	int range;

	cout<<"Enter the number prime numbers : "<<endl;
	cin>>range;
	
	int a=0;
	
    for (int i=2; i<range; i++) 
    {
        bool prime=true;
        
        for (int j=2; j*j<=i; j++)
        {
            if (i % j == 0) 
            {
                prime=false;
                break;    
            }
        }   
        if(prime){
        	
        	a++;
        	
		} 
    }
    int prime_numbers [a];
    int j=0;
    for (int i=2; i<range; i++) 
    {
        bool prime=true;
        for (int j=2; j*j<=i; j++)
        {
            if (i % j == 0) 
            {
                prime=false;
                break;    
            }
        }   
        if(prime){
        	
        	
        	
        	prime_numbers[j]=i;
        	j++;
		} 
    }
	
    
    double p = prime_numbers[rand()%(a-1)];
    double q = prime_numbers[rand()%(a-1)];
    double n=p*q;
    double count;
    double totient = (p-1)*(q-1);
 
    
    double e=2;
 
 
    while(e<totient){
    count = Greatest_Common_Divisor(e,totient);
    if(count==1)
        break;
    else
        e++;
    }
 
   
    double d;
    
   double k;
 
    
    float x;
    
    for(k=1;k<20;k++)
    {
    x = (1 + (k*totient))/e;
   
    if(roundf(x)==x)
{
    d=x;
    break;
    } 
}
	
 
  
    cout<<"\n"<<"p = "<<p;
    cout<<"\n"<<"q = "<<q;
    cout<<"\n"<<"n = pq = "<<n;
    cout<<"\n"<<"totient = "<<totient;
    cout<<"\n"<<"e = "<<e;
    cout<<"\n"<<"d = "<<d;

 
    return 0;
}
