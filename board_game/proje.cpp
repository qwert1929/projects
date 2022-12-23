#include<iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <functional>
using namespace std;
vector<int> ans;
vector<int> ans1;
vector<int> ans2;
int ox; /*old x*/
int oy;
vector<vector<int> > arr{
                        { 1, 0, 3 },
                        { 4, 5, 6 },
                        { 7, 0, 9 } 
                        };
int player1[2]={0,1};
int player2[2]={2,1};

bool checkWinner();
int dellCell();
int takePos1();
int takePos2();
vector<int> getAdjacent(vector<vector<int> >& arr, int i,int j);
int makeTheMove(int x, int y);

bool isValidPos(int i, int j, int n, int m)
{
    if (i < 0 || j < 0 || i > n - 1 || j > m - 1)
        return 0;
    return 1;
}


int minimax(int depth,int board,int h)
{ 
   // if (depth == 0 || arr.isGameOver()) {
   // return arr.utility();
    }
   /*   If it's the current player's turn, find the move that maximizes their score
  if (arr.currentPlayer == PLAYER_1) {
    bestScore = -infinity;
    for (Move move : arr.getValidMoves()) {
      arr newState = arr.applyMove(move);
      score = minimax(newState, depth - 1);
      if (score > bestScore) {
        bestScore = score;
        bestMove = move;
      }
    }
  }
  // If it's the other player's turn, find the move that minimizes their score
  else {
    bestScore = +infinity;
    for (Move move : arr.getValidMoves()) {
      arr newState = arr.applyMove(move);
      score = minimax(newState, depth - 1);
      if (score < bestScore) {
        bestScore = score;
        bestMove = move;
      }
    }
  }

  // Return the best move
  return bestMove;
}
*/
  /*
if it is player 1's turn:
    bestScore = -infinity
    for each possible move:
        score = minimax(game state after move, depth + 1)
        bestScore = max(bestScore, score)
    return bestScore

if it is player 2's turn:
    bestScore = +infinity
    for each possible move:
        score = minimax(game state after move, depth + 1)
        bestScore = min(bestScore, score)
    return bestScore
*/


bool checkWinner1(){
  
ans1 = getAdjacent(::arr, player1[0], player1[1]);
int sum1=0; 
int sum2=0;
for (int i=0; i<ans1.size(); i++)
{  
   sum1 += ans1[i];
}
  //int sum = accumulate(ans.begin(), ans.end(), 0);
  if(sum1==0)
  {
    cout<<"GAME OVER player1 lost"<<endl;
    abort();
    return false;
  }

}

bool checkWinner2(){
  
ans2 = getAdjacent(::arr, player2[0], player2[1]);

int sum2=0;

for (int i=0; i<ans2.size(); i++)
{  
   sum2 += ans2[i];
}
  //int sum = accumulate(ans.begin(), ans.end(), 0);

  if(sum2==0)
  {
    cout<<"GAME OVER player2 lost"<<endl;
    abort();
    return false;
  }

}

int dellCell(){
cout<<"which cell do you want to delete? x,y:";
int x,y;
cin>>x;
cin>>y;
if(::arr[x][y]==0||(x==::player1[0]&&y==::player1[1])||(x==::player1[0]&&y==::player1[1]))
{
  cout<<"\nalready deleted or opponent is on the cell, enter new:";
  dellCell();
}
else
{
  ::arr[x][y]=0;
}
}

bool checkMove1(int x,int y)
{
  //int x= player[0];
  //int y= player[1];
if(count(/*if adjacent*/ans1.begin(), ans1.end(), arr[x][y])&&
        /*and if not equal to 0*/(arr[x][y]!=0 ))
    {  
        ::player1[0] = x ;
        ::player1[1] = y;

         cout<<"valid location"<<endl;
         makeTheMove(x,y);
    }
    else{
        
        cout<<"!!!!invalid location!!!!"<<endl;
        ans = getAdjacent(::arr, ::player1[0], ::player1[1]);
        cout<<"Adjacent cells you can move:";
        // Print all the adjacent elements
        for (int i = 0; i < ans.size(); i++) 
        {
          cout << ans[i] << " ";
        }
        // yeni pos. input al
        takePos1();
      } 
    
}
bool checkMove2(int x,int y)
{
  //int x= player[0];
  //int y= player[1];
if(count(/*if adjacent*/ans2.begin(), ans2.end(), arr[x][y])&&
        /*and if not equal to 0*/(arr[x][y]!=0 ))
    {  
        ::player2[0] = x ;
        ::player2[1] = y;

         cout<<"valid location"<<endl;
         makeTheMove(x,y);
    }
    else{
        
        cout<<"!!!!invalid location!!!!"<<endl;
        ans = getAdjacent(::arr, ::player2[0], ::player2[1]);
        cout<<"Adjacent cells you can move:";
        // Print all the adjacent elements
        for (int i = 0; i < ans.size(); i++) 
        {
          cout << ans[i] << " ";
        }
        // yeni pos. input al
        takePos2();
      } 
    
}

int takePos1()
{
  cout<<"\nplayer 1 enter pos x and y to move:"<<endl;
int x1;//=player[0];
int y1;//=player[1];
cin>>x1;
cin>>y1;

checkMove1(x1,y1);
/*
::player1[0]=x1;
::player1[1]=y1;
::arr[0][1]=0;
*/


}
int takePos2()
{
  cout<<"\nplayer 2 enter pos x and y to move:"<<endl;
int x1;//=player[0];
int y1;//=player[1];
cin>>x1;
cin>>y1;

checkMove2(x1,y1);
/*
::player2[0]=x1;
::player2[1]=y1;
::arr[2][1]=0;
*/


}

int makeTheMove(int x,int y)
{
//if() ...
//else false;
int i,j,k;
cout<<x<<"&"<<y<<endl;
cout<<"pos is equal to cell:"<<arr[x][y]<<endl;
::arr[x][y]=0;

for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }    
        cout << endl;
    }

    
}

// Function that returns all adjacent elements
vector<int> getAdjacent(vector<vector<int> >& arr, int i,int j)
{
    // Size of given 2d array
    int n = arr.size();
    int m = arr[0].size();
 
    // Initialising a vector array
    // where adjacent element will be stored
    vector<int> v;
 
    // Checking for all the possible adjacent positions
    if (isValidPos(i - 1, j - 1, n, m))
        v.push_back(arr[i - 1][j - 1]);
    if (isValidPos(i - 1, j, n, m))
        v.push_back(arr[i - 1][j]);
    if (isValidPos(i - 1, j + 1, n, m))
        v.push_back(arr[i - 1][j + 1]);
    if (isValidPos(i, j - 1, n, m))
        v.push_back(arr[i][j - 1]);
    if (isValidPos(i, j + 1, n, m))
        v.push_back(arr[i][j + 1]);
    if (isValidPos(i + 1, j - 1, n, m))
        v.push_back(arr[i + 1][j - 1]);
    if (isValidPos(i + 1, j, n, m))
        v.push_back(arr[i + 1][j]);
    if (isValidPos(i + 1, j + 1, n, m))
        v.push_back(arr[i + 1][j + 1]);
 
    // Returning the vector
    return v;
}


int atPos(int player[]){

int i,x,y;
x=player[0];
y=player[1];
cout<<"You are at pos: ";
for ( i = 0; i < 2; i++)
{
    cout<<player[i]<<" ";//:: global array kullanımı için
}
cout<<" "<<endl;

}
int main(){

/*
int board[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    board[0][1]=33;
    board[2][1]=99;
int i,j,r=0,c;
    for(i=0;i<3;i++)
     {  
       cout<<r<<". ";
        r++;
      for(j=0;j<3;j++)
    {  
        cout<<"|";
        cout<< board[i][j]<<" "; 
    }
        cout<<"|\n";
     }
     cout<<"    ";
     for(c=0;c<3;c++)
     {
        cout<<c<<". ";
     }
*/
while(true){


//  int n, m;
//  int l, j,s=1;
// vector<vector<int> > arr;
// for(l=0; l<3; l++)
//  {
//      for(j=0; j<3; j++){
//         arr[l][j]=s;
//         s++;
//      }
//  }
//   for(l=0; l<3; l++)
//  {
//      for(j=0; j<3; j++){
//          cout<<arr[l][j]<<" ";
//      }
//      printf("\n");
//  }



arr[player1[0]][player1[1]];
   
   for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }    
        cout << endl;
    } 
//oyuncvu 1 ve 2 için fonksiyon haline getir
 /*
   ::ans = getAdjacent(::arr, x, y);
cout<<"Adjacent cells you can move:";
// Print all the adjacent elements
for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
} */

    //takePos buranın yaptığı şeyi yapmalı
/*cout<<"\nenter pos x and y to move:"<<endl;
cin>>player1[0];
cin>>player1[1];
x=player1[0];
y=player1[1];
::player1[0]=x;
::player1[1]=y; */
//makeMove(ans, arr,player1);
ans1 = getAdjacent(::arr, ::player1[0], ::player1[1]);

cout<<"adjacent cells of player1: ";
for (int i = 0; i < ans1.size(); i++) 
        {
          cout << ans1[i] << " ";
        }
cout<<endl;

//for player1(); gibi bir fonksiyon içinde player ai turları olabilir ona göre her fonskiyonu çağırırsın
checkWinner1();
atPos(player1);
checkWinner1();
takePos1();
checkWinner1();
dellCell();

//for player2
ans2 = getAdjacent(::arr, ::player2[0], ::player2[1]);
cout<<"adjacent cells of player2: ";
for (int i = 0; i < ans2.size(); i++) 
        {
          cout << ans2[i] << " ";
        }
cout<<endl;

checkWinner2();
atPos(player2);
checkWinner2();
takePos2();
checkWinner2();
dellCell();
}
}

