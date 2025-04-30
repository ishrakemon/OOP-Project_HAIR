#include <iostream>
#include <string>
#include <vector>

class Hair {
    //Only Hair Class can directly access this variables and thus prevents accidental modification.
private: 
    std:: string color; //For Hair color
    std:: string texture; // For Hair type
    double length; // For Hair Length
    std:: string condition; //Hair health

public:
    //Used to pass values when creating an object._Constructor for Class Hair.
    Hair(std::string c, std::string t, double l, std:: string cond) 
    {
        //Object's member variables
        color= c;
        texture= t;
        length= l;
        condition= cond;
    }

};

int main()
{
    std::cout<<"===================="<<std::endl;
    std::cout<<"|       HAIR       |"<<std::endl;
    std::cout<<"===================="<<std::endl;

    return 0;
}
