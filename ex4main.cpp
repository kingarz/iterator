#include "aghInclude.h"
#include <iostream>

using namespace std;
// ---------------------------------------------------------

void showTestResult(int, bool);
// ---------------------------------------------------------

int main(void)
{
	aghSlist<int>* lista = new aghSlist<int>;
	lista->append(1);
	lista->append(2);
	lista->append(3);
	lista->insert(1, 100);
	lista->at(1) = 5;
	delete lista;

	aghDlist<int>* dlista = new aghDlist<int>;
	dlista->append(1);
	dlista->append(2);
	dlista->append(3);
	dlista->insert(2,100);
	delete dlista;

}
// ---------------------------------------------------------

void showTestResult(int _ti, bool _r)
{
    if (_r) {
        cout << "Test" << _ti << " PASSED\n";
    }
    else {
        cout << "Test" << _ti << " FAILED\n";
    }
}
// ---------------------------------------------------------
