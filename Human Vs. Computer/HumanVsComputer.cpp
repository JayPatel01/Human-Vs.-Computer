/*  Author: Jay Patel 
//Human Vs. Computer
	
	Welcome to the world of Guessing Number. This Program takes user inputs in 0s and 1s only
	and using the power of forcasting users move, computer will try to guess the next input.
	And tries to bit the human.
	
	So, Good Luck Human.


*/
#include<iostream>

using namespace std;

//Function to display user Information.
void displayInfo()
{
	cout<<"Author:  Jay Patel "<<endl;
    cout<<"                                                         				"<<endl;
	cout<<"Enter 0 or 1, trying to outsmart the computer, which is going to 		"<<endl;
	cout<<"attempt to forecast your guesses.  On each move the score indicator		"<<endl;
	cout<<"moves to the right if the computer guesses correctly, and moves 			"<<endl;
	cout<<"to the left if the computer does not.                              		"<<endl;
    cout<<"Enter 't' to toggle displaying the data table.                 			"<<endl;
    cout<<"Enter 'r' to reset the board.                                  			"<<endl;
    cout<<"Enter 'x' to exit.														"<<endl;
}
//--------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------
//Function to convert table row into Binary numbers.
void convertBinary(int x)
{
	if(x<=3){cout<<"0";}
	if(x>=4){cout<<"1";}
	if(x==0||x==1||x==4||x==5){cout<<"0";}
	else{cout<<"1";}
	if(x%2==0){cout<<"0";}
	else{cout<<"1";}
}
//---------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------
//Function to create the game board/battle field...
int displayBoard(int score)
{
	char countArray[21];
	cout<<"Computer          Human"<<endl;
	cout<<"x---------x+++++++++x"<<endl;
	for(int i=0;i<21;i++)
	{
		if(i==score)
		{
			countArray[i]='^';
			cout<<countArray[i];
		}
		else
		{
			countArray[i]=' ';
			cout<<countArray[i];
		}
	}
	cout<<endl;
	return score;
}
//-----------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------
//Function to chose the opposite input for the first three moves.
void choseOpp(int human,int &computer,int &score)
{
	if(human==1)
	{
		computer=0; //assignes the opposite value to computer forcast
		cout<<"  Human gets a Point."<<endl;
		score++;
	}
	if(human==0)
	{
		computer=1; //assignes the opposite value to computer forcast
		cout<<"  Computer gets a Point."<<endl;
		score--;
	}
}
//---------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------
//Function to convert last three moves into decimal form.
int binaryIntoDecimal(int arrayLastThree[3])
{
	int binary;
	binary=(arrayLastThree[0]*4)+(arrayLastThree[1]*2)+(arrayLastThree[2]);  //Mathematical formula to convert into decimal numbers
	return binary;
}
//----------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------
//Function to update last three moves.
void updateLastThree(int update[3],int userInputValue)
{
	//Swaping the values of last Three move array with new Input values.
	update[0]=update[1];
	update[1]=update[2];
	update[2]=userInputValue;
}
//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
//Function to Forcast computer value when there is tie situation in table. FOr more than 3 moves.
void oppositeChoice(int userInput, int &comForecast)
{
	if(userInput==0)
	{
		comForecast=1;
	}
	if(userInput==1)
	{
		comForecast=0;
	}
}
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//Function to Check for all the possible forcasting conditions for the entire table.
void gettingForecast(int historyCheck[8][2], int &comForecast,int userInput)
{
	// First row and coloum conditions
	if(historyCheck[0][0]>historyCheck[0][1])
	{comForecast=0;}
	if(historyCheck[0][0]<historyCheck[0][1])
	{comForecast=1;}
	if(historyCheck[0][0]==historyCheck[0][1])
	{oppositeChoice(userInput,comForecast);} //Function call for Tie conditions.
	
	// Second row and coloum conditions
	if(historyCheck[1][0]>historyCheck[1][1])
	{comForecast=0;}
	if(historyCheck[1][0]<historyCheck[1][1])
	{comForecast=1;}
	if(historyCheck[1][0]==historyCheck[1][1])
	{oppositeChoice(userInput,comForecast);}
	
	// Third row and coloum conditions
	if(historyCheck[2][0]>historyCheck[2][1])
	{comForecast=0;}
	if(historyCheck[2][0]<historyCheck[2][1])
	{comForecast=1;}
	if(historyCheck[2][0]==historyCheck[2][1])
	{oppositeChoice(userInput,comForecast);}
	
	// Fourth row and coloum conditions
	if(historyCheck[3][0]>historyCheck[3][1])
	{comForecast=0;}
	if(historyCheck[3][0]<historyCheck[3][1])
	{comForecast=1;}
	if(historyCheck[3][0]==historyCheck[3][1])
	{oppositeChoice(userInput,comForecast);}
	
	// Fifth row and coloum conditions
	if(historyCheck[4][0]>historyCheck[4][1])
	{comForecast=0;}
	if(historyCheck[4][0]<historyCheck[4][1])
	{comForecast=1;}
	if(historyCheck[4][0]==historyCheck[4][1])
	{oppositeChoice(userInput,comForecast);}
	
	// Sixth row and coloum conditions
	if(historyCheck[5][0]>historyCheck[5][1])
	{comForecast=0;}
	if(historyCheck[5][0]<historyCheck[5][1])
	{comForecast=1;}
	if(historyCheck[5][0]==historyCheck[5][1])
	{oppositeChoice(userInput,comForecast);}
	
	// Seven row and coloum conditions
	if(historyCheck[6][0]>historyCheck[6][1])
	{comForecast=0;}
	if(historyCheck[6][0]<historyCheck[6][1])
	{comForecast=1;}
	if(historyCheck[6][0]==historyCheck[6][1])
	{oppositeChoice(userInput,comForecast);}
	
	// Eight row and coloum conditions
	if(historyCheck[7][0]>historyCheck[7][1])
	{comForecast=0;}
	if(historyCheck[7][0]<historyCheck[7][1])
	{comForecast=1;}
	if(historyCheck[7][0]==historyCheck[7][1])
	{oppositeChoice(userInput,comForecast);}
	
}
//--------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//Function for displaying messages.
void compareResult(int computer, int Human, int &score)
{
	if(computer==Human)
	{
		cout<<"   Computer gets a Point"<<endl;
		score--;
	}
	else if(computer!=Human)
	{
		cout<<"    Human Gets a Point"<<endl;
		score++;
	}
}
//----------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------
//Main Function ..
int main()
{
	//Variable Declerations....
	int score=10;
	int move=1;
	int value;
	bool win=false;
	char userInput;
	int comForecast=0;
	int userInputValue;
	int lastThreeMoves[3]={0,0,0};
	int movesHistory[8][2]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	
	//Function call for displaying info.
	displayInfo();
	
	// do...while loop begining
	do
	{
		//Function Call to display the board with score.
		displayBoard(score);
		
		//Asking for user Input	
		cout<<move<<". Your input: ";
		cin>>userInput;
		
		//Conditions for Toggling and exiting loop
		if(isalpha(userInput))
		{
			userInput=toupper(userInput);
		
			if(userInput=='T')
			{
				//bool variable 
				if(win)
				{
				   win=false;	
				}
				else
				{
				   win=true;
				}
				
				// Displaying the table for the vary first time.
				--move;
				cout<<"\t 0       1 "<<endl;
				cout<<"\t----   ----"<<endl;
				for(int row=0;row<8;row++)
				{
					convertBinary(row);
					cout<<" ";
					for(int col=0;col<2;col++)
					{
						cout<<"	 "<<movesHistory[row][col]<<"  "; 
					}
				cout<<endl;
				}
				cout<<"Last three Moves: "<<lastThreeMoves[0]<<lastThreeMoves[1]<<lastThreeMoves[2]<<".     Forecast: "<<comForecast<<". "<<endl;
			}
			
		}// end of conditions.
		
		//Condition for the first three moves..
		if(move<4 && userInput!='T')
		{
			userInputValue=userInput-'0';
			if(move==1)
			{lastThreeMoves[0]=userInputValue;}
			if(move==2)
			{lastThreeMoves[1]=userInputValue;}
			if(move==3)
			{lastThreeMoves[2]=userInputValue;}
			
			//Function call for chosing opposite value for the forecast.
			choseOpp(userInputValue,comForecast,score);
			if(win)
				{
			
				cout<<"\t 0       1 "<<endl;
				cout<<"\t----   ----"<<endl;
				for(int row=0;row<8;row++)
				{
					convertBinary(row);
					cout<<" ";
					for(int col=0;col<2;col++)
					{
						cout<<"	 "<<movesHistory[row][col]<<"  "; 
					}
				cout<<endl;
				}
				cout<<"Last three Moves: "<<lastThreeMoves[0]<<lastThreeMoves[1]<<lastThreeMoves[2]<<".     Forecast: "<<comForecast<<". "<<endl;
		
				}
		}//end of condition for first three moves.
		
		//Condition for Any moves greater than three.
		if(move>=4 && userInput!='T')
		{
			//converting userInput character into integer
			userInputValue=userInput-'0'; 
			//Function call for the result
			compareResult(userInputValue,comForecast, score);
			//displaying the messages...
			if(score==5)
			{
				cout<<"Human I will Crush you..."<<endl;
			}
			if(score==15)
			{
				cout<<"Computer I will Crush you..."<<endl;
			}
			// Assigning decimal into Value
			value = binaryIntoDecimal(lastThreeMoves);
			
			//Updating MovesHistory...
			movesHistory[value][userInputValue]++;
			
			//Updating Last three moves.
			updateLastThree(lastThreeMoves,userInputValue);
			
			//Getting the forcast for computer.
			gettingForecast(movesHistory,comForecast,userInputValue);
			
			if(win)
				{
				
				cout<<"\t 0       1 "<<endl;
				cout<<"\t----   ----"<<endl;
				for(int row=0;row<8;row++)
				{
					convertBinary(row);
					cout<<" ";
					for(int col=0;col<2;col++)
					{
						cout<<"	 "<<movesHistory[row][col]<<"  "; 
					}
				cout<<endl;
				}
				cout<<"Last three Moves: "<<lastThreeMoves[0]<<lastThreeMoves[1]<<lastThreeMoves[2]<<".     Forecast: "<<comForecast<<". "<<endl;
				}
		}
	move++;
	if(userInput== 'X' || userInput=='x')
	{
		exit(0);
	}
	if(userInput== 'R' || userInput=='r')
	{
		cout<<"Sorry...can not reset it."<<endl;
		exit(0);
	}
	}while(score!=0 && score!=20 ); // End of do...while loop
	
	if(userInput=='x'|| userInput=='X')
	{
		return 0;
	}
	
	if(score==0)
	{
		displayBoard(score);
		cout<<"Computer Wins!!!"<<endl;
	}
	if(score==20)
	{
		displayBoard(score);
		cout<<"Human Wins!!!"<<endl;
	}
	return 0;
}// End of main Function...
//--------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------

