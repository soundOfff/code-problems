#include <bits/stdc++.h>

using namespace std;

int calc1(int mx){
	
	int l = 1;
	int r = 1e9-1;
	
	int bs_ans = 0;
	
	while(l <= r){
		
		int mid = (l+r)/2;
		
		string s_num = to_string(mid);
		string tmp = s_num;
		reverse(tmp.begin(), tmp.end());
		for(auto c : tmp) s_num.push_back(c);
		
		// cout << s_num << endl << flush;
				
		int num = stoll(s_num);
		
		if(num <= mx){
			bs_ans = mid;
			l = mid+1;
		}
		else{
			r = mid-1;
		}
	}	
	
	return bs_ans;
}

int calc2(int mx){
	
	int l = 1;
	int r = 1e9-1;
	
	int bs_ans = 0;
	
	while(l <= r){
		
		int mid = (l+r)/2;
		
		string s_num = to_string(mid);
		string tmp = s_num;
		reverse(tmp.begin(), tmp.end());
		tmp.erase(tmp.begin());
		for(auto c : tmp) s_num.push_back(c);
		
		// cout << s_num << endl << flush;
		
		int num = stoll(s_num);
		
		if(num <= mx){
			bs_ans = mid;
			l = mid+1;
		}
		else{
			r = mid-1;
		}
	}	
	
	return bs_ans;
}

int main(){
	
    int t; cin >> t; while(t--){

		int l, r;
		cin >> l >> r;
		
		int ans = calc1(r) + calc2(r);
		if(l) ans -= calc1(l-1) + calc2(l-1);
		
		cout << ans << endl;
    }	
}