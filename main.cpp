//Jomar Felipe - Football Scoreboard
//Object Oriented Programming in C++
//Date: 4-24-2021, UPDATED NOVEMBER 2022
//Teacher: Dr. Tyson McMillan

#include <iostream>
#include <string> 
#include <unistd.h>
#include "Input_Validation_Extended.h"
using namespace std; 

class Team 
{
  private:
    int score; 
    bool homeStatus; 
    string name; 
    int shotsOnGoal; 
    string coachName; 
    int timeOutsLeft;
  public:
      Team() //default constructor 
      {
        score = 0; 
        homeStatus = false; //visitor = false, home = true
        name = "DefaultTeamName"; 
        shotsOnGoal = 0; 
        coachName = "DefaultCoachName"; 
        timeOutsLeft = 3;
      }
      void setScore(int s) { score = s; }
      void setHomeStatus(bool hs) { homeStatus = hs; }
      void setName(string n) { name = n; }
      void setShotsOnGoal(int sog) { shotsOnGoal = sog; }
      void setCoachName(string sCN) { coachName = sCN; }
      int getScore() const { return score; }
      bool getHomeStatus() const { return homeStatus; }
      string getName() const { return name; }
      int getShotsOnGoal() const { return shotsOnGoal; }
      string getCoachName() const { return coachName; }
      int getTimeOutsLeft() const { return timeOutsLeft; }
      bool useTimeOut()
      {
          if(timeOutsLeft > 0)
          {
            timeOutsLeft--; 
            return true;
          }

        return false;
      }
};

class Scoreboard
{
  private:
    int half; 
    Team home; //object that is a member of another object
    Team visitor; 
  public: 
    Scoreboard()
    {
      half = 0; 
    }  
    void setHalf(int h) { half = h; }
    void setHome(Team hSet) { home = hSet; }
    void setVisitor(Team vSet) { visitor = vSet; }
    int getHalf() const { return half; }
    Team getHome() const { return home; }
    Team getVisitor() const { return visitor; }
    void showScoreboard()
    {
      string color = ""; 
      string reset = "\x1b[0m";
      color = "\x1b[32;4m"; //green 
      string score = "\x1b[36;1m"; //score color 
      cout << color << "Football (Soccer) Scoreboard by Jomar Felipe" << reset << endl; 
      cout << home.getName() << "\t\t" << visitor.getName() << endl; 
      cout << score << "Score: " << home.getScore() << "\t\t\t" << "Score: " << visitor.getScore() << reset << endl; 
      cout << home.getCoachName() << reset << "\t" << visitor.getCoachName() << endl; 
      cout << "TOL: " << home.getTimeOutsLeft() << "\t\t\t\t" << "TOL: " << visitor.getTimeOutsLeft() << endl;
      for(int i = 0; i < 47; i++) { cout << "*"; } cout << endl;
       
       //proces to show the home team status
       cout << "Home> \t"; 
       if(home.getHomeStatus() == true)
       {
         cout << "Team 1: " << home.getName() << "*"; 
       }
       else if(visitor.getHomeStatus() == true)
       {
         cout << "Team 2: " << visitor.getName() << "*"; 
       }
       else
       {
         cout << "Error: "; 
       }
       
       cout  << endl; 
    }
};

int main() 
{
  Scoreboard s;
  Team tOne;
  Team tTwo; 
  string newName = ""; 
  string userChoice = ""; 
  string newCoachName = ""; 
  int homeTeamQuestion = 0; 
  int newScore = 0; 

  //Set the home team 
  tOne.setHomeStatus(true); //tOne is the Home Team now   

  //add some initial data to s
  s.setHome(tOne); 
  s.setVisitor(tTwo); 

  //Loop this to make it an interactive menu

  do 
  {
      system("clear"); //clear the screen of previous content 
      s.showScoreboard(); //show the current scoreboard data
      //menu choices 
      cout << "A = Update Home Team Name" << endl; 
      cout << "B = Update Home Team Score" << endl; 
      cout << "C = Update Home Status" << endl; 
      cout << "D = Update Visting Team Coach" << endl; 
      cout << "E = Update Timeouts Left Home" << endl;
      cout << "F = Update Timeouts Left Visitor" << endl;
      cout << "X = Exit" << endl;
      cout << ">"; 
      cin >> userChoice; 

      if(userChoice == "A" || userChoice == "a")
      {
        //Dr_T challenge Accept a new name for s's home team
        cout << "****Update Home Team Score module*** " << endl; 
        cout << "\nPlease enter a new name for the home team: ";
        cin >> newName; 
        //change that home team's default name
        tOne.setName(newName); //set tOne's data to the new desired name
      }
      else if(userChoice == "B" || userChoice == "b")
      {
        cout << "\nUpdate Home Score Module****" << endl; 
        cout << "\nPlease enter a new score for the home team: "; 
        cin >> newScore; 
        tOne.setScore(newScore);  //set the new score for tOne        
      }
      else if(userChoice == "C" || userChoice == "c")
      {
        cout << "\nUpdate Home Status Module****" << endl; 
        cout << "\nWho is the home team: 1 = T1, 2=T2: "; 
        homeTeamQuestion = validateInt(homeTeamQuestion); 
       // cin >> homeTeamQuestion; 
        if(homeTeamQuestion == 1)
        {
          tOne.setHomeStatus(true); 
          tTwo.setHomeStatus(false); 
        }
        else if(homeTeamQuestion == 2)
        {
          tOne.setHomeStatus(false); 
          tTwo.setHomeStatus(true);
        }
        else
        {
          cout << "\nInvalid Input!" << endl;
          sleep(2); 
        }
      }
      else if(userChoice == "D" || userChoice == "d")
      {
          cout << "\nUpdate Visitor Coach Module****" << endl; 
          cout << "\nPlease enter the visitor coach Name: "; 
          cin >> newCoachName; 
          tTwo.setCoachName(newCoachName); 
      }
      else if(userChoice == "E" || userChoice == "e")
      {
          cout << "\nUsing Home Timeout****" << endl; 
         if( tOne.useTimeOut() == true)
         {
           cout << "Timeout Used" << endl;
         }
         else{
           cout << "No Timeouts Left" << endl;
         }
          sleep(2);
      }
       else if(userChoice == "F" || userChoice == "f")
      {
          cout << "\nUsing Home Timeout****" << endl; 
         if( tTwo.useTimeOut() == true)
         {
           cout << "Timeout Used" << endl;
         }
         else{
           cout << "No Timeouts Left" << endl;
         }
          sleep(2);
      }
      else if(userChoice == "X" || userChoice == "x")
      {
        cout << "Exit chosen." << endl; 
      }
      else //invalid input: default clause
      {
        cout << "\nInvalid input." << endl; 
        sleep(2); //wait two seconds, go to the next process 
      }

      s.setHome(tOne); //refresh the data in s to the new updates...
      s.setVisitor(tTwo); //refresh the data
  
  }while(userChoice != "X" && userChoice != "x");


  return 0; 


}
    
