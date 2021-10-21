// 처음 나의 풀이 
// 내가 푼 풀이는 큐에 초점을 맞추어 풀었고, 생각이 부족했던것 같다.
/*
  내가 생각한 시나리오는 이렇다. 
  if(지금 보고 있는 큐의 순서가 젤 큰가)
  {
    if(너가 찾던 그수인가?)
      return;
    queue.pop()
  } 
  else
  { 
    queue.front() -> back으로 다시 push
    queue.pop)
  }
 아래의 풀이는 
*/
#include <string>
#include <vector>
#include <queue>

using namespace std;

bool isMaxValue(vector<int> array, int currentPriority)
{
    for(int i =0; i< array.size(); i ++)
    {
        if(currentPriority < array[i]) return false;
    }
    return true;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int,int>> priorityOrder;
    for(int i = 0 ; i < priorities.size(); i++)
    {
        priorityOrder.push(
            make_pair(i,priorities.at(i)));
           
    }
    int i =0;
    while(!priorityOrder.empty())
    {
        if(isMaxValue(priorities,priorityOrder.front().second))
        {
            priorities.at(i%4) = -1;
            answer++;
            
            if(priorityOrder.front().first == location) {
                return answer;
            }
            priorityOrder.pop();
        } else {
            priorityOrder.push(
                make_pair(
                    priorityOrder.front().first,
                    priorityOrder.front().second));
            priorityOrder.pop();
        }
        i++;
    }

    return answer;
}

// 위의 풀이는 최악의 경우 큐를 돌리는 과정이 불필요하게 많이 소모된다.

// 아래의 풀이는 우선순위의 개념을 정립하여 다시 풀었다. 

#include <string>
#include <vector>
#include <queue>
#include "algorithm"

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> indexQueue;
    // 찾고자하는 index의 위치를 나타내는 queue
    queue<int> orderQueue;
    // 순서를 나타내고자 하는 queue
    for(int i = 0; i < priorities.size(); ++i)
    {
        indexQueue.push(i);
        orderQueue.push(priorities[i]);
    }

    while(true)
    {
        auto iter = max_element(priorities.begin(), priorities.end());
        if (orderQueue.front() == (*iter))
        {
            // max값중 하나이기 때문에 pop
            priorities.erase(iter);
            ++answer;
            if(indexQueue.front() == location)
                break;
            orderQueue.pop();
            indexQueue.pop();
        }
        else
        {
            // queue 
            orderQueue.push(orderQueue.front());
            indexQueue.push(indexQueue.front());
            orderQueue.pop();
            indexQueue.pop();
        }
    }

    return answer;
}

