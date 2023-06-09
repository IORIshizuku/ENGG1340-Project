#include "all_interface.h"
#include "UI.h"
using namespace std;

UI i4 = UI();
vector<string> history;

void init_i4() // intialize interface 4 screen, no input, no output
{
    // i4.divide(1, 1, 120, 5, "resource-bar");
    i4.divide(1, 1, 20, 5, "interface-name"); // initialize interface 4 UI interface
    // i4.divide(40, 1, 60, 5, "resource-1");
    // i4.divide(60, 1, 80, 5, "resource-2");
    // i4.divide(80, 1, 100, 5, "resource-3");
    // i4.divide(100, 1, 120, 5, "resource-4");
    i4.divide(1, 5, 20, 29, "manual");
    i4.divide(20, 1, 120, 29, "game-content");
}

void run_interface_4(vector<string> &cmd) // runs interface 4 sub-functions, input command vactor<string> pass-by-reference, no output
{
    if (cmd[0] == "to" && cmd.size() == 2)
    {
        i4.print();
        return;
    }
    vector<string> content;                  // contains all result
    if (cmd[0] == "to" && cmd[2] == "admin") // below is debugging admin panel, can be accessed by to i4 admin, show all country resources
    {
        for (int i = 0; i < 4; i++)
        {
            content.push_back(countryList[i] + " resources");
            content.push_back(
                "food: " + to_string(player[i].food) + " fuel: " + to_string(player[i].fuel) + " metal: " + to_string(player[i].metal) + " citizen: " + to_string(player[i].citizen) + " soldier: " + to_string(player[i].soldier) + " tank: " + to_string(player[i].tank));
            for (int j = 0; j < 3; j++)
            {
                string bu = buildingList[j * 2];
                string tt = bu;
                tt += " Owned: " + to_string(player[i].qty_owned[bu]);
                tt += " build limit:" + to_string(player[i].build_lim[bu]);
                tt += " ";
                bu = buildingList[j * 2 + 1];
                tt += bu;
                tt += " Owned " + to_string(player[i].qty_owned[bu]);
                tt += " Lim " + to_string(player[i].build_lim[bu]);
                content.push_back(tt);
            }
        }
    }
    else
    {
        i4.print();
        return;
    }

    show_round_result(content);
}

void show_round_result(vector<string> content) // show interface 4 information, input vector<string> game content, no output
{
    i4.drawAll("interface-name", "center", {"Day : " + to_string(curGameDay), "Interface 4:", "Round Result"});

    i4.drawAll("game-content", "center", content);

    vector<string> i4_sidebarInfo = {"Try typing", "the following:", " ", "to i1", "to i2", "to i3", "to i4", "end", "quit", "help"};
    i4.drawAll("manual", "center", i4_sidebarInfo);
    i4.print();
}