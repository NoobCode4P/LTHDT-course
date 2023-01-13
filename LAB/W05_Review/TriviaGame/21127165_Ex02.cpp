#include "TriviaGame.h"
#include <ctime>

int main(){
    //Because time changes continually, so srand() uses the seed to take control of the
    //computer's time and randomly generates integers at different time
    srand(time(NULL));
    TriviaGame a(15);
    a.loadQuestions("listOfQueries.txt");
    
    a.playGame();

    return 0;
}