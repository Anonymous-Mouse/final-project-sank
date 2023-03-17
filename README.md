[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=9894820&assignment_repo_type=AssignmentRepo)
 > As you complete each section you **must** remove the prompt text. Every *turnin* of this project includes points for formatting of this README so keep it clean and keep it up to date. 
 > Prompt text is any lines beginning with "\>"
 > Replace anything between \<...\> with your project specifics and remove angle brackets. For example, you need to name your project and replace the header right below this line with that title (no angle brackets). 
# Mystery Menagerie
 
 > Authors: [Kareem Shehada](https://github.com/karyeet), [Adolfo Plata](https://github.com/Anonymous-Mouse), [Shriya Paturu](https://github.com/shriyapaturu07), [Nicholas Johnson](https://github.com/bricks4nick)

## Mystery Menagerie Project Description

Description:
- This project is interesting to us because it will be the first time we work with others on an application and for some of us, it will also be our first time using tools like Git and valgrind, which are industry standards and tools we will definitely use throughout our career. 
- A text based role-playing-game, like the survival game we are proposing, is a perfect project that would allow us to apply these tools over a four week period and create a fun, immersive experience with only text. A survival RPG like this makes the user focus on the story-telling aspect of the game and imagine a decrepit scene without expensive visual effects. The user can create a character and interact with the world around them using a simplified interface to fight, heal, discover, and slowly unfold a storyline hidden by monsters, mystery, and mayhem. 
- We plan on using C++ to code the project. Additionally, for feature planning we will use Github projects and likely diagrams.net or a similar site for our story/level planning.
- The input of the project will be through the terminal, it will mostly be a single character to select an option from a prompt. The output will also be through the terminal, it will be information about the player’s stats, items, and location. The terminal will also occasionally print ASCII art to immerse the player into the atmosphere of the game.
- The project will provide at least one unique story for the player to play through.
## The player will be able to...
- ### Fight Enemies
  - The player will be able to fight mutated rats, zombies, and giant spiders will roaming around the map.
  - Each of these enemies will have a unique attack strength, health amount, and status effect that damage the player in different ways.
- ### Use unique items
  - The player will be able to use consumables such as healthpacks, steriods, and cures for enemy status effects.
  - Weapons are given at the beginning of the game and found throughout the map. Each weapon has their own attack strength.
- ### Search preset locations
  - The player will be able to search around 3 different sections for items, story notes, and enemies.
- ### Make decisions that may impact the ending of the story
  - The player has to uncover a story filled with monsters and mystery. At the end of the game, the player can choose between two different endings.
- ### Increase/Decrease enemy difficulty at beginning of game
  - At the beginning game menu, the player can choose between three difficulty modes that affect the player's strength and health as well as the strength and health of their enemies.
- ### View their location and searched rooms on a map
  - The player can view their location and searched rooms on a map.
- ### Solve puzzles for containers that guide players through the map or open unique rewards
  - The player can unlock containers with keys only discovered by puzzles.
- ### Save their progress
  - The player can save their current location, items, and stats at certain points in the game.
  - Before a major event in the story, the game will save their progress thus far.
- ### Access their inventory
  - The player can access their inventory to drop items, upgrade items, or see what they have collected so far.


## Class Diagram!
![UML Diagram drawio roomcorrections](https://user-images.githubusercontent.com/28524112/222705543-da306cfd-061a-4ac3-bb08-4d4ec1651eee.png)
This diagram shows a tentative outline of the classes we will use for the project.
 - It should be noted that whether it is shown explicitly or not, all constructors of subclasses should have the necessary parameters to also call the constructor of their supers.
 - A story class will essentially be the top most class in our project, and will be responsible for prompting the user during attack cycles and other interactions. 
   - The story class will also have helper functions, such as the getRoomsAdjacentToPlayer, which returns x,y coordinates of the rooms.
   - The story class will make use of StoryIO, an abstraction for input/output which provides input validation but can also be overridden for testing the story class.
 - The level will hold all the Rooms and keep track of the rooms the player has been in as well as the difficulty of the story. 
 - A room can have an entity, container, or both. 
   - The story should not allow the container to be opened or the player to move to different room unless the enemy is dead or is not there. 
   - A locked room cannot be entered without the correct key in the inventory, once entered the key is consumed and the lockedroom is marked unlocked. 
   - Rooms can have a chance to spawn an enemy when first explored (to add randomness). 
   - The room map is a 2d array, to represent x and y coordinates. 
 - Weapons and enemies should be defined per story, Giant_Spider is just an example. 
 - The player will have an inventory, made up of a container class, which should be created before the player is made as should all part classes in the diagram (ex. Level, player, rooms). 
 - Some effects should be added to the effects array in the entities class when used, specifically ReduceMaxHealth, ReduceBaseDamage, and Slow, but others like Heal should not as healing does not have a lasting effect.
 - Items can be consumables, weapons, or keys. Some consumables will be of usageType “self”, meaning they can only applied to the player. 
   - Others, of usageType “enemy” are only used on enemies. Weapons will have unique durability and damage, durability is lowered 1 every attack. 
   - Keys should be used only when when the user interacts with a locked door or container.

   
   
 
 > 

- UML SOLID Updates
  - StoryIO was created to address IO into the story. It is an application of the Single Responsibility principle as it removes the job of user input validation and direct interfacing with cin and cout. It is implemented by replacing cin/cout usage with StoryIO in functions within the story class. StoryIO allows us to use any istream or ostream meaning we can easily switch between testing with stringstreams and production with cin/cout. The smaller class also had much more clear tests for itself.
  - The Dependency Inversion Principle and Liskov substitution principle was applied to the item classes children. Consumable, Weapon, and Key all implement use(entity), which can be called by the story when needed and thus the story does not care what type of item it is. The DIP principle reduced the complexity of the story class, which was expected to take the burden of implementing the usage of items. Furthermore, if we wish to change the implementation of an item, it is easier to rewrite tests and headers than if it were part of a larger class. The Liskov principle in this case means our items are all similar and their usage is predictable.
 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.


