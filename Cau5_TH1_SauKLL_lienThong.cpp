#include<bits/stdc++.h>
using namespace std;

#define MAX_M 30
#define MAX_N 30
#define MAX_VALUE 9

int L[MAX_M][MAX_N];
int m, n; 

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int isValid(int x, int y) {
    return x >= 0 && x < m && y >= 0 && y < n;
}

void DFS(int x, int y, int value, int visited[MAX_M][MAX_N]) {
    visited[x][y] = 1;
    
    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        
        if (isValid(newX, newY) && !visited[newX][newY] && L[newX][newY] == value) {
            DFS(newX, newY, value, visited);
        }
    }
}

int countConnectedRegion(int i, int j) {
    int visited[MAX_M][MAX_N] = {0};
    int value = L[i][j];
    int count = 0;
    
    DFS(i, j, value, visited);
    
    for (int x = 0; x < m; x++) {
        for (int y = 0; y < n; y++) {
            if (visited[x][y] == 1) {
                count++;
            }
        }
    }
    
    return count;
}

void findAllConnectedRegions() {
    int visited[MAX_M][MAX_N] = {0};
    cout << "Cac mien lien thong trong luoi:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                int value = L[i][j];
                cout << "Mien lien thong gia tri: " << value << " la " << i << " " << j << "\n";
                int count = 0;
        
                DFS(i, j, value, visited);
                
                for (int x = 0; x < m; x++) {
                    for (int y = 0; y < n; y++) {
                        if (visited[x][y] == 1) {
                            count++;
                        }
                    }
                }
                cout << "So o trong mien lien thong: " << count << "\n";
            }
        }
    }
}

void findRegionsWithValue(int k) {
    int visited[MAX_M][MAX_N] = {0};
    
    cout << "Cac mien lien thong co gia tri: " <<  k << " ";
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (L[i][j] == k && !visited[i][j]) {
                int count = 0;
                
                DFS(i, j, k, visited);
                
                for (int x = 0; x < m; x++) {
                    for (int y = 0; y < n; y++) {
                        if (visited[x][y] == 1) {
                            count++;
                        }
                    }
                }
                cout << "Mien lien thong toi o: " << i << " " << j << count << "\n";
            }
        }
    }
}

void generateGrid() {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            L[i][j] = rand() % (MAX_VALUE + 1);
        }
    }
}

int main() {
    m = 10; 
    n = 10;
    
    generateGrid();
    cout << "Luoi ngau nhien : \n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << L[i][j] << " ";
        }
        cout << "\n";
    }
    
    int i = 2, j = 3;  
    
    int regionSize = countConnectedRegion(i, j);
    cout << "So o trong mien lien thong cua o " <<  i << " " << j << "La : " <<  regionSize << "\n";
    
    findAllConnectedRegions();
    
    int k = 5; 
    findRegionsWithValue(k);
    
    return 0;
}

