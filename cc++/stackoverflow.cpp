#include<deque>

int arr[5][5] = {
    {0, 0, 1, 1, 0},
    {1, 0, 1, 1, 0},
    {1, 0, 0, 1, 1},
    {1, 1, 0, 0, 0},
    {1, 0, 0, 1, 1}
};

int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy[8] = {1, 0, -1, 1, 1, 0, -1, -1};

// using two queues to avoid pairs
std::deque<int> qx, qy;
int main(){
    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            if (arr[i][j] == 1){
                // run BFS:

                qx.push_back(i);
                qy.push_back(j);
                while (!qx.empty()){
                    int curx = qx.front(), cury = qy.front();

                }
            }
        }
    }
}