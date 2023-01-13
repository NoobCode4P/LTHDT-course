#include <iostream>
using namespace std;

class Question{
    string triviaQuestion;
    pair <int, string> answers[4];
    int correctAnswer;
public:
    Question();
    Question(string question, string ans1, string ans2, string ans3, string ans4, int correctAns);
    
    void setQuestion(string question);
    void setPossibleAnswers(string ans1, string ans2, string ans3, string ans4);
    void setCorrectAnswer(int ans);

    string getQuestion() const;
    pair <int, string> getPossibleAnswer1() const;
    pair <int, string> getPossibleAnswer2() const;
    pair <int, string> getPossibleAnswer3() const;
    pair <int, string> getPossibleAnswer4() const;
    int getCorrectAnswer() const;
    
};
ostream& operator << (ostream&, const Question&);