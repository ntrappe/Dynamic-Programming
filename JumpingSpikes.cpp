#include <stdio.h>
#include <stdlib.h>
#include <iostream>

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

int main () {
  int arrSz = 12;
  bool arr[] = {true, false, true, true, true, false, true, true, false, true, true};
  bool arr2[] = {true, false, false, true, true, false, true, true, false, true, true};
  cout << "TEST: speed 4 " << endl << stopSafely (arr, arrSz, 4, 0) << endl;
  cout << "TEST: speed 3 " << endl << stopSafely (arr, arrSz, 3, 0);
  cout << "TEST: speed 2 " << endl << stopSafely (arr, arrSz, 2, 0);
  cout << "TEST: speed 1 " << endl << stopSafely (arr2, arrSz, 2, 0); // should fail
  return EXIT_SUCCESS;
}
