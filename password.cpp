#include <iostream>
#include <string>
using namespace std;

// delcaring functions
void intro(string& password); // intro function
void checks(bool& uppercase, bool& lowercase, bool& number, string& password); // checking function
void errors(string& password, bool& correctLength, bool& number, bool& uppercase, bool& lowercase, bool& validPass); // errors function
void validation(string& password, string& password2, bool& validPass); // validation function

int main() {
    // declaring variables
    string password, password2;
    bool number, uppercase, lowercase;
    bool validPass = 0;
    bool correctLength = 0;
    
    // do while loop
    do {
    intro(password);
    
    checks(uppercase, lowercase, number, password);
    
    errors(password, correctLength, number, uppercase, lowercase, validPass);
    
    } while (!validPass);
    
    validation(password, password2, validPass);
    
    };
    
// defining functions
void intro(string& password) { // intro function
        cout << "-----------------------------------------------------\n";
    cout << "Please enter a password. The password must contain:\n - at least 8 characters\n - at least one number\n - one uppercase letter\n - one lowercase letter.\n";
    cout << "-----------------------------------------------------\n";
    getline(cin, password);
    cout << "-----------------------------------------------------\n";
}

void checks(bool& uppercase, bool& lowercase, bool& number, string& password) { // checking function
    int i = 0;
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
}

void errors(string& password, bool& correctLength, bool& number, bool& uppercase, bool& lowercase, bool& validPass) { // error function
    if (password.length() >= 8) {
        correctLength = true;
    };
    if (uppercase == true &&lowercase == true && number == true && correctLength == true) {
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

void validation(string& password, string& password2, bool& validPass) { // validation function
    if (validPass) {
        cout << "Your password is valid! Please verify it by typing it again: ";
        getline(cin, password2);
        } while (password2!= password) {
            cout << "That's wrong, enter it again\n";
            getline(cin, password2);
        }
        cout << "-----------------------------------------------------\n";
        cout << "Password verified";
}
