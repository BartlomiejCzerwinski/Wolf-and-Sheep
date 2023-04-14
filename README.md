# Wolf and Sheep
## ABOUT GAME

The game is also known as "Fox and Geese". The game is played on a board with an 8x8 chess grid of squares*. One player controls the wolf, while the other player controls the sheep.

The objective of the game is for the wolf to go through the board, while the objective of the sheep is to block the wolf's movement and prevent it from capturing the end of the board.

At the beginning of the game, the sheep are placed on the dark squares on one side of the board, while the wolf is placed on the dark square at the opposite end of the board. The wolf always moves first and can move to any adjacent dark square in a diagonal direction.

The game continues until either the wolf captures the end of the map or the sheep can't move or the sheep successfully blocks the wolf.

***NOTE:** In my implementation, black fields are shown as a "-" sign, while white ones are empty spaces " ".

## USER INTERFACE
The application includes a text user interface. In MENU you can start a new game, load a saved one, check the guide or read about the authors of the project. (If you get bored, you can also exit app :) )

![menu](https://user-images.githubusercontent.com/84719721/232044771-6094c498-135b-46e9-97a8-ed1af8ec1055.png)

After starting game board is generated and printed into the screen. Fields, where you can stand are represented by "-". Sheep's units are represented by the letter "S", while the wolf is "W".
You can choose the unit that you want to move (if playing sheep) or choose a destination position. Choose is done by checking coordinates from the printed board - upper numbers (1 - 8) are like X-coordinates, while a column of numbers (1 - 8) are Y-coordinates.

![in_game](https://user-images.githubusercontent.com/84719721/232044829-f03ddc59-a4e2-449b-9a07-b6282408db18.png)

At the end of the game properly communicate will be printed.

![end_game](https://user-images.githubusercontent.com/84719721/232044850-7cebe9d9-6cba-437a-b72d-f50f92a5c6c2.png)

### SAVING GAME
Right after each turn, you can save the game by selecting the appropriate option:
```
If you want to save the game and leave enter 1. If you want to play enter 2:
>>> 1
Enter save name
>>> save.txt
Successfully saved game!
```


## EXAMPLE WINNING CONDITIONS
Sheep block Wolf which can't move. (Sheep wins)
```
   1 2 3 4 5 6 7 8
1    -   -   -   - 
2  -   -   -   -   
3    -   -   -   - 
4  -   -   -   -   
5    -   -   -   - 
6  -   -   -   S   
7    -   -   S   S 
8  -   -   S   W   
```
Sheep have no available moves. (Wolf wins)
```
   1 2 3 4 5 6 7 8
1    -   -   -   - 
2  -   -   -   -   
3    -   W   -   - 
4  -   -   -   -   
5    -   -   -   - 
6  -   -   -   -   
7    -   -   -   - 
8  S   S   S   S    
```
Wolf successfully come through board. (Wolf wins)
```
   1 2 3 4 5 6 7 8
1    -   W   -   S 
2  -   -   -   -   
3    S   -   -   - 
4  -   -   -   -   
5    S   -   S   - 
6  -   -   -   -   
7    -   -   -   - 
8  -   -   -   -    
```

