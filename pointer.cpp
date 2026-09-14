#include <iostream>
#include <string>
#include <algorithm>
using std::string;


int main(){

    int a = 10;
    int* b = &a;
    int** c = &b;
    int*** d = &c;
 
    std::cout << "value of a : " << a << "\n";
    std::cout << "value of b : " << *b << "\n"; 

    string str = "swayam";
    int num[] = {1,4,3};


    std::sort(num,num + sizeof(num)/sizeof(num[0]));


    std::cout << "value of str : " << str << "\n";
    std::cout << "value of num : ";
    
    for(int& val : num){
        std::cout << val << " ";
    }

    return 0;
}