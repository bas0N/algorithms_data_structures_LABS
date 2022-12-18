// villains.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
#include <algorithm>
#include <iterator>
#include<vector>
#include <iostream>
using namespace std;

//villain class
class Villain {        
public:          // Access specifier
    string name;  // Attribute
    int s;  
    int e;      // Attribute
    Villain(string x, int y, int z) { // Constructor with parameters
        name = x;
        s = y;
        e = z;
    }
    friend bool operator == (Villain const& l, Villain const& r) noexcept {
        return l.name == r.name && l.s == r.s && l.e == r.e;
    }
    Villain(){}
};
//max values - globals
int maxNum = 0;
vector <Villain>maxVillains;


void Combi( vector<Villain> v, vector<char>a, int reqLen, int s, int currLen, vector<bool>check, int l)
// print the all possible combination of given array set
{
    if (currLen > reqLen)
        return;
    else if (currLen == reqLen) {
        cout << "\t";
        for (int i = 0; i < l; i++) {
            if (check.at(i) == true) {
                int currentNum = 0;
                vector <Villain>currentVillains;
                for (int j = 0; j < l; j++) {
                    //check if they dont kill each other

                    if (v.at(i).e < v.at(j).s) {
                        currentVillains.push_back(v.at(i));
                        currentVillains.push_back(v.at(j));
                       // cout << "PUSH TO ARR" << endl;
                    }
                }
                //find unique values only
                vector<Villain>::iterator ip;
            

                ip = unique(currentVillains.begin(), currentVillains.end());
                currentVillains.resize(distance(currentVillains.begin(), ip));
                currentNum = currentVillains.size();

                if (currentNum > maxNum) {
                    maxNum = currentNum;
                    std::copy(maxVillains.begin(), maxVillains.end(), currentVillains.begin() );

              
                }
              
            }
           
        }
        cout << "\n";
        return;
    }
    if (s == l) {
        return;
    }
    check[s] = true;
    Combi(v,a, reqLen, s + 1, currLen + 1, check, l);
    //recursively call Combi() with incremented value of ‘currLen’ and ‘s’.
    check[s] = false;
    Combi(v,a, reqLen, s + 1, currLen, check, l);
    // recursively call Combi() with only incremented value of ‘s’.
}

int main()
{

  
    
    int i, n;
    cout << "Enter the number of villains: ";
    cin >> n;
    //initialize vectors for finding the combinations
    vector <bool> check;
    vector <char>a;
    vector <Villain> v;
    cout << "\n";
    //insert villains
   for (i = 0; i < n; i++) {
       string name;
       int s;
       int e;
       cout << "Input the name of villain: ";
       cin >> name;
       cout << "Input the ego of villain: ";
       cin >> e;
       cout << "Input the strength of villain: ";
       cin >> s;
       Villain v1(name, s, e);
       cout <<"Name: " << v1.name <<" Ego: "<< v1.e <<" Strength: " << v1.s << endl;
       v.push_back(v1);
        a.push_back(i);
        check.push_back(false);
    }
    for (i = n; i>0; i--) {
        Combi(v,a, i, 0, 0, check, n);
    }
    //output the results
   cout << "Max num of Villains is: " << maxNum << endl;
   cout << "The array of villains is: \n" << endl;
   
   for (int x = 0;x<maxNum;x++) {
       cout << "Name: " << v.at(x).name << " Ego: " << v.at(x).e << " Strength: " << v.at(x).s << endl;

   }
    return 0;
}
