#include <iostream>
#include <string>
#include <vector>

class Hair {
    //Only Hair Class can directly access this variables and thus prevents accidental modification.
private: 
    std:: string color; //For Hair color
    std:: string texture; // For Hair type
    double length; // For Hair Length
};

int main()
{
    std::cout<<"===================="<<std::endl;
    std::cout<<"|       HAIR       |"<<std::endl;
    std::cout<<"===================="<<std::endl;
    
    return 0;
}
