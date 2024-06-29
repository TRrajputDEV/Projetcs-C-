// libraries
#include <iostream>
using namespace std;
#include <ctime>

// function declaration
void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);

// main
int main()
{
    char spaces[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;
    drawBoard(spaces);

    while(running)
    {
        playerMove(spaces ,player);
        // drawBoard(spaces);
        if(checkWinner(spaces , player , computer))
        {
            running = false; 
            break;
        }else if (checkTie(spaces)){
            running=false;
            break;
        }
        computerMove(spaces, computer);
        drawBoard(spaces);
        if(checkWinner(spaces , player , computer))
        {
            running = false; 
            break;
        }else if (checkTie(spaces)){
            running=false;
            break;
        }
    }
    std:: cout << "Thanks for playing!";
    return 0;
}

// functions

void drawBoard(char *spaces)
{
    std::cout<<endl;
    std:: cout << "     |     |     "<< '\n';
    std:: cout << "   "<< spaces[0] << " |   "<< spaces[1] << " |   "<< spaces[2] << "  "<< '\n';
    std:: cout << "_____|_____|_____"<< '\n';
    std:: cout << "     |     |     "<< '\n';
    std:: cout << "   "<< spaces[3] << " |   "<< spaces[4] << " |   "<< spaces[5] << "  "<< '\n';
    std:: cout << "_____|_____|_____"<< '\n';
    std:: cout << "     |     |     "<< '\n';
    std:: cout << "   "<< spaces[6] << " |   "<< spaces[7] << " |   "<< spaces[8] << "  "<< '\n';
    std:: cout << "     |     |     "<< '\n';
    std::cout<<endl;
}
void playerMove(char *spaces, char player)
{
    int number;
    do
    {
        std:: cout<< " Enter a spot to place a maarker (1-9): ";
        std::cin >> number;
        number--;
        if(spaces[number] == ' ')
        {
            spaces[number] = player ;
            break;
        }
    }while (!number > 0 || !number <8 );
    
}
void computerMove(char *spaces, char computer)
{
    int number;
    srand(time(0));
    while (true)
    {
        /* code */
        number = rand() % 9;
        if(spaces[number] == ' ')
        {
            spaces[number] = computer ;
            break;
        }
    }
    
}
bool checkWinner(char *spaces, char player, char computer)
{
    if (spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2])
    {
        /* code */
        spaces[0] == player ? std:: cout << "YOU WIN\n! " : std::cout<<" YOU LOSE\n";
    }
    else if (spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5])
    {
        /* code */
        spaces[3] == player ? std:: cout << "YOU WIN\n! " : std::cout<<" YOU LOSE\n";
    }
    else if (spaces[6] != ' ' && spaces[6] == spaces[7] && spaces[7] == spaces[8])
    {
        /* code */
        spaces[6] == player ? std:: cout << "YOU WIN\n! " : std::cout<<" YOU LOSE\n";
    }
    else if (spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[3] == spaces[6])
    {
        /* code */
        spaces[0] == player ? std:: cout << "YOU WIN\n! " : std::cout<<" YOU LOSE\n";
    }
    else if (spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[4] == spaces[7])
    {
        /* code */
        spaces[1] == player ? std:: cout << "YOU WIN\n! " : std::cout<<" YOU LOSE\n";
    }
    else if (spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8])
    {
        /* code */
        spaces[2] == player ? std:: cout << "YOU WIN\n! " : std::cout<<" YOU LOSE\n";
    }
    else if (spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8])
    {
        /* code */
        spaces[0] == player ? std:: cout << "YOU WIN\n! " : std::cout<<" YOU LOSE\n";
    }
    else if (spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6])
    {
        /* code */
        spaces[2] == player ? std:: cout << "YOU WIN\n! " : std::cout<<" YOU LOSE\n";
    }
    else{
        return false;
    }
    
    return true;
}
bool checkTie(char *spaces)
{
    for (int i = 0; i < 9; i++)
    {
        if (spaces[i]==' ')
        {
            return false;
        }
        
    }
    std:: cout<< "ITS A TIE!\n";
    
    return true;
}