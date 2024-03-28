
#include "functions.h" //reference the header file 

int main() 
{
  string option = ""; //the option local to int main()
  string color = "\x1b[" + to_string(32) + ";1m";
  string reset = "\x1b[0m";
  string color1 = RED;
  string color2 = YELLOW;
  string color3 = GREEN;
  string color4 = BLUE;
  string color5 = MAGENTA;
  string color6 = CYAN;
  string color7 = BOLDREDTEXT;
  
  do
  {
    showMenu(color1, color2, color3, color4, color5, color6, color7); //call a menu void function here
    cout << "\nPlease enter an option: ";
      cout << color; //change text to green 
  
    option = validateString(option); 
    cout << reset; //reset back to standard
    handleOption(option); //call handleOption and pass the user option as an argument


  }while(option != "e" && option != "E");  
  cout << "\nThank you, Goodbye!" << endl;
  return 0; 
}