// BOJ 3/2 코딩테스트 대비 모의고사 A번 - 계란으로 계란치기
#include<iostream>
using namespace std;
int N, S, W, ans;
bool flag;
struct e
{
	int broken;
	int durability;
	int weight;
}typedef EGG;
int arr[9];
EGG egg[9];
// 깨진 계란 복구하기
void crushback(int e1, int e2)
{
	egg[e1].durability += egg[e2].weight;
	egg[e2].durability += egg[e1].weight;
	if (egg[e1].durability > 0) egg[e1].broken = 0;
	if (egg[e2].durability > 0) egg[e2].broken = 0;
	return;
}
// 계란 깨뜨리기
void crush(int e1, int e2)
{
	egg[e1].durability -= egg[e2].weight;
	egg[e2].durability -= egg[e1].weight;
	if (egg[e1].durability <= 0) egg[e1].broken = 1;
	if (egg[e2].durability <= 0) egg[e2].broken = 1;
	return;
}
// 깨진 계란의 개수를 세는 함수
int findnumbroken()
{
	int v = 0;
	for (int i = 0; i < N; i++)
	{
		if (egg[i].broken == 1) v++;
	}
	return v;
}
void simulate(int idx)
{
	flag = false;
	// 갱신
	if (idx >= N)
	{
		int val = findnumbroken();
		if (ans < val) ans = val;
		return;
	}
	// 깨지지 않은 계란 하나 골라 깨뜨리기
	for (int i = 0; i < N; i++)
	{
		// 깨뜨리기
		if (i != idx && egg[i].broken == 0) {
			crush(idx, i);
			int k = idx + 1;
			while (egg[k].broken == 1) k++;
			simulate(k);
			crushback(idx, i);
			flag = true;
		}
	}
	// 더 이상 깨뜨릴 수 있는 계란이 없을 때, 값 갱신
	if (!flag)
	{
		int k = idx + 1;
		while (egg[k].broken == 1) k++;
		simulate(k);
	}
	return;
}
int main()
{
	cin >> N;
	for (int i = 0; i <= N; i++)
	{
		egg[i].broken = 0;
		egg[i].durability = 0;
		egg[i].weight = 0;
	}
	for (int i = 0; i < N; i++)
		cin >> egg[i].durability >> egg[i].weight;
	simulate(0);
	cout << ans;
}
