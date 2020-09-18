#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;

struct Event // template for each event
{
    string text; // for the line of text
    int options; // shows how many options are available, 0 = end game
    int nextevent[24]; // shows the array and length of array
};

const Event gameEvents[] = { // States how to define each event
        // event 0
        {
            "Press 1 to continue\n",
            1,
            {1}
        },
        // event 1
        {
            "'All survivors are required to stay put in the city. All citizens are now \n"
            "quarantined and are required to stay in the city until a cure is discovered and \n"
            "that safety is ensured'\n\n"
            "Now the question is… Do you:\n\n"
            
            "Press 1 to stay and wait for help to arrive\n"
            "Press 2 to try and find a way out\n",
            2,
            {2,6}
        },
        // stay / event 2
        {
            "You decide to stay. After all, what could go wrong. You’re only staying\n"
            "until a new opportunity comes up and the people rescue you. As time \n"
            "ticks on, common sense makes you realize that the government isn’t \n"
            "going to rescue you.\n\n"
            
            "Suddenly you hear a pounding on your door.\n\n"
            "Press 1 to answer the door\n"
            "Press 2 to find a closet to hide in\n",
            2,
            {3,4}
        },

        // door / event 3
        {
            "The soldiers shoot you in the head. Apparently, you didn’t hear the memo \n"
            "That you needed to identify yourself to be saved. GAME OVER\n\n",
            0,
            {}
        },

        // closet / event 4
        {
            "The closet is very stuffy. Inside, you can see office supplies and coffee. \n"
            "Suddenly, the door breaks down and the zombies start piling in, some \n"
            "looking like some of your former co-workers. Fear settles in and you \n"
            "start to panic. \n\n"
            "The zombies hear another noise across the hallway and they then start to \n"
            "leave the room. You sigh of relief and quietly follow them to ground floor. \n"
            "You look around for options to choose from.\n\n"
            
            "Press 1 to get a vehicle and use your driving skills to get to the out\n"
            "Press 2 to look for another way out\n"
            "\n",
            2,
            {5,6}
        },
        
        //vehicle / event 5
        {
            "\n--------------------------Chapter 2: Escape the Area------------------------\n"
            "You run down to the garage to find that there are exactly two vehicles left:\n"
            "a motorcycle and a really old Jeep that doesn’t look like it would ever start.\n\n"
           
            "Press 1 to take the motorcycle\n"
            "Press 2 to take the jeep\n",
            2,
            {7,23}
        },

        // another way out / event 6
        {
            "You remember that you can tap into radio signals. Should be easy for an\n"
            "engineer like yourself to fix up a solution. You hook up an old flip phone\n"
            "to your radio and signal SOS in Morse code over and over to the citywide\n"
            "amber-alert program. They tell you over the radio that the north exit is the \n"
            "Evac site, and you have about 1 day to get there. That’s enough for you, and\n"
            "you go to the garage to find a vehicle to exit the city.\n\n"
            
            "Press 1 to continue\n",
            1,
            {5}
        },
        
        // motorcycle / event 7
        {
        "You decide to take the motorcycle. After all, you didn’t take those motocross\n"
        "classes for nothing, right? You hotwire the vehicle using a video tutorial and\n"
        "hightail it out of the parking space. A zombie comes over to you as you hotwire\n"
        "the vehicle, but you bash the helmet against the zombie. Not everything is safe \n"
        "though, as the zombie drew blood with a physical attack. Now that you get a \n"
        "better glimpse at the city, you choose to either:\n\n"
        
        "Press 1 to go fast and risk falling off the bike.\n"
        "Press 2 to at a medium pace and ensure that you don’t crash.\n",
            2,
            {8,9}
        },

        // Blitz / event 8
        {
            "You decided that blitzing it as fast as you can would yield the best chance \n"
            "of survival. A horde of zombies starts to chase after you though. You swerve\n"
            "in and out of abandoned cars and seem to lose sight of them. However, a final\n"
            "swerve yields terrible results as you crash. You come out, your face bleeding \n"
            "from the impact, pain wincing through you. On the other hand, you happen to\n"
            "crash into a hospital. A zombie sees you do this. You decide to:\n\n"
            
            "Press 1 to explore the hospital\n"
            "Press 2 to fight the zombie\n",
            2,
            {9, 10}
        
        },

        // Going slow / event 9
        {
            "You decide to go at a medium pace. After all, what could go wrong, right?\n"
            "I mean, you’re going at a reasonable pace. However, a rock comes flying out\n"
            "of nowhere and nails you in the shoulder. You fall off your bike, but only \n"
            "experience minor scratches. Suddenly, a zombie sees you on the ground and\n"
            "sprints towards you. You decide to…\n\n"
            
            "Press 1 to stay and fight it off\n"
            "Press 2 to run for your life\n",
            2,
            {10,12}
        },
        
        // Stay and fight it off / event 10
        {
            "You clench your fists and scramble for a pipe laying on the ground. You then\n"
            "close your eyes and swing as hard as you can, resulting in a satisfying 'thunk'.\n"
            "Opening your eyes reveals the zombie impaled by the pipe, limp and overall\n"
            "not moving. You praise yourself for this feat and go to the hospital right\n"
            "across the street.\n\n"
            
            "Press 1 to continue \n",
            1,
            {11}
        },

        // Hospital / event 11
        {
            "The hospital was old and bare, but well worth it. You happen to find a gun\n"
            "AND bandages, restoring a lot of the pain that you were caused. You even \n"
            "manage to find one of the hospital cars and head to the highway\n\n"
            
            "Press 1 to continue\n",
            1,
            {12}
        },

        // Run for your life / event 12
        {
            "You have no idea what kind of crazy thing you are doing, but all you’re\n"
            "doing is running. You hightail it out of the street and scramble to a vehicle,\n"
            "but not before that zombie swipes you in the arm. Bleeding out, you drive \n"
            "the vehicle onto the highway in search of an exit.\n"
            "\n"
            "You turn on the radio for amber alerts in hopes of an evacuation site, but all\n"
            "you hear is static. That’s when your heart sinks when you see the pile of cars\n"
            "up ahead and you have to make a quick decision…\n\n"

            "Press 1 to keep heading towards the cars and go on foot (north)\n"
            "Press 2 to get off the exit ramp and find another way out (east)\n",
            2,
            {13, 16}
        },

        // north / event 13
        {
            "-----------------------------Chapter 3: Crossroads----------------------------\n"
            "You go about on foot for now. I mean, you’ve come this far. You walk\n"
            "for what seems to be hours on end until you see a red flag. You walk a \n"
            "little closer to take a better look at what the flag says. Staring in horror,\n"
            "you make out the words.\n\n"

            "'Living Things are KOS' \n"
            "You mouth to yourself, 'kill on sight' \n\n"

            "Suddenly, gunfire erupts from beneath your feet and you rush to cover. \n"
            "Right there and then, the best choice is to… \n\n"
            "Press 1 to wave a white flag of surrender\n"
            "Press 2 to find a weapon and fire back\n",
            2,
            {14,15}
        },

        // White flag / event 14
        {
            "You tear off your shirt, which coincidentally is white with a few blood\n"
            "stains on it and tie it to the police rifle next to you and wave it. Immediately,\n"
            "the firing stops. Scientists rush out in a rover and pick you up. You find\n"
            "yourself safe and sound at the very end…\n\n"
             "until you notice the bite on your finger.\n\n"
             "GAME END… Victory?\n\n",
            0,
            {}
        },

        // firing back / event 15
        {
            "You grab a police rifle and fire back at the soldiers; unfortunately, you\n"
            "take heavy fire. You also can’t really fire a rifle, but you try anyway.\n"
            "Your life flashes before your eyes as you see what looks like a grenade\n"
            "fly through the air. \n\n"
            "'Should’ve thought of something else'\n\n"
            "GAME OVER\n",
            0,
            {}
        },

        // east / event 16
        {
            "-----------------------------Chapter 3: Crossroads----------------------------\n"
            "Zombies hoard your vehicle over and over as you drive down the ramp. \n"
            "One smashes your window while another splatters blood all around your\n"
            "vehicle. You plow on through anyway, not quite sure where you’re going.\n"
            "You realize that the sewer system leads to the drainage outside the city, \n"
            "and that it’s probably not guarded. Focusing your efforts, you try to find\n"
            "your way to the sewers\n\n"
            "Press 1 to continue\n",
            1,
            {17}
        },
        
        // sewers / event 17
        {
            "You find the nearest drain and go inside. You get a chilly feeling all\n"
            "around as all you see is darkness. You open your phone to pull up a map\n"
            "of the sewer system\n"
            "You decide to go…\n\n"
            "Press 1 to go left\n"
            "Press 2 to go right\n",
            2,
            {19,20}
        },

        // sewer main / event 18
        {
            "You get a chilly feeling all around as all you see is darkness.\n"
            "You open your phone to pull up a map of the sewer system\n"
            "You decide to go…\n\n"
            "Press 1 to go left\n"
            "Press 2 to go right\n",
            2,
            {19,20}
        },

        // sewer left 1 / event 19
        {
            "Tunnel keeps continuing until another crossroad\n\n"
            "Press 1 to go left\n"
            "Press 2 to go right\n",
            2,
            {22,21}
        },
        
        // sewer right 1 / event 20
        {
            "Bars, go back to where you came from\n"
            "Press 1 to continue",
            1,
            {18}
        },

        // sewer right 2 / event 21
        {
            "You meet a series of turtles and a rat who guide you home\n\n"
            "(SECRET ENDING, YOU WIN)\n",
            0,
            {}
        },

        // sewer left 2 / event 22
        {
            "You meet a Japanese samurai guy that looks like he could be in a cartoon.\n"
            "He orders 'foot' soldiers to shred you to pieces.\n\n"
            "(SECRET ENDING, YOU LOSE)\n",
            0,
            {}
        },
            
        // jeep / event 23
            {
                "The Jeep doesn't work\n\n"
                "Press 1 to continue",
                1,
                {5}
                
            }
};
    
int activateEvent(int list) // function prototype to activate the events
{
    
    cout << gameEvents[list].text; // displays the text
    
    if(gameEvents[list].options <= 0) // checks to see if loop can be terminated
        return -1;
    
    int input; // prompts for input
    cin >> input; // registers input
    
    while(  input < 1 || input > gameEvents[list].options) // loops for incorrect input
    {
        cout << "That is an invalid input. 1 for option 1 and 2 for option 2\n";
        cin >> input; // reprompts input
    }
    
    return gameEvents[list].nextevent[ input - 1 ]; // returns the input - 1
}

int main()
{
    
char NAME[50]; // establishes length of name

cout << "__________   __  __ ____ _____ ______    _____ _    _ _______      _________      __     _" << endl;
cout << "|___  / __ \\|  \\/  |  _ \\_   _|  ____|  / ____| |  | |  __ \\ \\    / /_   _\\ \\    / /\\   | |" << endl;
cout << "   / / |  | | \\  / | |_) || | | |__    | (___ | |  | | |__) \\ \\  / /  | |  \\ \\  / /  \\  | |" << endl;
cout << "  / /| |  | | |\\/| |  _ < | | |  __|    \\___ \\| |  | |  _  / \\ \\/ /   | |   \\ \\/ / /\\ \\ | |" << endl;
cout << " / /_| |__| | |  | | |_) || |_| |____   ____) | |__| | | \\ \\  \\  /   _| |_   \\  / ____ \\| |____" << endl;
cout << "/_____\\____/|_|  |_|____/_____|______| |_____/ \\____/|_|  \\_\\  \\/   |_____|   \\/_/    \\_\\______|" << endl;
    
cout << "\n\n\n\n\n"<<endl;

    
    
cout << "Enter your name for people to call you by: ";
cin >> NAME; // prompts for name input
    
cout << endl;
    
cout << "Hello " << NAME << "!" << endl << endl; // user-defined introduction

    cout << "Zombie Survival is a choice-based game. This means that some choices will" << endl
         << "involve decision-making to escape the city. The best way to beat this game" << endl
         << "is to make the best decisions you can for the highest chance of survival." << endl;

    cout << "\n\n--------------------------Press Enter to continue---------------------------" << endl;
    system("read"); // creates pauses
    
    cout << "\n----------------------------------Prologue----------------------------------\n"<<
    "It was a normal day like any other and you’re listening to your favorite \n" <<
    "radio station on your break, 88.5 FM. Suddenly, you hear a static-like noise\n" <<
    "and an alert that 'strange things' have been happening. Obviously, it feels \n" <<
    "weird that a prank was going on the radio until… the radio message states \n" <<
    "that the announcement was a GOVERNMENT MESSAGE.\n\n" <<
    "All across, your coworkers get texts about secure evacuation due to an\n" <<
    "illness outbreak and you start to worry. In your confusion, you run into\n"<<
    "the glass door and knock out cold.\n\n" << endl;
    
    cout << "\n\n--------------------------Press Enter to continue---------------------------" << endl;
    system("read");

    cout <<"\n-----------------------Chapter 1: Not-So-Good Morning-----------------------\n" <<
    "You wake up, not quite sure of what happened or how long you were out. \n" <<
    "You sit up and look around. Everything’s a mess; doors blocked by shelves. \n" <<
    "windows broken, papers everywhere, and you’re by yourself. You get up and \n" <<
    "go to a window to see the streets in a similar manner but you don’t know why. \n" <<
    "You go to what’s left of your personal office space and find your radio that \n" <<
    "you used to listen to in your free time. \n\n" <<
    "Surprisingly, it still works. You turn it on and search for a channel that’ll \n" <<
    "hopefully give you an idea of the situation of the outside world and after a \n" <<
    "few minutes you do. People on the street are acting strange, twitching \n" <<
    "with a bloodshot look. They look cold and almost lifeless with blood \n" <<
    "everywhere. Your worst nightmares come true as you realize that they are \n" <<
    "zombies.\n\n" <<
    "Your radio then sparks up with an announcement.\n";
    
    int currentEvent = 0;
    
    while(currentEvent >= 0) // loops the events until a return -1 is recieved
    {
        currentEvent = activateEvent(currentEvent);
    }
    
    return 0; // ends program
};


