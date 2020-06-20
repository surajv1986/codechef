#include<bits/stdc++.h>
#include<iostream>
#include<cstdlib>

using namespace std;

#define SZ 10000
#define PLAYER_1 1
#define PLAYER_2 2

bool bo_player1 = false, bo_player2 = false;

int compute_victor(int lead1, int lead2, int diff)
{
	int ret = 0;

	if (diff < 0) 
		ret = PLAYER_1;
	else
		ret = PLAYER_2;

	return ret;
}

int print_array(int a[], int b[],int c[], int d[], int len)
{
	int i = 0;

	for (i = 0; i < len; i++) {
		cout << a[i] << " " << b[i] << "  " << c[i] << "  " << d[i] << endl;
	}

	return 0;	
}

int decide_lead_winner(int lead1[], int lead2[], int len)
{
	int i = 0, max1 = lead1[0], max2 = lead2[0], max;

	for (i = 0; i < len; i++) {
		if (lead1[i] > max1) 
			max1 = lead1[i];
		if (lead2[i] > max2)
			max2 = lead2[i];
	}
	if (max1 > max2) {
		max = max1;
		bo_player1 = true;
	} else {
		max = max2;
		bo_player2 = true;
	}
	return max;
}

int main(void)
{
	int ret, diff, no_test_cases, player1[SZ], player2[SZ], lead1[SZ], lead2[SZ], i = 0, max;
	
	cin >> no_test_cases;
	while (i < no_test_cases) {
		cin >> player1[i];
		cin >> player2[i];
		if (i >= 1) {
			player1[i] += player1[i - 1];
			player2[i] += player2[i - 1];
		}
		diff = player2[i] - player1[i];
		ret = compute_victor(player1[i], player2[i], diff);
		if (ret == PLAYER_1) {
			lead1[i] = abs(diff);
			lead2[i] = 0;
		} else {	
			lead1[i] = 0;	
			lead2[i] = diff;
		}
		i++;
	}	
	print_array(player1, player2, lead1, lead2, i);
	max = decide_lead_winner(lead1, lead2, i);
	if (bo_player1 == true)
		cout << PLAYER_1 << " " << max << endl;
	else
		cout << PLAYER_2 << " " << max << endl;

	return 0;
}
