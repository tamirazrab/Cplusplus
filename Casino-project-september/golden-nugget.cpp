/*
	Made by: Tamir Azrab
	It may sound easy to just remove this comment
	or maybe replace my name with yours but it ain't
	easy to write this long code and the time being invested
	so please do give credits if you can.
*/

#include <iostream>
#include <stdlib.h> // for seeding rand()
#include <time.h> // using time()
#include <string.h> // for string class

using namespace std;

#define MAX_STR_AMT 700 // Dice Roll max bet amount
#define MIN_STR_AMT 5 // Dice Roll min bet amount
#define PC_FIRST_DICE 0
#define PC_SECOND_DICE 1
#define USER_FIRST_DICE 2
#define USER_SECOND_DICE 3
#define PC_DICE_SUM 0
#define USER_DICE_SUM 1

// Function Declaration area
/*
	Draw line function draws a line of special
	character specified in it's parameters to a
	given length
*/
void drawLine( int length , char character );
/*
	cleaner function takes two argument one to how many
	times move cursor to next line and second how many
	times should it give spaces
*/
void cleaner( int newline_length = 0 , int tab_length = 0 );

/*
 * Dice roll function works with by taking user starting amount, asking user to bet some money
 * then proceed to game. It contains all the validation of user input so user input can't be wrong
 * It proceeds by rolling two dices of Computer first then adding their sum and displaying it to the screen
 * then asks the player or user to press a special relevant key to proceed rolling user or player dice
 * then it's compare who got the greater number and declares that player as winner
 * If computer or player dice sum equals to 2 -> then they will be automatically declared as loser
 * If computer or player dice sum equals to 12 -> then they will automatically be declared as winner
 */

int diceRoll( );

/*
 * Number Guessing function generates a random number in range of 1 - 10
 * And ask user to bet any amount > 0 and < maximum bet amount
 * then asks user for guess, if user somehow guesses correctly
 * then he gets x10 amount back which he bett, if player guesses wrong then
 * he loses money
 */

void NumberGuessing( );

/*
 * High and low function proceed by generating two random numbers,
 * it shows first random generated number to user then asks user to guess
 * whether second random generated number is higher ( greater ) or lower ( lesser)
 * then previously generated number. ( Second number isn't shown to user )
 * Awards x2 money back if user guesses right.
 */

void High_and_Low();

/*
 * back to main function as name suggest directs user back to main() function when user is done
 * playing one game and wants to play another game or to close program.
 * It is called on every function end before asking whether user want to play again or not.
 */

void backToMain();

/*
 * Ask user bet gets user bet ( validated ) and stores it in global variable so that all functions
 * can access it properly, it is called on every function start. Returns true after it's get valid bet amount/
 */

bool askUserBet( int maxBet, int minBet );

/*
 * Play again gets user choice ( validated ) whether he wants to play again or not.
 * then returns true if user presses Y or y and returns false if user enters n or N
 */

bool playAgain();

/*
 * Check user money functions checks whether user starting balance reached zero or not
 * if it reached zero it redirects user back to main function so user can deposit some new amount
 * and can enjoy game again. If it doesn't reached zero then it asks user whether he wants to play again
 * or not.
 */

bool checkUserMoney();

/*
 * game Greetings function basically takes game name as argument and display it in a fancy way
 * in a starting of every game function.
 */

void gameGreetings( string gameName );

// Global variables area
/*
	direct back to main() function
	in a way that avoids asking user name again
	and let user deposit some new amount to play some
	more games.
*/
bool getBackToMain = true;
/*
	Made userName variable to global to avoid
	un-necessary passing to back to back to
	functions and let ease our work
*/
string userName;
/*
	startingBalanceOfUser variable holds the starting money that user
	deposits and let it change through every function
	required it
*/
int startingBalanceOfUser = 0;

/*
 * userBettingAmount is the variable which holds the amount user bets
 * before playing any game.
 */
int userBettingAmount = 0;

int main() {
    system("cls"); // Clear Screen
    srand( time( NULL ) ); // calls only once seeding rand()
    if ( getBackToMain ) {
        cleaner( 1 ); drawLine( 80, '-' ); cleaner( 2, 3 );
        cout << "Golden Nuggets Casino" << endl;
        cleaner( 1 ); drawLine( 80, '-' ); cleaner( 1, 2 );
        cout << "Enter your name please : ";
        getline( cin , userName );
    }
    else {
        cleaner( 2, 2 );
        cout << "Your balance is " << startingBalanceOfUser << "$ from previous games.";
        cleaner( 2 , 2 ); cout << " Please Deposit some new amount to play more games.";
        cleaner( 2 );
    }

    bool validateUserStartingAmount = false;
    do {
        cleaner( 2 , 2 );
        cout << "Enter your starting betting amount in $ : ";
        cin >> startingBalanceOfUser;
        if( startingBalanceOfUser > 700 ) {
            validateUserStartingAmount = true;
            cleaner( 2, 2 ); cout << "Sorry you can't deposit more then 700$";
        }
        else if( startingBalanceOfUser < 200 ) {
            validateUserStartingAmount = true;
            cleaner( 2 , 2 ); cout << "Sorry you must deposit more then 200$";
        }
        else
            validateUserStartingAmount = false;
    } while ( validateUserStartingAmount );
    cleaner( 1 , 2 );
    cout << "Welcome to Golden Nugget Casino, " << userName << endl;
    cleaner( 1 ); drawLine( 80, '-' ); cleaner( 1, 1 );
    cout << "Please Choose from the list below, Which game you want to play ? ";
    cleaner( 2, 2 );
    cout << " 1 - Number Guessing ( Win amount x10) " << endl; cleaner( 1 , 2);
    cout << " 2 - High and Low ( Win amount x2) " << endl; cleaner( 1 , 2);
    cout << " 3 - Dice Roll ( Win amount x2)" << endl; cleaner( 1 , 2);
    cout << " 4 - To Exit Program." << endl; cleaner( 1 , 2 );
    cleaner( 1 );  drawLine( 80, '-' );
    cleaner( 0 , 2);  cout << "Enter your choice below ( in numbers ) : ";
    int gameSelection; cin >> gameSelection;
    cleaner( 1, 0 ); drawLine( 80, '-' );
    switch ( gameSelection ) {
        case 1: NumberGuessing(); break;
        case 2: High_and_Low(); break;
        case 3: diceRoll(); break;
        case 4: exit( 0 ); // Didn't added break because it's unreachable if exit function called first.
        default: cleaner( 2, 2 ); cout << "Wrong Choice, Exiting Program."; break;
    }
    return 0;
}

void drawLine( int length , char character ) {
    for( int i = 1; i <= length; ++i )
        cout << character;
    cout << "\n";
}


void cleaner( int newline_length , int tab_length ) {
    for( int i = 1; i <= newline_length; ++i )
        cout << endl;
    for( int i = 1; i <= tab_length; ++i )
        cout << "\t";
}

int diceRoll( ) {
    start_of_diceRoll:
        gameGreetings( "Dice Roll" );
        bool rolldice_check = true;

            /*
                According to betting rule minimum bet allowed is 5$
                whereas maximum is 700$ user can't bypass these rules
                if userBettingAmount is more then the deposited money by the user
                then it also not allowed
            */
            /*
             * MAX_STR_AMT represents maximum bet can be placed in dice roll which is 700$
             * MIN_STR_AMT represents minimum bet can be placed in dice roll which is 5$
             */
            askUserBet( MAX_STR_AMT, MIN_STR_AMT );

            /*
             * Array of integer dice contains the sum of dices rolled both by computer and user.
             * First two indexes of dice array represents computer dices rolled on floor
             * dice [ PIC_FIRST_DICE -> equivalent to 0 ] , dice [ PC_SECOND_DICE -> equivalent to 1 ]
             * Last two indexes of dice array represents user or player dices
             * dice [ USER_FIRST_DICE -> equivalent to 2 ] , dice [ USER_SECOND_DICE -> equivalent to 3 ]
             */

        int dice[ 4 ] , diceSum[ 2 ];
        dice[ PC_FIRST_DICE ] = ( rand() % 6 ) + 1; // in range 1 - 6;
        dice[ PC_SECOND_DICE ] = ( rand() % 6 ) + 1;
        diceSum[ PC_DICE_SUM ] = dice[ PC_FIRST_DICE ] + dice [ PC_SECOND_DICE ];

         cleaner( 1 ); drawLine( 80, '*' ); cleaner( 2 , 2 );
         cout << "Computer rolls the dice on the floor " << diceSum[ PC_DICE_SUM]
              << " for the bet of " << userBettingAmount << "$" << endl;
         cleaner( 1 ); drawLine( 80, '*' );

        if ( diceSum[ PC_DICE_SUM ] == 2 ) {
            // Computer Loses automatically
            cleaner( 2 ); drawLine( 80, '_' );
            cleaner( 2 , 2 );
            cout << "Computer looses automatically as it lands on 2." << endl;
            cleaner( 1, 2 );
            cout << "Congratulations you have won " << userBettingAmount * 2 << "$.";
            cleaner( 1 ); drawLine( 80, '_' ); cleaner( 1 );
            drawLine( 80, '^' );
            startingBalanceOfUser = startingBalanceOfUser + ( userBettingAmount * 2 );
            cleaner( 1, 2 );
            cout /* << endl */ << "Your new balance is " << startingBalanceOfUser << "$.";
            cleaner( 1 ); drawLine( 80, '.' );
            goto end_of_diceRollGame;
        }
        else if ( diceSum[ PC_DICE_SUM ] == 12 ) {
            // Computer Won automatically
            cleaner( 1 ); drawLine( 80, '_' );
            cleaner( 1, 2 );
            cout << "Computer Wons automatically as it lands on 12." << endl;
            cleaner( 1, 2 );
            cout << "Sorry you can't roll dice, as chances of yours getting 12 "
                 << " is equal to NULL." << endl;
            cleaner( 1 );  drawLine( 80, '_' );
            cleaner( 1 );
            drawLine( 80, '^' );
            cout << "Your new balance is " << startingBalanceOfUser << "$.";
            cleaner( 1 ); drawLine( 80, '.' );
            goto end_of_diceRollGame;
        }
        // if computer didn't got 2, or 12 then
        char rollDice;

        do {
            cleaner( 2 , 2 );
            cout << " Please press r/R to roll your dice : ";
            cin >> rollDice;
            // to let user out of loop if he/she typed r/R
            rolldice_check = !(rollDice == 'r' || rollDice == 'R');
        } while( rolldice_check ); /*rollDice != 'r' || rollDice != 'R'*/

        dice[ USER_FIRST_DICE ] = ( rand() % 6 ) + 1; // in range 1 - 6;
        dice[ USER_SECOND_DICE ] = ( rand() % 6 ) + 1;
        diceSum[ USER_DICE_SUM ] = dice[ USER_FIRST_DICE ] + dice [ USER_SECOND_DICE ];

        cleaner( 1 );  	drawLine( 80, '*' ); cleaner( 1, 2 );
        cout << userName << " rolls the dice on the floor " << diceSum[ USER_DICE_SUM]
                        << " for the bet of " << userBettingAmount << "$" << endl;
        cleaner( 1 ); drawLine( 80, '*' );

        if ( diceSum[ USER_DICE_SUM ] == 2 ) {
            // User Losses automatically
            cleaner( 1 ); drawLine( 80, '_' );
            cleaner( 1, 2 );
            cout << userName << " Sorry you have lost as you got 2." << endl;
            cleaner( 1 );  drawLine( 80, '_' );
            cleaner( 1 );
            drawLine( 80, '^' );
            // startingBalanceOfUser = startingBalanceOfUser - userBettingAmount;
            cleaner( 1, 2 );
            cout  << "Your new balance is " << startingBalanceOfUser << "$.";
            cleaner( 1 ); drawLine( 80, '.' );
            goto end_of_diceRollGame;
        }
        else if ( diceSum[ USER_DICE_SUM ] == 12 ) {
            // User Won automatically
            cleaner( 1 ); drawLine( 80, '_' );
            cleaner( 1, 2 );
            cout << userName << " Congratulation on getting number 12, you've won automatically "
                 << endl;
            cleaner( 1 );  drawLine( 80, '_' );
            cleaner( 2 ); drawLine( 80, '^' );
            startingBalanceOfUser = startingBalanceOfUser + ( userBettingAmount * 2 );
            cleaner( 2 , 3 );
            cout << "Your new balance is " << startingBalanceOfUser << "$.";
            cleaner( 2 ); drawLine( 80, '.' );
            goto end_of_diceRollGame;
        }
        else if ( diceSum[ PC_DICE_SUM ] == diceSum[ USER_DICE_SUM ] ) {
            // if both got the same number in their dices
            cleaner( 2 );
            drawLine( 80, '^' );
            cleaner( 2 , 3 );
            cout << " Haha, Sorry no one won as both players dices rolled";
            cleaner( 1 , 3 );
            cout << " on same number. " << endl;
            cleaner( 2 ); drawLine( 80, '.' );
            /*
             * Assigning user bett amount back to user starting balance ( startingBalanceOfUser )
             * As of it's gonna ask user again to bet new amount after goto statement.
             */
            startingBalanceOfUser = userBettingAmount;
            goto end_of_diceRollGame;
        }
        // else if user didn't got either 2, or 12

        if( diceSum[ PC_DICE_SUM ] > diceSum[ USER_DICE_SUM ] ) {
            cleaner( 1, 0 );  drawLine( 80, '_' );
            cleaner( 1, 2 );
            cout << "Computer got the higher number on their dice "
                 << " Which was " << diceSum[ PC_DICE_SUM ]; /*<< endl */
            cleaner( 2  , 2 );
            cout << " Whereas you got " << diceSum[ USER_DICE_SUM ];
            cleaner( 2 );
            drawLine( 80, '_' );
            cleaner( 2 );
            drawLine( 80, '^' );
            cleaner( 2 , 2 );
            cout  << " Sorry you've just lost " << userBettingAmount << "$.";
            cleaner( 3, 0 ); drawLine( 80, '^' );
            cleaner( 2 ); drawLine( 80, '^' ); cleaner( 2 , 2 );
            cout  << "Your new balance is " << startingBalanceOfUser << "$.";
            cleaner( 3, 0 ); drawLine( 80, '.' );
        }
        else {
            cleaner( 1, 0 );  drawLine( 80, '_' );
            cleaner( 2 , 2 );
            cout  << userName << " got the higher number on their dice "
                  << " Which was " << diceSum[ USER_DICE_SUM ];
            cleaner( 2 , 2 );
            cout << " Whereas Computer got " << diceSum[ PC_DICE_SUM ];
            cleaner( 2 );
            drawLine( 80, '_' );		cleaner( 1, 2 );
            cout  << " Congratulations you've won " << userBettingAmount << "$.";
            cleaner( 3 );
            drawLine( 80, '^' );
            startingBalanceOfUser = startingBalanceOfUser + ( userBettingAmount * 2 );
            cleaner( 2 , 2 );
            cout  << "Your new balance is " << startingBalanceOfUser << "$.";
            cleaner( 2 ); drawLine( 80, '.' );
        }
        end_of_diceRollGame:
                /*
                 * checkUserMoney returns true if balance == 0 or < 0 else -> returns false
                 * playAgain returns true if userChoice == y || Y else returns false
                 */
                if( checkUserMoney() )
                    /* Send to main menu */
                        backToMain();
                else {
                    if( playAgain() )
                        goto start_of_diceRoll;
                    else
                        backToMain();
                }

        /*
            Eliminating use of conditions directly inside while
            loop as it's gives un-expected results
            using boolean variable playagain_check to determine
            whether user want to play again or not.
            Sending back user to the lable "END" if user entered
            character different then Y/y N/n
        */

    /* if( startingBalanceOfUser < 0 || startingBalanceOfUser == 0 || startingBalanceOfUser > 0 ) */

    return 0;
}

void NumberGuessing( ) {
    start_of_numberGuessing:
        gameGreetings( "Number Guessing" );
        askUserBet( 200 , 100 );
    // After user bet is validated properly
    // generates number in range of 1 - 10 and stores in RandomNumberByComputer;
    int RandomNumberByComputer = ( rand() % 10 ) + 1;
    int getUserGuess = 0;
    cleaner( 2 ); drawLine( 80, '*' ); cleaner( 2, 2 );
    cout << "Computer Generated a random number in range of ( 1 - 10) ";
    cleaner( 2 ); drawLine( 80, '*' );
    bool validateUserGuess = false;
    do {
        cleaner( 3 );
        drawLine( 80, '*' );
        cleaner( 1 , 2 );
        cout << "Enter your guess : ";
        cin >> getUserGuess;
        if( getUserGuess < 1 || getUserGuess > 10 ) {
            validateUserGuess = true;
            cleaner( 1 , 2 ); cout << "Your Guess is invalid , it must be in range of 1 - 10." << endl;
            cleaner( 1 , 2 ); cout << "Please enter guess again in range of ( 1 - 10 )" << endl;
        }
        else
            validateUserGuess = false;
    } while( validateUserGuess );
    // Checking user Guess
    if( getUserGuess == RandomNumberByComputer ) {
        cleaner( 1 ); drawLine( 80, '$' ); cleaner( 1, 2 );
        cout << "Congratulations Your guess is correct." << endl;
        cleaner( 1 , 2 ); cout << "Computer Generated Number was " << RandomNumberByComputer;
        cleaner( 1  ); drawLine( 80, '-'); cleaner( 1 , 2 );
        cout << "You have won x10 money " << userBettingAmount * 10 << " $ ";
        startingBalanceOfUser = startingBalanceOfUser + ( userBettingAmount * 10 );
        cleaner( 1 , 2 ); cout << "Your new balance is " << startingBalanceOfUser << "$";
        cleaner( 1 ); drawLine( 80, '-'); cleaner( 1 );
        cleaner( 1 ); drawLine( 80, '$' );
    }
    else {
        cleaner( 1 ); drawLine( 80, '*' ); cleaner( 1, 2 );
        cout << "Computer Generated Number was " << RandomNumberByComputer;
        cleaner( 2, 2 ); cout << "Whereas your guess was " << getUserGuess;
        cleaner( 2 , 2 ); cout << "Sorry you've lost " << userBettingAmount << " $ ";
        cleaner( 2 ); drawLine( 80, '*' );
    }

    if( checkUserMoney() )
        /* Send to main menu */
             backToMain();
    else {
        if ( playAgain() )
            goto start_of_numberGuessing;
        else
            backToMain();
    }
}

void High_and_Low() {
    start_of_highAndLow:
        gameGreetings( "High and Low" );
        char takeGuessFromUser;
        bool validateGuessByUser = false;
        int holdTwoNumbers [ 2 ];
        askUserBet( 800 , 100 );
        // Starting Game by generating two random numbers
        holdTwoNumbers [ 0 ] = ( rand() % 10 ) + 1; // in range 1 - 10
        holdTwoNumbers [ 1 ] = ( rand() % 10 ) + 1;
        getValid_randomNumber:
        if( holdTwoNumbers[ 0 ] > 8 || holdTwoNumbers[ 0 ] < 3 ) {
            /*
             * Did, because if first random generated number is greater then 8
             * Then it's obvious that second number will be lesser
             * Or if first random generated number is lesser then 3
             * Then it's also obvious that second number will be greater no matter what!
             */
            holdTwoNumbers[0] = (rand() % 10) + 1;
            goto getValid_randomNumber;
        }
        cleaner( 1 ); drawLine( 80, '*' ); cleaner( 1, 2 );
        cout << "Computer Generated first number is " << holdTwoNumbers[ 0 ];
        cleaner( 2 ); drawLine( 80, '*' );
        // Taking User guess
        do {
            cleaner( 1, 2 ); cout << "Tell whether next generated number is high or low";
            cleaner( 2, 2 ); cout << "then previously generated number. ( H/h for high )";
            cleaner( 2, 2 ); cout << "(L/l for Low) ";
            cleaner( 2, 2 ); cout << "Enter your guess : ";
            cin >> takeGuessFromUser;
            if( takeGuessFromUser == 'H' || takeGuessFromUser == 'h' ) {
                validateGuessByUser = false;
                if( holdTwoNumbers[ 1 ] > holdTwoNumbers[ 0 ] ) {
                    cleaner( 1 );  drawLine( 80, '*' ); cleaner( 1, 2 );
                    cout << "Congratulations you guessed right";
                    cleaner( 2, 2 ); cout << "Second generated number was " << holdTwoNumbers[ 1 ];
                    cleaner( 2, 2 ); cout << "You won " << userBettingAmount * 2 << "$";
                    cleaner( 2 );  drawLine( 80, '*' ); cleaner( 1 );
                    drawLine( 80, '-' ); cleaner( 2 , 2 );
                    startingBalanceOfUser = startingBalanceOfUser + ( userBettingAmount * 2 );
                    cout << "Your new balance is " << startingBalanceOfUser;
                    cleaner( 3 ); drawLine( 80, '-' );
                    goto end_of_highAndLow;
                }
                else {
                    cleaner( 1 );  drawLine( 80, '*' ); cleaner( 2, 2 );
                    cout << "Sorry you have lost " << userBettingAmount << "$";
                    cleaner( 2, 2 ); cout << "Second generated number was " << holdTwoNumbers[ 1 ];
                    cleaner( 2 );  drawLine( 80, '-' ); cleaner( 2 , 2 );
                    cout << "Your new balance is " << startingBalanceOfUser << "$";
                    cleaner( 2 );  drawLine( 80, '-' );
                    goto end_of_highAndLow;
                }
            }
            else if ( takeGuessFromUser == 'L' || takeGuessFromUser == 'l' ) {
                validateGuessByUser = false;
                if( holdTwoNumbers[ 1 ] < holdTwoNumbers[ 0 ] ) {
                    cleaner( 2 );  drawLine( 80, '*' ); cleaner( 1 , 2 );
                    cout << "Congratulations you guessed right";
                    cleaner( 2, 2 ); cout << "Second generated number was " << holdTwoNumbers[ 1 ];
                    cleaner( 2, 2 ); cout << "You won " << userBettingAmount * 2 << "$";
                    cleaner( 2 );  drawLine( 80, '*' ); cleaner( 1 );
                    drawLine( 80, '-' ); cleaner( 2 , 2 );
                    startingBalanceOfUser = startingBalanceOfUser + ( userBettingAmount * 2 );
                    cout << "Your new balance is " << startingBalanceOfUser << "$";
                    cleaner( 2 ); drawLine( 80, '-' );
                    goto end_of_highAndLow;
                }
                else {
                    cleaner( 1 );  drawLine( 80, '*' ); cleaner( 1, 2 );
                    cout << "Sorry you have lost " << userBettingAmount << "$";
                    cleaner( 2, 2 ); cout << "Second generated number was " << holdTwoNumbers[ 1 ];
                    cleaner( 2 );  drawLine( 80, '-' ); cleaner( 2 , 2 );
                    cout << "Your new balance is " << startingBalanceOfUser << "$";
                    cleaner( 2 );  drawLine( 80, '-' );
                    goto end_of_highAndLow;
                }
            }
            else {
                cleaner( 2 , 2 ); cout << "You entered invalid guess.";
                cleaner( 2 , 2 ); cout << "Please enter valid guess again.";
                validateGuessByUser = true;
            }
        } while ( validateGuessByUser );
        end_of_highAndLow:
            if( checkUserMoney() ) {
                /* Send to main menu */
                backToMain();
            }
            else {
                if( playAgain() )
                     goto start_of_highAndLow;
                else
                    backToMain();
            }
    }

void backToMain() {
    bool confirmTransfer = false;
    do {
        cleaner( 2 , 2 ); cout << "Please Press m or M to go to main menu : ";
        char askUser; cin >> askUser;
        if( askUser == 'M' || askUser == 'm' )
            confirmTransfer = false;
        else {
            confirmTransfer = true;
            cleaner( 2 , 2 ); cout << "Please enter m or M to get back to main menu.";
            cleaner( 2, 2 ); cout << "Anything else is not accepted.";
        }
    } while ( confirmTransfer );

    getBackToMain = false;
    main();
}

bool askUserBet( int maxBet, int minBet ) {
    bool validateUserBet = false;
    do {
        cleaner( 2, 2 ); cout << "Please enter the amount you want to bet : ";
        cin >> userBettingAmount;
        if( userBettingAmount > startingBalanceOfUser ) {
            validateUserBet = true;
            cleaner( 2 , 2 ); cout << "Sorry you can't bet more then your original balance.";
        }
        else if ( userBettingAmount > maxBet ) {
            validateUserBet = true;
            cleaner( 2 , 2 ); cout << "Sorry you cannot place bet more then " << maxBet << "$.";
        }
        else if( userBettingAmount < minBet ) {
            validateUserBet = true;
            cleaner( 2 , 2 ); cout << "Sorry your bet must be greater then " << minBet << "$.";
        }
        else {
            validateUserBet = false;
            // deducting money before hand
            startingBalanceOfUser = startingBalanceOfUser - userBettingAmount;
        }
    } while ( validateUserBet );
    return true;
}

bool playAgain() {
    bool confirmPlayAgain = false;
    char askUser;
    do {
        cleaner( 2 ); drawLine( 80, '-'); cleaner( 2 , 2 );
        cout << "Do you want to play again ? (Y/N) : ";
        cin >> askUser;
        if( askUser == 'Y' || askUser == 'y' )
            return true;

        else if( askUser == 'N' || askUser == 'n' )
            return false;

        else {
            confirmPlayAgain = true;
            cleaner( 2 , 2 ); cout << "Please enter your choice correctly.";
        }
    } while( confirmPlayAgain );
}

bool checkUserMoney() {
    if( startingBalanceOfUser <= 0 ) {
        cleaner( 3 , 0 ); drawLine( 80, '#' ); cleaner( 1, 2 );
        cout << "You don't have any money left to bet. ";
        cleaner( 2, 2 ); cout << "Sending you back to main menu.";
        cleaner( 3 , 0 ); drawLine( 80, '#' ); cleaner( 1, 2 );
        return true;
    }
    else
        return false;
}

void gameGreetings( string gameName ) {
    system("cls");
    cleaner( 1 ); drawLine( 80, '$'); cleaner( 2 , 2 );
    cout << "Welcome to " << gameName << " Game " << " Mr." << userName << endl;
    cleaner( 2 ); drawLine( 80, '$'); cleaner( 2 );
}