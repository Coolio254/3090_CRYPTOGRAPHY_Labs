#include<iostream>
#include<math.h>
#include<cstdlib>

using namespace std;

//function to find the greatest common divisor (GCD) using Euclidean algorithm
int gcd(int a, int b) {
   int t;
   while(1) {
      t = a % b;
      if(t == 0)
         return b;
      a = b;
      b = t;
   }
}

int main() {
   
    int range;
    //Prompt the user to enter the range for generating prime numbers
    cout << "Please enter the number of choice n'th prime numbers: " << endl;
    cin >> range;
    cout << "\n";
    
    int a = 0;
    
    //Find the number of prime numbers less than the specified range
    for (int i = 2; i < range; i++) {
        bool prime = true;
        
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                prime = false;
                break;    
            }
        }   
        if (prime) {
            a++;
        } 
    }
    
    //Store the prime numbers in an array
    int prime_numbers[a];
    int j = 0;
    for (int i = 2; i < range; i++) {
        bool prime = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                prime = false;
                break;    
            }
        }   
        if (prime) {
            prime_numbers[j] = i;
            j++;
        } 
    }
    
    //Select two random prime numbers from the array
    double p = prime_numbers[rand() % (a - 1)];
    double q = prime_numbers[rand() % (a - 1)];
   
    //Calculate n (part of the public key)
    double n = p * q;
    double track;
   
    //Calculate the totient (phi)
    double phi = (p - 1) * (q - 1);
   
    //choose a public key exponent e such that 1 < e < phi and gcd(e, phi) = 1
    double e = 7;
    while(e < phi) {
        track = gcd(e, phi);
        if(track == 1)
            break;
        else
            e++;
    }
   
    //calculate the private key exponent d such that d * e = 1 mod phi
    double d1 = 1 / e;
    double d = fmod(d1, phi);
   
    //ask the user to enter the plaintext number they want to encrypt
    double plaintext = 0;
    cout << "Please enter the number you want to encrypt: " << endl;
    cin >> plaintext;
    cout << "\n";
   
    //Encrypt the message
    double c = pow(plaintext, e); 
   
    //Decrypt the message
    double m = pow(c, d);
    c = fmod(c, n);
    m = fmod(m, n);
   
    //Display the results
    cout << "The range in which prime numbers should be is from 1 to " << range << "\n";
    cout << "Original number: " << plaintext << "\n";
    cout << "p = " << p << "\n";
    cout << "q = " << q << "\n";
    cout << "n = pq = " << n << "\n";
    cout << "phi = " << phi << "\n";
    cout << "e = " << e << "\n";
    cout << "d = " << d << endl << "\n";
   
    cout << "Public Key is {" << e << "," << n << "}" << "\n";
    cout << "Private Key is {" << d << "," << n << "}" << "\n";
    cout << "Encrypted message: " << c << endl;
    cout << "Decrypted message: " << m << endl;
    return 0;
}
