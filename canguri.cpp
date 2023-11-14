#include <fstream>
#define MAX_CANGURI 500
using namespace std;
void citeste(int &, int [MAX_CANGURI]);
int lungimeMinimaTraseu(int, int [MAX_CANGURI]);
int main()
{
	int nrCanguri, lungimeSalt[MAX_CANGURI];
	citeste(nrCanguri, lungimeSalt);	
	ofstream fout("canguri.out");
	fout << lungimeMinimaTraseu(nrCanguri, lungimeSalt);
	fout.close();
	return 0;
}
int celMaiMareDivizorComun(int a, int b)
{
	while (b)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int celMaiMicMultipluComun(int a, int b)
{
	return a/celMaiMareDivizorComun(a, b) * b;
}
int lungimeMinimaTraseu(int nrCanguri, int lungimeSalt[MAX_CANGURI])
{
	int cmmmc, lungimeSaltMaxim, i, rezultat;
	cmmmc = lungimeSaltMaxim = lungimeSalt[0];
	for (i = 1; i < nrCanguri; i++)
	{
		cmmmc = celMaiMicMultipluComun(lungimeSalt[i], cmmmc);
		if (lungimeSalt[i] > lungimeSaltMaxim)
			lungimeSaltMaxim = lungimeSalt[i];
	}
	rezultat = cmmmc;
	while (rezultat/lungimeSaltMaxim < 3)
		rezultat += cmmmc;
	return rezultat;
}
void citeste(int & nrCanguri, int lungimeSalt[MAX_CANGURI])
{
	ifstream fin("canguri.in");
	fin >> nrCanguri;
	for (int i = 0; i < nrCanguri; i++)
		fin >> lungimeSalt[i];
	fin.close();
}
