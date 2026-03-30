# COP3003_ProgrammingII
# Project Title: Casino Simulation
Brief description of your project (1–2 sentences).

For this project, we want to create a casino-style simulator that allows the user to play classic gambling games through the program. It will allow the user to play using their own decision-making and experience the same (rigged) odds. 

---
## Team Members
- Name 1 - Avery Daniel
- Name 2 - Nico Jelua
- Name 3 - Ismeal Perez 
- Name 4 - Joel Concepcion
---
 Feature 1: Functional Main Menu – The program should start with a main menu. The user should be able to navigate through the options and select the game of their choosing. It should also allow the user to exit the program once finished.  
Feature 2: Balance System – The user will be able to view their “balance”, displayed in the corner of the screen at all times, updating after each bet is placed.  
Feature 3: Blackjack Game – By selecting the “Blackjack” option, a fully functional blackjack game will be playable, with standard rules like “hit” and “stand”, as well as proper dealer logic and the opportunity to double down or change bet size.  
Feature 4: Roulette Game – The user can place a bet, spin a virtual wheel with red and black numbers, and win or lose based on their original bet. 
Feature 5: Slots – The player will spin three reels that will randomly choose three symbols. If all symbols match, the player wins; otherwise, the player loses
Feature 6: Save/Load System – Users will be able to save their balance and load it into the program at a later date if they wish to continue playing. 
Feature 7: Sic Bo - Users will make a bet on three rolled dice. This can be finding a specific, total combination, or a specific two combination. 

---
## OOP Concepts Used
 5. OOP Concepts to be used:
	Encapsulation:
Each class will manage its own data (ex, Player handles balance updates), ensuring controlled access through public methods. Specifically, this will be done using setter and getter functions. 
	
Abstraction:
The Game base class provides a simplified interface “play()”, hiding the complexity of individual game implementations.
Inheritance:
Specific games like Blackjack, Roulette, and ? inherit from the Game class to reuse shared structure. The Game class may also inherit from the Player class for withdrawing and depositing money. 
Polymorphism: Provides member functions for different game behaviors. For instance, Class Game may use the play() function to call other classes like Blackjack, Roulette, and other games to be announced.
Composition: Each game will have a has-a relationship with its own objects. For example, the SicBo class will have Dice1, Dice2, and Dice3, while the Slots class Blackjack will have deck, deckHand, and playerHand.

---
## Team Contributions
### Member 1: [Avery Daniel]
Worked on the .h and .cpp files for slots and Sic bo
 
### Member 2: [Nico Jelua]
Created GitHub repository and worked on the .h and .cpp files for roulette
 
### Member 3: [Ismeal Perez]
Worked on the .h and .cpp files for class Blackjack. Also worked on the UML Diagram
### Member 4: [Joel Concepcion]  
Worked on the .h files for class Player, Game, and save/load system.

---
## AI and External Resources Disclosure (Required)
You must clearly document **all external help used** in this project.
### AI Tools: Tools that will be used in the project include ChatGPT, Claude, and Google Gemini. So far, I asked ChatGPT to provide sample codes of polymorphism and abstraction, along with have it explaining each Casino game goal. What I learned so far was an idea of how polymorphism and abstraction work, and the objective of each Casino game. 
 

- UML Diagram:

[Untitled document.pdf](https://github.com/user-attachments/files/26336812/Untitled.document.pdf)


