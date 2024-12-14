#include <bits/stdc++.h>
using namespace std;

// Player inventory
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

// Player details
class playerdetails {
    private:
        int stamina;
        int food;
        int torch_battery;

    public:
        int health;
        string playername;
        vector<int> player_pos = {1, 1};
        unordered_map<string, bool> track_riddles;
        playerdetails();
        void getinfo();
        void updateinfo();
        void updatedetails(playerinventory);
        void updatehealth();
};

// Room variable
int room = 1;

// Creating grids for game environment
vector<vector<string>> mainroom = {
    {" # ", " # ", " # ", " # ", " # ", " # ", " # ", " # ", " # ", " # ", " # ", " # ", " # ", " # ", " # ", " # ", " # ", " # ", " # ", " # "},
    {" # ", " P ", " . ", " . ", " . ", " . ", " . ", " . ", " L ", " # ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " # "},
    {" # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . "},
    {" # ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . "},
    {" # ", " . ", " # ", " . ", " # ", " . ", " # ", " I ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . "},
    {" # ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " I ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . "},
    {" # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . "},
    {" # ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . "},
    {" # ", " # ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . "},
    {" # ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . "},
    {" # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " I "},
    {" # ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . "},
    {" # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . "},
    {" # ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . "},
    {" # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " I ", " . ", " # ", " . ", " # ", " . "},
    {" # ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . "},
    {" # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . "},
    {" # ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " L ", " . ", " . ", " . ", " . ", " . ", " . "},
    {" # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . "},
    {" # ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " E ", " # "},
};

//Room 1
vector<vector<string>> room2 = {
    {" # ", " # ", " # ", " # ", " # ", " # ", " # ", " # ", " # ", " # ", " # ", " # ", " # ", " # ", " # ", " # ", " # ", " # ", " # ", " # "},
    {" # ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " P ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " # "},
    {" # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . "},
    {" # ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " I ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . "},
    {" # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . "},
    {" # ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . "},
    {" # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . "},
    {" # ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . "},
    {" # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . "},
    {" # ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . "},
    {" # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " I ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . "},
    {" # ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . "},
    {" # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . "},
    {" # ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " E ", " # "}
};


//Room 2
vector<vector<string>> room3 = {
    {" # ", " # ", " # ", " # ", " # ", " # ", " # ", " # ", " # ", " # ", " # ", " # ", " # ", " # ", " # ", " # ", " # ", " # "},
    {" # ", " P ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " # "},
    {" # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . "},
    {" # ", " . ", " . ", " . ", " . ", " . ", " . ", " I ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . "},
    {" # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . "},
    {" # ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . "},
    {" # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . "},
    {" # ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . "},
    {" # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . "},
    {" # ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . "},
    {" # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " I ", " . ", " # ", " . ", " # ", " . ", " # ", " . "},
    {" # ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . "},
    {" # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . "},
    {" # ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . "},
    {" # ", " . ", " # ", " . ", " # ", " . ", " # ", " I ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . "},
    {" # ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . "},
    {" # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " . ", " # ", " E "},
    {" # ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " . ", " # ", " . "}
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
    stamina -= 1;
    if (stamina <= 0) {
        cout<<"--------------PLAYER LOW ON STAMINA!! HEALTH DECREASING-------------"<<endl<<endl;
        health -= 5;
    }
    food -= 1;
    torch_battery -= 2;
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

// Display environment
void display_enviro(const vector<vector<string>>& grid) {
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            cout << cell;
        }
        cout << endl;
    }
}

void endgame(int a) {
    if(a==1) {
        cout<<endl<<endl<<endl<<"--------------------------------NINA : YOU LOST YOUR HEALTH AND YOU DIED!!-------------------------------"<<endl<<endl;
        cout<<"NINA : For centuries no one had ever escaped this place"<<endl;
        exit(0);
    }
    else{
        cout<<endl<<endl<<"Finally!! You made it, for centuries no one could escape the room but you are the chosen one!!";
        cout<<endl<<endl<<endl<<"---------------------THANK YOU FOR PLAYING---------------------------------"<<endl<<endl;
        exit(0);
    }
}

// Check for riddle and transition to next room
void handleLTransition(playerdetails &player, vector<vector<string>>& grid,int pos) {
    cout<<endl<<endl<<"NINA : You are in front of the door answer the riddle to go inside the room"<<endl<<endl;
    string answer;
    if(pos==1){   //entrance of room 2
        cout <<endl<<endl<< "I speak without a mouth and hear without ears. I have no body, but I come alive with the wind. What am I?"<<endl;
        cout<<"Answer : ";
        cin>>answer;
        if(answer=="echo") {
            cout<<endl<<endl<<"NINA : Correct Moving to ROOM 2........."<<endl<<endl;
            cout<<endl<<endl<<"---------------------ROOM 2----------------------------------"<<endl;
            cout<<endl<<endl<<"NINA : This is ROOM 2, find clues and escape from the room"<<endl<<endl;
            if(room==1 || room==3) {
                grid=room2;
                room=2;
            }
        }
        else{
                cout<<endl<<endl<<"NINA : Incorrect answer your Health will be decreased!!";
                player.updatehealth();
                handleLTransition(player,grid,pos);
        }
    }
    else if(pos==17) {   //entrance of room 3
        cout<<"NINA : The more of me you take, the more you leave behind.";
        cout<<"Answer : ";
        cin>>answer;
        if(answer=="footsteps") {
            cout<<endl<<endl<<"NINA : Correct Moving to ROOM 3........."<<endl<<endl;
            cout<<endl<<endl<<"---------------------ROOM 3----------------------------------"<<endl;
            cout<<endl<<endl<<"NINA : So you are Finaly here, for the last time find clues and reach to the EXIT"<<endl<<endl;
            if(room==1 || room==2) {
                grid=room3;
                room=3;
            }
        }
        else{
                cout<<endl<<endl<<"NINA : Incorrect answer your Health will be decreased!!";
                player.updatehealth();
                handleLTransition(player,grid,pos);
        }
    }  
    else if(pos==3) {   //Escaped from room 2
        cout<<endl<<endl<<"NINA : You have escaped from the room continue to find more clues "<<endl<<endl;
        room=1;
        grid=mainroom;
    }
    else if(pos==4) {   //Escpaed from room 3 
        cout<<endl<<endl<<"NINA : You have escaped from the room continue to find more clues "<<endl<<endl;
        room=1;
        grid=mainroom;
    }  
    else if(pos==5) {
        cout<<endl<<endl<<"NINA : So you finally came here and you are returning back home"<<endl;
        cout<<"NINA : The door to exit has a passkey Enter the PassKey to Exit  "<<endl;
        cout<<"PassKey : ";
        cin>>answer;
        if(answer=="nina") {
            endgame(2);
        }
        else{     //escape from room 1
            cout<<"Incoreect key Try again"<<endl;
            handleLTransition(player,grid,pos);
        }
    }  
}

// Move the player
void moveplayer(char input, playerdetails& obj1, playerinventory& obj2, vector<vector<string>>& grid) {
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
    else if(input == 'i') {
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
        cout << "Invalid input!" << endl;
        return;
    }

    if (grid[newx][newy] == " # ") {
        cout << "-------------You hit a wall!----------------------" << endl;
        return;
    }

   else if (grid[newx][newy] == " L ") {
        handleLTransition(obj1, grid,newx);
    }

    else if(grid[newx][newy] == " E ") {
        if(room==1 || grid==mainroom) {
            handleLTransition(obj1,grid,5);
        }
        else if(room==2 || grid==room2) {
            handleLTransition(obj1,grid,3);
        }
        else if(room==3 || grid==room3) {
            handleLTransition(obj1,grid,4);
        }
    }

    else if(grid[newx][newy] == " I ") {
        obj2.updateitem();
    }
    else{
        grid[x][y] = " . ";
    obj1.player_pos = {newx, newy};
    grid[newx][newy] = " P ";
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
    vector<vector<string>>* currentGrid = &mainroom;
    greetinganddetails(player);

    cout<<endl<<endl<<"-------------------------------MAIN ROOM--------------------------------"<<endl<<endl;
    cout<<endl<<"NINA : This is the MAIN ROOM of this map you must find clues inside the map to escape from here"<<endl;
    cout<<"NINA : The clues might be or might not be interconnceted with each other "<<endl<<endl;
    while (true) {
        display_enviro(*currentGrid);
        cout << "Enter move (w/a/s/d): ";
        char input;
        cin >> input;
        cout<<endl;
        player.getinfo();
        cout<<endl;
        moveplayer(input, player, inventory, *currentGrid);
        player.updateinfo();
    }
}

int main() {
    gameloop();
}
