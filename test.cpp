// 在一个机器人王国里，围绕首都分N层构建卫星城市。以首都为圆心，以路相连分出两个卫星城在第一个层，
// 然后每个卫星城又有路相连分出两个卫星城在下一层，但每条路的长度不同。第N层的卫星城不再分出新的卫星城。
//现在人类只探知到所有直接相连的城市间的路程，你能计算某个卫星城到达首都的路程吗？
// 第一行为N，表示机器人王国里有N层卫星城，N最大为10。从第二行开始，共2N+1-2行，
// 每行分别是城市的代号到其分出的卫星城的代号和它们间的路程。
// 代号用若干个字母表示，直连路程最大为100。最后一行是某卫星城的代号。
//根据最后一行的卫星城代号，求该卫星城到首都的路程。
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct City {
    string name;
    string parent;
    int distance;
};

int findCityIndex(vector<City>& cities, string& name) {
    for (int i = 0; i < cities.size(); ++i) {
        if (cities[i].name == name) {
            return i;
        }
    }
    return -1; // 如果找不到则返回-1
}

int main() {
    int N;
    cin >> N;
    int num_cities = (1 << (N + 1)) - 2;//2^(N+1)-2这个是左移，可以类比上课讲过的右移

    vector<City> cities(num_cities);//用于存储城市的容器（数组）

    for (int i = 0; i < num_cities; ++i) 
    {
        string from, to;
        int distance;
        cin >> from >> to >> distance;
        cities[i] = {to, from, distance};
    }

    string target;
    cin >> target;

    int total_distance = 0;
    while (true) 
    {
        int index = findCityIndex(cities, target);
        if (index == -1) {
            break;
        }
        total_distance += cities[index].distance;
        target = cities[index].parent;
    }

    cout << total_distance << endl;

    return 0;
}
