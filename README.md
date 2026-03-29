# COP3003_ProgrammingII
# Project Title
Brief description of your project (1–2 sentences).

For this project, will be creating a Casino-like stimualtion. This will be used for users who want to attempt a fake Casino, with the choices being playing Blackjack, slots, rouettle, and Sic bo.
---
## Team Members
- Name 1 - Avery Daniel
- Name 2 - NIco Jelau
- _ Ismal Persex Name 3
- Name 4 (if applicable) - Joel Concpetion
---
 Feature 1: Functional Main Menu – The program should start with a main menu. The user should be able to navigate through the options and select the game of their choosing. It should also allow the user to exit the program once finished.  
Feature 2: Balance System – The user will be able to view their “balance”, displayed in the corner of the screen at all times, updating after each bet is placed.  
Feature 3: Blackjack Game – By selecting the “Blackjack” option, a fully functional blackjack game will be playable, with standard rules like “hit” and “stand”, as well as proper dealer logic and the opportunity to double down or change bet size.  
Feature 4: Roulette Game – The user can place a bet, spin a virtual wheel with red and black numbers, and win or lose based on their original bet. 
Feature 5: Slots – The player will spin three reels that will randomly choose three symbols. If all symbols match, the player wins; otherwise, the player loses
Feature 6: Save/Load System – Users will be able to save their balance and load it into the program at a later date if they wish to continue playing. 
Feature 7: Sic Bo - Users will make a bet on three rolled dices. This can be finding a specific, total, combionation, or specific two combination. 

---
## OOP Concepts Used
 5. OOP Concepts to be used:
	Encapsulation:
Each class will manage its own data (ex: Player handles balance updates), ensuring controlled access through public methods. Specfiically, this will be done using setter and getter funcitons. 
	
	 Abstraction:
The Game base class provides a simplified interface “play()”, hiding the complexity of individual game implementations.
	Inheritance:
Specific games like Blackjack, Roulette, and ? inherit from the Game class to reuse shared structure. the Game class may also inherit from the Player class for withdrawing and depositing money. 
Polymorphism: Provides member functions for different game behaviors. For instance, Class Game may use the play() function to call other classes like Blackjack, Roulette, and other games to be announced.
Composition: Each game will have a has-a relationship with their own objects. For examaple, the SicBo class will have Dice1, Dice2, and Dice3 while the Slots class Blackjack will have deck, deckHand, and playerHand.

---
## Team Contributions
### Member 1: [Name]
- Responsibility 1
- Responsibility 2
### Member 2: [Name]
- Responsibility 1
- Responsibility 2
### Member 3: [Name]
- Responsibility 1
- Responsibility 2
### Member 4: [Name] (if applicable)
- Responsibility 1
- Responsibility 2
---
## AI and External Resources Disclosure (Required)
You must clearly document **all external help used** in this project.
### AI Tools
List any AI tools used (e.g., ChatGPT, Copilot, etc.) and describe:
- What you asked the AI to do
- What code or explanation it generated
- What you modified or learned from it
