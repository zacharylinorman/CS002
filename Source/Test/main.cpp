#include <cmath>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <string>

#include <vector>
#include <iostream>

using namespace std;
bool same_elements(vector<int> a, vector<int> b){
    if(a.size() != b.size()){
        return false;
    }
    vector<int> foundIndices;
    for(int i = 0; i < a.size(); i++){
        for(int k = 0; k < b.size(); k++){
            if(a[i] == b[k]){
                bool alreadyFound = false;
                for(int j = 0; j < foundIndices.size(); j++){
                    if(k == foundIndices[j]){
                        alreadyFound = true;
                        break;
                    }
                }
                if(!alreadyFound){
                    foundIndices.push_back(k);
                }
            }
        }
    }

    return foundIndices.size() == a.size();
}

int main()
{
    enum Direction { N, S, E, W } d;
    cout << static_cast<Direction>(W+1) << " " << E << " " << S << " " << N << endl;
}
/*
int base, rows;
base = 21;
rows = base / 2.0 + 0.5;
for(int i = rows; i > 0; i--){
       for(int k = 1; k <= base; k++){
           if(k<i||k>=base+2-i){ //i+(((5-i)*2)+1) = 11-i
               cout << " ";
           }else{
               cout << "*";
           }
       }
       cout << endl;
   }
*/
