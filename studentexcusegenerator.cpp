#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    string name;

    // Taking student name input
    cout << "Enter student name: ";
    getline(cin, name);

    // Check empty input
    if(name.empty())
    {
        cout << "Name cannot be empty!" << endl;
        return 0;
    }

    // Excuse templates
    vector<string> excuses = {
        "{name} couldn't complete the assignment because the laptop battery died unexpectedly.",
        "{name} tried finishing the homework, but the internet stopped working.",
        "{name} was ready to submit the assignment when the file mysteriously disappeared.",
        "{name} spent hours doing the assignment, but forgot to save the work.",
        "{name}'s computer suddenly restarted during the assignment.",
        "{name} was about to complete the homework when the Wi-Fi vanished.",
        "{name} accidentally deleted the assignment folder.",
        "{name}'s keyboard stopped working in the middle of typing.",
        "{name} couldn't focus because the system kept showing update notifications.",
        "{name} completed the assignment mentally, but not physically."
    };

    // Random number generator
    srand(time(0));

    int randomIndex = rand() % excuses.size();

    string excuse = excuses[randomIndex];

    // Replace {name} with actual student name
    int pos = excuse.find("{name}");

    while(pos != string::npos)
    {
        excuse.replace(pos, 6, name);
        pos = excuse.find("{name}");
    }

    // Display excuse
    cout << "\nStudent Excuse Generator\n";
    cout << excuse << endl;

    return 0;
}
