#include "ArrayQueue.hpp"
#include <iostream>
using namespace std;

int main() {
    ArrayQueue<int> q(3);

    // front/back on empty queue
    try { q.front(); }
    catch (string& e) { cout << "front empty ok "; }
    try { q.back(); }
    catch (string& e) { cout << "back empty ok "; }

    // enqueue + front/back
    q.enqueue(10);
    q.enqueue(20);
    cout << "front:" << q.front() << " back:" << q.back() << " ";

    // dequeue
    q.dequeue();
    cout << "after dequeue front:" << q.front() << " ";

    // full queue check + enqueue on full
    q.enqueue(30);
    q.enqueue(40);
    try { q.enqueue(50); }
    catch (string& e) { cout << "full enqueue ok "; }

    // copy constructor check
    ArrayQueue<int> copyQ(q);
    cout << "copy front:" << copyQ.front() << " back:" << copyQ.back() << " ";

    // clear check
    q.clear();
    if (q.isEmpty()) cout << "clear ok ";

    // assignment operator check
    ArrayQueue<int> assignQ;
    assignQ = copyQ;
    cout << "assign front:" << assignQ.front() << " back:" << assignQ.back() << '\n';

    return 0;
}
