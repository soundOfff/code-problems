using namespace std;

const int me = 1000025;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
int ans = 0;
        while(n > 0){
            char s[10];
            fill(s, s + 10, '0');
            sprintf(s, "%d", n);
            sort(s, s + (int)strlen(s));
            n -= atoi(s);
            ans ++;
        }
        cout << ans << endl;
    }
    
    return 0;
}