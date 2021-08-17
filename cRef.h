#include <iostream>
#include <vector>

using namespace std;

vector <string> wSplit(string text);
string condense(vector <char> gas);


// Condenses a vector of strings to one string
string condense(vector <char> gas)
{
    string add = "";  // String for adding on to
    if (gas.size() <= 1)  // Outputs error in case of a short length
    {
        return "sizeError: Please input a vector with a size of 2 or greater";
    }
    
    for (int i = 0; i <= gas.size() - 1; i++)  //  Add chars to final string
    {
        add += gas[i];
    }
    
    return add;  // Return final string
}


// Returns a vector of strings based on the words seperated by spaces
vector <string> wSplit(string text)
{
    vector <string> final;      //  Return vector
    vector <char> condenser;    //  Condensing vector  
    
    for (int i = 0; i <= text.length() - 1; i++)  // Iterate through the text
    {
        if (text[i] == ' ')  //  Condense the condenser vector and clear it
        {                    //  if the character of the index is a space
            final.push_back(condense(condenser));
            condenser.clear();
        }
        
        else  // Push back the element of the text
        {
            condenser.push_back(text[i]);
        }
    }
    final.push_back(condense(condenser));  // Condense last item
    condenser.clear();  // Deallocate condenser
    return final;  // Return the final vector
}
