#include "Question.h"
#include "Player.h"
#include <vector>
#include <unordered_set>
#include <fstream>

class TriviaGame{
    vector <Question> questions;
    int numOfQuestions;
    Player player[2];
public:
    TriviaGame();
    TriviaGame(int n);
    void loadQuestions(string filename);
    bool isValidInputNumber(int choice);
    void playGame();
};