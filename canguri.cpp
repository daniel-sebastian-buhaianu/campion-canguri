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
	return a*b/celMaiMareDivizorComun(a, b);
}
int lungimeMinimaTraseu(int nrCanguri, int lungimeSalt[MAX_CANGURI])
{
	int cmmmc, lungimeSaltMaxim, nrSalturi, i;
	cmmmc = lungimeSaltMaxim = lungimeSalt[0];
	for (i = 1; i < nrCanguri; i++)
	{
		cmmmc = celMaiMicMultipluComun(lungimeSalt[i], cmmmc);
		if (lungimeSalt[i] > lungimeSaltMaxim)
			lungimeSaltMaxim = lungimeSalt[i];
	}
	nrSalturi = cmmmc/lungimeSaltMaxim;
	if (nrSalturi >= 3)
		return cmmmc;
	if (nrSalturi == 2)
		return cmmmc + lungimeSaltMaxim;
	return cmmmc * 3;
}
void citeste(int & nrCanguri, int lungimeSalt[MAX_CANGURI])
{
	ifstream fin("canguri.in");
	fin >> nrCanguri;
	for (int i = 0; i < nrCanguri; i++)
		fin >> lungimeSalt[i];
	fin.close();
}
