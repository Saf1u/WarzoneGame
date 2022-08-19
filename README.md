# WarzoneGame
Text based c++ game based on risk.
## build
ensure you have [cmake](https://cmake.org/) installed and a [c++ compiler](https://clang.llvm.org/)
then:
```shell
mkdir "build"
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make
./WarzoneGameb -file [config-file-dir-explained below]
```
## About the game

The game consists of a set of players,territories and orders. Players battle each other in order to win territories. The players are all initialized and are not controlled by the user currently. They run and execute actions based on their
current strategy ranging from 
- cheater (who cheats)
- neutral (who basically is passive)
- Aggressive (who always attacks)
- Benevolent (who never attacks)
- Human (who waits for input from keyboard but right not allow the game to execute we choose automatically for him)

The maps are maps used in the original risk game and are parsed and loaded in as territories and continents belonging to the players. for example the europass map included in the repo.The orders are different kinds of attacks that players can execute on each other aimed at winning the game and are automatically loaded
and constant throughout the game's lifetime

## structure
- Map class constructs the map from parsing the map data and configures territories 
- command processor imitates a finite state machine to knoe current game state and allow for only plausible transitions while validating commands
- GameEngine basically helps initialize and process instructions and commands happening throughout the game in the main game loop (executing orders,redistributing territories,etc...)
- Strategy design pattern utilized to vary current player strategy to define what happens when issueOrder , defense and attack are called
- the observer design pattern is utilized on game objects in order to build a logging system for game actions that can be found in gamelog.txt (note after run this file should be cleared due to size amd console output ignored as it is for debugging)
- the adapter design pattern is utilized to vary the way for starting the game (file based config command or text entry in console, It's better to use the config explained below to avoid hassle just for a demo run)



## Running 
To start game create a conifg file with desired configurations of the form  below
```shell
tournament -M europass.map -P Neutral Benevolent Human -G 4 -D 50
where -g represents the number of games, -d represent number of turns for each player -p represents player strategies and -M represents the map
```

and run the binary by passing the -file option followed by the dir of the config generated
