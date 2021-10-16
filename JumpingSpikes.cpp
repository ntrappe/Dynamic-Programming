#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <array>
#include <vector>

#define EMPTY_CELL -1

using namespace std;

/**
 * Jumping Spikes DP Problem
 * Taken from: https://www.freecodecamp.org/news/follow-these-steps-to-solve-any-dynamic-programming-interview-problem-cc98e508cd0e/
 * 
 * Statement: You're given a flat runway with spikes. The runway is a boolean
 * array where a clear spot is True and ones with spikes are False. We're given
 * a starting speed and can increase/decrease the speed by 1 or stay the same.
 * We want to stop anywhere along the runway where there are no spikes. You
 * stop when your speed is 0. If you land on a spike, the ball burts. Function should
 * output a boolean whether you can stop safely.
 */

bool stopSafely (bool runway[], int runwayLength, int initSpeed, int startIdx) {
  cout << "stopSafely() with speed " << initSpeed << " and idx " << startIdx << endl;
  /* Base Cases: */
  // invalid inputs speed must be non-negative
  if (initSpeed < 0 || startIdx < 0)
    return false;
  // if past end of runway, stop recursing
  if (startIdx >= runwayLength)
    return false;
  // hit a spike, done
  if (runway[startIdx] == false)
    return false;

  // goal
  if (initSpeed == 0)
    return true;

  /* Recursive Case: */
  if ((stopSafely (runway, runwayLength, initSpeed, startIdx + initSpeed)) ||
      (stopSafely (runway, runwayLength, initSpeed + 1, startIdx + initSpeed + 1)) ||
      (stopSafely (runway, runwayLength, initSpeed - 1, startIdx + initSpeed - 1))) {
    return true;
  }  
  return false;
}


/**
 * Knapsack Problem
 * Taken from: https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
 * Given weights and values of a number of items, put them in a knapsack.
 * Want to maximize the values but they're restricted by their weight. Weights
 * combined cannot exceed weight of knapsack. Return max subset of values.
 * 
 */
int knapsackBrute(int value[], int weight[], int arrLength, int W) {
  return EXIT_SUCCESS;
}

/**
 * We want to make change for N cents. Count the number of ways.
 */
int makeChange (int coins[], int change) {
  /* base case */
  if (change < 0) 
    return 0;

  if (change == 0)
    return 1;

  return makeChange (coins, change - 1) + makeChange (coins, change - 5);
}

/**
 * We want to make change for N cents. Count the number of ways.
 * More efficient by remembering previous state calculations
 */
int makeChangeMemo (int change, vector<int> * memo) {
  /* base case */
  if (change < 0) 
    return 0;

  if (change == 0)
    return 1;

  // for the current change we want to make, check if already
  // calculated the number of ways for that
  if (memo->at(change) == EMPTY_CELL)
    memo->at(change) = (makeChangeMemo (change - 1, memo)) + (makeChangeMemo (change - 5, memo));

  // cout << "memo [" << change << "] = (" << memo->at(change) << ")\n";
  return memo->at(change);
}

int main () {
  int arrSz = 12;
  bool arr[] = {true, false, true, true, true, false, true, true, false, true, true};
  bool arr2[] = {true, false, false, true, true, false, true, true, false, true, true};
  // cout << "TEST: speed 4 " << endl << stopSafely (arr, arrSz, 4, 0) << endl;
  // cout << "TEST: speed 3 " << endl << stopSafely (arr, arrSz, 3, 0);
  // cout << "TEST: speed 2 " << endl << stopSafely (arr, arrSz, 2, 0);
  // cout << "TEST: speed 1 " << endl << stopSafely (arr2, arrSz, 2, 0); // should fail

  int coins[] = {1};
  cout << "ways to makeChange for 3 cents " << makeChange (coins, 3) << endl;
  cout << "ways to makeChange for 4 cents " << makeChange (coins, 4) << endl;
  cout << "ways to makeChange for 5 cents " << makeChange (coins, 5) << endl;
  cout << "ways to makeChange for 6 cents " << makeChange (coins, 6) << endl;

  vector<int> * memo = new vector<int>();
  for (int i = 0; i < 30; i++) {
    memo->push_back (-1);
  }
  cout << "ways to makeChange for 3 cents " << makeChangeMemo (3, memo) << endl;
  cout << "ways to makeChange for 4 cents " << makeChangeMemo (4, memo) << endl;
  cout << "ways to makeChange for 5 cents " << makeChangeMemo (5, memo) << endl;
  cout << "ways to makeChange for 6 cents " << makeChangeMemo (6, memo) << endl;

  delete memo;

  return EXIT_SUCCESS;
}
