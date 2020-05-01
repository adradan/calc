#include <iostream>
#include <string>
#include <cstdio>
#include <limits>
#include <iomanip>

void addition( double a, double b){
    std::cout << std::fixed;
    std::cout << std::setprecision(4);

    std::cout << "Result: " << a + b << '\n';
}

void subtraction( double a, double b){
    std::cout << std::fixed;
    std::cout << std::setprecision(4);

    std::cout << "Result: " << a - b << '\n';
}

void multiply( double a, double b){
    std::cout << std::fixed;
    std::cout << std::setprecision(4);

    std::cout << "Result: " << a * b << '\n';
}

void divide( double a, double b){
    std::cout << std::fixed;
    std::cout << std::setprecision(4);
    
    std::cout << "Result: " << a / b << '\n';
}

int opFind(std::string op){
    std::string ad ("+"); //Defines what we need to look for
    std::string sub ("-");
    std::string mul ("*");
    std::string div ("/");
    std::string ending ("quit");

    std::size_t found = op.find(ad);
    if (found!=std::string::npos){
    return 1;
    }
    found = op.find(sub);
    if (found!=std::string::npos){
        return 2;
    }
    found = op.find(mul);
    if (found!=std::string::npos){
        return 3;
    }
    found = op.find(div);
    if (found!=std::string::npos){
        return 4;
    }
    found = op.find(ending);
    if (found!=std::string::npos){
        return 6;
    }
    else {
        return 5;
    }
}

int main(){
    double first{};
    double second{};
    std::string operation;

    std::cout << std::fixed;
    std::cout << std::setprecision(4);

    std::cout << "Enter first number. (Up to 4 decimal places)" << '\n';
    std::cin >> first; //Stores first variable


    std::cout << "Enter second number. (Up to 4 decimal places)" << '\n';
    std::cin >> second; //Stores second variable

    std::cin.clear(); //Clears input buffer so ENTER is not used as input
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter operator (+ - / *)" << '\n';
    std::getline (std::cin, operation); //Gets operator they want to use

    int opTwo { opFind(operation) }; //Calls on opFind to figure out operation given
    if ( opTwo == 1 ){
        addition(first, second);
    }else if ( opTwo == 2 ){
        subtraction(first, second);
    }else if ( opTwo == 3 ){
        multiply(first, second);
    }else if ( opTwo == 4 ){
        divide(first, second);
    }else if ( opTwo == 5){ //If given unsupported character allows to try again or quit
        std::string operation;
        std::cout << "You have entered a wrong operator. Now quitting." << '\n';
    }else if ( opTwo == 6){
        std::cout << "Quitting..." << '\n';
    } else{
        return 0;
    }

    return 0;
}
