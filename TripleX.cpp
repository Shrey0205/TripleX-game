#include <iostream>
#include<ctime>
using namespace std;

void PrintIntro(int Diff)
{
      //Print Welcome message to the terminal
    std::cout<<"\n\nYou are a secret agent breaking into a Level " << Diff;
    std::cout<<" secure server room....\nYou need to enter the correct codes to continue...\n\n";
}

bool PlayGame(int Diff)
{
    PrintIntro(Diff);

     //Intializing of 3 number code
   const int CodeA=rand()%Diff+Diff;
   const int CodeB=rand()%Diff+Diff;
   const int CodeC=rand()%Diff+Diff;

   // Addition and Multiplication of the code numbers
    const int CodeSum=CodeA+CodeB+CodeC;
    const int CodeProd=CodeA*CodeB*CodeC;


       //Printing Process
     std::cout<<" + There are 3 numbers in the code";
     std::cout<<"\n + The code adds upto: "<< CodeSum ;
     std::cout<<"\n + The code multiplies to give: "<< CodeProd<<std::endl;
    
    //Store Player Guess
    int GuessA, GuessB, GuessC,GuessSum, GuessProd;
    std::cout<<"\nEnter Your Guess\n";
    std::cin>>GuessA;
    std::cin>>GuessB;
    std::cin>>GuessC;
    

    //check if the player is correct or not
   GuessSum=GuessA+GuessB+GuessC;
   GuessProd=GuessA*GuessB*GuessC;
  
    if(GuessSum==CodeSum && GuessProd==CodeProd)
    {
        std::cout<<"\n*** Well done Agent! You have extracted a file! Keep Going!! *** \n";
        return true;
        
        }
     else
     {

      std::cout<<"\n*** You have entered the wrong codes! Careful Agent! Try Again!! ***\n";
      return false;
     
     }
}

int main()
{
  srand(time(NULL)); //creates random sequence based on the time of day
  int LevelDiff=1;
  const int MaxLevel=5;

  while (LevelDiff <= MaxLevel)// loop the game until all levels are completed
  {

    bool bLevelComplete=PlayGame(LevelDiff);
    std::cin.clear();//Clears any error
    std::cin.ignore();//Discards The Buffer

     if (bLevelComplete)
     {
       ++LevelDiff; 
     }
     

  } 
  std::cout<< "\n*** Great Work Agent! You have extracted all the files! Now get out of there.\n";
    return 0;
} 