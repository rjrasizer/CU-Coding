#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/* int main()
{
    // Declare Variables
    double height, time;
    
    // outputs to 3 sig figs 
    cout << setprecision(2) << fixed;

    // prompt user with question
    cout << "How far did the object fall in meters? " << endl;
    cin >> height;

    // calculate time
    time = sqrt(2.00*height/9.80);

    // write how far it fell
    cout << "The object fell for " << time << " seconds." << setprecision(3) << endl;
    return 0;
}
*/
/*int main()
{
    // declare variables
    double length, width, height, volume;

    // outputs to 3 sig figs 
    cout << setprecision(1) << fixed;

    // prompt user with questions
    cout << "What is the length of the fish tank in inches? " << endl;
    cin >> length;

    cout << "What is the width of the fish tank in inches? " << endl;
    cin >> width;

    cout << "What is the height of the fish tank in inches? " << endl;
    cin >> height;

    // calculate Volume
    volume = (length*width*height)*0.004329;

    // write the capacity
    cout << "This fish tank has a " << volume << " gallon capacity." << endl;
    return 0;
}
*/

/*int main()
{
    // define variables
    double hours;
    float indoor_pool, outdoor_pool;

    // output to 1 decimal
    cout << fixed << setprecision(1);

    // prompt user to enter hours passed
    cout << "How many hours have passed? " << endl;
    cin >> hours;

    // calculate indoor pool
    indoor_pool = (.2*hours)+19.0;

    // calculate outdoor pool
    outdoor_pool = (.2*hours)+22.0;

    // write the amount of water in each pool
    cout << "The indoor pool has " << indoor_pool << " inches of water, and the outdoor pool has " << outdoor_pool << " inches of water." << endl;
    return 0;
}
*/

int main()
{
    // define variables
    int total_potatoes = 0;
    int chickens = 0;
    int avocados = 0;
    int watermelons = 0;
    int potatoes_per_chicken = 48;
    int potatoes_per_avocado = 8;
    int potatoes_per_watermelon = 4;

    // prompt user to enter number of potatoes
    cout << "Enter the number of potatoes: " << endl;
    cin >> total_potatoes;

    // conversions
    chickens = total_potatoes / potatoes_per_chicken;
    total_potatoes = total_potatoes % potatoes_per_chicken;

    avocados = total_potatoes / potatoes_per_avocado;
    total_potatoes = total_potatoes % potatoes_per_avocado;

    watermelons = total_potatoes / potatoes_per_watermelon;
    total_potatoes = total_potatoes % potatoes_per_watermelon;

    // print to user maximum number of each item
    cout << "Maximum number of chicken(s) " << chickens << ", avocado(s) " << avocados << ", watermelon(s) " << watermelons << ", potato(es) " << total_potatoes << endl;
    return 0;
}
