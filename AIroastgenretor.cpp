#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    string name;

    // Taking user input
    cout << "Enter your name: ";
    getline(cin, name);

    // Roast templates
    vector<string> roasts = {
        "{name}'s code runs so slowly that even dial-up internet feels fast.",
        "If laziness had a brand ambassador, it would be {name}.",
        "{name} doesn't debug code — they negotiate with bugs.",
        "{name} writes code so confusing that even the compiler gets emotional.",
        "If procrastination were an Olympic sport, {name} would win gold.",
        "{name}'s typing speed is faster than their thinking speed.",
        "{name} opens Stack Overflow before even reading the question.",
        "{name}'s code has more errors than a broken calculator.",
        "Even Google gets confused after seeing {name}'s code.",
        "{name} treats deadlines like suggestions."
    };

    // Random number generator
    srand(time(0));

    int randomIndex = rand() % roasts.size();

    string roast = roasts[randomIndex];

    // Replace {name} with actual name
    int pos = roast.find("{name}");

    while(pos != string::npos)
    {
        roast.replace(pos, 6, name);
        pos = roast.find("{name}");
    }

    // Display roast
    cout << "\nAI Roast Generator\n";
    cout << roast << endl;

    return 0;
}
