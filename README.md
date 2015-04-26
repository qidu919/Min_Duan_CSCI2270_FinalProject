# Min_Duan_CSCI2270_FinalProject

Project Summary)
Michael Min, Qiu Duan's, and Michael Xiao's Final Project CSCI2270. This project is made to simulate the matchmaking
system of the game League of Legends, made by Riot Games. For every game of League of Legends, two teams of five
players are required, resulting in 10 players who need to be found. However, these players also must be of roughly
equal skill level, which is determined by their ranking division. There are seven ranking divisions: Bronze, Silver,
Gold, Platinum, Diamond, Master, and Challenger, with Bronze being the lowest and Challenger being the the greatest.
It is determined based on the number of wins in 10 promo games, which are games that are hosted at the beginning of
every new season of League of Legends to place all new players in their initial division. For instance, having one
win in the 10 games would place a player in Bronze while having all 10 wins would place a player in Challenger. In
this project, we have increased the scope of the initial divisions(in reality, it is only possible to reach Gold
Division as the highest initial division) and we intend to simulate the queue of the matchmaking system by using a
hash table that holds the queues of each division individually instead of creating one queue that contains all
players. This is in order to simulate the matchmaking system of the real League of Legends matchmaking queue by
creating relatively fair matches. Then, once a queue corresponding to a division is filled with 10 players, those 10
will be disengaged from the queue and placed in their own match.

How to Run) 

Dependencies) This program should be run with C++11. Also, must be run in a terminal.

System Requirements) This program is made for Linux.

Group Members) Michael Min, Qiu Duan, Michael Xiao.

Constrbutors) Obtained help from Jon Huang.

Bugs/Issues) When inserting the value for number of promotional games won, inserting non-numerical characters 
can cause the program to read in nonsensical data.

