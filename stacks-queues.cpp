
using namespace std;
#include <tuple>
#include <vector>
#include "iostream"

/*PART 1 - CHECK FORMULA ALGORITHM */
struct Node {
    Node* next;
    char val;
    Node(char val) {
        this->val = val;
        next = NULL;
    }
};



class Stack {
    Node* head;
public:
    Stack() {
        head = NULL;
    }

    void Put(char val) {
        if (head == NULL) {
            head = new Node(val);
            return;
        }
        Node* tmp = new Node(val);
        tmp->next = head;
        head = tmp;
    }

    char Get() {
        if (head == NULL) {
            return 'n';
        }
        char val = head->val;
        Node* temp = head;
        head = head->next;
        delete temp;
        return val;
    }

    bool Empty() {
        return head == NULL;
    }
};
int isEquationCorrect(string equation) {
    Stack stack;
    for (int i = 0; i < equation.length(); i++) {
        //push to the stack

        if ((equation[i] == '(')
            || (equation[i] == '{')
            || (equation[i] == '[')) {
            stack.Put(equation[i]);
            //cout <<"add to stack"<< equation[i] << endl;

        }
        else if ((equation[i] == ')')
            || (equation[i] == '}')
            || (equation[i] == ']')) {
            //check if there is a pair in the stack
            //cout << "compare with" << equation[i] << endl;

         if((equation[i] == ')')) {
             if (stack.Get() != '(') {
                 cout << "Formula is incorrect" << endl;

                 return 0;
             }
         }
         else if (equation[i] == '}') {
             if (stack.Get() != '{') {
                 cout << "Formula is incorrect" << endl;

                 return 0;
             }
         }
         else if (equation[i] == ']') {
             if (stack.Get() != '[') {
                 cout << "Formula is incorrect" << endl;

                 return 0;
             }
         }
        }
    }
    if (!stack.Empty()) {
        cout << "Formula is incorrect" << endl;
        return 0;
    }
    cout << "Formula is correct" << endl;

    return 1;

}/*
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/*PART 2 - LABIRYNTH ALGORITHM*/
bool FOUND = false;

class Coords {
public:
    int row, col;
    Coords(int row, int col) : row(row), col(col) {}
    bool operator==(const Coords& rhs) {
        return std::tie(row, col) == std::tie(rhs.row, rhs.col);
    }
};
int x[10][10] = { {7,1,3,5,3,6,1,1,7,5},{2,3,6,1,1,6,6,6,1,2},{6,1,7,2,1,4,7,1,6,2},{6,4,7,1,3,3,5,1,3,4},{5,5,6,1,5,4,6,4,7,4},{3,5,5,2,7,5,3,3,3,6},{4,1,4,3,6,4,5,5,2,6},{4,4,1,7,4,3,3,3,4,2},{4,4,5,1,5,2,3,3,3,5},{3,6,3,5,2,2,6,0,2,1} };

void printPath(std::vector<Coords> const& input)
{
    cout << "start->";
    for (int i = 0; i < input.size(); i++) {
        std::cout <<"[" << input.at(i).row <<"]" << "[" << input.at(i).col<<"]" << " -> ";
    }
    cout<<"end" << endl;
}
void HarryPath( int stepsAvailable, int param_row,int param_col,vector<Coords>alreadyVisited) {
    if (FOUND) {
        return;
    }
    //success case
    if ((param_row == 9) && (param_col == 9)) {
        Coords currectCoords(param_row, param_col);
        alreadyVisited.push_back(currectCoords);
        printPath(alreadyVisited);
        FOUND = true;
        return;
    }
 
    //new node
    Coords currectCoords(param_row, param_col);
    
    //check if it already been visited
    if (std::find(alreadyVisited.begin(), alreadyVisited.end(), currectCoords) != alreadyVisited.end()) {
       // cout << "end of path" << endl;
        return;
    }
    else {
        alreadyVisited.push_back(currectCoords);
        //case 1
        if (param_row + stepsAvailable > 9) {

        }
        else {
            HarryPath(x[param_row + stepsAvailable][param_col], param_row + stepsAvailable, param_col, alreadyVisited);
        }
        //case 2
        if (param_col + stepsAvailable > 9) {

        }
        else {
            HarryPath(x[param_row][param_col + stepsAvailable], param_row, param_col + stepsAvailable, alreadyVisited);


        }
        //case 3
        if (param_row - stepsAvailable < 0) {

        }
        else {
            HarryPath(x[param_row - stepsAvailable][param_col], param_row - stepsAvailable, param_col, alreadyVisited);
        }
        //case 4
        if (param_col - stepsAvailable < 0) {

        }
        else {
            HarryPath(x[param_row][param_col - stepsAvailable], param_row, param_col - stepsAvailable, alreadyVisited);
        }
        return;

    }
}

int main() {

    /*UNCOMMENT PART TO CHECK*/

    /*PART 1 - CHECK EQUATION ALGORITHM*/
    //cout << isEquationCorrect("{{a+b}-[(a+b)+{a]}") << endl;

    /*PART 1 - LABIRYNTH PATH  ALGORITHM*/

    //vector<Coords>alreadyVisited;
    //HarryPath(x[0][0], 0, 0, alreadyVisited);


    return 0;
}





