#include <iostream>
#include <string>
#include <vector>
#include <cassert> //Library for running tests

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
        length= (l>=0)? l:0; //Prevent negative length
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

    //Change hair based on Styling action (Polymorphism)
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
            std::cout <<"Straight hair is now Curly!\n";
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
    virtual void useTool(Hair& hair)= 0; //Virtual function that can not used directly and define how it styles hair
    virtual ~StylingTool() {} //Virtual destructor for cleanup
};

//Tools that cut Hair: Scissors Class
class Scissors: public StylingTool {
public:
    void useTool(Hair& hair) 
    {
        std::cout<< "Cutting hair with Scissors.\n";
        hair.setLength(hair.getLength() - 0.5); // Cut 0.5cm
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
        dyeColor = color; //Constructor: Sets the dye's color
    }
// Defines how dye effects hair
    void useTool(Hair& hair)
    {
        std::cout << "Dyeing hair with " << dyeColor <<".\n";
        hair.setColor(dyeColor);
        hair.setCondition("Damaged");
        hair.applyStyle("Dye");
        std::cout << "Hair is now "<< dyeColor <<" but damaged.\n";
    }
};

//Tool that curls hair
class CurlingIron: public StylingTool{
public:
//Makes hair curly and damages condition
    void useTool(Hair& hair) {
        std::cout<<"Curling hair with Curling Iron.\n";
        hair.setTexture("Curly");
        hair.setCondition("Damaged");
        hair.applyStyle("Curl");
        std::cout<<"Hair is curly but damaged.\n";
    }
};

//Avatar: Represent a person with hair
class Avatar {
private:
    std::string name; //Name of the Avatar
    Hair hair; //Stores all the hair information

public:
    Avatar(std::string n, Hair h) : name(n), hair(h) {
        //Initialization is done in the initializer list
    }

    void styleHair(StylingTool& tool){
        std::cout<<name<<" is styling their hair.\n";
        tool.useTool(hair);
    }

    void display() {
        std::cout<<"Avatar: "<<name<<"\n";
        hair.display();
    }
};
//For Test
void runTests()
{
    std::cout<<"Running Tests...\n";
    Hair testHair("Black", "Straight", 23.0, "Healthy");

    assert(testHair.getColor()=="Black");
    assert(testHair.getTexture()=="Straight");
    assert(testHair.getLength()==23.0);
    assert(testHair.getCondition()== "Healthy");

    std::cout<<"All tests Passed successfully!\n\n";
}



int main()
{
    runTests(); //To run the test

    std::cout<<"===================="<<std::endl;
    std::cout<<"|       HAIR       |"<<std::endl;
    std::cout<<"===================="<<std::endl;

    //Variables to store user inputs
    std::string name, color, texture, condition;
    double length;

    //Avatar Name
    std::cout<<"Enter your avatar's name: ";
    std::getline(std::cin, name); //Allows space in name

    std::cout<< "Enter Your Hair Color: ";
    std::getline(std::cin, color); //Using getlines so that it reads everything until the Enter key is pressed — including spaces
    std::cout<< "Enter Your Hair Texture: ";
    std::getline(std::cin, texture); 
    do
    {
        std::cout<< "Enter Hair Length in cm: ";
        std::cin>>length;

        if(length<0)
        {
            std::cout<<"Length cannot be negative! Try again.\n";
        }
    } while (length<0);
    std::cin.ignore(); //Clear newline from input buffer
    std::cout<< "Enter Your Hair Condition: ";
    std::getline(std::cin, condition);

    // Create hair and avatar
    Hair hair(color, texture, length, condition);
    Avatar avatar(name, hair);

    //Styling tools
    Scissors scissors;
    CurlingIron curlingIron;

    //Store tools in a list
    std::vector<StylingTool*> tools = {&scissors, nullptr, &curlingIron}; //Storing pointers to objects

    //Showing Initial state
    std::cout<<"\nInitial State:\n";
        std::cout<<"-----------------\n";

    avatar.display();
    std::cout<<"\n";

    //INteractive menu loop
    int choice;
    do
    {
        std::cout<<"Choose a styling tool:\n";
        std::cout<<"----------------------\n";

        std::cout<<"1. Scissors\n2. Dye\n3. Curling Iron\n4. Exit\n";
        std::cout<<"\nEnter choice (1-4): ";
        std::cin>>choice;

        std::cin.ignore(); //To cleare newline

        if (choice ==2)
        {
            std::string dyeColor; //Declaration for dyeColor
            std::cout<<"Enter dye color: ";
            std::getline(std::cin, dyeColor);
            Dye dye(dyeColor);
            avatar.styleHair(dye);
            std::cout<<"\nUpdate State: \n";
            avatar.display();
            std::cout<<"\n";

        }
        
        else if (choice >=1 && choice <=3)
        {
            avatar.styleHair(*tools[choice - 1]);
            std::cout<<"\nUpdate State: \n";
            avatar.display();
            std::cout<<"\n";
        }
        else if (choice!=4)
        {
            std::cout<<"Invalid choice! Please enter 1-4.\n\n";
        }   
        
    } while (choice != 4);

    std::cout<<"Thank You for using Hair styling Simulator!\n";
    

    return 0;
}
