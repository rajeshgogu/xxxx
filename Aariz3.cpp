#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

class User {
public:
    string firstName;
    string lastName;
    int age;
    string gender;

    User() {}

    User(string firstName, string lastName, int age, string gender) {
        this->firstName = firstName;
        this->lastName = lastName;
        this->age = age;
        this->gender = gender;
    }
};

map<string, User> mapUserName;   // Map to store users by username
map<string, set<string>> Friends;   // Map to store friendships

// Function to add a user
void addUser(string userName, const User& user) {
    if (mapUserName.find(userName) == mapUserName.end()) {
        mapUserName[userName] = user;
        cout << "User added successfully.\n";
    } else {
        cout << "UserName already taken. Please choose a different UserName.\n";
    }
}

// Function to make two users friends
void makeThemFriend(string userName1, string userName2) {
    if (mapUserName.find(userName1) != mapUserName.end() && mapUserName.find(userName2) != mapUserName.end()) {
        Friends[userName1].insert(userName2);
        Friends[userName2].insert(userName1);
        cout << "Friendship established between " << userName1 << " and " << userName2 << ".\n";
    } else {
        cout << "One or both usernames do not exist.\n";
    }
}

// Function to display all users
void displayAllUsers() {
    if (mapUserName.empty()) {
        cout << "No users found.\n";
    } else {
        cout << "List of all users:\n";
        for (const auto& user : mapUserName) {
            cout << "UserName: " << user.first << ", Name: " << user.second.firstName << " " << user.second.lastName << "\n";
        }
    }
}

// Function to display all friendships
void displayAllFriendships() {
    if (Friends.empty()) {
        cout << "No friendships found.\n";
    } else {
        cout << "List of all friendships:\n";
        for (const auto& pair : Friends) {
            cout << pair.first << " is friends with: ";
            for (const auto& friendName : pair.second) {
                cout << friendName << " ";
            }
            cout << "\n";
        }
    }
}

int main() {
    int choice;
    while (true) {
        cout << "\n1. Add User\n2. Make Friends\n3. Display All Users\n4. Display All Friendships\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                string userName, firstName, lastName, gender;
                int age;
                cout << "Enter UserName: ";
                cin >> userName;
                cout << "Enter First Name: ";
                cin >> firstName;
                cout << "Enter Last Name: ";
                cin >> lastName;
                cout << "Enter Age: ";
                cin >> age;
                cout << "Enter Gender: ";
                cin >> gender;
                User newUser(firstName, lastName, age, gender);
                addUser(userName, newUser);
                break;
            }
            case 2: {
                string userName1, userName2;
                cout << "Enter First UserName: ";
                cin >> userName1;
                cout << "Enter Second UserName: ";
                cin >> userName2;
                makeThemFriend(userName1, userName2);
                break;
}
            case 3:
                displayAllUsers();
                break;
            case 4:
                displayAllFriendships();
                break;
            case 5:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}

