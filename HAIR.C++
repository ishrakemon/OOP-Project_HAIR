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

    //Functions that let others see the properties of Class_Hair (Getters)
    std::string getColor() {return color;}
    std::string getTexture() {return texture;}
    double getLength() {return length;}
    std::string getCondition() {return condition;}

    //Function that let others change the Hair's properties (Setters)
    void setColor(std::string c) {color = c;}
    void setTexture(std::string t) {texture = t;}
    void setLength(double l)
    {
        // Prevent negative hair length given by user
        if(l>=0) length = l;
        else length = 0;
    }
    void setCondition(std::string cond) {condition = cond;}
    





};

int main()
{
    std::cout<<"===================="<<std::endl;
    std::cout<<"|       HAIR       |"<<std::endl;
    std::cout<<"===================="<<std::endl;

    //Variables to store user inputs
    std::string name, color, texture, condition;
    double length;

    std::cout<< "Enter Your Hair Color: ";
    std::getline(std::cin, color); //Using getlines so that it reads everything until the Enter key is pressed — including spaces
    std::cout<< "Enter Your Hair Texture: ";
    std::getline(std::cin, texture); 
    std::cout<< "Enter Hair Length in cm: ";
    std::cin>>length;
    std::cin.ignore(); //Clear newline from input buffer
    std::cout<< "Enter Your Hair Condition: ";
    std::getline(std::cin, condition);


    return 0;
}
