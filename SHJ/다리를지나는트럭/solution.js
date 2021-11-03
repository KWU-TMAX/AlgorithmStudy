function solution(bridge_length, weight, truck_weights) {
    let bridge = new Array(bridge_length).fill(0);    // 트럭이 지나가는 다리    new Array(size)를 하면 사이즈가 정해진 array를 만들수 있음.
    // fill을 사용하면 0으로 초기화 가능
    let cur_weight = 0;
    let time = 0;
    while(1) {
        if(cur_weight === 0 && truck_weights.length === 0) break;    // 다리위의 트럭이 없고 지나갈 트럭이 없으면 계산 종료
        let truck = bridge[bridge.length-1];
        if(truck > 0) {
            cur_weight -= truck;
        }
        bridge.pop();      // 일단 시간이 1초 흐르면 배열에서 하나를 꺼낸다
        time++;            // 시간이 1초 지남을 의미
        if(cur_weight + truck_weights[0] <= weight) {   // 다리에 트럭이 지나갈 수 있을 때
            let truck = truck_weights.shift();
            bridge.unshift(truck);                      // 트럭을 넣는다
            cur_weight += truck;
        } else {                                        // 다리에 트럭이 못지나갈떄
            bridge.unshift(0);                          // 0을 넣는다
        }
    }    
    return time;
}
