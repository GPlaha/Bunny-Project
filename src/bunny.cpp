#include "../include/bunny.h"

Bunny::Bunny()
{
    int randomValue = rand() % 100;
    
    age = 0;

    (randomValue % 2 == 0) ? (sex = Gender::male):(sex = Gender::female);
    
    if      (randomValue < 25)     {colour = Colours::white;}                  
    else if (randomValue < 50)     {colour = Colours::brown;}
    else if (randomValue < 75)     {colour = Colours::black;}
    else                           {colour = Colours::spotted;}
     
    randomValue = rand() % 100;
    (randomValue < 2 ) ? (infected = true) : (infected = false);

    
    randomValue = rand() % names.size(); 
    Name = names[randomValue]; 
}



std::string Bunny::GetSex()
{
    return (sex == Gender::male) ? ("male") : ("female");
}

std::string Bunny::GetColour()
{
    if (colour == Colours::white)
        return "white";
    else if (colour == Colours::brown)
        return "brown";
    else if (colour == Colours::black)
        return "black";
    return "spotted";
}

int Bunny::GetAge()
{
    return age;
}

std::string Bunny::GetName()
{
    return Name; 
}

std::string Bunny::GetInfected()
{
    return (infected) ? ("infected") : ("non infected");
}

void Bunny::increaseAge()
{
    age++;
}

bool Bunny::isInfected()
{
    return infected;
}

Bunny::Bunny(Colours motherCol)
{
    
    int randomValue = rand() % 100;

    age = 0;
    
    (randomValue % 2 == 0) ? (sex = Gender::male):(sex = Gender::female);
    
    colour = motherCol;
    
    randomValue = rand() % 100;
    (randomValue < 2 ) ? (infected = true) : (infected = false);

    
    randomValue = rand() % names.size(); 
    Name = names[randomValue]; 
}

Colours Bunny::GetColourVal()
{
    return colour;
}

void Bunny::setInfected()
{
    infected = true;
}