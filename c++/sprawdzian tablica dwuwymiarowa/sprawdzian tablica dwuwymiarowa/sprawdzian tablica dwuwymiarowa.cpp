#include <iostream>
using namespace std;
int main()
{
    const int M = 3;
    const int N = 4;
    int lacznie_liczb = M * N;
    int ile_ujemnych = 0;
    int ile_dodatnich = 0;

    cout << "Podaj " << lacznie_liczb << " liczb do tablicy " << M << "x" << N << "\n";
    double tab[M][N];
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> tab[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (tab[i][j] > 0) {
                ile_dodatnich++;
            }
        }
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (tab[i][j] < 0) {
                    ile_ujemnych++;
                }

            }
        }
    }
    cout << "Liczb dodatnich jest : " << ile_dodatnich<<" \n";
    cout << "Liczb ujemnych jest : " << ile_ujemnych << " \n";
}