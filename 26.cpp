#include <iostream>
#include <priority_queue>

using namespace std;

int  main() {
priority_queue <int> P;
P.push(17); P.push(5); P.push(400);
P.push(2500); P.push(1);
while (!P.empty()) {
cout<< P.front() << ' ';
P.pop();
} 
return 0;
}
