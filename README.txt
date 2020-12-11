______To compile and create the executable "project" :______

1 - Go to a folder refering to the achievement that you want :
   Example : "cd achiev0"
   
2 - Then use the "make" command


______To launch a game :______

1 - Execute the project with "./project"

2 - You can add options before executing :

    	"-d 1" if you want to have a graphic interface after the game (a file named "output.html"
	    is created, you can open it with your browser); default value is 0
	
	"-n X" to settle the number of players to X (between 2 and 20) ; default value is 2
	
	"-b X" to settle the size of the board to X*X (the maximum is 50) ; default value is 10
	
	"-s X" to settle a new seed changing the course of the game ; default value is 0

Example :
	"./project -d 1 -n 15 -s 156" launch a game with 15 players, a board size of 10*10,
	a seed of 156, and will show the board in a graphic interface after the game
	

______After the game :______

1 - You can launch another game with the same executable "project"

2 - You can clean the folder with the command "make clean"


______Additional :______

1 - To verify the functions of the project, you can use the command "make test" which compile and execute several tests
