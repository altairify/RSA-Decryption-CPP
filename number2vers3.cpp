#include <iostream> 
#include <vector>
#include <cmath>



unsigned long long int modularExp(unsigned long long int C, unsigned long long int D, unsigned long long int N) {
    unsigned long long int tot = 1;
    if (D == 0) {
        return 1;
    }
    if (D == 1) {
        return C;
    }
    
    while (D > 0) {
    if (D == 0) {
        return 1;
    }
    //if (D == 1) {
        //return tot;
    //}
    if (D % 2 == 0) {
        C = (C * C) % N;
        D = D/2;
    }
    else if (D % 2 != 0) {
        tot = (tot * C) % N;
        D--;
    }
    }
    return tot;
}
bool isPrime(int num) {
    if (num == 0 || num == 1) {
        return false;
    }
    int sqrtnum = std::sqrt(num);
    for (unsigned int i = 2; i <= sqrtnum; i++) {
    if (num % i == 0) {
        return false;
    }
}
    return true;
}
int gcd(int a, int b ) {
    if (a == b) {
        return a;
    }
    else if (a == 0) {
        return b;
    }
    else if (b == 0) {
        return a; 
    }
    if (a > b) {
        return gcd(a % b, b);
    }
    else {
        return gcd(a, b % a);
    }
    return 0;
}


int main() {
int e;
unsigned long long int n;
int m;

//std::cout << "Enter numbers " << std:: endl;

std::cin >> e;
std::cin >> n;
std::cin >> m;


if(!std::cin>>e) {
    return 1;
}
else {
    if (!std::cin>>n) {
        return 1;
    }
    else {
       if (!std::cin>>m) {
            return 1;
        }
    }
//error checking
//std::cout << e << " " << n << " " << m << std::endl;


int numbers;
std::vector<unsigned long long int> numberVector(0);

for (unsigned long long int i = 0; i < m; i++) {
    std::cin>>numbers;
    if (!std::cin>>numbers) {
        return 1;
    }
    numberVector.push_back(numbers);
} 


//test
//for (unsigned long long int i = 0; i < numberVector.size(); i++) {
    //std::cout << numberVector.at(i) << " ";
//} 
std::cout << std::endl;
unsigned long long int sQrtofN = std::sqrt(n);
int p = 0;
int q = 0;
bool foundPair = false;

for (unsigned int i = 2; i <= sQrtofN && foundPair == false; i++) {
    if (n % i == 0) {
        p = i;
        q = n/i;
        if (isPrime(p) && isPrime(q) && p < q) {
            //std:: cout << p << " " << q << " ";
            foundPair = true;
        }
    }
}

if (!foundPair) {
    std::cout << "Public key is not valid!" << std::endl;
}

//find phi
if (foundPair) {
    unsigned long long int k = 1;
    unsigned long long int phi = (p-1) * (q-1);
    //std::cout << phi << " ";
   if (gcd(e, phi) == 1) {
    unsigned long long int d = 0;
    //find k
    bool foundK = false;
    while (foundK == false ) {
        if((phi * k + 1) % e == 0) {
            foundK = true;
            d = (phi * k + 1) / e;
        }
    k++;
    //std::cout << ??? << std::endl;
   }
   std:: cout << p << " " << q << " ";
   std::cout << phi << " ";
   std::cout << d << std::endl;
   std::vector<unsigned long long int> numberVectorM(m);
   for (unsigned int i = 0; i < m; i++) {
    numberVectorM.at(i) = 1; // initialize 0->1 
   }
   for (unsigned int i = 0; i < m; i++) {
    numberVectorM.at(i) = modularExp(numberVector.at(i), d, n);
    std::cout <<(numberVectorM.at(i)) << " ";
   }
   std::cout << std::endl;
    int number = 0;
   //convert to text
   std::vector<char> wordVector = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
   for (unsigned int i = 0; i < m; i++) {
     if (numberVectorM.at(i) <= 32 && numberVectorM.at(i) >= 7) {
       std::cout << wordVector.at(numberVectorM.at(i)-7);
     } 
     else if (numberVectorM.at(i) == 33) {
        std::cout << ' ';
     }
     else if (numberVectorM.at(i) == 34) {
        std::cout << '\"';
     }
     else if (numberVectorM.at(i) == 35) {
        std::cout << ',';
     }
     else if (numberVectorM.at(i) == 36) {
        std::cout << '.';
     }
     else if (numberVectorM.at(i) == 37) {
        std::cout << "'";
     }
     else if (numberVectorM.at(i) > 37 || numberVectorM.at(i) < 7) {
        std::cout << "Public key is not valid!" << std::endl;
     }
   }
   }
   else if (gcd(e, phi) != 1){
    std::cout << "Public key is not valid!" << std::endl;
   }
}
}
return 0;
}
