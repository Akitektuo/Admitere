#include <iostream>
#include <queue>
using namespace std;

bool areEqualNotNull(int a, int b, int c) {
    if (a != 0 && a == b && b == c) {
        return true;
    }
    return false;
}

struct State {
    int board[3][3] = {
        { 0, 0, 0 },
        { 0, 0, 0 },
        { 0, 0, 0 }
    };

    State() {}

    State(const State& state) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = state.board[i][j];
            }
        }
    }
    int checkWin() {
        if (areEqualNotNull(board[0][0], board[1][1], board[2][2])) {
            return board[0][0];
        }
        if (areEqualNotNull(board[0][2], board[1][1], board[2][0])) {
            return board[0][2];
        }
        if (areEqualNotNull(board[0][0], board[0][1], board[0][2])) {
            return board[0][0];
        }
        if (areEqualNotNull(board[1][0], board[1][1], board[1][2])) {
            return board[1][0];
        }
        if (areEqualNotNull(board[2][0], board[2][1], board[2][2])) {
            return board[2][0];
        }
        if (areEqualNotNull(board[0][0], board[1][0], board[2][0])) {
            return board[0][0];
        }
        if (areEqualNotNull(board[0][1], board[1][1], board[2][1])) {
            return board[0][1];
        }
        if (areEqualNotNull(board[0][2], board[1][2], board[2][2])) {
            return board[0][2];
        }
        return 0;
    }
};


struct Node {
    State state;
    int score = 0;
    Node* children[9];
    int length = 0;
};

void bfs(Node* root){
    queue<Node*> q;
    q.push(root);
    int k=0;
    while(!q.empty() && k<30){
        Node* current = q.front();
        cout<<"\n";
        k++;
        cout<<current->score<<"\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
            cout<<current->state.board[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
        for (int i =0;i<current->length;i++){
            q.push(current->children[i]);
        }
        q.pop();
    }
}


void generateOffspring(Node* node, bool isMax, bool isXTurn,int& cnt) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (node->state.board[i][j] == 0) {
                Node* offspring = new Node();
                State st(node->state);
                st.board[i][j]=isXTurn?1:-1;
                offspring->state = st;

                node->children[node->length++]=offspring;
                int win =st.checkWin();
                if (win==0){
                    generateOffspring(offspring,!isMax,!isXTurn,++cnt);

                }
                else{
                    offspring->score = win*10;

                }
            }
        }
    }
    int val;
    if (isMax){
        val = -11;
        for (int i =0;i<node->length;i++){
            if (node->children[i]->score>val){
                val = node->children[i]->score;
            }
        }
    }else{
            val = 11;
        for (int i =0;i<node->length;i++){
            if (node->children[i]->score<val){
                val = node->children[i]->score;
            }
        }
    }
    node->score=val;
}

Node* generateMiniMaxTree(int& nr) {
    Node* root = new Node();
    generateOffspring(root,false,true,nr);
    return root;
}



int main() {
    cout << "Hello world!" << endl;
    int nr=0;
    Node* root = generateMiniMaxTree(nr);
    cout<<"Number of:"<<nr<<"\n";
    //generateOffspring(root,true,true);
    bfs(root);
    return 0;
}
