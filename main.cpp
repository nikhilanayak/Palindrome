#include <iostream>
#include <cstring>

int main()
{
    char input[80]; // original input
    memset(input, 0, 80);
    std::cout << "Input a string: ";
    std::cin.get(input, 80, '\n'); // read from stdin
    char clean[80];
    memset(clean, 0, 80);

    int i = 0;
    int j = 0;

    while (i < 80)
    {
        if (isalpha(input[i])) // if input[i] is a-z or A-Z
        {
            if(input[i] >= 97){ // make everything caps, so A == a
                input[i] -= 32;
            }
            clean[j] = input[i]; // copy from input into clean
            j++; // only increment j if a new character is added
        }
        i++;
    }

    clean[j] = '\0'; // add null to end

    char reverse[80];
    memset(reverse, 0, 80);

    i = 0;
    while(i < j){
        reverse[j-1-i] = clean[i]; // reverse clean and add to reverse
        i++;
    }
    reverse[j] = '\0'; // add null to end


    if(memcmp(clean, reverse, j) == 0){ // if reverse == clean, it's a palindrome
        std::cout << "Palindrome\n";
    }
    else{ // otherwise, it's not
        std::cout << "Not a Palindrome\n";
    }

    return 0;
}
