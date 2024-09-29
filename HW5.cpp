// #include <iostream>
// #include <iomanip>
// #include <cmath>

// using namespace std;

// char encryptLower(char letter, int shiftValue);

// char encryptLower(char letter, int shiftValue){
//     shiftValue = shiftValue % 26;

//     int newLetter = ((letter - 'a' + shiftValue) % 26) + 'a';
    
//     if (newLetter < 'a') {
//         newLetter += 26;
//     }

//     return newLetter;
// }

// int main(){
//     //declare variables
//     char userChar;
//     int letterShift;
//     char encryptedChar;

//     //prompt user for their letter (lowercase)
//     cout << "Enter the lowercase character to encrypt:" << endl;
//     cin >> userChar;

//     cout << "Enter the encryption value:" << endl;
//     cin >> letterShift;

//     //set up statement to shift the value
//     encryptedChar = encryptLower(userChar, letterShift);
//         if (userChar >= 'a' && userChar <= 'z'){
//             cout << "Letter " << userChar << " was encrypted to " << encryptedChar << endl;
//         }
//         else{
//             cout << "Letter " << userChar << " was encrypted to " << userChar << endl;
//         }
//     return 0;

// }

// #include <iostream>
// #include <iomanip>
// #include <cassert>

// using namespace std;

// int calculateTime(int targetSize){
//     int time = 0;
//     int currentSize = 1;
//     int growthRate = 1;

//     while (currentSize < targetSize) {
//         time++;
//         currentSize += growthRate;
//         growthRate++;
//     }

//     return time;

// }

// int main(){
//     //define variables
//     int headSize;
//     int midBodySize;
//     int lowerBodySize;

//     //prompt user 3 times for each part of the body
//     do{
//         cout << "Enter head size:" << endl;
//         cin >> headSize;
//         if (headSize <= 0){
//             cout << "Please enter a positive integer for head size:" << endl;
//             cin >> headSize;
//         }
//     }
//     while (headSize <= 0);
    
    
//     do{
//         cout << "Enter mid-body size:" << endl;
//         cin >> midBodySize;
//         if (midBodySize <= 0){
//             cout << "Please enter a positive integer for mid-body size:" << endl;
//             cin >> midBodySize;
//         }
//     }
//     while (midBodySize <= 0);

//     do{
//         cout << "Enter lower-body size:" << endl;
//         cin >> lowerBodySize;
//         if (lowerBodySize <= 0){
//             cout << "Please enter a positive integer for lower-body size:" << endl;
//             cin >> lowerBodySize;
//         }
//     }
//     while (lowerBodySize <= 0);

//     //calculate times
//     int headTime = calculateTime(headSize);
//     int midBodyTime = calculateTime(midBodySize);
//     int lowerBodyTime = calculateTime(lowerBodySize);

//     int totalTime = headTime + midBodyTime + lowerBodyTime;

//     cout << "Time to reach head size: " << headTime << " seconds" << endl;
//     cout << "Time to reach mid-body size: " << midBodyTime << " seconds" << endl;
//     cout << "Time to reach lower-body size: " << lowerBodyTime << " seconds" << endl;
//     cout << "Total time to create the snowman: " << totalTime << " seconds" << endl;

//     return 0;
// }

// #include <iostream>
// #include <iomanip>
// #include <cmath>

// using namespace std;

// int main(){
//     int userNum;
//     int steps = 0;

//     do{
//         cout << "Enter a number between 10 and 500:" << endl;
//         cin >> userNum;
//         if (userNum <= 10 || userNum >= 500){
//             cout << "Invalid input." << endl;
//         }
//     }
//     while (userNum <= 10 || userNum >= 500);

//     while (userNum != 1){
//         if (userNum % 2 == 0){
//             userNum = (userNum / 2);
//         }

//         else if (userNum % 2 != 0){
//             userNum = (3*userNum) + 1;
//         }

//         cout << userNum << endl;
//         steps++;
//     }

//     cout << "Total steps: " << steps << endl;

//     return 0;
// }

// #include <iostream>
// #include <iomanip>

// using namespace std;

// //fuction to calculate potions
// int calculatePotions(int leaves, int flowers, int stools, int needles, 
// int reqLeaves, int reqFlowers, int reqStools, int reqNeedles){
//     int potionsTea = leaves/reqLeaves;
//     int potionsSun = flowers/reqFlowers;
//     int potionsToad = stools/reqStools;
//     int potionsPine = needles/reqNeedles;
    
//     //check ingredients
//     int potions = potionsTea;
//     if (potionsSun < potions){
//         potions = potionsSun;
//     }
//     if (potionsToad < potions){
//         potions = potionsToad;
//     }
//     if (potionsPine < potions){
//         potions = potionsPine;
//     }

//     return potions;
// }

// void updateIngredients(int leaves, int flowers, int stools, int needles, 
// int reqLeaves, int reqFlowers, int reqStools, int reqNeedles, int potionsMade){
//     leaves -= potionsMade * reqLeaves;
//     flowers -= potionsMade * reqFlowers;
//     stools -= potionsMade * reqStools;
//     needles -= potionsMade * reqNeedles;
// }

// int main(){

//     int magicPotion;
//     int healthPotion;
//     int potionChoice;
//     int tea, sun, toad, pine;

//     int hPotionTea = 6, hPotionSun = 1, hPotionToad = 5, hPotionPine = 2;
//     int mPotionTea = 2, mPotionSun = 3, mPotionToad = 10, mPotionPine = 1;

//     do{
//         cout << "Select a potion crafting priority:" << endl;
//         cout << "1. Health Potion" << endl;
//         cout << "2. Magic Potion" << endl;
//         cin >> potionChoice;
//         if (potionChoice != 1 && potionChoice != 2){
//             cout << "Invalid input. Please select 1 or 2." << endl;
//             cin >> potionChoice;
//         }
//     }while (potionChoice != 1 && potionChoice != 2);

//     cout << "How many Tealeaves do you have?" << endl;
//     cin >> tea;
//     cout << "How many Sunflowers do you have?" << endl;
//     cin >> sun;
//     cout << "How many Toadstools do you have?" << endl;
//     cin >> toad;
//     cout << "How many Pine Needles do you have?" << endl;
//     cin >> pine;
    
//     magicPotion = 0, healthPotion = 0;

//     if (potionChoice == 1){
//         healthPotion = calculatePotions(tea, sun, toad, pine, hPotionTea, 
//                                     hPotionSun, hPotionToad, hPotionPine);

//         updateIngredients(tea, sun, toad, pine, hPotionTea, 
//                         hPotionSun, hPotionToad, hPotionPine, healthPotion);
    
//         magicPotion = calculatePotions(tea, sun, toad, pine, mPotionTea, 
//                                     mPotionSun, mPotionToad, mPotionPine);
//     }

//     else if (potionChoice == 2){
//         magicPotion = calculatePotions(tea, sun, toad, pine, mPotionTea, 
//                                     mPotionSun, mPotionToad, mPotionPine);

//         updateIngredients(tea, sun, toad, pine, hPotionTea, 
//                         hPotionSun, hPotionToad, hPotionPine, healthPotion);
        
//         healthPotion = calculatePotions(tea, sun, toad, pine, hPotionTea, 
//                                     hPotionSun, hPotionToad, hPotionPine);
//     }

//     if (potionChoice == 1){
//         cout << "You can make " << healthPotion << " Health potion(s) and " << magicPotion << " Magic potion(s)." << endl;
//     }
//     else if (potionChoice == 2){
//         cout << "You can make " << magicPotion << " Magic potion(s) and " << healthPotion << " Health potion(s)." << endl;
//     }

//     return 0;
// }

// #include <iostream>
// #include <iomanip>

// using namespace std;


// int magicPotion(int teaLeaves, int sunFlowers, int toadStools, int pineNeedles){
//     int mPotions = 0;
//     while (teaLeaves >= 2 && sunFlowers >= 3 && toadStools >= 10 && pineNeedles >= 1){
//         mPotions++;
//         teaLeaves -= 2;
//         sunFlowers -= 3;
//         toadStools -= 10;
//         pineNeedles -= 1;
//     }
//     return mPotions;
// }

// int healthPotion(int teaLeaves, int sunFlowers, int toadStools, int pineNeedles){
//     int hPotions = 0;
//     while (teaLeaves >= 6 && sunFlowers >= 1 && toadStools >= 5 && pineNeedles >= 2){
//     hPotions++;
//     teaLeaves -= 6;
//     sunFlowers -= 1;
//     toadStools -= 5;
//     pineNeedles -= 2;
//     }
//     return hPotions;
// }

// int main(){
//     int mPotion;
//     int hPotion;
//     int potionChoice;
//     int tea, sun, toad, pine;

//     do{

//         cout << "Select a potion crafting priority:" << endl;
//         cout << "1. Health Potion" << endl;
//         cout << "2. Magic Potion" << endl;
//         cin >> potionChoice;
//         if (potionChoice != 1 && potionChoice != 2){
//             cout << "Invalid input. Please select 1 or 2." << endl;
//             cin >> potionChoice;
//         }
//     }while (potionChoice != 1 && potionChoice != 2);

//     do{
//         cout << "How many Tealeaves do you have?" << endl;
//         cin >> tea;
//         if (tea < 0){
//             cout << "Invalid input. Please enter a non-negative integer." << endl;
//             cin >> tea;
//         }
//     }while (tea < 0);

//     do{
//         cout << "How many Sunflowers do you have?" << endl;
//         cin >> sun;
//         if (sun < 0){
//             cout << "Invalid input. Please enter a non-negative integer." << endl;
//             cin >> sun;
//         }
//     }while (sun < 0);

//     do{
//         cout << "How many Toadstools do you have?" << endl;
//         cin >> toad;
//         if (toad < 0){
//             cout << "Invalid input. Please enter a non-negative integer." << endl;
//             cin >> toad;
//         }
//     }while (toad < 0);

//     do{
//         cout << "How many Pine Needles do you have?" << endl;
//         cin >> pine;
//         if (pine < 0){
//             cout << "Invalid input. Please enter a non-negative integer." << endl;
//             cin >> pine;
//         }
//     }while (pine < 0);

//     mPotion = 0, hPotion = 0;

//     switch (potionChoice){
//         case 1:
//             hPotion = healthPotion(tea, sun, toad, pine);
//             mPotion = magicPotion(tea, sun, toad, pine);
//             cout << "You can make " << hPotion << " Health potion(s) and " << mPotion << " Magic potion(s)." << endl;
//             break;
//         case 2:
//             mPotion = magicPotion(tea, sun, toad, pine);
//             hPotion = healthPotion(tea, sun, toad, pine);
//             cout << "You can make " << mPotion << " Magic potion(s) and " << hPotion << " Health potion(s)." << endl;
//             break;
//     }
//     return 0;
// }

// #include <iostream>
// #include <cmath>
// #include <cassert>
//  using namespace std; 

// bool validateInt(string input) {
//     int len = input.length();
//     if (len == 0) return false;
//     int i = 0;
//     if (input[0] == '-') {
//         if (len == 1) return false;
//         i = 1;
//     }
//     for (; i < len; i++) {
//         if (input[i] < '0' || input[i] > '9') return false;
//     }
//     return true;
// }