// ECOO '16 R1 P3 - Railway Sort

#include<bits/stdc++.h>
using namespace std;

int cases = 10;
const int MM = 1003;
int n, arr[MM];
deque<int> start, mid;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	while (cases--){
		cin >> n;
		int ans = 0;
		for (int i=0; i<n; i++){
			int a; cin >> a;
			arr[a] = 1;
			start.push_back(a);
		}
		for (int i=n; i>=1; i--){
			if (arr[i] == 1){
				while (start.back() != i){
					mid.push_back(start.back());
					arr[start.back()] = 2;
					start.pop_back();
					ans++;
				}
				start.pop_back();
			}
			else {
				while (mid.back() != i){
					start.push_back(mid.back());
					arr[mid.back()] = 1;
					mid.pop_back();
					ans++;
				}
				mid.pop_back();
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}