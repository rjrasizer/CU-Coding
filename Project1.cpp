#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//Question 1 (check for valid base)

bool isValidBase(char base){
    //set up switch statement to check each letter
    switch(base){
        case 'A':
            base = true;
        break;

        case 'C':
            base = true;
        break;

        case 'G':
            base = true;
        break;

        case 'T':
            base = true;
        break;

        default:
            base = false;
        break;
    }
    //return the base value
    return base;
}

//Question 2
bool isValidStrand(string strand){
    //set up variable for strand length
    int length = strand.length();
    
    //check if strand length is zero return false
    if(length == 0){
        return false;
    }

    //create loop to check each character
    for (int i = 0; i < length; i++){
        char currentChar = strand[i];
        
        //check if characters are not correct for a strand
        if (currentChar != 'A' && currentChar != 'C' && currentChar != 'G' && currentChar != 'T'){
            return false;
        }
    }
    
    //If everything is correct return true
    return true;
}

//Question 3
double strandSimilarity(string strand1, string strand2){
    //initialize strand.lengths as ints so there is no comparison error in for loop
    int length1 = strand1.length();
    int length2 = strand2.length();
    double total = 0; //used at the end for total characters in strand regardless of correct or not
    double correct = 0; //used to track correct character matches
    double similarityScore = 0;

    if(length1 == length2){ //used to make sure that lengths are the same for a proper user input
    for(int i = 0; i < length1; i++){//every time each character i is less than the total length of the string, run the loop
        char currentChar1 = strand1[i]; //set up both strand[i]s as char variables
        char currentChar2 = strand2[i];

        if (currentChar1 == currentChar2){ //if the characters at that instance are the same add one to correct
            correct++;
        }
    total++; //always add 1 to total every loop
    }
    similarityScore = correct/total; //divide correct by total to get sim score
    
    return similarityScore;
    }

    else{ //if the lengths are not the same return 0
        return 0;
    }

}

//Question 4
int bestStrandMatch(string input_strand, string target_strand){
    strandSimilarity(input_strand, target_strand);
    double bestStrandSim = 0.0;
    double currentStrandSim = 0.0;
    int alignment_index = 0;

    if(input_strand.length() < target_strand.length()){ //if the input strand is less than the target strand return sim score of 0.0 and alignment of -1
        cout << "Best similarity score: 0.0" << endl;
        alignment_index = -1;
        return alignment_index;
    }
    
    else if(input_strand.length() >= target_strand.length()){//checking for correct entry
        for(unsigned int i = 0; i <= input_strand.length() - target_strand.length(); i++){//you subtract the lengths to then let i check for the best alignment
            string stringBlock = input_strand.substr(i, target_strand.length());//practically the coordinates are i (the starting point) and then the length of the smaller strand
            currentStrandSim = strandSimilarity(stringBlock, target_strand);
             
            if (currentStrandSim > bestStrandSim){//if the current updated strand has a better score than best, update best to that strand
            bestStrandSim = currentStrandSim;
            alignment_index = i; //always update the alignment index whenever the best strand updates
            }

        }
        cout << "Best similarity score: " << bestStrandSim << endl;
    }
    return alignment_index;
}

int updatedBestStrandMatch(string input_strand, string target_strand){ //same as the last function but used to avoid the repeat sim score cout statements for the next one
    strandSimilarity(input_strand, target_strand);
    double bestStrandSim = 0.0;
    double currentStrandSim = 0.0;
    int alignment_index = 0;

    if(input_strand.length() < target_strand.length()){
        cout << "Best similarity score: 0.0" << endl;
        alignment_index = -1;
        return alignment_index;
    }
    
    else if(input_strand.length() >= target_strand.length()){
        for(unsigned int i = 0; i <= input_strand.length() - target_strand.length(); i++){
            string stringBlock = input_strand.substr(i, target_strand.length());
            currentStrandSim = strandSimilarity(stringBlock, target_strand);
             
            if (currentStrandSim > bestStrandSim){
            bestStrandSim = currentStrandSim;
            alignment_index = i;
            }

        }
        //cout << "Best similarity score: " << bestStrandSim << endl;
    }
    return alignment_index;
}

//Question 5
void identifyMutations(string input_strand, string target_strand){

    if (input_strand == target_strand){ //if the strands are the exact same
        int matchIndex = updatedBestStrandMatch(input_strand, target_strand); //initialize the match index and sim score for this type of strand comparison
        double simScore = strandSimilarity(input_strand.substr(matchIndex, target_strand.length()), target_strand);//set up so that it is only starting the comparison from where the best alignment is
        
        //Strands are the exact same
        cout << "Best similarity score: " << simScore << endl;
        cout << "Best alignment index: " << matchIndex << endl;
        cout << "No mutations found." << endl;
    }

//if lengths match but the strands are not the exact same
   else if((input_strand.length() == target_strand.length()) && (input_strand != target_strand)){ 
        int matchIndex = updatedBestStrandMatch(input_strand, target_strand); //initialize the match index and sim score for this type of strand comparison
        double simScore = strandSimilarity(input_strand.substr(matchIndex, target_strand.length()), target_strand);
        
        //Strand lengths are the same but different characters
        cout << "Best similarity score: " << simScore << endl;
        cout << "Best alignment index: " << matchIndex << endl;
        
        //Only check substitutions since the lengths are the same
        for(unsigned int i = 0; i < target_strand.length(); i++){
            if(target_strand[i] != input_strand[i]){
                cout << "Substitution at position " << i + 1 << ": " << input_strand[i] << " -> " << target_strand[i] << endl;
            }
        }
    }

    //Not the same strand and input is greater length than target
    else if((input_strand != target_strand) && (input_strand.length() > target_strand.length())){
        int matchIndex = updatedBestStrandMatch(input_strand, target_strand); //initialize the match index and sim score for this type of strand comparison
        double simScore = strandSimilarity(input_strand.substr(matchIndex, target_strand.length()), target_strand);
        
        cout << "Best similarity score: " << simScore << endl;
        cout << "Best alignment index: " << matchIndex << endl;
        
        //Check for deletions before strand if the match index isnt at the start
        if(matchIndex > 0){
            for(int i = 0; i < matchIndex; i++){
                cout << "Deletion at position " << i + 1 << ": " << input_strand[i] << " is deleted in target strand" << endl;
            }
        }

        //Check for substitutions within where the strings match up
        for(unsigned int i = 0; i < target_strand.length(); i++){
            if(input_strand[i + matchIndex] != target_strand[i]){
                cout << "Substitution at position " << (matchIndex + i + 1) << ": " << input_strand[i + matchIndex] << " -> " << target_strand[i] << endl;
            }
        }

        //Check for if there needs to be deletions after
        if(matchIndex + target_strand.length() < input_strand.length()){
            for(unsigned i = matchIndex + target_strand.length(); i < input_strand.length(); i++){
                cout << "Deletion at position " << i + 1 << ": " << input_strand[i] << " is deleted in target strand" << endl;
            }
        }
    }

    //in the case that target is longer than the input because you need to reverse them
    else if (input_strand.length() < target_strand.length()){
        int reverseMatchIndex = updatedBestStrandMatch(target_strand, input_strand);//initialize the match index and sim score for this type of strand comparison
        double reverseSimScore = strandSimilarity(target_strand.substr(reverseMatchIndex, input_strand.length()), input_strand);//set up so that it is only starting the comparison from where the best alignment is but reversed since strand similarity needs the larger input first
        
        cout << "Best similarity score: " << reverseSimScore << endl;
        cout << "Best alignment index: " << reverseMatchIndex << endl;
        
        //Check for insertions before
        if(reverseMatchIndex > 0){
            for(int i = 0; i < reverseMatchIndex; i++){
                cout << "Insertion at position " << i + 1 << ": " << target_strand[i] << " is inserted in target strand" << endl;
            }
        }

        //Check for substitutions inside
        for(unsigned int i = 0; i < input_strand.length(); i++){
            if(target_strand[reverseMatchIndex + i] != input_strand[i]){
                cout << "Substitution at position " << (reverseMatchIndex + i + 1) << ": " << input_strand[i] << " -> " << target_strand[reverseMatchIndex + i] << endl;
            }
        }

        //Check for insertions after
        if(reverseMatchIndex + input_strand.length() < target_strand.length()){
            for(unsigned i = reverseMatchIndex + input_strand.length(); i < target_strand.length(); i++){
                cout << "Insertion at position " << i + 1 << ": " << target_strand[i] << " is inserted in target strand" << endl;
            }
        }
    }
}

//Question 6
void transcribeDNAtoRNA(string strand){
    int length = strand.length();
    for (int i = 0; i < length; i++){//check character by character using this loop
        char currentChar = strand[i];

        if(currentChar == 'T'){//if the character is T change it to U
            currentChar = 'U';
            cout << currentChar;
        }
        
        else if(currentChar != 'T'){//if the character is not T just print the character
            cout << currentChar;
        }
    }
}

//Question 7
void reverseComplement(string strand){
    int length = strand.length();
    for (int i = length; i >= 0; i--){//check each character one by one but start at the end of the strand and use i--
        char currentChar = strand[i];

        if (currentChar == 'A'){//change A to T
            currentChar = 'T';
            cout << currentChar;
        }

        else if (currentChar == 'T'){//change T to A
            currentChar = 'A';
            cout << currentChar;
        }

        else if (currentChar == 'C'){//change C to G
            currentChar = 'G';
            cout << currentChar;
        }

        else if (currentChar == 'G'){//change G to C
            currentChar = 'C';
            cout << currentChar;
        }
    }
}

//Question 8
void getCodingFrames(string strand){
bool presentReadingFrames = false; //set an initial boolean of if there is a reading frame to false and only set it to true if there is a reading frame
    for(unsigned int i = 0; i < strand.length() - 3; i++){ //checking each working position and stop when the point is not 3 characters long

        if(strand.substr(i, 3) == "ATG"){ //if the 3 char sequence is ATG or a start codon, start a loop to check until a stop codon

            unsigned int stopStrand = i; //set up the stop strand as i

            for(unsigned int j = stopStrand; j < strand.length() - 2; j++){//checking for every 3 after the start to look for a stop codon
                
                //check if the strand substr is equal to a stop codon or the comparison that it makes is not divisible by 3
                if((strand.substr(j, 3) == "TAA" || strand.substr(j, 3) == "TAG" || strand.substr(j, 3) == "TGA") && ((j - stopStrand) % 3 == 0)){
                    cout << strand.substr(stopStrand, j + 3 - stopStrand) << endl;//print the strand from the start codon to the stop codon
                    i = j;//set i back to j to continue to check for any more start codons
                    presentReadingFrames = true; //set the reading frames to true since there are reading frames present
                break;
                }
            
            }
        
        }
    }
    
    if(presentReadingFrames != true){ //if the reading frames never get set to true then print there are none
        cout << "No reading frames found." << endl;
    }
}

int main(){
    int userSelection;
    string userStrand;
    string userStrand1, userStrand2;
    double simTest;
    int userMatchIndex;
    double userSimScore; 

    do{
        cout << "--- DNA Analysis Menu ---" << endl;
        cout << "1. Calculate the similarity between two sequences of the same length" << endl;
        cout << "2. Calculate the best similarity between two sequences of either equal or unequal length" << endl;
        cout << "3. Identify mutations" << endl;
        cout << "4. Transcribe DNA to RNA" << endl;
        cout << "5. Find the reverse complement of a DNA sequence" << endl;
        cout << "6. Extract coding frames" << endl;
        cout << "7. Exit" << endl;
        cout << "Please enter your choice (1 - 7):" << endl;
        cin >> userSelection;

        if(userSelection != 1 && userSelection != 2 && userSelection != 3 && userSelection != 4 && userSelection != 5 && userSelection != 6 && userSelection != 7){
            cout << "Invalid input. Please select a valid option." << endl;
        }

        else if(userSelection == 7){
            cout << "Exiting program." << endl;
            return 0;
        }


        else if(userSelection == 1 || userSelection == 2 || userSelection == 3 || userSelection == 4 || userSelection == 5 || userSelection == 6){
            switch (userSelection){
                case 1:
                    
                    do{
                    cout << "Enter the first DNA sequence:" << endl;
                    cin >> userStrand1;

                    if(isValidStrand(userStrand1) == false){
                        cout << "Invalid input. Please enter a valid sequence." << endl;
                    }
                    
                    }while(isValidStrand(userStrand1) == false);
                    
                    do{
                    
                    cout << "Enter the second DNA sequence:" << endl;
                    cin >> userStrand2;

                    if(isValidStrand(userStrand2) == false){
                        cout << "Invalid input. Please enter a valid sequence." << endl;
                    }

                    }while(isValidStrand(userStrand2) == false);

                    if(userStrand1.length() != userStrand2.length()){
                        cout << "Error: Input strands must be of the same length." << endl;
                    }

                    else{
                    simTest = strandSimilarity(userStrand1, userStrand2);

                    cout << "Similarity score: " << simTest << endl;
                    }

                break;

                case 2:
                                        
                    do{
                    cout << "Enter the first DNA sequence:" << endl;
                    cin >> userStrand1;

                    if(isValidStrand(userStrand1) == false){
                        cout << "Invalid input. Please enter a valid sequence." << endl;
                    }
                    
                    }while(isValidStrand(userStrand1) == false);
                    
                    do{
                    
                    cout << "Enter the second DNA sequence:" << endl;
                    cin >> userStrand2;

                    if(isValidStrand(userStrand2) == false){
                        cout << "Invalid input. Please enter a valid sequence." << endl;
                    }

                    }while(isValidStrand(userStrand2) == false);

                    //bestSimTest = bestStrandMatch(userStrand1, userStrand2);

                    if(userStrand1.length() < userStrand2.length()){
                        cout << "Best similarity score: 0.0" << endl;
                    }

                    else{
                    userMatchIndex = updatedBestStrandMatch(userStrand1, userStrand2);
                    userSimScore = strandSimilarity(userStrand1.substr(userMatchIndex, userStrand2.length()), userStrand2);

                    cout << "Best similarity score: " << userSimScore << endl;
                    }

                break;

                case 3:
                    
                    cout << "Enter the first DNA sequence:" << endl;
                    cin >> userStrand1;

                    cout << "Enter the second DNA sequence:" << endl;
                    cin >> userStrand2;
                    
                    identifyMutations(userStrand1, userStrand2);

                break;

                case 4:
                    
                    do{
                    cout << "Enter the DNA sequence to be transcribed:" << endl;
                    cin >> userStrand;
                    
                    if(isValidStrand(userStrand) == false){
                        cout << "Invalid input. Please enter a valid sequence." << endl;
                    }

                    }while(isValidStrand(userStrand) == false);

                    cout << "The transcribed DNA is: ";
                    
                    transcribeDNAtoRNA(userStrand);

                    cout << endl;

                break;

                case 5:
                    
                    do{
                    cout << "Enter the DNA sequence:" << endl;
                    cin >> userStrand;
                    
                    if(isValidStrand(userStrand) == false){
                        cout << "Invalid input. Please enter a valid sequence." << endl;
                    }

                    }while(isValidStrand(userStrand) == false);

                    cout << "The reverse complement is: ";
                    
                    reverseComplement(userStrand);

                    cout << endl;

                break;
                
                case 6:

                    do{
                        cout << "Enter the DNA sequence: " << endl;
                        cin >> userStrand;

                        if(isValidStrand(userStrand) == false){
                            cout << "Invalid input. Please enter a valid sequence." << endl;
                        }

                    }while(isValidStrand(userStrand) == false);
                    
                    cout << "The extracted reading frames are:" << endl;

                    getCodingFrames(userStrand);

                break;
            }
        }

    }while((userSelection == 1 || userSelection == 2 || userSelection == 3 || userSelection == 4 || userSelection == 5 || userSelection == 6 || userSelection == 7) || (userSelection > 7 || userSelection < 1));

    return 0;

}
