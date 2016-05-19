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
