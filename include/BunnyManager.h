#ifndef BUNNYMANAGER_H
#define BUNNYMANAGER_H

#include <list>
#include <memory>
#include "bunny.h"

class BunnyManager{
    private:
        //std::list<Bunny> bunnyList;
        std::list<std::shared_ptr<Bunny>> bunnyList;
        const int MAX_AGE_HEALTHY =10;
        const int MAX_AGE_INFECTED =50;
        const int MIN_AGE_BREED = 2;

    public:
        BunnyManager();
        void addBunny();
        void ageAllBunny();
        void displayAll();
        bool maleAndTwo();
        void breed();
        void addBunny(Colours);
        int InfectedCount();
        void infectBunny(int);
        void killHalf();
        int getBunnyListSize();
        void programme();
};

#endif

