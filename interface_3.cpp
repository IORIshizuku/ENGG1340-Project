#include "all_interface.h"
using namespace std;

void run_interface_3(vector<string> &cmd){
    gameScreen.divide(1, 1, 120, 5, "resource-bar");
    gameScreen.divide(1, 1, 39, 5, "interface-name");
    gameScreen.divide(39, 1, 60, 5, "resource-1");
    gameScreen.divide(60, 1, 80, 5, "resource-2");
    gameScreen.divide(80, 1, 100, 5, "resource-3");
    gameScreen.divide(100, 1, 120, 5, "resource-4");
    gameScreen.divide(1, 5, 40, 29, "manual");
    

    gameScreen.drawAll("interface-name", "center", {"Interface 3: External Action"});
    gameScreen.drawAll("resource-1", "center", {"All army: xxxx"});
    gameScreen.drawAll("resource-2", "center", {"All Tank: xxxx"});
    gameScreen.drawAll("resource-3", "center", {"Metal: xxxx"});
    gameScreen.drawAll("resource-4", "center", {"Population: xxxx"});
    gameScreen.drawLineStart("manual");
    gameScreen.drawLine("center", "user manual");
    gameScreen.drawLine("center", "sdfsdfsdf");
    gameScreen.drawLineStop();

    gameScreen.divide(39, 5, 120, 29, "game-content");
    gameScreen.divide(39, 5, 120, 7, "world-map-title");
    gameScreen.drawAll("world-map-title", "center", {"WORLD MAP"});
    class i3Map : public Military_Resouces{
        public:
            string owner = "nobody";
    } wldMap[4][4];
    map<string, pair<string, string>> colorCode = {
        {"Player", {"\033[30m", "\033[46m"}}, 
        {"PC1", {"\033[30m", "\033[48;2;204;85;0m"}}, 
        {"PC2", {"\033[30m", "\033[48;2;218;112;214m"}}, 
        {"PC3", {"\033[30m", "\033[43m"}},
        {"nobody", {"\033[37m", "\033[48;5;243m"}}
    };
    
    for(int i = 0; i < 4; i++) for(int j = 0; j < 4; j++) wldMap[i][j].owner = "nobody";
    wldMap[0][0].owner = "Player", wldMap[3][0].owner = "PC1", wldMap[0][3].owner = "PC2", wldMap[3][3].owner = "PC3" ;

    //loop through each land in the world map
    for(int y = 8, i = 0; i < 4; y += 5, i++){
        for(int x = 40, j = 0; j < 4; x += 20, j++){
            string land_id =  "land-"; land_id += (char)(i + '0'); land_id += ","; land_id += (char)(j + '0');
            string CurName = "world-map-" + land_id;
            string landOwner = wldMap[j][i].owner;
            //land screen drawing setting
            gameScreen.divide(x, y, x + 19, y + 4, CurName);
            gameScreen.drawLineStart(CurName);
            gameScreen.drawLine("center", land_id + " " + landOwner);
            gameScreen.drawLine("left", "YourSolider:00000");
            gameScreen.drawLine("left", "Your Tank : 00000");
            gameScreen.drawLineStop();
            //land color setting
            gameScreen.setWordColor(x, y, x + 19, y + 4, colorCode[landOwner].first);
            gameScreen.setBackgroundColor(x, y, x + 19, y + 4, colorCode[landOwner].second);
        }
    }


    gameScreen.print();
}



// extern setting maplist[16], playerland;

/*string eventl[20];
string input, yon;
int eventlist_content()
{
    eventl[0] = "Help from other country"; // increase diplomaticval
    eventl[1] = "Nothing happen";
    eventl[2] = "Wave of unemployment"; // farm, factory decrease
    eventl[3] = "Nothing happen";
    eventl[4] = "Food crisis"; // farm decrease
    eventl[5] = "Nothing happen";
    eventl[6] = "Defence Secretary of your city turn coat!"; // millitaryval decrease
    eventl[7] = "Nothing happen";
    eventl[8] = "Strike";                                                     // manpower decrease in one round
    eventl[9] = "Oil refinery collapse";                                      // oil refinery -1
    eventl[10] = "Your country send a wreck hook to quake-afflicted country"; // increase diplomaticval
    eventl[11] = "Exchange Fund increased by 10%";                            // econ increase
    eventl[12] = "Nothing happen";
    eventl[13] = "Econoy cooperation with other country";          // increase diplomaticval
    eventl[14] = "Military Laboratory has developed a new weapon"; // milliteryval increase
    eventl[15] = "Nothing happen";
    eventl[16] = "Nothing happen";
    eventl[17] = "A new fertilizer has developed in your country";    // farm factory increase
    eventl[18] = "Pandemic";                                          // manpower, born rate decrease
    eventl[19] = "Recruiting office in your country draft more army"; // milliteryval increase
    return 0;
}
int event()
{
    int randomevent = rand() % 20;
    cout << eventl[randomevent] << endl;
    if (randomevent == 0)
    {
        int eventpick = rand() % 3;
        if (eventpick == 0)
        {
            maplist[0].allianceval += 50;
        }
        if (eventpick == 1)
        {
            maplist[3].allianceval += 50;
        }
        if (eventpick == 2)
        {
            maplist[15].allianceval += 50;
        }
    }
    if (randomevent == 2)
    {
        agriculture -= 200;
        economy -= 300;
    }
    if (randomevent == 4)
    {
        agriculture -= 700;
    }
    if (randomevent == 6)
    {
        millitaryval -= 1000;
    }
    if (randomevent == 8)
    {
        manpower -= 100000;
    }
    if (randomevent == 9)
    {
        oil_refinery -= 1;
    }
    if (randomevent == 10)
    {
        int eventpick = rand() % 3;
        if (eventpick == 0)
        {
            maplist[0].allianceval += 100;
        }
        if (eventpick == 1)
        {
            maplist[3].allianceval += 100;
        }
        if (eventpick == 2)
        {
            maplist[15].allianceval += 100;
        }
    }
    if (randomevent == 11)
    {
        economy *= 1.1;
    }
    if (randomevent == 13)
    {
        int eventpick = rand() % 3;
        if (eventpick == 0)
        {
            maplist[0].allianceval += 80;
        }
        if (eventpick == 1)
        {
            maplist[3].allianceval += 80;
        }
        if (eventpick == 2)
        {
            maplist[15].allianceval += 80;
        }
    }
    if (randomevent == 14)
    {
        millitaryval *= 1.2;
    }
    if (randomevent == 17)
    {
        agriculture *= 1.3;
        economy *= 1.1;
    }
    if (randomevent == 18)
    {
        manpower *= 0.5;
    }
    if (randomevent == 19)
    {
        millitaryval *= 1.2;
        manpower *= 0.9;
    }
    return 0;
}

struct map
{
    int num;           // num of the land (1-15)
    int requiredpower; // the required mill power
    int allianceval;   // gaining
};

map maplist[16] = {{1, 50000, 0}, {2, 50000, 0}, {3, 50000, 0}, {4, 50000, 0}, {5, 50000, 0}, {6, 50000, 0}, {7, 50000, 0}, {8, 50000, 0}, {9, 50000, 0}, {10, 50000, 0}, {11, 50000, 0}, {12, 50000, 0}, {13, 50000, 0}, {14, 50000, 0}, {15, 50000, 0}, {16, 50000, 0}};

bool check_if_occupied()
{
    return true;
}
int printmap()
{
    // is the player has 4 options on the initial land ? then how to give the num of the land if the map will change ?
    // and we didnot discuss on the initial value of the 4 option right?
    int k = 0;
    cout << "+--------------------------------------------------------------------------------------------+" << endl;
    cout << "+----------------------------------------------MAP-------------------------------------------+" << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (k < 10)
            {
                cout << "    " << maplist[k].num;
            }
            else
            {
                cout << "   " << maplist[k].num;
            }
            k++;
        }
        cout << endl;
    }
    cout << "+--------------------------------------------------------------------------------------------+" << endl;
    return 0;
}

int alliance(int d)
{
    cout << "You have a close relationship with country" << maplist[d].num << endl;
    cout << "Would you want to alliance with her ? (Y/N) (No need spacing): ";
    cin >> yon;
    while (yon != "Y" || yon != "N")
    {
        cout << "Invalid command." << endl;
        cout << "You have a close relationship with country" << maplist[d].num << endl;
        cout << "Would you want to alliance with her ? (Y/N) (No need spacing): ";
        cin >> yon;
    }
    if (yon == "Y")
    {
        int randnum = rand() % 3;
        if (randnum != 0)
        {
            cout << "success" << endl;
            if (d == 0)
            {
                // benefits and change sth in the map struct
                // show the alliance in interface 4
            }
            if (d == 15)
            {
                // benefits ...
                // show the alliance in interface 4
            }
            if (d == 3)
            {
                // benefits
                // show the alliance in interface 4
            }
        }
        else
        {
            cout << "fail" << endl;
        }
    }
}

int instruction()
{
    cout << "+--------------------------------------------------------------------------------------------+" << endl;
    cout << "In this interface you can choose to or not to attack the unoccupied land or other countries." << endl;
    cout << "REMINDER! YOU WILL NOT KNOW THE REQUIRED MILLITARY VALUES THAT MAKE YOU OCCUPIED SUCCESSFULLY" << endl;
    cout << "If you don't have enough millitary value, you will lose ALL value you try to attack!" << endl;
    cout << "THINK WISELY BEFORE ATTACK" << endl;
    cout << "+--------------------------------------------------------------------------------------------+" << endl;
    return 0;
}

void run_interface_3(vector<string> &cmd)
{
    cout << "interface 3" << endl; // testing
    instruction();
    cout << "Please enter show / attack / peace (no need spacing):";
    cin >> input;
    while (input != "show" || input != "attack" || input != "peace")
    {
        cout << "Invalid command." << endl;
        cout << "Please enter show / attack / peace (no need spacing):";
        cin >> input;
    }
    if (input == "show")
    {
        printmap();
    }
    else if (input == "attack")
    {
        int attnum = 0;
        printmap();
        cout << "Enter the number of the land you would like to attack: ";
        cin >> attnum;
        while (attnum < 2 || attnum > 16 || check_if_occupied() == true)
        {
            cout << "Enter the number of the land you would like to attack: ";
            cin >> attnum;
        }
        if (millitaryval >= requiredpower)
        {
            // get the land
            millitaryval /= 2;
        }
        else
        {
            int chosenum;
            cout << "Your millitary level is lower then the land you want to attack" << endl;
            cout << "You can enter a number (1-3) to get a stragegy to see if you can win in the war." << endl;
            cout << " Wrong entering see as fail the war." << endl;
            cout << "Please enter (1-3) ";
            cin >> chosenum;
            int ran = rand() % 4 + 1;
            if (chosenum == ran)
            {
                cout << "You win the war tragicly." << endl;
                // get the land
                millitaryval /= 5;
            }
            else
            {
                cout << "You lose in the war. " << endl;
                millitaryval *= 0.1;
                economy *= 0.7;
                agriculture *= 0.7;
            }
        }
    }
    else if (input == "peace")
    {
        maplist[0].allianceval += rand() % 51;
        maplist[3].allianceval += rand() % 51;
        maplist[15].allianceval += rand() % 51;
        cout << "You have earned diplomatic values. " << endl;
        cout << "The new values are " << maplist[0].num << " :" << maplist[0].allianceval << " " << maplist[3].num << " :" << maplist[3].allianceval << " " << maplist[15].num << " :" << maplist[15].allianceval << " " << maplist[0].allianceval << endl;
        event();
        if (maplist[0].allianceval > 800)
        {
            alliance(0);
        }
        if (maplist[15].allianceval > 1000)
        {
            alliance(15);
        }
        if (maplist[3].allianceval > 2000)
        {
            alliance(3);
        }
    }
    else
    {
        return;
    }
}
*/