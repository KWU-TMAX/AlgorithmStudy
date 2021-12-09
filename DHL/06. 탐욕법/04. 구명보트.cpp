#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;


int solution(vector<int> people, int limit) {
    int answer = 0;
    deque<int> peopleDq;
    sort(people.begin(),people.end());
    for(int i = 0; i < people.size(); i++) {
        peopleDq.push_back(people[i]);
    }


    while(peopleDq.size()!=0 && peopleDq.size() != 1){
        for(int i = peopleDq.size()-1; i > 0; i--) {
            if(peopleDq.front() + peopleDq.at(i) <= limit) {
                peopleDq.pop_front();
                peopleDq.pop_back();
                answer++;
                break;
            } else {
                peopleDq.pop_back();
                answer++; 
                break;
            }
        }
    }
    if(peopleDq.size() == 1) answer++; // 한명이 남은 경우
    return answer;
}
