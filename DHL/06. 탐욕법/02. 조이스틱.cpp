#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int minimumMove[26] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,12,11,10,9,8,7,6,5,4,3,2,1};

// 오른쪽이 더 가까운 알파벳이 있는지
// 가장 가까운 위치를 리턴하고, 몇번 이동해야 있는지를 리턴한다.
vector<int> right(int position, string name) {
    int move=0;
    vector<int> moveAndPosition;
    while(true){
        move++;
        position++;
        if(position > name.size()) position = 0;
        if(name[position] != 'A') {
            moveAndPosition.push_back(move);
            moveAndPosition.push_back(position);
            return moveAndPosition;
        } 
    }
}
// 왼쪽이 더 가까운 알파벳이 있는지
vector<int> left(int position, string name) {
    int move=0;
    vector<int> moveAndPosition;
    while(true){
        move++;
        position--;
        if(position < 0) position = name.size()-1;
        if(name[position] != 'A') {
            moveAndPosition.push_back(move);
            moveAndPosition.push_back(position);
            return moveAndPosition;
        }
    }
}

int solution(string name) {
    int answer = 0;
    int position = 0;
    int count = 0;
    for(int i =0; i < name.size(); i++ ) {
        if(name[i] != 'A') count++;
    }
    
    if(name[position] != 'A') count--;
    answer += minimumMove[(int)(name[position]) - 65];
    name[position] = 'A';

    while(count) {
        if(right(position,name)[0] <= left(position,name)[0]) {
            cout << "right" << endl;
            answer += right(position,name)[0];
            position = right(position,name)[1];
            answer += minimumMove[(int)(name[position]) - 65];
            name[position] = 'A';
            count--;
        }
        else {
            cout << "left" << endl;
            answer += left(position,name)[0];
            position = left(position,name)[1];
            answer += minimumMove[(int)(name[position]) - 65];
            name[position] = 'A';
            count--;
        }
    }
    return answer;
}
