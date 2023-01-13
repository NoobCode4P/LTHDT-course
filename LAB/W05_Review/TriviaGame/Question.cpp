#include "Question.h"

Question::Question(){}

Question::Question(string question, string ans1, string ans2, string ans3, string ans4, int correctAns){
    setQuestion(question);
    setPossibleAnswers(ans1, ans2, ans3, ans4);
    setCorrectAnswer(correctAns);
}

void Question::setQuestion(string question){
    triviaQuestion = question;
}

void Question::setPossibleAnswers(string ans1, string ans2, string ans3, string ans4){
    answers[0] = make_pair(1, ans1);
    answers[1] = make_pair(2, ans2);
    answers[2] = make_pair(3, ans3);
    answers[3] = make_pair(4, ans4);
}

void Question::setCorrectAnswer(int ans){
    if (ans < 0 || ans > 4)
        return;
    correctAnswer = ans;
}

string Question::getQuestion() const{
    return triviaQuestion;
}

pair <int, string> Question::getPossibleAnswer1() const{
    return answers[0];
}

pair <int, string> Question::getPossibleAnswer2() const{
   return answers[1];
}

pair <int, string> Question::getPossibleAnswer3() const{
    return answers[2];
}

pair <int, string> Question::getPossibleAnswer4() const{
    return answers[3];
}

int Question::getCorrectAnswer() const{
    return correctAnswer;
}

ostream& operator << (ostream& out, const Question& q){
    out << q.getQuestion() << endl;
    out << q.getPossibleAnswer1().first << "." << q.getPossibleAnswer1().second << endl;
    out << q.getPossibleAnswer2().first << "." << q.getPossibleAnswer2().second << endl;
    out << q.getPossibleAnswer3().first << "." << q.getPossibleAnswer3().second << endl;
    out << q.getPossibleAnswer4().first << "." << q.getPossibleAnswer4().second << endl;
    return out;
}

