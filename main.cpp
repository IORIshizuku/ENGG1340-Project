#include<iostream>
#include<string>
using namespace std;

void pick_random_event();

void processAction(string cmd)
{

    // interface 1
    // interface 2
    …
        //interface 3
…
    // interface 4
}

void round_result();

void end_game();

// GRACE HERE
for (int round = 0; round < 50; round++)
{
    for (int curCountry : countryList)
    {
        pick_random_event();

        // let player make decision;
        while (getline(cin, cmd))
        {
            if (cmd == “end”)
            {
                // may need to print sth
                break;
            }
            processAction(cmd);
        }

        round_result();
    }
}
end_game();
// testing for github update
