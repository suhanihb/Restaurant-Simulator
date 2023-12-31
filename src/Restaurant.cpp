#include "../header/Restaurant.h"
#include "../header/Chef.h"
#include "../header/Customer.h"
#include "../header/Employee.h"
#include "../header/Manager.h"
#include "../header/Server.h"
#include "../header/Table.h"
#include "../header/OrderNode.h"

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

Restaurant::Restaurant() {
    restaurantName = "";
    restaurantBalance = 100.0;
    rating = 5.0;
    m = Manager();
    s = Server();
    c = Chef();
}

const string& Restaurant::getRestaurantName() const {
    return restaurantName;
}

void Restaurant::setRestaurantName(string restName) {
    restaurantName = restName;
}

const double Restaurant::getBalance() {
    return restaurantBalance;
}

void Restaurant::setBalance(double restBalance) {
    restaurantBalance = restBalance;
}

const double Restaurant::getRating() {
    return rating;
}

void Restaurant::setRating(double restRating) {
    rating = restRating;
}

void Restaurant::displayFloorPlan(int userNum) { 
    int numTables = userNum;
    int tableNumber = 1;
    int numRows = 0;
    int tablesPerRow = 5;

    if(numTables%5==0) {                    //Checks if tables can be split evenly into 5 rows
        numRows = numTables/5;
    }
    else {                                  //Handles cases where tables can be split evenly into 5 rows
        if(numTables<5) {
            numRows = 1;
        }
        numRows = numTables/5+1;
    }

    for(int i=0; i<numRows; ++i) {          //Makes tables given number of rows
        if(numTables%5!=0) {                //Makes adjustments for last row if unevenly distributed
            if(i==numRows-1) {
                tablesPerRow = numTables%5;
            }
        }
        
        for(unsigned int numDashes=0; numDashes<tablesPerRow; ++numDashes) {    //Creates table head
            if(numDashes<tablesPerRow-1) {
                cout<<"-----"<<setw(10);
            }
            else {
                cout<<"-----";
            }
        }
        cout<<endl;
        
        for(unsigned int numSpaces=0; numSpaces<3; ++numSpaces) {       //Creates "seats" for table
            int iterations = 0;
            int columnNumber = 1;
            while(iterations<tablesPerRow) {
                if(numSpaces==1) {                          //Writes down table number
                    if(tableNumber<10) {
                        cout<<"| "<<tableNumber<<" |";
                    }
                    else {
                        cout<<"| "<<tableNumber<<"|";
                    }
                    if(iterations!=tablesPerRow-1) {        //Adjusts spacing issues if necessary
                        cout<<setw(7);
                    }
                    tableNumber++;
                }
                else {
                    cout<<"|   |";
                    if(iterations!=tablesPerRow-1) {        //Formats area without table number
                        cout<<setw(10);
                    }
                }
                iterations++;
                columnNumber++;
            }
            cout<<endl;
        }
        
        for(unsigned int numDashes=0; numDashes<tablesPerRow; ++numDashes) {    //Creates table end
            if(numDashes<tablesPerRow-1) {
                cout<<"-----"<<setw(10);
            }
            else {
                cout<<"-----";
            }
        }
        cout<<endl;
    }
}

void Restaurant::simulateRestaurant() {         //Simulates Restaurant game
    srand(time(NULL));

    //initial restaurant setup
    string restaurantName = "";
    cout << "Enter a name for your restaurant: ";
    getline(cin, restaurantName);
    this->setRestaurantName(restaurantName);
    cout << endl;
    
    int numTables = 0;
    int cycleNum = 1; //counter to keep track of number of cycles in game

    while (this->getRating() >= 2 && this->getBalance() > 0) {
        //manager screen
        if (cycleNum == 1) {
            m.printCharacterDetails();
            cout << endl;
            cout << "Enter the number of tables you would like in your restaurant: ";
            cin >> numTables;
            numTables = validateIntInput(numTables, 1, 100);
            cout << endl;
            s.openUpTables(numTables);
        }
        else {
            cout << "You are now Manager " << m.Employee::getEmployeeName() << "! 🎉" << endl << endl;
        }
            
            //create menu
            if (cycleNum >= 2) {
                string makeChange;
                int _newFoodNum;
                double _newFoodPrice;

                cout << endl << "Would you like to change the price of any items on your menu? 💲" << endl;
                cout << "Type 'y' for yes, 'n' for no: ";
                cin >> makeChange;
                makeChange = validateStringInput(makeChange, 2);
                cout << endl;

                if (makeChange == "y") {
                    int lastNum = 0;

                    cout << "Enter the menu number (1 - ";
                    lastNum = m.getLastMenuNumber();
                    cout << lastNum << ") of the item's price to change: ";
                    cin >> _newFoodNum;

                    while (_newFoodNum > m.getLastMenuNumber() || _newFoodNum <= 0) {
                        cout << endl << "Uh-oh, that's not a valid menu number! Try again: ";
                        cin >> _newFoodNum;
                    }
                    cout << endl;

                    cout << "Enter the new price of the item: $";
                    cin >> _newFoodPrice;
                    _newFoodPrice = validateDoubleInput(_newFoodPrice, 1);
                    cout << endl << endl;

                    m.changeMenuPrice(_newFoodNum, _newFoodPrice);
                    cout << "Here is the updated menu!" << endl << endl;
                }
            }
            else {
                cout << "Time to create a menu for " << restaurantName << "! ";
                cout << "What would you like your customers to have? 📝" << endl << endl;

                int _menuNumber = 0;
                string _foodType = "x";
                string _foodItem = "x";
                double _foodPrice = 0.0;
                string userInput = "y";

                while (userInput != "n") {
                    _menuNumber++;

                    cout << "Enter food type ('a' = appetizer, 'm' = main course, 'd' = dessert): ";
                    cin >> _foodType;
                    _foodType = validateStringInput(_foodType, 1);
                    cout << endl;

                    cout << "Enter food item: ";
                    cin.ignore();
                    getline(cin, _foodItem);
                    cout << endl;

                    cout << "Enter food price: $";
                    cin >> _foodPrice;
                    _foodPrice = validateDoubleInput(_foodPrice, 1);
                    cout << endl;

                    MenuItem* newMenuItem = new MenuItem(_menuNumber, _foodType, _foodItem, _foodPrice);
                    m.menuAdd(newMenuItem);

                    cout << "Add another item? ('y' = yes, 'n' = no): ";
                    cin >> userInput;
                    userInput = validateStringInput(userInput, 2);
                    cout << endl << endl;
                }
            }

            m.viewFullMenu(); //print full menu for each cycle

        //server screen
        if (cycleNum == 1) {
            s.printCharacterDetails();
            cout << endl;
        }
        else {
            cout << "You are now Server " << s.Employee::getEmployeeName() << "! 👱" << endl << endl;
        }

            //display floorplan
            cout<<"Here is the floorplan for your restaurant: "<<endl << endl;
            this->displayFloorPlan(numTables);

            //seat a customer
            int totalMenuItems = m.getLastMenuNumber();

            s.clearUsedTables();
            s.seatCustomer(totalMenuItems, numTables);

            vector<OrderNode> customerOrders;
            s.removeOrders();
            customerOrders = s.takeOrder();

            cout << endl;
            cout << "Wonderful! Now that you have the orders, it's time for the chef to make the items... 🍲" << endl;

        //create bill
        
        double billTotalAmount = 0;
        for(int i=0; i<customerOrders.size(); ++i) {
            billTotalAmount+=m.getPriceOfChosenMenuItem((customerOrders.at(i)).getItemNumber());
        }
        s.billTable(billTotalAmount);

        //chef screen
        if (cycleNum == 1) {
            c.printCharacterDetails();
            cout << endl;
        }
        else {
            cout << "You are now Chef " << c.Employee::getEmployeeName() << "! 🍴" << endl << endl;
        }

            // Print orders with food type
            cout << "Here are the orders you need to prepare:" << endl;
            for (int i = 0; i < customerOrders.size(); i++) {
                int itemNumber = (customerOrders.at(i)).getItemNumber();
                string itemType = m.getItemType(itemNumber);
                cout << "Item #" << itemNumber << " is a " << itemType << endl;
            }
            cout << endl;

            // Prompt mc and typing game in order of appetizer, main course, and dessert
            for (int i = 0; i < customerOrders.size(); i++) {
                string itemType = m.getItemType((customerOrders.at(i)).getItemNumber());
                
                if (itemType == "appetizer") {
                    c.MCGame(itemType);
                    c.typingGame(itemType);
                    break;
                }
            }

            for (int i = 0; i < customerOrders.size(); i++) {
                string itemType = m.getItemType((customerOrders.at(i)).getItemNumber());

                if (itemType == "main course") {
                    c.MCGame(itemType);
                    c.typingGame(itemType);
                    break;
                }
            }

            for (int i = 0; i < customerOrders.size(); i++) {
                string itemType = m.getItemType((customerOrders.at(i)).getItemNumber());
                
                if (itemType == "dessert") {
                    c.MCGame(itemType);
                    c.typingGame(itemType);
                    break;
                }
            }

            // Prompt typing game for clean-up
            cout << "You're done prepping the meals! Time to clean up! 🧹" << endl;
            c.MCGame("clean");
            cout << endl;

            // Adjust restaurant balance for chef's mistakes
            for (int i = 0; i < c.getMistakes(); i++) {
                this->setBalance(this->getBalance() * 0.9);
                if (this->getRating() >= 0.1) {
                    this->setRating(this->getRating() - 0.1);
                }
            }

        //server screen
        cout << "You are now Server " << s.Employee::getEmployeeName() << "! 👱" << endl << endl;

            //serve customers their food in correct order
                cout << "Now that the food is prepared, it is time to serve your table..." << endl;
                cout << "Do you remember what menu item each person ordered?" << endl << endl;
                cin.ignore();
                for(int i=0; i<customerOrders.size(); ++i) {
                    s.serveCustomer(i, m.getItemName((customerOrders.at(i)).getItemNumber()));
                }
            
            // Adjust restaurant balance for server's mistakes
                for (unsigned int i = 0; i < s.getMistakes(); i++) {
                    this->setBalance(this->getBalance() * 0.9);
                    if (this->getRating() >= 0.1) {
                        this->setRating(this->getRating() - 0.1);
                    }
                }

        
        //pay bill
        cout << "Looks like the party just finished their meal and paid the bill..." << endl;
        cout << "Congrats! You made $" << billTotalAmount << " dollars for your restaurant. 💰" << endl << endl;
        this->setBalance(this->getBalance() + billTotalAmount);

        //adjust average rating
        int totalMistakes = c.getMistakes() + s.getMistakes();
        double customerRating = generateRating(totalMistakes);
        cout << "This group gave your restaurant a rating of " << customerRating << " stars ⭐" << endl << endl;
        this->setAverageRating(customerRating);

        //adjust balance according to mistakes - 5% decrease for every mistake
        int newBalance = this->getBalance() - (this->getBalance() * 0.05 * totalMistakes);
        this->setBalance(newBalance);

            //evaluate results (check balance, rating, etc) and go back to start if results pass
            cout << this->getRestaurantName() << " Review: " << this->getRating() << "/5 Stars ⭐" << endl;
            cout << this->getRestaurantName() << " Balance: $" << this->getBalance() << " 💵" << endl << endl;

 
        //display message based on whether results pass or fail
        if (this->getRating() >= 2 && this->getBalance() > 0) {
                string userChoice;
                cycleNum++;

                cout << "Congratulations! Your first day at your new restaurant was a success! 👏" << endl;
                cout << "Would you like to continue or quit? ('c' = continue, 'q' = quit): ";
                cin >> userChoice;
                userChoice = validateStringInput(userChoice, 4);
                cout << endl;

                if (userChoice == "q") {
                    cout << "We hope you had fun playing Restaurant Simulator! Until next time! 👋" << endl << endl;
                    m.clearFullMenu();

                    return; //end game
                }
                else if (userChoice == "c") {
                    cout << "TIME FOR ROUND " << cycleNum << "! GOOD LUCK! 🍀" << endl << endl;
                }
        }
        else {
            cout << "Oh no! Seems like your restaurant didn't do too well. 🙁" << endl;
            cout << "Thanks for playing, better luck next time! 👋" << endl << endl;
            m.clearFullMenu();

            return; //end game
        }
    }
}

double Restaurant::generateRating(int numberOfMistakes) {
    if (numberOfMistakes == 0) {
        return 5;
    }
    double rating = rand() % 6 + (50 - 5 * numberOfMistakes);
    rating = rating / 10;
    if (rating < 0) {
        return 0;
    }
    return rating;
}

void Restaurant::setAverageRating(int newRating) {
    int totalRating = this->getRating() + newRating;
    totalRating = totalRating / 2;
    this->setRating(totalRating);
}

string Restaurant::validateStringInput(string userInput, int num) {
    string newInput = userInput;

    if (num == 1) {
        while (newInput != "a" && newInput != "m" && newInput != "d") {
            cout << endl << "Invalid food type, try again: ";
            cin >> newInput;
        }
    }
    else if (num == 2) {
        while (newInput != "n" && newInput != "y") {
            cout << endl << "Invalid input, try again: ";
            cin >> newInput;
        }
    }
    else if (num == 3) {
        while (newInput != "y") {
            cout << endl << "Invalid input, try again: ";
            cin >> newInput;
        }
    }
    else if (num == 4) {
        while (newInput != "c" && newInput != "q") {
            cout << endl << "Invalid input, try again: ";
            cin >> newInput;
        }
    }

    return newInput;
}

int Restaurant::validateIntInput(int userInput, int num, int upperBound) {
    int newInput = userInput;

    if (num == 1) {
        while (newInput <= 0 || newInput > upperBound) {
            cout << endl << "Invalid table number, try again: ";
            cin >> newInput;
        }
    }

    return newInput;
}

double Restaurant::validateDoubleInput(double userInput, int num) {
    double newInput = userInput;

    if (num == 1) {
        while (newInput <= 0.0 || newInput > 1000.0) {
            cout << endl << "Invalid price, try again: $";
            cin >> newInput;
        }
    }

    return newInput;
}