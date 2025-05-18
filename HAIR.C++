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

    //Change hair based on Styling (Polymorphism)
    void applyStyle(std::string styleType) 
    {
        std::cout <<"Styling "<< texture <<" hair with "<<styleType<<".\n";
        if(texture == "Curly" && styleType == "Straighten")
        {
            std::cout <<"Curly hair stays curly, resists straightening!\n";
        }
        else if(texture == "Straight" && styleType=="Curl")
        {
            texture = "Curly";
            std::cout <<"Sstraight hair is now Curly!\n";
        }
        else
        {
            std::cout <<"Style applied normally.\n";
        }
    }

    //Shows the hair's current state
    void display(){
        std::cout<<"Hair: Color= "<< color <<", Texture= "<< texture <<", Length= "<< length <<"cm, Condition= "<< condition <<"\n";
    }
};

//Abstract Base Class
class StylingTool{
public:
    virtual void useTool(Hair& hair)= 0; //Virtual function that can not used directly
    virtual ~StylingTool() {} //Virtual destructor for cleanup
};

//Tools that cut Hair: Scissors Class
class Scissors: public StylingTool {
public:
    void useTool(Hair& hair) 
    {
        std::cout<< "Cutting hair with Scissors.\n";
        hair.setLength(hair.getLength() - 0.5); // Cut 5cm
        hair.setCondition("Healthy");
        hair.applyStyle("Cut");
        std::cout<< "Hair is now 5cm shorter and healthier.\n";
    }
};

//Tool that changes hair color: Dye Class
class Dye: public StylingTool {
private:
    std::string dyeColor; //Color to apply on hair

public:
    Dye(std::string color) {
        dyeColor = color;
    }

    void useTool(Hair& hair)
    {
        std::cout << "Dyeing hair with " << dyeColor <<".\n";
        hair.setColor(dyeColor);
        hair.setCondition("Damaged");
        hair.applyStyle("Dye");
        std::cout << "Hair is now "<< dyeColor <<" but damaged.\n";
    }
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
