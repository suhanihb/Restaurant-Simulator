[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-718a45dd9cf7e7f842a935f5ebbe5719a5e09af4491e668f4dbf3b35d5cca122.svg)](https://classroom.github.com/online_ide?assignment_repo_id=10870110&assignment_repo_type=AssignmentRepo)
 > As you complete each section you **must** remove the prompt text. Every *turnin* of this project includes points for formatting of this README so keep it clean and keep it up to date. 
 > Prompt text is any lines beginning with "\>"
 > Replace anything between \<...\> with your project specifics and remove angle brackets. For example, you need to name your project and replace the header right below this line with that title (no angle brackets). 
# Restaurant Simulator
 > Your author list below should include links to all members GitHub (remove existing author).
 
 > Authors: [Suhani Bhanvadia](https://github.com/suhanihb), [Suhani Chaudhary](https://github.com/suhanic44), [Satvi Kammula](https://github.com/Satvi-Kammula), [Vaneesha Singh](https://github.com/vsingh9)

 > You will be forming a group of **FOUR** students and working on an interesting project. The project has 4 phases, each one with specific requirements. A list of proposed project ideas that have been successful in previous quarters is listed in the project specifications document on Canvas. You can select an idea from the list and start thinking about the features you will implement. If you want to propose your own original idea, you will have to contact your instructor to discuss the project and obtain written permission before you submit your project proposal (Phase 1). The project work should be divided almost equally among team members. You can of course help each other, but it needs to be clear who will be responsible for which features. Additionally, you are expected to follow Scrum patterns, specifically the use of a Scrum (Project) board, Sprints, and Scrum meetings.

 > ## Expectations
 > * The backend of your project should be implemented in C++. If you wish to choose anoher programming language (e.g. Java, Python), please discuss with your lab TA to obtain permission.
 > * You can incorporate additional technologies/tools but they must be approved (in writing) by the instructor or the TA.
 > * Each member of the group **must** be committing code regularly and make sure their code is correctly attributed to them. We will be checking attributions to determine if there was equal contribution to the project.
 > * **Each member of the group must actively participate in the Github Project board, writing unit tests, and reviewing commited code.**
> * All project phases are to be submitted to this GitHub repository. You should modify this README file to reflect the different phases of the project. In addition, you should regularly hold sprint meetings with your group. You will need to hold two to three scrum/check-in meetings with your lab TA/reader at different times in addition to the final demo.

## Project Description
 > Your project description should summarize the project you are proposing.
 > * The project we are going to complete is a restaurant simulator game. This game will allow the user to play as various characters present in a restaurant, and experience the day to day tasks each character faces. We are also intending it to be like a "Text Based Role-Playing Game", where the user will face various tasks along the way. Considering the fact that some of us are experienced in the food industry, we also wanted to put the user in the shoes of various employees to show the complexity of completing certain tasks. However, this project caught our interest because we have all grown up playing computer games similar to this. In fact, the idea of being able to code a terminal based game using the skills we currently possess was exciting to us, and encouraged us to formulate a project that anyone could find entertaining.  
 > * The languages and tools we will use include VScode and C++ for the programming and creation of the project. We will also use Github to keep track of our progress and our different game features/roles. Additionally, we may potentially use some kind of GUI for the display of the restaurant game and user input/interaction. This may require the use of additional languages and tools.
 > * Inputs and outputs for this project will be divided among the different characters the user will roleplay in this restaurant simulator. Some of the different characters we plan to include are the manager, the cook, the waiter, and the customer. As a manager, the user can add items to the menu (item type, item name, item price), delete items from the menu, or change prices of items on the menu. As a waiter, the user can choose to display the menu (output), take orders (input), serve customers (output), and collect payments (input). As a cook, the user can receieve a list of pending orders (output), prepare orders (input), and remove orders from the list once completed (input). As a customer, the user can place orders (input), make a payment (input), and leave a review (input).
 > * The game will consist of 4 levels that the player will move through and play as different roles in the restaurant. Beginning with 5 stars, the player will keep playing the game, looping through the 4 levels, until the restaurant has 0 stars.
 >   * First, the player will have the role of a customer. A menu will be printed and they will be prompted to select items, their choose their payment type, and leave a review of the restaurant (how many stars out of 5). For reviews less than 3, the retaurant will lose a star.
 >   * Next, the player will become a server. A timer will be set to complete different tasks including printing the menu (typing "menu"), taking orders (typing the item number), and taking payments (typing "check out") before the timer ends. Failure to complete all tasks will result in a loss of a star.
 >   * Next, the player will be a manager. The player will be prompted to add, delete, and change items on the menu. The restaurant will lose a star if the player deletes an item that was ordered in the previous level.
 >   * Lastly, the player will be the cook. The list of orders will be printed and the user will prepare orders (select an item and enter "make") and remove orders (select an item and enter "done"). The restaurant will lose a star if an item is removed before being prepared. If the restaurant has at least 1 star, the player will move back to the customer level and repeat the cycle.
 > This description should be in enough detail that the TA/instructor can determine the complexity of the project and if it is sufficient for the team members to complete in the time allotted. 
 > 
 > You also need to set up an empty project board using GitHub projects (board view). Make sure you add the board under your project repository. You should also have a Product Backlog and In testing columns added.
 > ## Phase II
 > In addition to completing the "User Interface Specification" and "Class Diagram" sections below, you will need to:
 > * Create an "Epic" (note) for each feature. Place these epics in the `Product Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Break down the "Epics" into smaller actionable user stories (i.e. smaller development tasks). Convert them into issues and assign them to team members. Place these in the `TODO` column.
 >   * These cards should represent roughly 7 days worth of development time for your team. Then, once the sprint is over you should be repeating these steps to plan a new sprint, taking you until your second scrum meeting with the reader in phase III.
 > * Schedule two check-ins using Calendly. You need to pick both time slots during your lab on week 6. Your entire team must be present for both check-ins.
 >   * The first check-in needs to be scheduled with your lab TA. During that meeting, you will discuss your project design/class diagram from phase II.
 >   * The second check-in should be scheduled with a reader. During that meeting you will discuss:
 >     * The tasks you are planning for the first sprint
 >     * How work will be divided between the team members
## User Interface Specification
 > Include a navigation diagram for your screens and the layout of each of those screens as desribed below. For all the layouts/diagrams, you can use any tool such as PowerPoint or a drawing program. (Specification requirement is adapted from [this template](https://redirect.cs.umbc.edu/~mgrass2/cmsc345/Template_UI.doc))

### Navigation Diagram
> ![Navigation Diagram drawio](https://user-images.githubusercontent.com/129975596/236902494-14ac1d05-3dbe-4d88-be37-40cb19697e6f.png)

### Screen Layouts
> <img width="517" alt="Screenshot 2023-05-19 at 9 57 17 AM" src="https://github.com/cs100/final-project-skamm006-sbhan020-schau062-vsing035/assets/117537786/cdbc95c4-e9b8-4dd3-874f-2cc82279b2c4">
> <img width="517" alt="Screenshot 2023-05-19 at 9 57 44 AM" src="https://github.com/cs100/final-project-skamm006-sbhan020-schau062-vsing035/assets/117537786/4e242997-782a-4c04-a461-77a4e03719b8">
> <img width="517" alt="Screenshot 2023-05-19 at 9 58 09 AM" src="https://github.com/cs100/final-project-skamm006-sbhan020-schau062-vsing035/assets/117537786/cb5c9d1b-3df8-4a1b-ac36-4c70dd18b2c5">

## Class Diagram
 > ![Restaurant Class UML Diagram](https://user-images.githubusercontent.com/129975596/236901920-3de228c7-4f95-4142-bda7-3f6cab2a5729.png)
 
 > The Restaurant class is responsible for setting up the name of the restaurant. It contains a lot of the main functionality that different classes will need access to. The balance function will be increased every time the Customer pays their bill, and decreased anytime the Chef cooks meals incorrectly or the Server serves meals to the wrong customers. The rating will be received from the Customer, which will be evaluated at the end of each cycle to determine whether the game can continue or not. The menu will be stored in the Restaurant class, where the Manager has access to adding or deleting items from the menu. The menu will also be used by the Server and Customer classes to display and view the menu, respectively. An  additional aspect of the Restaurant class is the floorPlan. This will be implemented through a 2d array which will contain pointers to table objects. The method for the floorPlan will be protected, which allows all the employees to have access to it, including the server. The purpose of the floorPlan is to allow the server to seat the customers at an open table and keep track of which tables are occupied. Each table in the floorPlan will be given a number which will be used to keep track of which orders are from which groups of customers.
 
 > The Table class will be utilized by the Restaurant class, the Server class, and the Manager class. Each “Table” will consist of a certain number of customers, an occupied status, as well as the order list from the table. This occupation information will be utilized by the Manager class and Server class when designing a floor plan and initially seating the customers at a table. The server class will further implement the functionality of this class when taking the customers’ orders and calculating the payment required for the Restaurant. Overall, this class will merely be used for organizational purposes, and will be pivotal in deciding the reviews that the customers submit to the Restaurant.
 
 > The Customer class is the main competition that the user faces in the game. It will be implemented as a robot with randomly generated values and reviews, mocking how a real customer would behave in a restaurant. The randomly generated values represent the order they would want from the menu, while a randomly generated review (between 1-5), will be generated based on the service from the employees. For instance, a customer’s review may be generated as a higher or lower value based on seating availability, accurate customer order, and accurate food preparation. The customer will be a completely randomized, behind-the-scenes development, where the user is in charge of pleasing them through the means of the restaurant’s employees. The Customer class will also be utilized by the Table class in terms of group orders and group placement.
 
 > The Employee class serves as a base class for the Server, Chef, and Manager classes. This class includes a basic setter and getter for the employee’s name. A virtual function to print the employee’s information has been created to be overridden by the derived classes, since the server, chef, and manager will each have their own information.
 
 > The Manager Class is responsible for the beginning of the game involving the setup of the restaurant. The manager role is the person who names the restaurant and creates the menu for the customers. The manager can add and delete recipes, as well as edit the ingredients for each recipe. When the user is acting as the manager, they also give the restaurant and prepare everything for the server to start taking orders. The Manager class inherits from the Employee class, which means that each manager object will have a name, as well as access to the floor plan of the restaurant.
 
 > In the Server class, the player will be given tasks to seat the customer, display the menu, and take orders. To seat the customer, they will have access to the data already in the restaurant’s floorplan to select a suitable table in the floorplan to place the customer at. Therefore, the Server class will aggregate the group size from the customer class and make changes to the restaurant class. Next, they will print the Restaurant class’s menu list. Using the data in the menu, the player will input a string of numbers to replicate taking the customers order. The player will then play as the chef and return to the Server class to input the correct numbers again to replicate serving the customers. The Server class inherits from the Employee class, which means that each server object will have a name, as well as access to data in a table object and the restaurant’s menu list.
 
 > The Chef class is responsible for using the list of orders from the table to “make orders” and remove them from the table’s list of orders. In order to use the list of orders, the Chef class will access the data in a table object in the Restaurant class’s floor plan. To make orders, the player will be prompted to input various strings representing the recipe. Once they’ve successfully completed the task, the order will be automatically removed from the list of orders. The Chef class inherits from the Employee class, which means that each chef object will have a name, as well as access to data in a table object and the restaurant’s menu list.
 
 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * You should also make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
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
 
