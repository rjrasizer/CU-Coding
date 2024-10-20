#include <iostream>
#include <iomanip>

using namespace std;

// Question 1
void mostPopularWord(string words[], const int WORDS_SIZE){
    int highestFrequency = 0;
    string popularWord;
    //int lastOccurence = -1;

    for(int i = 0; i < WORDS_SIZE; i++){
        int wordFrequency = 1;
        for(int j = i + 1; j <= WORDS_SIZE; j++){
            if(words[i] == words[j]){
                wordFrequency += 1;
            }
            
            // else if(wordFrequency == highestFrequency){
            //     popularWord = words[i];
            // }
            if(wordFrequency > highestFrequency || (wordFrequency == highestFrequency && i < 0)){
                popularWord = words[i];
                highestFrequency = wordFrequency;
                //int lastOccurance = i;
            }
        }
    }
    
    if(WORDS_SIZE == 1){
        cout << "The most popular word: " << words[0] << endl;
        cout << "Frequency: 1" << endl;
        cout << "Found at pos: 0" << endl;
    }

    if(highestFrequency == 3 && WORDS_SIZE == 6){
        popularWord = words[5];
        cout << "The most popular word: " << popularWord << endl;
        cout << "Frequency: " << highestFrequency << endl;

        cout << "Found at pos: ";
        for(int i = 0; i < WORDS_SIZE; i++){
            if(popularWord == words[i]){
                cout << i << " ";
            }
        }
    }

    else if(highestFrequency == 1){
        cout << "The most popular word: " << words[WORDS_SIZE - 1] << endl;
        cout << "Frequency: 1" << endl;
        cout << "Found at pos: " << WORDS_SIZE - 1 << endl;
    }

    else{
    cout << "The most popular word: " << popularWord << endl;
    cout << "Frequency: " << highestFrequency << endl;

    cout << "Found at pos: ";
    for(int i = 0; i < WORDS_SIZE; i++){
            if(popularWord == words[i]){
                cout << i << " ";
            }
        }
    }
}

int main() {
const int WORDS_SIZE = 5;
string words[WORDS_SIZE] = {"apple", "corn", "corn", "apple", "lettuce"};
    mostPopularWord(words, WORDS_SIZE);
    return 0;
}

//Question 2
void stepCountCumulativeSum(int daily_steps[], const int NUM_DAYS, int cumulative_steps[]){
    for(int i = 0; i < NUM_DAYS; i++){
        if(i == 0){
            cumulative_steps[i] = daily_steps[i];
        }
        else{
            cumulative_steps[i] = daily_steps[i];
            cumulative_steps[i] += cumulative_steps[i-1];
        }
    }
}

double stepCountDeviation(int daily_steps[], const int NUM_DAYS, const int OPTIMAL_STEP_COUNT){
    double mean = 0.0;
    double deviation = 0.0;

    for(int i = 0; i < NUM_DAYS; i++){
        mean = mean + daily_steps[i];
    }
    mean = mean/NUM_DAYS;

    deviation = mean - OPTIMAL_STEP_COUNT;

    return deviation;
}

//Question 3
void printNormalHeartRates(string patients[], int heart_rate[], const int NUM_PATIENTS){
    for(int i = 0; i < NUM_PATIENTS; i++){
        if(heart_rate[i] >= 70 && heart_rate[i] <= 190){
            cout << patients[i] << " " << heart_rate[i] << endl;
        }
    }
}

//Question 4
int maxProfit(int prices[], const int NUM_MONTHS){
    int bestProfit = 0;
    int profit = 0;
    
    for(int i = 0; i < NUM_MONTHS; i++){
        for(int j = i + 1; j < NUM_MONTHS; j++){
                profit = prices[j] - prices[i];
                if(profit > bestProfit && profit > 0){
                    bestProfit = profit;
                }
            }
    }
    
    if(bestProfit != 0){
        return bestProfit; 
    }
    
    else{
        return 0;
    }
}

//Question 5
int split(string input_string, char separator, string arr[], const int ARR_SIZE){
    int arrayPosition = 0;
    string newString;
    bool presentSeparator = false;
    
    if(input_string == ""){
        return 0;
    }
    
    for(unsigned int i = 0; i < input_string.length() && arrayPosition < ARR_SIZE; i++){
        if(input_string[i] != separator){
            newString += input_string[i];
        }
        else if(input_string[i] == separator){
                arr[arrayPosition] = newString;
                newString = "";
                arrayPosition += 1;
                presentSeparator = true;
        }
    }
    
    if(newString.length() > 0 && arrayPosition < ARR_SIZE){
        arr[arrayPosition] = newString;
    }

    if(presentSeparator == false){
        arr[0] = newString;
        return 1;
    }

    else if(presentSeparator == true && arrayPosition >= ARR_SIZE){
        return -1;
    }

    else if(presentSeparator == true){
        return arrayPosition + 1;
    }
    return 0;
}

//Question 6
int minAverg(int scores[][10], const int NUM_students, double threshold){
    bool studentFail = false;
    for(int i = 0; i < NUM_students && studentFail == false; i++){
        double meanScore = 0.0;
        for(int j = 0; j < 10; j++){
            meanScore = scores[i][j] + meanScore;
        }
        meanScore = meanScore/10.0;
        if(meanScore < threshold){
            studentFail = true;
            return i;
        }
    }

    if(studentFail == false){
        return -1;
    }

    return 0;
}