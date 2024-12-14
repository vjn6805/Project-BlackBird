#include <bits/stdc++.h>
using namespace std;

//Player inventory
class playerinventory {
    private:
        int healthpack = 1;
        int foodpack = 1;
        int battery = 0;

    public:
        void getitem();
        void updateitem();
        int decreaseitem();
};

// Player Details
class playerdetails {
    private:
        int stamina;
        int food;
        int torch_battery;

    public:
        int health;
        char playername[100];
        vector<int> player_pos = {1, 1};
        unordered_map<string, bool> track_riddles;
        playerdetails();
        void getinfo();
        void updateinfo();
        void updatedetails(playerinventory);
        void updatehealth();
};

int room=1;

// Creating a grid for game environment
// 1. Main room
vector<vector<string>> mainroom = {
    {" # ", " # ", " # ", " # ", " # ", " # ", " # ", " # ", " # ", " #"},
    {" # ", " P ", " . ", " . ", " # ", " # ", " # ", " L ", " # ", " #"},
    {" # ", " . ", " # ", " . ", " . ", " # ", " # ", " . ", " . ", " #"},
    {" # ", " . ", " # ", " # ", " . ", " . ", " . ", " . ", " . ", " #"},
    {" # ", " I ", " # ", " # ", " . ", " # ", " # ", " # ", " # ", " #"},
    {" # ", " . ", " . ", " . ", " . ", " . ", " . ", " # ", " . ", " #"},
    {" # ", " . ", " . ", " I ", " # ", " . ", " . ", " . ", " . ", " #"},
    {" # ", " # ", " . ", " # ", " # ", " # ", " . ", " # ", " L ", " #"},
    {" # ", " # ", " # ", " # ", " # ", " # ", " # ", " # ", " . ", " E"}
};

// Room 2
vector<vector<string>> room2 = {
    {" # ", " # ", " # ", " # ", " # ", " # ", " # ", " # ", " # "},
    {" # ", " P ", " . ", " . ", " # ", " # ", " . ", " . ", " # "},
    {" # ", " # ", " # ", " . ", " # ", " # ", " . ", " # ", " # "},
    {" # ", " # ", " . ", " . ", " # ", " # ", " . ", " . ", " # "},
    {" # ", " # ", " # ", " . ", " . ", " . ", " # ", " # ", " # "},
    {" # ", " . ", " . ", " # ", " . ", " . ", " # ", " . ", " # "},
    {" # ", " . ", " . ", " . ", " # ", " . ", " # ", " # ", " # "},
    {" E ", " . ", " # ", " . ", " . ", " . ", " . ", " . ", " . "},
    {" # ", " . ", " . ", " # ", " . ", " # ", " . ", " . ", " I "},
    {" # ", " # ", " # ", " # ", " # ", " # ", " # ", " # ", " # "}
};

// Room 3
vector<vector<string>> room3 = {
    {" # ", " # ", " # ", " # ", " # ", " # ", " # ", " # ", " # "},
    {" # ", " P ", " . ", " # ", " # ", " # ", " . ", " # ", " # "},
    {" # ", " # ", " . ", " . ", " # ", " # ", " . ", " . ", " # "},
    {" # ", " . ", " # ", " . ", " . ", " . ", " # ", " # ", " # "},
    {" # ", " . ", " . ", " . ", " # ", " . ", " # ", " . ", " # "},
    {" # ", " # ", " . ", " . ", " # ", " . ", " . ", " . ", " # "},
    {" # ", " . ", " . ", " # ", " . ", " # ", " # ", " . ", " # "},
    {" # ", " . ", " # ", " . ", " . ", " # ", " . ", " . ", " # "},
    {" I ", " . ", " . ", " . ", " . ", " # ", " . ", " . ", " E "},
    {" # ", " # ", " # ", " # ", " # ", " # ", " # ", " # ", " # "}
};

void endgame(int);

//Player inventory functions
void playerinventory::getitem() {
    cout << endl << "------------------------YOUR INVENTORY----------------------" << endl << endl;
    cout << "HealthPack = " << healthpack << endl;
    cout << "FoodPack = " << foodpack << endl;
    cout << "Batteries = " << battery << endl<<endl;
}

void playerinventory::updateitem() {
    cout << endl <<endl<< "----------------INVENTORY UPDATED SUCCESSFULLY---------------" << endl << endl;
    healthpack += 1;
    foodpack += 1;
    battery += 1;
}

int playerinventory::decreaseitem() {
    int choice;
    cout<<"Enter item to be used  (1-> HealthPack 2-> Battry 3-> FoodPack : )";
    cin>>choice;
    if(choice==1) {
        if(healthpack==0) {
            cout<<"-----------------NO HEALTH PACK AVAILABLE---------------"<<endl<<endl;
            return 0;
        }
        else {
            healthpack--;
            return 1;
        }

    }
    else if (choice==2) {
        if(battery==0){
            cout<<"-----------------NO BATTERY PACK AVAILABLE---------------"<<endl<<endl;
            return 0;
        }           
        else{
            battery--;
            return 2;
        }
    }
    else if(choice==3) {
        if(foodpack==0){
            cout<<"-----------------NO FOOD PACK AVAILABLE---------------"<<endl<<endl;
            return 0;
        }
        else{
            foodpack--;
            return 3;
        }
    }
    else{
        cout<<"You Enterted wrong choice!!";
        return decreaseitem();   
    }
    return 0;
}

//Players details
playerdetails::playerdetails() {
    health = 100;
    stamina = 50;
    food = 50;
    torch_battery = 90;
}

void playerdetails::getinfo() {
    cout << "Health = " << health << endl;
    cout << "Stamina = " << stamina << endl;
    cout << "Food = " << food << endl;
    cout << "Torch Battery = " << torch_battery << endl;
}

void playerdetails::updateinfo() {
    stamina -= 2;
    if (stamina <= 0) {
        cout<<"--------------PLAYER LOW ON STAMINA!! HEALTH DECREASING-------------";
        health -= 5;
    }
    food -= 2;
    torch_battery -= 5;
    if (torch_battery <= 0) {
        health -= 5;
        cout << endl << "-----------TORCH BATTERY LOW PLEASE REFUEL IT--------------" << endl;
    }

    if (health <= 0) {
        endgame(1);
    }
}

void playerdetails::updatedetails(playerinventory obj1) {
    int a=obj1.decreaseitem();
    if(a==1) {
        health=100;
        stamina=100;
    }
    else if(a==2) {
        torch_battery=100;
    }
    else if(a==3) {
        food=100;
    }
    else{
        cout<<endl<<endl<<"------------------------INVALID OUTPUT TRY AGAIN---------------------"<<endl<<endl;
    }
}

void playerdetails :: updatehealth() {
    health-=10;
    if(health<=0) {
        endgame(1);
    }
}

// Display the environment
void display_enviro(int num) {
    vector<vector<string>> grid;
    if (num == 1) {
        grid = mainroom;
    }
    else if (num == 2) {
        grid = room2;
    }
    else {
        grid = room3;
    }

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

bool askriddle(int room,playerdetails obj1,playerinventory obj2) {
    string ans;
    if(room==1) {
        
        cout<<"NINA : I speak without a mouth and hear without ears, I have no body, but I come alive with the wind.";
        cout<<"Answer : ";
        string temp="echo";
        cin>>ans;

        if(temp==ans) {
            return true;
        }
        else{
            askriddle(room,obj1,obj2);
        }
    }

    else if(room==2) {
        cout<<"NINA : The more of me you take, the more you leave behind.";
        cout<<"Answer : ";
        string temp="footsteps";
        cin>>ans;

        if(temp==ans) {
            return true;
        }
        else{
            askriddle(room,obj1,obj2);
        }
    }

    else if(room==3) {
        cout<<"NINA : I am always running, but I never move";
        cout<<"Answer : ";
        string temp="clock";
        cin>>ans;

        if(temp==ans) {
            return true;
        }
        else{
            askriddle(room,obj1,obj2);
        }
    }

    else if(room==4) {
        cout<<"NINA : I am not alive, but I can grow.I don’t have lungs, but I need air";
        cout<<"Answer : ";
        string temp="fire";
        cin>>ans;

        if(temp==ans) {
            return true;
        }
        else{
            askriddle(room,obj1,obj2);
        }
    }

    else if(room==5) {
        cout<<"NINA : I am light as a feather, yet the strongest person can't hold me for long.";
        cout<<"Answer : ";
        string temp="breath";
        cin>>ans;

        if(temp==ans) {
            return true;
        }
        else{
            askriddle(room,obj1,obj2);
        }
    }

    else if(room==6) {
        cout<<"NINA : The door is locked you must enter password to open"<<endl;
        cout<<"NINA : but remember with each incorect answer your health decreased"<<endl;
        cout<<"Answer : ";
        string temp="bce2f";
        cin>>ans;

        if(temp==ans) {
            return true;
        }
        else{
            obj1.updatehealth();
            askriddle(room,obj1,obj2);
        }
    }
    return false;
}

void endgame(int a) {
    if(a==1) {
        cout<<endl<<endl<<"NINA : YOU LOST YOUR HEALTH AND YOU DIED!!"<<endl;
        cout<<"NINA : For centuries no one had ever escaped this place"<<endl;
    }
    else{
        cout<<endl<<endl<<"Finally!! You made it, for centuries no one could escape the room but you are the chosen one!!";
        cout<<endl<<endl<<endl<<"---------------------THANK YOU FOR PLAYING---------------------------------"<<endl<<endl;
        exit(0);
    }
}

// Move the player
void moveplayer(char input, playerdetails &obj1, playerinventory &obj2, int a) {
    vector<vector<string>> grid;
    if(a==1) {
        grid=mainroom;
    }
    else if(a==2) {
         grid=room2;
    }
    else if(room==3) {
         grid=mainroom;

    }
    
    int x = obj1.player_pos[0];
    int y = obj1.player_pos[1];
    int newx = x, newy = y;

    if (input == 'w') {
        newx--;
    }
    else if (input == 'a') {
        newy--;
    }
    else if (input == 's') {
        newx++;
    }
    else if (input == 'd') {
        newy++;
    }
    else if (input == 'i') {
        obj2.getitem();
        cout<<endl<<endl<<"-----------------------Do you want to use your Inventory---------------------------"<<endl;
        cout<<"Enter 1->yes, 2->no  :  ";
        int choice;
        cin>>choice;
        if(choice==1) {
            obj1.updatedetails(obj2);
            cout<<endl<<endl<<"-------------------PLAYER INVENTORY UPDATED SUCCESFULLY--------------------------"<<endl<<endl;
        }        
    }
    else {
        cout <<endl<<endl<< "------------------INVALID INPUT TRY AGAIN-------------------"<<endl<< endl;
    }

    if (grid[newx][newy] == " # ") {
        cout <<endl<<endl<<"---------------------YOU HIT A WALL--------------------------"<<endl<< endl;
    }
    else if (grid[newx][newy] == " . ") {
        grid[x][y] = " . ";
        obj1.player_pos = {newx, newy};
        grid[newx][newy] = " P ";
    }
    else if (grid[newx][newy] == " I ") {
         obj2.updateitem();
    }
    else if (grid[newx][newy] == " L ") {
        bool ans;
        int move;
        if(obj1.player_pos[0]==1) {
            ans=askriddle(1,obj1,obj2);
            move=1;
        }
        else if(obj1.player_pos[0]==7) {
            ans=askriddle(2,obj1,obj2);
            move=2;
        }
        if (ans) {
            cout<<endl<<endl<<"--------------CORRECT ANSWER PROCCEDING TO NEXT ROOM------------------------"<<endl<< endl;
            if(move==1) {
                room=2;
                cout<<endl<<endl<<"---------------------ROOM 2----------------------------------"<<endl;
                cout<<endl<<endl<<"NINA : This is ROOM 2, find clues and escape from the room"<<endl<<endl;
                return; 
            }   
            else{
                room=3;
                cout<<endl<<endl<<"---------------------ROOM 3----------------------------------"<<endl;
                cout<<endl<<endl<<"NINA : So you are Finaly here, for the last time find clues and reach to the EXIT"<<endl<<endl;
                return; 
            }     
        }
        else {
            cout<<endl<<endl<<"--------------INCORRECT ANSWER!! DECREASING HEALTH!!----------------------"<<endl<< endl;
            obj1.health-=20;
        }
     }
    else if (grid[newx][newy] == " E ") {
        cout <<endl<<endl<<"-------------YOU HAVE REACHED YOUR FINAL DESTINATION-----------------------"<<endl<<endl;
        bool ans;
        if(room==1) {
            ans=askriddle(6,obj1,obj2);
            endgame(2);
            room=0;
        }
        else if(room==2) {
            ans=askriddle(5,obj1,obj2);
            room=1;
        }
        else if(room==3) {
            ans=askriddle(4,obj1,obj2);
            room=1;
        }

        if(ans) {
            cout<<endl<<endl<<"Congratitions you Escaped "<<endl<<endl;
            return;
        }
        else {
            cout<<endl<<endl<<"--------------INCORRECT ANSWER!! DECREASING HEALTH!!----------------------"<<endl<< endl;
            obj1.health-=20;
        }
    }
}

void greetinganddetails(playerdetails obj1) {
    cout<<endl<<endl<<"------------------------WELCOME TO PROJECT BLACKBIRD--------------------------------"<<endl<<endl;
    cout<<endl<<"Enter your name : ";
    cin>>obj1.playername;
    cout<<endl<<endl<<"Hello "<<obj1.playername<<", I am NINA your Host for this game I hope you are Excited"<<endl;
    cout<<"For years this place is abandoned and no one ever dare to come here"<<endl;
    cout<<"I dont know what got you here and you must escape from here before you die from food and hunger"<<endl;

    cout<<endl<<endl<<"---------------------------CONTROLS-------------------------------------"<<endl;
    cout<<"Press : d-> move forward, a->move backward, w->move upwards, s->move downwards"<<endl<<endl;

    cout<<endl<<"------------------------------RULES-------------------------------"<<endl;
    cout<<"1. You have limited resources but you can find them on the map"<<endl;
    cout<<"2. With each moves your Stamina decrease and if it becomes low your health starts decreasing"<<endl;
    cout<<"3. Your Torch Battery also decreases with time which will result in decrease in health"<<endl;
    cout<<"4. For each new map you have to asnwer riddles correctly to enter and escape that room"<<endl;

    cout<<endl<<"---------------JUST REALX AND ENJOY THE GAME-----------------------"<<endl<<endl;
}


void gameloop() {
    playerdetails player;
    playerinventory inventory;
    greetinganddetails(player);

    cout<<endl<<endl<<"-------------------------------MAIN ROOM--------------------------------"<<endl<<endl;
    cout<<endl<<"NINA : This is the MAIN ROOM of this map you must find clues inside the map to escape from here"<<endl;
    cout<<"NINA : The clues might be or might not be interconnceted with each other "<<endl<<endl;
    display_enviro(1);


    while(true) {
        if(room==0) {
            break;
        }
        char choice;
        cout<<"Enter move : ";
        cin>>choice;
        moveplayer(choice,player,inventory,room);
        cout<<endl;
        player.getinfo();
        cout<<endl;
        display_enviro(room);
    }

}

int main() {
    gameloop();

}