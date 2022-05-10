#include "BunnyManager.h"
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <conio.h>

BunnyManager::BunnyManager()
{
    addBunny();
    addBunny();
    addBunny();
    addBunny();
    addBunny();
    programme();

};

void BunnyManager::addBunny()
{
    
    std::shared_ptr<Bunny>newBunny(new Bunny());
    std::cout << newBunny->GetName() << " a " << newBunny->GetInfected() << " " << newBunny->GetColour() << " bunny that is " << newBunny->GetSex() << " and " << newBunny->GetAge() << "  years old was created" << std::endl;
    bunnyList.push_back(newBunny);
}

void BunnyManager::ageAllBunny()
{
    std::list<std::shared_ptr<Bunny>>::iterator bunny = bunnyList.begin();
    while (bunny != bunnyList.end())
    {
        (*bunny)->increaseAge();
        if (((*bunny)->GetAge() > MAX_AGE_HEALTHY && !(*bunny)->isInfected()) || ((*bunny)->GetAge() > MAX_AGE_INFECTED && (*bunny)->isInfected()))
        {
            std::cout << (*bunny)->GetInfected()<< " "  << (*bunny)->GetColour()<< " " << (*bunny)->GetAge() << " year old " << (*bunny)->GetSex() << " called " << (*bunny)->GetName() << "bunny die" << std::endl;
            bunnyList.erase(bunny++);
        }
        else
        {
            ++bunny;
        }
    }
}

void BunnyManager::displayAll()
{
    std::list<std::shared_ptr<Bunny>>::iterator bunny;
    for (bunny = bunnyList.begin(); bunny != bunnyList.end(); ++bunny)
    {
        std::cout << (*bunny)->GetInfected()<< " "  << (*bunny)->GetColour()<< " " << (*bunny)->GetAge() << " year old " << (*bunny)->GetSex() << " called " << (*bunny)->GetName() << std::endl;
    }
}

bool BunnyManager::maleAndTwo()
{
    std::list<std::shared_ptr<Bunny>>::iterator bunny;
    for (bunny = bunnyList.begin(); bunny != bunnyList.end(); ++bunny)
    {
        if((*bunny)->GetAge() > 1 && !(*bunny)->isInfected() && (*bunny)->GetSex() == "male")
        {
        return true;
        }
    }
    return false;
}


void BunnyManager::addBunny(Colours motherCol)
{
    std::shared_ptr<Bunny>newBunny(new Bunny(motherCol));
    std::cout << newBunny->GetName() << " a " << newBunny->GetInfected() << " " << newBunny->GetColour() << " bunny that is " << newBunny->GetSex() << " and " << newBunny->GetAge() << "  years old is born" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    bunnyList.push_back(newBunny);
}

void BunnyManager::breed()
{
    std::list<std::shared_ptr<Bunny>>::iterator bunny;
    for (bunny = bunnyList.begin(); bunny != bunnyList.end(); ++bunny)
    {
        if((*bunny)->GetAge() >= MIN_AGE_BREED && !(*bunny)->isInfected() && (*bunny)->GetSex() == "female")
        {
            addBunny((*bunny)->GetColourVal());
        }
    }
}


int BunnyManager::InfectedCount()
{
    int radioCount = 0;
    std::list<std::shared_ptr<Bunny>>::iterator bunny;
    for (bunny = bunnyList.begin(); bunny != bunnyList.end(); ++bunny)
    {
        if((*bunny)->isInfected())
        {
            radioCount++;
        }
        
    }
    return radioCount;
}

void BunnyManager::infectBunny(int InfectedCount)
{
    int infectedCount = 0;
    std::list<std::shared_ptr<Bunny>>::iterator bunny;
    for (bunny = bunnyList.begin(); bunny != bunnyList.end(); ++bunny)
    {
        if (infectedCount == InfectedCount)
        {
            return;
        }
        else if(!(*bunny)->isInfected())
        {
            (*bunny)->setInfected();
            infectedCount++;
        }

    }
    
}


void BunnyManager::killHalf()
{
    std::list<std::shared_ptr<Bunny>>::iterator bunny;
    
    int killAmount = bunnyList.size()/2;
    for(int i = 0; i < killAmount; i++)
    {
        int randomBunny = rand()% bunnyList.size();
        bunny = bunnyList.begin();
        std::advance(bunny, randomBunny);
        std::cout << (*bunny)->GetName() << "has died" << std::endl;
        bunnyList.erase(bunny);
        
    }

}

int BunnyManager::getBunnyListSize()
{
    return bunnyList.size();
}

void BunnyManager::programme()
{
    system("cls");
    fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    fflush(stdout);
    srand(time(NULL));
    std::this_thread::sleep_for(std::chrono::seconds(2));
    do
    {
        fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
        fflush(stdout);
        std::cout << "press K to kill half of the population of bunnies" << std::endl;
        float timer = 0;
        while (timer < 2)
        {
            if(_kbhit())
            {
                char keyPressed = getch();
                if (keyPressed == 'k' || keyPressed == 'K')
                {
                    killHalf();
                }
                timer = 2;
            }
            else
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                timer += 0.1;
            }
        }
        ageAllBunny();
        infectBunny(InfectedCount()); // can do before or after but before quicker death
        std::this_thread::sleep_for(std::chrono::seconds(1));
        if (maleAndTwo())
            breed();
        std::this_thread::sleep_for(std::chrono::seconds(1));
        if (getBunnyListSize() > 1000)
            killHalf();
        displayAll();
        std::this_thread::sleep_for(std::chrono::seconds(2));
    } while (true);
}