#include <iostream>
using namespace std;

int r,c;

void printMat(char input[][50]){

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<input[i][j];
        }
        cout<<endl;
    }
}

// W,S,E,N
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

// ch is the charater to be replaced
// color is the character to be added
void floodFill(char mat[][50], int i, int j, char ch, char color){

    // Base case - Matrix Bounds
    if(i<0 || j<0 || i>=r || j>=c){
        return;
    }

    // Figure Boundary Condition
    if(mat[i][j] != ch){
        return;
    }

    mat[i][j] = color;
    // Recursive case
    for(int k=0; k<4; k++){
        floodFill(mat, i + dx[k], j + dy[k], ch, color);
    }
}

int main(){

    cin>>r>>c;

    char input[15][50];
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>input[i][j];
        }
    }

    printMat(input);

    floodFill(input, 8, 13, '.', 'r');
    floodFill(input, 0, 0, '.', '!');

    printMat(input);
    return 0;
}