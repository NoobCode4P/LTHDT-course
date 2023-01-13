#include "TriviaGame.h"

TriviaGame::TriviaGame(){
    numOfQuestions = 0;
}

TriviaGame::TriviaGame(int n){
    numOfQuestions = n;
    questions.resize(n);
}

void TriviaGame::loadQuestions(string filename){
    ifstream in (filename);
    if (!in){
        cout << "Unable to open " << filename << endl;
        return;
    }
    while (!in.eof()){
        string question;
        getline(in, question);

        int qNumber = stoi(question.substr(0,question.find_first_of(')')));
        string q = question.substr(question.find_first_of('.') + 1);

        vector <string> v(4);
        string choice;

        getline(in, choice);
        v[0] = choice.substr(choice.find_first_of('.') + 1);

        getline(in, choice);
        v[1] = choice.substr(choice.find_first_of('.') + 1); 

        getline(in, choice);
        v[2] = choice.substr(choice.find_first_of('.') + 1); 

        getline(in, choice);
        v[3] = choice.substr(choice.find_first_of('.') + 1); 

        int ans;
        in >> ans;
        in.ignore();

        Question tmp(q,v[0],v[1],v[2],v[3],ans);
        questions[qNumber - 1] = tmp;
    }
    in.close();
}

bool TriviaGame::isValidInputNumber(int choice) {
    return (1 <= choice && choice <= 4);
}

void TriviaGame::playGame(){
    int min = 1;
    int max = numOfQuestions;

    cout << "Input a number(1-4 corresponding to answers a,b,c,d)" << endl;
    
    unordered_set <int> index;
    while (index.size() < 10)
        index.insert((rand() % (max - min + 1) + min) - 1);

    int turn = 0;
    for (unordered_set <int> :: iterator i = index.begin(); i != index.end(); ++i){
        cout << "++ Question for" << ((turn & 1) ? " Player2:" : " Player1:") << endl;
        cout << questions[*i];
        
        if (!(turn & 1)){
            int choice;
            do{
                cout << "==>Player1's answer: ";
                cin >> choice;
            }while (!isValidInputNumber(choice));

            if (questions[*i].getCorrectAnswer() == choice)
                player[0].increasePoints();
        }
        else {
            int choice;
            do{
                cout << "==>Player2's answer: ";
                cin >> choice;
            }while (!isValidInputNumber(choice));

            if (questions[*i].getCorrectAnswer() == choice)
                player[1].increasePoints();
        }
        turn++;
    }
    cout << "===========GAME ENDED===========" << endl;
    int point1 = player[0].getPoints();
    int point2 = player[1].getPoints();
    cout << "Player1 got " << point1 << " points" << endl;
    cout << "Player2 got " << point2 << " points" << endl;
    if (point1 > point2){
        cout << "Player1 won!" << endl;
        cout << "Player2 lost!" << endl;
    }
    else if (point1 < point2){
        cout << "Player2 won!" << endl;
        cout << "Player1 lost!" << endl;
    }
    else{
        cout << "Both of you are on equal terms!" << endl;
    }
}