#include <bits/stdc++.h>
using namespace std;
struct State{
	int x, y;
	int step;
	vector<pair<int, int>> path;
};
void printPath( const vector<pair<int, int>>& path){
	for( const auto& p : path){
		cout << "(" << p.first << " " << p.second << ") ";
	}
}
bool isVisited(unordered_set<int> &visited, int x, int y){
	return visited.find(x * 1000 + y) != visited.end() ;
}
void markVisited(unordered_set<int> &visited, int x, int y){
	visited.insert(x * 1000 + y);
}
State findSteps(int a, int b, pair<int, int> target){
    unordered_set<int> visited;
    queue<State> q;
    State initi = {a, b, 0, {{a, b}}};
    q.push(initi);
    markVisited(visited, a, b);
    while(!q.empty()){
    	State varicur = q.front();
    	q.pop();
    	if(varicur.x == target.first && varicur.y == target.second){

    		return varicur;
		}

        if(varicur.x > varicur.y && !isVisited(visited, varicur.x - varicur.y, varicur.y)){
			vector<pair<int, int>> nextPath = varicur.path;
			nextPath.push_back({varicur.x - varicur.y, varicur.y});
			State nextState1 = {varicur.x - varicur.y, varicur.y, varicur.step + 1, nextPath};
			q.push(nextState1);
			markVisited(visited, nextState1.x, nextState1.y);
		}
		if(!isVisited(visited, varicur.x + varicur.y, varicur.y) && (varicur.x + varicur.y <= target.first )){
			vector<pair<int, int>> nextPath = varicur.path;
		 	nextPath.push_back({varicur.x + varicur.y, varicur.y});
		    State nextState2 = {varicur.x + varicur.y, varicur.y, varicur.step + 1, nextPath};
			q.push(nextState2);
			markVisited(visited, nextState2.x, nextState2.y);
		}
    	if(!isVisited(visited, varicur.y, varicur.x)){
    		vector<pair<int, int>> nextPath = varicur.path;
			nextPath.push_back({varicur.y, varicur.x});
			State nextState3 = {varicur.y, varicur.x, varicur.step + 1, nextPath};
			q.push(nextState3);
			markVisited(visited, nextState3.x, nextState3.y);
		}
	}
    return State{0, 0, -1, {}};
}

int main(){
	int c, d, a , b;
	cin >> c >> d >> a >> b;
	pair<int, int> target;
	target.first = a;
	target.second = b;
    State finalState = findSteps(c, d, target);
	if(finalState.step == -1) cout << "-1";
	else {

        cout << finalState.step << " ";
		printPath(finalState.path);
	}
	return 0;
}