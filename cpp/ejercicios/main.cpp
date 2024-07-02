#include <bits/stdc++.h>

using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b,c;

    cin >> a >> b >> c;
    int qnty = 1;
    int qntyMonth = 1;
    int money = 0;
    int months = 0;
     
    while(qnty < c)
    {
        money += b*qnty;
        qntyMonth = money / a;
        qnty += qntyMonth;
        money -= a*qntyMonth;
        months++;
    }

    cout << months << endl;

}