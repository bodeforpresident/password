// Example program
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string password;
    int i = 0;
    bool number, uppercase, lowercase, validPass;
    bool correctLength = 0;
    cout << "-----------------------------------------------------\n";
    cout << "Please enter a password. The password must contain:\n - at least 8 characters\n - at least one number\n - one uppercase letter\n - one lowercase letter.\n";
    cout << "-----------------------------------------------------\n";
    getline(cin, password);
    
    do {
        if (isupper(password[i])) {
            uppercase = true;
        } else if (islower(password[i])) {
            lowercase = true;
        } else if (isdigit(password[i])) {
            number = true;
        }
        
        i++;
    } while (i < password.length());
    
    if (password.length() >= 8) {
        correctLength = true;
    };
    if (uppercase == true && lowercase == true && number == true && correctLength == true) {
        validPass = true;
    };
    if (!uppercase) {
        cout << "You need an uppercase letter\n";
    }
    if (!lowercase) {
        cout << "You need a lowercase letter\n";
    }
    if (!number) {
        cout << "You need a number\n";
    }
    if (!correctLength) {
        cout << "You need 8 letters\n";
    };
}
