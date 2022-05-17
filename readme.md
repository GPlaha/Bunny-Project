# Bunny Project
## Bunnies
-At program initialization, 5 bunnies must be created and given random colours, age can be 0 or random between 0 and 9. 

-Each turn, the bunnies age 1 year. 

-As long as there is a male (aged 2 or older), for each female in the list (aged 2 or older) a new bunny is created each turn. (E.G. if there was 1 adult male and 3 adult females, three new bunnies would be born each turn) 

-New born bunnies should be the same colour as their mother. 

-If a bunny becomes older than 10 years old, it dies. 

-If an infected bunny is born, each turn it will change one normal bunny into a infected bunny (E.G. If there are two infected bunnies two bunnies will be changed each turn and so on...) 

-Infected bunnies are excluded from regular breeding and do not count as adult bunnies. 

-Infected do not die until they reach age 50. 

-Each turn, the program should print a list of all the bunnies in the colony with all the details, sorted by age. 

-The program should also output each turns events such as: Bunny Keith was born!  

-When all the bunnies have died the program terminates. 

-If the bunny population exceeds 1000 a food shortage must occur killing exactly half of the bunnies (randomly chosen) 

EXTRAS 

## 1  

Modify the program to run in real time, with each turn lasting 2 seconds, and a one second pause between each announcement. 

## 2  

Remove the population limit and see how many bunnies your program can handle  

Allow the user to hit the 'k' key to initiate a mass rabbit cull! which causes half of all the rabbits to be killed (randomly chosen). 

## Decisions
Some decisions i made regarding the project were to do the main functions in such a way that i could look at them and see if they have been completed. So i could look at the spec required and essentially tick everything off. Secondly the spec required half the bunnies to die, but it had to be chosen randomly. To do this randomly the process i followed was to choose a random bunny from the array and delete it. Repeat the process until the bunny list has been halved.