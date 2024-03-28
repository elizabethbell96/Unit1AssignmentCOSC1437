
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
// put libraries here
#include "Input_Validation_Extended.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// Define ANSI escape codes for colors
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLDREDTEXT "\033[1;31m"

// PROTOPTYPES
void handleOption(string);
void showMenu(string, string, string, string, string, string, string);
void showsubMenu();
string subOption();
void printMulti(int, char);
string evenOddChecker(int);
int numberReverse(int);
void getMinMax(double, double, double);

// FUNCTION DEFINITIONS
void handleOption(string userOption) {
  string color1 = RED;
  string color2 = YELLOW;
  string color3 = GREEN;
  string color4 = BLUE;
  string color5 = MAGENTA;
  string color6 = CYAN;
  string color7 = BOLDREDTEXT;
  string colorReset = RESET;
  
  // for velocity
  double speed = 0.0;
  string speedUnits = "";
  double time = 0.0;
  string timeUnits = "";
  // for acceleration
  double velocity = 0.0;
  string velocityUnits = "";
  double time2 = 0.0;
  string time2Units = "";
  // for motion
  // option 1
  double initialVelocity = 0.0;
  string initialVelocityUnits = "";
  double accelerationM = 0.0;
  string accelerationUnits = "";
  double time3 = 0.0;
  string time3Units = "";
  // option 2
  double initialSpeed = 0.0;
  string initialSpeedUnits = "";
  double initialVelocity2 = 0.0;
  string initialVelocity2Units = "";
  double time4 = 0.0;
  string time4Units = "";
  double acceleration2 = 0.0;
  string acceleration2Units = "";
  // option 3
  double initialVelocity3 = 0.0;
  double acceleration3 = 0.0;
  double speed2 = 0.0;
  double initialspeed2 = 0.0;
  // option 4
  double velocity2 = 0.0;
  double initialvelocity2 = 0.0;
  // for Newtons 2nd Law
  double mass = 0.0;
  string massUnits = "";
  double acceleration4 = 0.0;
  string acceleration4Units = "";
  // for weight on earth
  double mass2 = 0.0;
  string weightUnits = "";
  double gravity = 9.81;
  string object = "";
  // for momentum
  double mass3 = 0.0;
  string mass3Units = "";
  double velocity3 = 0.0;
  string velocity3Units = "";

  // VELOCITY CALCULATOR
  if (userOption == "V" || userOption == "v") {
    cout << "\nTime to calculate Velocity!\n";
    cout << "\nPlease enter your change in speed (ds): ";
    speed = validateDouble(speed); // cin >> speed;
    cout << "\nPlease enter your unit of speed (mi,km,m ect.): ";
    speedUnits = validateString(speedUnits);
    cout << "\nPlease enter your change in time (dt) ";
    time = validateDouble(time); // cin >> time;
    cout << "\nPlease enter your unit of time (hr,min,sec ect.): ";
    timeUnits = validateString(timeUnits);
    double velocity = (speed / time);
    cout << fixed << setprecision(4);
    cout << "\n The velocity is: " << speed << "/" << time << " = " << velocity
         << " " << speedUnits << "/" << timeUnits << endl;

    // ACCELERATION CALCULATOR
  } else if (userOption == "A" || userOption == "a") {
    cout << "\nTime to calculate acceleration!" << endl;
    cout << "\n Please endter your change in velocity (dv): " << endl;
    velocity = validateDouble(velocity); // cin >> num;
    cout << "\nPlease enter your distance unit of velocity (mi,m,km ect.): ";
    velocityUnits = validateString(velocityUnits);
    cout << "\nPlease enter your change in time (dt): " << endl;
    time2 = validateDouble(time2);
    cout << "\nPlease enter your unit of time (hr,min,sec ect.): ";
    time2Units = validateString(time2Units);

    double acceleration = (velocity / time2);
    cout << fixed << setprecision(4);
    cout << "\nThe acceleration is: " << velocity << "/" << time2 << "="
         << acceleration << " " << velocityUnits << "/" << time2Units << "^2"
         << endl;
    // MOTION CALCULATIONS
  } else if (userOption == "M" || userOption == "m") {
    cout << "\nTime to calculate Motion! " << endl;
    showsubMenu();
    cout << "Please choose which method you would like to use to perform "
            "calculations. "
         << endl;

    string subOption;

    do {
      cout << "Please enter your choice: ";
      subOption = validateString(subOption);

      if (subOption == "1") {
        cout << "\nYou have chosen to use the Ma = solve for v formula" << endl;
        cout << "\nPlease enter your initial velocity: ";
        initialVelocity = validateDouble(initialVelocity);
        cout << "\nPlease enter your units of initial velocity: ";
        initialVelocityUnits = validateString(initialVelocityUnits);
        cout << "\nPlease enter your acceleration: ";
        accelerationM = validateDouble(accelerationM);
        cout << "\nPlease enter your units of acceleration: ";
        accelerationUnits = validateString(accelerationUnits);
        cout << "\nPlease enter your time: ";
        time3 = validateDouble(time3);
        cout << "\nPlease enter your units of time: ";
        time3Units = validateString(time3Units);

        double motion1 = (initialVelocity + (accelerationM * time3));
        cout << fixed << setprecision(4);
        cout << "\nThe motion is" << initialVelocity << "+" << accelerationM
             << "*" << time3 << "=" << motion1 << endl;
      }

      else if (subOption == "2") {
        cout << "\nYou have chosen to use the Ms = solve for s formula" << endl;
        cout << "\nPlease enter your initial speed " << endl;
        initialSpeed = validateDouble(initialSpeed);
        cout << "\nPlease enter your initial velocity " << endl;
        initialVelocity2 = validateDouble(initialVelocity2);
        cout << "Please eneter your acceleration " << endl;
        acceleration2 = validateDouble(acceleration2);
        cout << "\n Please enter your time " << endl;
        time4 = validateDouble(time4);

        double motion2 = (initialSpeed + (initialVelocity2 * time4) +
                          (acceleration2 * time4 * time4)) /
                         2;
        cout << fixed << setprecision(4);

        cout << "\nThe motion is: " << initialSpeed << "+" << initialVelocity2
             << "*" << time4 << "+ 1/2(" << acceleration2 << "*" << time4
             << ")^2"
             << "=" << motion2 << " " << initialSpeedUnits << "/" << timeUnits;

      } else if (subOption == "3") {
        cout << "\nYou have chosen to use the Mv2 = solve for v^2 formula"
             << endl;
        cout << "\nPlease enter your initial velocity " << endl;
        initialVelocity3 = validateDouble(initialVelocity3);
        cout << "\nPlease enter your acceleration " << endl;
        acceleration3 = validateDouble(acceleration3);
        cout << "\nPlease enter your speed " << endl;
        speed2 = validateDouble(speed2);
        cout << "\nPlease enter your initial speed " << endl;
        initialspeed2 = validateDouble(initialspeed2);

        double motion3 = (initialVelocity3 * initialVelocity3) +
                         (2 * acceleration3 * (speed2 - initialSpeed));
        cout << fixed << setprecision(4);
        cout << "\nThe motion is: " << initialVelocity3 << "^2 + 2*"
             << acceleration3 << " *(" << speed2 << "-" << initialspeed2
             << ") = " << motion3 << endl;
      } else if (subOption == "4") {
        cout << "\nYou have chosen to use the Mv = solve for v_bar" << endl;
        cout << "\nPlease enter your velocity " << endl;
        velocity2 = validateDouble(velocity2);
        cout << "\nPlease enter your initial velocity " << endl;
        initialvelocity2 = validateDouble(initialvelocity2);
        double motion4 = (velocity2 - initialvelocity2);
        cout << fixed << setprecision(4);
        cout << "\nThe motion is: "
             << "1/2(" << velocity2 << "-" << initialvelocity2
             << ") =" << motion4 << endl;
      }

      else if (subOption == "5" || subOption == "5") {
        cout << "Returning to main menu\n";
        break;

      } else {

        cout << "Invalid submenu option. Please try again.\n";
      }
    } while (true);
  }

  // NEWTONS SECOND LAW CALCULATOR
  else if (userOption == "N" || userOption == "d\n") {
    cout << "\nTime to calculate Newtons 2nd Law (F = ma)!" << endl;
    cout << "Please enter your mass value " << endl;
    mass = validateDouble(mass);
    cout << "\nPlease enter your peferred unit of mass " << endl;
    massUnits = validateString(massUnits);
    cout << "\nPlease enter your acceleration value " << endl;
    acceleration4 = validateDouble(acceleration4);
    cout << "\nPlease enter your peferred unit of acceleration " << endl;
    acceleration4Units = validateString(acceleration4Units);
    // final output
    double newtons = (mass * acceleration4);
    cout << fixed << setprecision(4);
    cout << "\nThe force is: " << mass << "*" << acceleration4 << "=" << newtons
         << " " << massUnits << "/" << acceleration4Units << endl;

    // WEIGHT ON EARTH CALCULATOR

  } else if (userOption == "W" || userOption == "w") {
    cout << "\nTime to calculate Weight on Earth (using a= 9.81m/s^2)!" << endl;
    cout << "\nPlease enter your mass value " << endl;
    mass2 = validateDouble(mass2);
    cout << "\nPlease enter your unit of weight at the output (lbs, ounces "
            "ect.) "
         << endl;
    weightUnits = validateString(weightUnits);
    cout << "\n Please enter the name of the object you are calculating the "
            "weight of "
         << endl;
    string object = validateString(object);
    double weight = (mass2 * gravity);
    cout << fixed << setprecision(4);
    cout << "\nThe weight is: " << mass2 << "*" << gravity << " = " << weight
         << weightUnits << "," << object << endl;

    // MOMENTUM CALCULATOR
  } else if (userOption == "P" || userOption == "p") {
    cout << "\nTime to calculate Momentum (using P = mv)!" << endl;
    cout << "\nPlease enter your mass value " << endl;
    mass3 = validateDouble(mass3);
    cout << "\nPlease enter your unit of mass " << endl;
    mass3Units = validateString(mass3Units);
    cout << "\nPlease enter your velocity value " << endl;
    velocity3 = validateDouble(velocity3);
    cout << "\nPlease enter your unit of velocity (m/s, km/hr ect.) " << endl;
    velocity3Units = validateString(velocity3Units);
    double momentum = (mass3 * velocity3);
    cout << fixed << setprecision(4);
    cout << "\nThe momentum is: " << mass3 << "*" << velocity3 << " = "
         << momentum << " " << mass3Units << " " << velocity3Units << endl;

  } else if (userOption == "E" || userOption == "e") {
    char answer = '\0';
    cout << "\nPlease enter another charachter to exit the program ";
    answer = validateChar(answer);

    if (answer == 'A') {
      cout << "\nExiting the program. Goodbye!\n";
    }
  }
}

void showMenu(string color1, string color2, string color3, string color4, string color5, string color6, string color7) {
  cout << "\nMENU" << endl;
  cout << color1 << "V: Calculate Velocity" << RESET << endl;
  cout << color2 << "A: Calculate Acceleration" << RESET << endl;
  cout << color3 << "M: Caclulate Motion" << RESET << endl;
  cout << color4 <<"N: Newtons 2nd Law" << RESET << endl;
  cout << color5 << "W: Calclate Weight on Earth" << RESET << endl;
  cout << color6 << "P: Calculate Momentum" << RESET << endl;
  cout << color7 << "E: Exit" << RESET << endl;
  cout << color7 << "X: clear the screen" << RESET << endl;
}

void showsubMenu() {
  cout << "\nMOTION CALCULATION MENU" << endl;
  cout << "1: Ma = solve for v" << endl;
  cout << "2: Ms = solve for s" << endl;
  cout << "3: Mv2 = solve for v^2" << endl;
  cout << "4: Mv = solve for v_bar" << endl;
  cout << "5: Exit" << endl;
}

#endif